
local generator = require "comgen.generator"

local types = generator.types

local IUnknown =  { name = "IUnknown", iid = "{00000000-0000-0000-C000-000000000046}" }

local FILETIME = types.struct("FILETIME", {
  { type = types.dword, name = "dwLowDateTime" },
  { type = types.dword, name = "dwHighDateTime" },
})

local OPCDATASOURCE = {
  name = "OPCDATASOURCE",
  fields = {
    { name = "OPC_DS_CACHE", value = 1 },
    { name = "OPC_DS_DEVICE", value = 2 },
  }
}

local HRESULT = {
  name = "HRESULT",
  fields = {
    { name = "S_OK", value = 0 },
    { name = "S_FALSE", value = 1 }
  }
}

local OPCITEMSTATE = types.struct("OPCITEMSTATE", {
  { type = types.dword, name = "hClient" },
  { type = FILETIME, name = "ftTimeStamp" },
  { type = types.word, name = "wQuality" },
  { type = types.word, name = "wReserved" },
  { type = types.variant, name = "vDataValue" }
})

local OPCITEMDEF = types.struct("OPCITEMDEF", {
  { type = types.wstring, name = "szAccessPath" },
  { type = types.wstring, name = "szItemID" },
  { type = types.bool, name = "bActive" },
  { type = types.dword, name = "hClient" },
  { type = types.dword, name = "dwBlobSize" },
  { type = types.array(types.byte,  { size_is = "dwBlobSize" }), name = "pBlob" },
  { type = types.enum("VARTYPE"), name = "vtRequestedDataType" },
  { type = types.word, name = "wReserved" }
})

local OPCITEMRESULT = types.struct("OPCITEMRESULT", {
  { type = types.dword, name = "hServer" },
  { type = types.enum("VARTYPE"), name = "vtCanonicalDataType" },
  { type = types.word, name = "wReserved" },
  { type = types.dword, name = "dwAccessRights" },
  { type = types.dword, name = "dwBlobSize" },
  { type = types.array(types.byte,  { size_is = "dwBlobSize" }), name = "pBlob" },
})

local OPCITEMVQT = types.struct("OPCITEMVQT", {
  { type = types.variant, name = "vDataValue" },
  { type = types.bool, name = "bQualitySpecified" },
  { type = types.word, name = "wQuality" },
  { type = types.word, name = "wReserved" },
  { type = types.bool, name = "bTimeStampSpecified" },
  { type = types.dword, name = "dwReserved" },
  { type = FILETIME, name = "ftTimeStamp" },
})

local OPCSERVERSTATUS = types.struct("OPCSERVERSTATUS", {
  { type = FILETIME, name = "ftStartTime" },
  { type = FILETIME, name = "ftCurrentTime" },
  { type = FILETIME, name = "ftLastUpdateTime" },
  { type = types.dword, name = "dwServerState" },
  { type = types.dword, name = "dwGroupCount" },
  { type = types.dword, name = "dwBandWidth" },
  { type = types.word, name = "wMajorVersion" },
  { type = types.word, name = "wMinorVersion" },
  { type = types.word, name = "wBuildNumber" },
  { type = types.word, name = "wReserved" },
  { type = types.wstring, name = "szVendorInfo" }
})

local IOPCServer = {
  name = "IOPCServer",
  iid = "{39C13A4D-011E-11D0-9675-0020AFD8ADB3}",
  parent = IUnknown,
  methods = {
    {
      name = "AddGroup",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true }, name = "szName" },
        { type = types.bool, attributes = { ["in"] = true }, name = "bActive" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwRequestedUpdateRate" },
        { type = types.dword, attributes = { ["in"] = true }, name = "hClientGroup" },
        { type = types.long, attributes = { ["in"] = true, unique = true }, name = "pTimeBias" },
        { type = types.float, attributes = { ["in"] = true, unique = true }, name = "pPercentDeadBand" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwLCID" },
        { type = types.dword, attributes = { out = true }, name = "phServerGroup" },
        { type = types.dword, attributes = { out = true }, name = "pRevisedUpdateRate" },
        { type = types.refiid, attributes = { ["in"] = true }, name = "riid" },
        { type = types.interface(IUnknown), attributes = { ["out"] = true, iid_is = "riid" }, name = "ppUnk" },
      }
    },
    {
      name = "RemoveGroup",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "hServerGroup" },
        { type = types.bool, attributes = { ["in"] = true }, name = "bForce" },
      }
    },
    {
      name = "GetStatus",
      parameters = { { type = types.array(OPCSERVERSTATUS), attributes = { out = true, size_is = "1" }, name = "ppServerStatus" } }
    },
    {
      name = "GetErrorString",
      parameters = {
        { type = types.hresult, attributes = { ["in"] = true }, name = "dwError" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwLocale" },
        { type = types.wstring, attributes = { out = true }, name = "ppString" }
      }
    }
  }
}

local IOPCItemProperties = {
  name = "IOPCItemProperties",
  iid = "{39C13A72-011E-11D0-9675-0020AFD8ADB3}",
  parent = IUnknown,
  methods = {
    {
      name = "QueryAvailableProperties",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szItemID" },
        { type = types.dword, attributes = { out = true }, name = "pdwCount" },
        { type = types.array(types.dword), attributes = { out = true, size_is = "pdwCount" },
          name = "ppPropertyIDs" },
        { type = types.array(types.wstring), attributes = { out = true, size_is = "pdwCount" },
          name = "ppDescriptions" },
        { type = types.array(types.enum("VARTYPE")), attributes = { out = true, size_is = "pdwCount" },
          name = "ppvtDataTypes" },
      }
    },
    {
      name = "GetItemProperties",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szItemID" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" },
          name = "pdwPropertyIDs" },
        { type = types.array(types.variant), attributes = { out = true, size_is = "dwCount" }, name = "ppvData" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" }, name = "ppErrors" },
      }
    }
  }
}

local IOPCItemMgt = {
  name = "IOPCItemMgt",
  iid = "{39C13A54-011E-11D0-9675-0020AFD8ADB3}",
  parent = IUnknown,
  methods = {
    {
      name = "AddItems",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(OPCITEMDEF), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pItemArray" },
        { type = types.array(OPCITEMRESULT), attributes = { out = true, size_is = "dwCount" }, name = "ppAddResults" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" }, name = "ppErrors" },
      }
    },
    {
      name = "RemoveItems",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "phServer" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" }, name = "ppErrors" },
      }
    }
  }
}

local IOPCSyncIO = {
  name = "IOPCSyncIO",
  iid = "{39C13A52-011E-11D0-9675-0020AFD8ADB3}",
  parent = IUnknown,
  methods = {
    {
      name = "Read",
      parameters = {
        { type = types.enum("OPCDATASOURCE"), attributes = { ["in"] = true }, name = "dwSource" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "phServer" },
        { type = types.array(OPCITEMSTATE), attributes = { out = true, size_is = "dwCount" }, name = "ppItemValues" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" }, name = "ppErrors" },
      }
    },
    {
      name = "Write",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "phServer" },
        { type = types.array(types.variant), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pItemValues" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" }, name = "ppErrors" },
      }
    }
  }
}

local IOPCItemIO = {
  name = "IOPCItemIO",
  iid = "{85C0B427-2893-4cbc-BD78-E5FC5146F08F}",
  parent = IUnknown,
  methods = {
    {
      name = "Read",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.wstring), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pszItemIDs" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pdwMaxAge" },
        { type = types.array(types.variant), attributes = { out = true, size_is = "dwCount" }, name = "ppvValues" },
        { type = types.array(types.word), attributes = { out = true, size_is = "dwCount" }, name = "ppwQualities" },
        { type = types.array(FILETIME), attributes = { out = true, size_is = "dwCount" }, name = "ppftTimeStamps" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" }, name = "ppErrors" },
      }
    },
    {
      name = "WriteVQT",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.wstring), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pszItemIDs" },
        { type = types.array(OPCITEMVQT), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pItemVQT" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" }, name = "ppErrors" },
      }
    }
  }
}

local IOPCDataCallback = {
  name = "IOPCDataCallback",
  iid = "{39C13A70-011E-11D0-9675-0020AFD8ADB3}",
  parent = IUnknown,
  methods = {
    {
      name = "OnDataChange",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwTransid" },
        { type = types.dword, attributes = { ["in"] = true }, name = "hGroup" },
        { type = types.enum("HRESULT"), attributes = { ["in"] = true }, name = "hrMasterquality" },
        { type = types.enum("HRESULT"), attributes = { ["in"] = true }, name = "hrMastererror" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "phClientItems" },
        { type = types.array(types.variant), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pvValues" },
        { type = types.array(types.word), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pwQualities" },
        { type = types.array(FILETIME), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pftTimeStamps" },
        { type = types.array(types.hresult), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pErrors" },
      }
    },
    {
      name = "OnReadComplete",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwTransid" },
        { type = types.dword, attributes = { ["in"] = true }, name = "hGroup" },
        { type = types.enum("HRESULT"), attributes = { ["in"] = true }, name = "hrMasterquality" },
        { type = types.enum("HRESULT"), attributes = { ["in"] = true }, name = "hrMastererror" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "phClientItems" },
        { type = types.array(types.variant), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pvValues" },
        { type = types.array(types.word), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pwQualities" },
        { type = types.array(FILETIME), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pftTimeStamps" },
        { type = types.array(types.hresult), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pErrors" },
      }
    },
    {
      name = "OnWriteComplete",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwTransid" },
        { type = types.dword, attributes = { ["in"] = true }, name = "hGroup" },
        { type = types.enum("HRESULT"), attributes = { ["in"] = true }, name = "hrMastererror" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "phClienthandles" },
        { type = types.array(types.hresult), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pErrors" },
      }
    },
    {
      name = "OnCancelComplete",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwTransid" },
        { type = types.dword, attributes = { ["in"] = true }, name = "hGroup" },
      }
    }
  }
}

local IOPCSecurityPrivate = {
  name = "IOPCSecurityPrivate",
  iid = "{7AA83A02-6C77-11D3-84F9-00008630A38B}",
  parent = IUnknown,
  methods = {
    {
      name = "IsAvailablePriv",
      parameters = {
        { type = types.bool, attributes = { out = true }, name = "pbAvailable" }
      }
    },
    {
      name = "Logon",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true }, name = "szUserID" },
        { type = types.wstring, attributes = { ["in"] = true }, name = "szPassword" }
      }
    },
    {
      name = "Logoff",
      parameters = {}
    }
  }
}

local OPCEVENTSERVERSTATE = {
  name = "OPCEVENTSERVERSTATE",
  fields = {
    { name = "OPCAE_STATUS_RUNNING", value = 1 },
    { name = "OPCAE_STATUS_FAILED", value = 2 },
    { name = "OPCAE_STATUS_NOCONFIG", value = 3 },
    { name = "OPCAE_STATUS_SUSPENDED", value = 4 },
    { name = "OPCAE_STATUS_TEST", value = 5 },
    { name = "OPCAE_STATUS_COMM_FAULT", value = 6 },
  }
}

local OPCEVENTSERVERSTATUS = types.struct("OPCEVENTSERVERSTATUS", {
  { type = FILETIME, name = "ftStartTime" },
  { type = FILETIME, name = "ftCurrentTime" },
  { type = FILETIME, name = "ftLastUpdateTime" },
  { type = types.enum("OPCEVENTSERVERSTATE"), name = "dwServerState" },
  { type = types.word, name = "wMajorVersion" },
  { type = types.word, name = "wMinorVersion" },
  { type = types.word, name = "wBuildNumber" },
  { type = types.wstring, name = "szVendorInfo" }
})

local ONEVENTSTRUCT = types.struct("ONEVENTSTRUCT", {
  { type = types.word, name = "wChangeMask" },
  { type = types.word, name = "wNewState" },
  { type = types.wstring, name = "szSource" },
  { type = FILETIME, name = "ftTime" },
  { type = types.wstring, name = "szMessage" },
  { type = types.dword, name = "dwEventType" },
  { type = types.dword, name = "dwEventCategory" },
  { type = types.dword, name = "dwSeverity" },
  { type = types.wstring, name = "szConditionName" },
  { type = types.wstring, name = "szSubconditionName" },
  { type = types.word, name = "wQuality" },
  { type = types.word, name = "wReserved" },
  { type = types.bool, name = "bAckRequired" },
  { type = FILETIME, name = "ftActiveTime" },
  { type = types.dword, name = "dwCookie" },
  { type = types.dword, name = "dwNumEventAttrs" },
  { type = types.array(types.variant, { size_is = "dwNumEventAttrs" }),
    name = "pEventAttributes" },
  { type = types.wstring, name = "szActorID" },
})

local OPCCONDITIONSTATE = types.struct("OPCCONDITIONSTATE", {
  { type = types.word, name = "wState" },
  { type = types.word, name = "wReserved1" },
  { type = types.wstring, name = "szActiveSubCondition" },
  { type = types.wstring, name = "szASCDefinition" },
  { type = types.dword, name = "dwASCSeverity" },
  { type = types.wstring, name = "szASCDescription" },
  { type = types.word, name = "wQuality" },
  { type = types.word, name = "wReserved2" },
  { type = FILETIME, name = "ftLastAckTime" },
  { type = FILETIME, name = "ftSubCondLastActive" },
  { type = FILETIME, name = "ftCondLastActive" },
  { type = FILETIME, name = "ftCondLastInactive" },
  { type = types.wstring, name = "szAcknowledgerID" },
  { type = types.wstring, name = "szComment" },
  { type = types.dword, name = "dwNumSCs" },
  { type = types.array(types.wstring, { size_is = "dwNumSCs" }),
    name = "pszSCNames" },
  { type = types.array(types.wstring, { size_is = "dwNumSCs" }),
    name = "pszSCDefinitions" },
  { type = types.array(types.dword, { size_is = "dwNumSCs" }),
    name = "pdwSCSeverities" },
  { type = types.array(types.wstring, { size_is = "dwNumSCs" }),
    name = "pszSCDescriptions" },
  { type = types.dword, name = "dwNumEventAttrs" },
  { type = types.array(types.variant, { size_is = "dwNumEventAttrs" }),
    name = "pEventAttributes" },
  { type = types.array(types.hresult, { size_is = "dwNumEventAttrs" }),
    name = "pErrors" },
})

local IOPCEventServer = {
  name = "IOPCEventServer",
  iid = "{65168851-5783-11d1-84A0-00608CB8A7E9}",
  parent = IUnknown,
  methods = {
    {
      name = "GetStatus",
      parameters = {
        { type = types.array(OPCEVENTSERVERSTATUS), attributes = { out = true, size_is = "1" }, name = "ppEventServerStatus" }
      }
    },
    {
      name  = "CreateEventSubscription",
      parameters = {
        { type = types.bool, attributes = { ["in"] = true }, name = "bActive" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwBufferTime" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwMaxSize" },
        { type = types.dword, attributes = { ["in"] = true }, name = "hClientSubscription" },
        { type = types.refiid, attributes = { ["in"] = true }, name = "riid" },
        { type = types.interface(IUnknown), attributes = { ["out"] = true, iid_is = "riid" }, name = "ppUnk" },
        { type = types.dword, attributes = { out = true }, name = "pdwRevisedBufferTime" },
        { type = types.dword, attributes = { out = true }, name = "pdwRevisedMaxTime" },
      }
    },
    {
      name = "QueryAvailableFilters",
      parameters = {
        { type = types.dword, attributes = { out = true }, name = "pdwFilterMask" }
      }
    },
    {
      name = "QueryEventCategories",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwEventType" },
        { type = types.dword, attributes = { out = true }, name = "pdwCount" },
            { type = types.array(types.dword), attributes = { out = true, size_is = "pdwCount" }, name = "ppdwEventCategories" },
            { type = types.array(types.wstring), attributes = { out = true, size_is = "pdwCount" }, name = "ppEventCategoryDescs" },
      }
    },
    {
      name = "QueryConditionNames",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwEventCategory" },
        { type = types.dword, attributes = { out = true }, name = "pdwCount" },
            { type = types.array(types.wstring), attributes = { out = true, size_is = "pdwCount" }, name = "ppszConditionNames" },
      }
    },
    {
      name = "QuerySubConditionNames",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szConditionName" },
        { type = types.dword, attributes = { out = true }, name = "pdwCount" },
            { type = types.array(types.wstring), attributes = { out = true, size_is = "pdwCount" }, name = "ppszSubConditionNames" },
      }
    },
    {
      name = "QuerySourceConditions",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szSource" },
        { type = types.dword, attributes = { out = true }, name = "pdwCount" },
            { type = types.array(types.wstring), attributes = { out = true, size_is = "pdwCount" }, name = "ppszConditionNames" },
      }
    },
    {
      name = "QueryEventAttributes",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwEventCategory" },
        { type = types.dword, attributes = { out = true }, name = "pdwCount" },
            { type = types.array(types.dword), attributes = { out = true, size_is = "pdwCount" }, name = "ppdwAttrIDs" },
            { type = types.array(types.wstring), attributes = { out = true, size_is = "pdwCount" }, name = "ppszAttrDescs" },
            { type = types.array(types.enum("VARTYPE")), attributes = { out = true, size_is = "pdwCount" }, name = "ppvtAttrTypes" },
      }
    },
    {
      name = "TranslateToItemIDs",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szSource" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwEventCategory" },
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szConditionName" },
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szSubconditionName" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
            { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pdwAssocAttrIDs" },
            { type = types.array(types.wstring), attributes = { out = true, size_is = "dwCount" }, name = "ppszAttrDescs" },
            { type = types.array(types.wstring), attributes = { out = true, size_is = "dwCount" }, name = "ppszNodeNames" },
        { type = types.array(types.refiid), attributes = { out = true, size_is = "dwCount" } , name = "ppCLSIDs" },
      }
    },
    {
      name = "GetConditionState",
      parameters = {
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szSource" },
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szConditionName" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwNumEventAttrs" },
            { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwNumEventAttrs" }, name = "pdwAttributeIDs" },
        { type = types.array(OPCCONDITIONSTATE), attributes = { out = true, size_is = "1" }, name = "ppConditionState" },
      }
    },
    {
      name = "AckCondition",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szAcknowledgerID" },
        { type = types.wstring, attributes = { ["in"] = true, ctype = "LPWSTR" }, name = "szComment" },
            { type = types.array(types.wstring), attributes = { ["in"] = true, size_is = "dwCount", ctype = "LPWSTR" }, name = "pszSource" },
            { type = types.array(types.wstring), attributes = { ["in"] = true, size_is = "dwCount", ctype = "LPWSTR" }, name = "pszConditionName" },
            { type = types.array(FILETIME), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pftActiveTime" },
            { type = types.array(types.dword), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pdwCookie" },
        { type = types.array(types.hresult), attributes = { out = true, size_is = "dwCount" } , name = "pErrors" },
      }
    },
    {
      name = "EnableConditionBySource",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwNumSources" },
            { type = types.array(types.wstring), attributes = { ["in"] = true, size_is = "dwNumSources", ctype = "LPWSTR" }, name = "pszSources" },
      }
    },
    {
      name = "DisableConditionBySource",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "dwNumSources" },
            { type = types.array(types.wstring), attributes = { ["in"] = true, size_is = "dwNumSources", ctype = "LPWSTR" }, name = "pszSources" },
      }
    },
  }
}

local IOPCEventSink = {
  name = "IOPCEventSink",
  iid = "{6516885F-5783-11d1-84A0-00608CB8A7E9}",
  parent = IUnknown,
  methods = {
    {
      name = "OnEvent",
      parameters = {
        { type = types.dword, attributes = { ["in"] = true }, name = "hClientSubscription" },
        { type = types.bool, attributes = { ["in"] = true }, name = "bRefresh" },
        { type = types.bool, attributes = { ["in"] = true }, name = "bLastRefresh" },
        { type = types.dword, attributes = { ["in"] = true }, name = "dwCount" },
            { type = types.array(ONEVENTSTRUCT), attributes = { ["in"] = true, size_is = "dwCount" }, name = "pEvents" },
      }
    }
  }
}

local opcda = {
  modname = "opclib",
  header = "opcda",
  interfaces = { IOPCServer, IOPCSyncIO, IOPCItemMgt, IOPCItemIO, IOPCDataCallback, IOPCItemProperties },
  wrappers = { DataCallback = { IOPCDataCallback } },
  enums = { OPCDATASOURCE, HRESULT, types.vartype }
}

local opcae = {
  modname = "opcae",
  header = "opc_ae",
  interfaces = { IOPCEventServer, IOPCEventSink },
  wrappers = { EventSink = { IOPCEventSink } },
  enums = { OPCEVENTSERVERSTATE, HRESULT, types.vartype }
}

local opcsec = {
  modname = "opcsec",
  header = "opcsec",
  interfaces = { IOPCSecurityPrivate },
  wrappers = {},
  enums = { HRESULT }
}

local source, def, wrap = generator.compile(opcda)

generator.writefile("opclib.cpp", source)
generator.writefile("opclib.def", def)
generator.writefile("opclib_w.cpp", wrap)

local source, def, wrap = generator.compile(opcae)

generator.writefile("opcae.cpp", source)
generator.writefile("opcae.def", def)
generator.writefile("opcae_w.cpp", wrap)

local source, def, wrap = generator.compile(opcsec)

generator.writefile("opcsec.cpp", source)
generator.writefile("opcsec.def", def)
