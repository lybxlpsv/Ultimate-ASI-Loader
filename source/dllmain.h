#pragma once
#include <windows.h>
#include <cctype>
#include <string>
#include <shlobj.h>
#include <stdio.h>
#include <filesystem>
#include <functional>
#include <set>
#include <ModuleList\ModuleList.hpp>
#include <intrin.h>
#pragma intrinsic(_ReturnAddress)

struct shared
{
    FARPROC DllCanUnloadNow;
    FARPROC DllGetClassObject;
    FARPROC DllRegisterServer;
    FARPROC DllUnregisterServer;
    FARPROC DebugSetMute;

    void LoadOriginalLibrary(HMODULE dll)
    {
        DllCanUnloadNow = GetProcAddress(dll, "DllCanUnloadNow");
        DllGetClassObject = GetProcAddress(dll, "DllGetClassObject");
        DllRegisterServer = GetProcAddress(dll, "DllRegisterServer");
        DllUnregisterServer = GetProcAddress(dll, "DllUnregisterServer");
        DebugSetMute = GetProcAddress(dll, "DebugSetMute");
    }
} shared;

struct dnsapi_dll
{
	HMODULE dll;

	// generated using windows 7 dnsapi.dll
	// functions not in vista are commented out manually
	// needed windows 8+ have been manually added so they can be stubbed
	FARPROC BreakRecordsIntoBlob;
	FARPROC CombineRecordsInBlob;
	FARPROC DnsAcquireContextHandle_A;
	FARPROC DnsAcquireContextHandle_W;
	FARPROC DnsAllocateRecord;
	FARPROC DnsApiAlloc;
	FARPROC DnsApiAllocZero;
	FARPROC DnsApiFree;
	FARPROC DnsApiHeapReset;
	FARPROC DnsApiRealloc;
	FARPROC DnsApiSetDebugGlobals;
	FARPROC DnsAsyncRegisterHostAddrs;
	FARPROC DnsAsyncRegisterInit;
	FARPROC DnsAsyncRegisterTerm;
	FARPROC DnsCancelQuery;
	FARPROC DnsCopyStringEx;
	FARPROC DnsCreateReverseNameStringForIpAddress;
	FARPROC DnsCreateStandardDnsNameCopy;
	FARPROC DnsCreateStringCopy;
	FARPROC DnsDhcpRegisterAddrs;
	FARPROC DnsDhcpRegisterHostAddrs;
	FARPROC DnsDhcpRegisterInit;
	FARPROC DnsDhcpRegisterTerm;
	FARPROC DnsDhcpRemoveRegistrations;
	FARPROC DnsDhcpSrvRegisterHostAddr;
	//FARPROC DnsDhcpSrvRegisterHostAddrEx;
	FARPROC DnsDhcpSrvRegisterHostName;
	//FARPROC DnsDhcpSrvRegisterHostNameEx;
	FARPROC DnsDhcpSrvRegisterInit;
	FARPROC DnsDhcpSrvRegisterInitialize;
	FARPROC DnsDhcpSrvRegisterTerm;
	FARPROC DnsDowncaseDnsNameLabel;
	FARPROC DnsExtractRecordsFromMessage_UTF8;
	FARPROC DnsExtractRecordsFromMessage_W;
	FARPROC DnsFindAuthoritativeZone;
	FARPROC DnsFlushResolverCache;
	FARPROC DnsFlushResolverCacheEntry_A;
	FARPROC DnsFlushResolverCacheEntry_UTF8;
	FARPROC DnsFlushResolverCacheEntry_W;
	FARPROC DnsFree;
	FARPROC DnsFreeConfigStructure;
	//FARPROC DnsFreePolicyConfig;
	//FARPROC DnsFreeProxyName;
	FARPROC DnsGetBufferLengthForStringCopy;
	FARPROC DnsGetCacheDataTable;
	FARPROC DnsGetDnsServerList;
	FARPROC DnsGetDomainName;
	FARPROC DnsGetLastFailedUpdateInfo;
	//FARPROC DnsGetPolicyTableInfo;
	//FARPROC DnsGetPolicyTableInfoPrivate;
	FARPROC DnsGetPrimaryDomainName_A;
	//FARPROC DnsGetProxyInfoPrivate;
	//FARPROC DnsGetProxyInformation;
	FARPROC DnsGlobals;
	FARPROC DnsIpv6AddressToString;
	FARPROC DnsIpv6StringToAddress;
	FARPROC DnsIsAMailboxType;
	FARPROC DnsIsStatusRcode;
	FARPROC DnsIsStringCountValidForTextType;
	FARPROC DnsLogEvent;
	FARPROC DnsLogIn;
	FARPROC DnsLogInit;
	FARPROC DnsLogIt;
	FARPROC DnsLogOut;
	FARPROC DnsLogTime;
	FARPROC DnsMapRcodeToStatus;
	FARPROC DnsModifyRecordsInSet_A;
	FARPROC DnsModifyRecordsInSet_UTF8;
	FARPROC DnsModifyRecordsInSet_W;
	FARPROC DnsNameCompareEx_A;
	FARPROC DnsNameCompareEx_UTF8;
	FARPROC DnsNameCompareEx_W;
	FARPROC DnsNameCompare_A;
	FARPROC DnsNameCompare_UTF8;
	FARPROC DnsNameCompare_W;
	FARPROC DnsNameCopy;
	FARPROC DnsNameCopyAllocate;
	FARPROC DnsNetworkInfo_CreateFromFAZ;
	FARPROC DnsNetworkInformation_CreateFromFAZ;
	FARPROC DnsNotifyResolver;
	FARPROC DnsNotifyResolverClusterIp;
	FARPROC DnsNotifyResolverEx;
	FARPROC DnsQueryConfig;
	FARPROC DnsQueryConfigAllocEx;
	FARPROC DnsQueryConfigDword;
	FARPROC DnsQueryEx;
	FARPROC DnsQueryExA;
	FARPROC DnsQueryExUTF8;
	FARPROC DnsQueryExW;
	FARPROC DnsQuery_A;
	FARPROC DnsQuery_UTF8;
	FARPROC DnsQuery_W;
	FARPROC DnsRecordBuild_UTF8;
	FARPROC DnsRecordBuild_W;
	FARPROC DnsRecordCompare;
	FARPROC DnsRecordCopyEx;
	FARPROC DnsRecordListFree;
	FARPROC DnsRecordSetCompare;
	FARPROC DnsRecordSetCopyEx;
	FARPROC DnsRecordSetDetach;
	FARPROC DnsRecordStringForType;
	FARPROC DnsRecordStringForWritableType;
	FARPROC DnsRecordTypeForName;
	FARPROC DnsRegisterClusterAddress;
	FARPROC DnsReleaseContextHandle;
	FARPROC DnsRemoveRegistrations;
	FARPROC DnsReplaceRecordSetA;
	FARPROC DnsReplaceRecordSetUTF8;
	FARPROC DnsReplaceRecordSetW;
	FARPROC DnsResolverOp;
	FARPROC DnsScreenLocalAddrsForRegistration;
	FARPROC DnsSetConfigDword;
	FARPROC DnsStatusString;
	FARPROC DnsStringCopyAllocateEx;
	//FARPROC DnsTraceServerConfig;
	FARPROC DnsUnicodeToUtf8;
	FARPROC DnsUpdate;
	//FARPROC DnsUpdateMachinePresence;
	FARPROC DnsUpdateTest_A;
	FARPROC DnsUpdateTest_UTF8;
	FARPROC DnsUpdateTest_W;
	FARPROC DnsUtf8ToUnicode;
	FARPROC DnsValidateNameOrIp_TempW;
	FARPROC DnsValidateName_A;
	FARPROC DnsValidateName_UTF8;
	FARPROC DnsValidateName_W;
	//FARPROC DnsValidateServerArray_A; // available in vista sp2
	//FARPROC DnsValidateServerArray_W; // available in vista sp2
	//FARPROC DnsValidateServerStatus;
	//FARPROC DnsValidateServer_A; // available in vista sp2
	//FARPROC DnsValidateServer_W; // available in vista sp2
	FARPROC DnsValidateUtf8Byte;
	FARPROC DnsWriteQuestionToBuffer_UTF8;
	FARPROC DnsWriteQuestionToBuffer_W;
	FARPROC DnsWriteReverseNameStringForIpAddress;
	FARPROC Dns_AddRecordsToMessage;
	FARPROC Dns_AllocateMsgBuf;
	FARPROC Dns_BuildPacket;
	FARPROC Dns_CleanupWinsock;
	FARPROC Dns_CloseConnection;
	FARPROC Dns_CloseSocket;
	FARPROC Dns_CreateMulticastSocket;
	FARPROC Dns_CreateSocket;
	FARPROC Dns_CreateSocketEx;
	FARPROC Dns_ExtractRecordsFromMessage;
	FARPROC Dns_FindAuthoritativeZoneLib;
	FARPROC Dns_FreeMsgBuf;
	FARPROC Dns_GetRandomXid;
	FARPROC Dns_InitializeMsgBuf;
	FARPROC Dns_InitializeMsgRemoteSockaddr;
	FARPROC Dns_InitializeWinsock;
	FARPROC Dns_OpenTcpConnectionAndSend;
	FARPROC Dns_ParseMessage;
	FARPROC Dns_ParsePacketRecord;
	FARPROC Dns_PingAdapterServers;
	FARPROC Dns_ReadPacketName;
	FARPROC Dns_ReadPacketNameAllocate;
	FARPROC Dns_ReadRecordStructureFromPacket;
	FARPROC Dns_RecvTcp;
	FARPROC Dns_ResetNetworkInfo;
	FARPROC Dns_SendAndRecvUdp;
	FARPROC Dns_SendEx;
	FARPROC Dns_SetRecordDatalength;
	FARPROC Dns_SetRecordsSection;
	FARPROC Dns_SetRecordsTtl;
	FARPROC Dns_SkipPacketName;
	FARPROC Dns_SkipToRecord;
	FARPROC Dns_UpdateLib;
	FARPROC Dns_UpdateLibEx;
	FARPROC Dns_WriteDottedNameToPacket;
	FARPROC Dns_WriteQuestionToMessage;
	FARPROC Dns_WriteRecordStructureToPacketEx;
	FARPROC ExtraInfo_Init;
	FARPROC Faz_AreServerListsInSameNameSpace;
	//FARPROC FlushDnsPolicyUnreachableStatus;
	FARPROC GetCurrentTimeInSeconds;
	FARPROC HostsFile_Close;
	FARPROC HostsFile_Open;
	FARPROC HostsFile_ReadLine;
	FARPROC IpHelp_IsAddrOnLink;
	FARPROC Local_GetRecordsForLocalName;
	FARPROC Local_GetRecordsForLocalNameEx;
	FARPROC NetInfo_Build;
	FARPROC NetInfo_Clean;
	FARPROC NetInfo_Copy;
	FARPROC NetInfo_Free;
	FARPROC NetInfo_GetAdapterByAddress;
	FARPROC NetInfo_GetAdapterByInterfaceIndex;
	FARPROC NetInfo_GetAdapterByName;
	FARPROC NetInfo_IsAddrConfig;
	FARPROC NetInfo_IsForUpdate;
	FARPROC NetInfo_ResetServerPriorities;
	//FARPROC NetInfo_UpdateServerReachability;
	FARPROC QueryDirectEx;
	FARPROC Query_Main;
	FARPROC Reg_FreeUpdateInfo;
	FARPROC Reg_GetValueEx;
	FARPROC Reg_ReadGlobalsEx;
	FARPROC Reg_ReadUpdateInfo;
	FARPROC Security_ContextListTimeout;
	FARPROC Send_AndRecvUdpWithParam;
	FARPROC Send_MessagePrivate;
	FARPROC Send_OpenTcpConnectionAndSend;
	FARPROC Socket_CacheCleanup;
	FARPROC Socket_CacheInit;
	FARPROC Socket_CleanupWinsock;
	FARPROC Socket_ClearMessageSockets;
	FARPROC Socket_CloseEx;
	FARPROC Socket_CloseMessageSockets;
	FARPROC Socket_Create;
	FARPROC Socket_CreateMulticast;
	FARPROC Socket_InitWinsock;
	FARPROC Socket_JoinMulticast;
	FARPROC Socket_RecvFrom;
	FARPROC Socket_SetMulticastInterface;
	FARPROC Socket_SetMulticastLoopBack;
	FARPROC Socket_SetTtl;
	FARPROC Socket_TcpListen;
	//FARPROC Trace_Reset;
	FARPROC Update_ReplaceAddressRecordsW;
	FARPROC Util_IsIp6Running;


	// DnsQueryEx and DnsCancelQuery are only present on win 8+ so they need stubs for older versions
	// they both take pointers to structs as parameters
	// (three for DnsQueryEx and one for DnsCancelQuery)
	// fortunately they should fit in registers so the stack doesn't matter
	static LONG WINAPI DnsQueryExStub()
	{
		return 9004; // DNS_ERROR_RCODE_NOT_IMPLEMENTED
	}
	static LONG WINAPI DnsCancelQueryStub()
	{
		return 9004; // DNS_ERROR_RCODE_NOT_IMPLEMENTED
	}

	void LoadOriginalLibrary(HMODULE module)
	{
		dll = module;
		shared.LoadOriginalLibrary(dll);

		BreakRecordsIntoBlob = GetProcAddress(dll, "BreakRecordsIntoBlob");
		CombineRecordsInBlob = GetProcAddress(dll, "CombineRecordsInBlob");
		DnsAcquireContextHandle_A = GetProcAddress(dll, "DnsAcquireContextHandle_A");
		DnsAcquireContextHandle_W = GetProcAddress(dll, "DnsAcquireContextHandle_W");
		DnsAllocateRecord = GetProcAddress(dll, "DnsAllocateRecord");
		DnsApiAlloc = GetProcAddress(dll, "DnsApiAlloc");
		DnsApiAllocZero = GetProcAddress(dll, "DnsApiAllocZero");
		DnsApiFree = GetProcAddress(dll, "DnsApiFree");
		DnsApiHeapReset = GetProcAddress(dll, "DnsApiHeapReset");
		DnsApiRealloc = GetProcAddress(dll, "DnsApiRealloc");
		DnsApiSetDebugGlobals = GetProcAddress(dll, "DnsApiSetDebugGlobals");
		DnsAsyncRegisterHostAddrs = GetProcAddress(dll, "DnsAsyncRegisterHostAddrs");
		DnsAsyncRegisterInit = GetProcAddress(dll, "DnsAsyncRegisterInit");
		DnsAsyncRegisterTerm = GetProcAddress(dll, "DnsAsyncRegisterTerm");
		DnsCancelQuery = GetProcAddress(dll, "DnsCancelQuery");
		DnsCopyStringEx = GetProcAddress(dll, "DnsCopyStringEx");
		DnsCreateReverseNameStringForIpAddress = GetProcAddress(dll, "DnsCreateReverseNameStringForIpAddress");
		DnsCreateStandardDnsNameCopy = GetProcAddress(dll, "DnsCreateStandardDnsNameCopy");
		DnsCreateStringCopy = GetProcAddress(dll, "DnsCreateStringCopy");
		DnsDhcpRegisterAddrs = GetProcAddress(dll, "DnsDhcpRegisterAddrs");
		DnsDhcpRegisterHostAddrs = GetProcAddress(dll, "DnsDhcpRegisterHostAddrs");
		DnsDhcpRegisterInit = GetProcAddress(dll, "DnsDhcpRegisterInit");
		DnsDhcpRegisterTerm = GetProcAddress(dll, "DnsDhcpRegisterTerm");
		DnsDhcpRemoveRegistrations = GetProcAddress(dll, "DnsDhcpRemoveRegistrations");
		DnsDhcpSrvRegisterHostAddr = GetProcAddress(dll, "DnsDhcpSrvRegisterHostAddr");
		//DnsDhcpSrvRegisterHostAddrEx = GetProcAddress(dll, "DnsDhcpSrvRegisterHostAddrEx");
		DnsDhcpSrvRegisterHostName = GetProcAddress(dll, "DnsDhcpSrvRegisterHostName");
		//DnsDhcpSrvRegisterHostNameEx = GetProcAddress(dll, "DnsDhcpSrvRegisterHostNameEx");
		DnsDhcpSrvRegisterInit = GetProcAddress(dll, "DnsDhcpSrvRegisterInit");
		DnsDhcpSrvRegisterInitialize = GetProcAddress(dll, "DnsDhcpSrvRegisterInitialize");
		DnsDhcpSrvRegisterTerm = GetProcAddress(dll, "DnsDhcpSrvRegisterTerm");
		DnsDowncaseDnsNameLabel = GetProcAddress(dll, "DnsDowncaseDnsNameLabel");
		DnsExtractRecordsFromMessage_UTF8 = GetProcAddress(dll, "DnsExtractRecordsFromMessage_UTF8");
		DnsExtractRecordsFromMessage_W = GetProcAddress(dll, "DnsExtractRecordsFromMessage_W");
		DnsFindAuthoritativeZone = GetProcAddress(dll, "DnsFindAuthoritativeZone");
		DnsFlushResolverCache = GetProcAddress(dll, "DnsFlushResolverCache");
		DnsFlushResolverCacheEntry_A = GetProcAddress(dll, "DnsFlushResolverCacheEntry_A");
		DnsFlushResolverCacheEntry_UTF8 = GetProcAddress(dll, "DnsFlushResolverCacheEntry_UTF8");
		DnsFlushResolverCacheEntry_W = GetProcAddress(dll, "DnsFlushResolverCacheEntry_W");
		DnsFree = GetProcAddress(dll, "DnsFree");
		DnsFreeConfigStructure = GetProcAddress(dll, "DnsFreeConfigStructure");
		//DnsFreePolicyConfig = GetProcAddress(dll, "DnsFreePolicyConfig");
		//DnsFreeProxyName = GetProcAddress(dll, "DnsFreeProxyName");
		DnsGetBufferLengthForStringCopy = GetProcAddress(dll, "DnsGetBufferLengthForStringCopy");
		DnsGetCacheDataTable = GetProcAddress(dll, "DnsGetCacheDataTable");
		DnsGetDnsServerList = GetProcAddress(dll, "DnsGetDnsServerList");
		DnsGetDomainName = GetProcAddress(dll, "DnsGetDomainName");
		DnsGetLastFailedUpdateInfo = GetProcAddress(dll, "DnsGetLastFailedUpdateInfo");
		//DnsGetPolicyTableInfo = GetProcAddress(dll, "DnsGetPolicyTableInfo");
		//DnsGetPolicyTableInfoPrivate = GetProcAddress(dll, "DnsGetPolicyTableInfoPrivate");
		DnsGetPrimaryDomainName_A = GetProcAddress(dll, "DnsGetPrimaryDomainName_A");
		//DnsGetProxyInfoPrivate = GetProcAddress(dll, "DnsGetProxyInfoPrivate");
		//DnsGetProxyInformation = GetProcAddress(dll, "DnsGetProxyInformation");
		DnsGlobals = GetProcAddress(dll, "DnsGlobals");
		DnsIpv6AddressToString = GetProcAddress(dll, "DnsIpv6AddressToString");
		DnsIpv6StringToAddress = GetProcAddress(dll, "DnsIpv6StringToAddress");
		DnsIsAMailboxType = GetProcAddress(dll, "DnsIsAMailboxType");
		DnsIsStatusRcode = GetProcAddress(dll, "DnsIsStatusRcode");
		DnsIsStringCountValidForTextType = GetProcAddress(dll, "DnsIsStringCountValidForTextType");
		DnsLogEvent = GetProcAddress(dll, "DnsLogEvent");
		DnsLogIn = GetProcAddress(dll, "DnsLogIn");
		DnsLogInit = GetProcAddress(dll, "DnsLogInit");
		DnsLogIt = GetProcAddress(dll, "DnsLogIt");
		DnsLogOut = GetProcAddress(dll, "DnsLogOut");
		DnsLogTime = GetProcAddress(dll, "DnsLogTime");
		DnsMapRcodeToStatus = GetProcAddress(dll, "DnsMapRcodeToStatus");
		DnsModifyRecordsInSet_A = GetProcAddress(dll, "DnsModifyRecordsInSet_A");
		DnsModifyRecordsInSet_UTF8 = GetProcAddress(dll, "DnsModifyRecordsInSet_UTF8");
		DnsModifyRecordsInSet_W = GetProcAddress(dll, "DnsModifyRecordsInSet_W");
		DnsNameCompareEx_A = GetProcAddress(dll, "DnsNameCompareEx_A");
		DnsNameCompareEx_UTF8 = GetProcAddress(dll, "DnsNameCompareEx_UTF8");
		DnsNameCompareEx_W = GetProcAddress(dll, "DnsNameCompareEx_W");
		DnsNameCompare_A = GetProcAddress(dll, "DnsNameCompare_A");
		DnsNameCompare_UTF8 = GetProcAddress(dll, "DnsNameCompare_UTF8");
		DnsNameCompare_W = GetProcAddress(dll, "DnsNameCompare_W");
		DnsNameCopy = GetProcAddress(dll, "DnsNameCopy");
		DnsNameCopyAllocate = GetProcAddress(dll, "DnsNameCopyAllocate");
		DnsNetworkInfo_CreateFromFAZ = GetProcAddress(dll, "DnsNetworkInfo_CreateFromFAZ");
		DnsNetworkInformation_CreateFromFAZ = GetProcAddress(dll, "DnsNetworkInformation_CreateFromFAZ");
		DnsNotifyResolver = GetProcAddress(dll, "DnsNotifyResolver");
		DnsNotifyResolverClusterIp = GetProcAddress(dll, "DnsNotifyResolverClusterIp");
		DnsNotifyResolverEx = GetProcAddress(dll, "DnsNotifyResolverEx");
		DnsQueryConfig = GetProcAddress(dll, "DnsQueryConfig");
		DnsQueryConfigAllocEx = GetProcAddress(dll, "DnsQueryConfigAllocEx");
		DnsQueryConfigDword = GetProcAddress(dll, "DnsQueryConfigDword");
		DnsQueryEx = GetProcAddress(dll, "DnsQueryEx");
		DnsQueryExA = GetProcAddress(dll, "DnsQueryExA");
		DnsQueryExUTF8 = GetProcAddress(dll, "DnsQueryExUTF8");
		DnsQueryExW = GetProcAddress(dll, "DnsQueryExW");
		DnsQuery_A = GetProcAddress(dll, "DnsQuery_A");
		DnsQuery_UTF8 = GetProcAddress(dll, "DnsQuery_UTF8");
		DnsQuery_W = GetProcAddress(dll, "DnsQuery_W");
		DnsRecordBuild_UTF8 = GetProcAddress(dll, "DnsRecordBuild_UTF8");
		DnsRecordBuild_W = GetProcAddress(dll, "DnsRecordBuild_W");
		DnsRecordCompare = GetProcAddress(dll, "DnsRecordCompare");
		DnsRecordCopyEx = GetProcAddress(dll, "DnsRecordCopyEx");
		DnsRecordListFree = GetProcAddress(dll, "DnsRecordListFree");
		DnsRecordSetCompare = GetProcAddress(dll, "DnsRecordSetCompare");
		DnsRecordSetCopyEx = GetProcAddress(dll, "DnsRecordSetCopyEx");
		DnsRecordSetDetach = GetProcAddress(dll, "DnsRecordSetDetach");
		DnsRecordStringForType = GetProcAddress(dll, "DnsRecordStringForType");
		DnsRecordStringForWritableType = GetProcAddress(dll, "DnsRecordStringForWritableType");
		DnsRecordTypeForName = GetProcAddress(dll, "DnsRecordTypeForName");
		DnsRegisterClusterAddress = GetProcAddress(dll, "DnsRegisterClusterAddress");
		DnsReleaseContextHandle = GetProcAddress(dll, "DnsReleaseContextHandle");
		DnsRemoveRegistrations = GetProcAddress(dll, "DnsRemoveRegistrations");
		DnsReplaceRecordSetA = GetProcAddress(dll, "DnsReplaceRecordSetA");
		DnsReplaceRecordSetUTF8 = GetProcAddress(dll, "DnsReplaceRecordSetUTF8");
		DnsReplaceRecordSetW = GetProcAddress(dll, "DnsReplaceRecordSetW");
		DnsResolverOp = GetProcAddress(dll, "DnsResolverOp");
		DnsScreenLocalAddrsForRegistration = GetProcAddress(dll, "DnsScreenLocalAddrsForRegistration");
		DnsSetConfigDword = GetProcAddress(dll, "DnsSetConfigDword");
		DnsStatusString = GetProcAddress(dll, "DnsStatusString");
		DnsStringCopyAllocateEx = GetProcAddress(dll, "DnsStringCopyAllocateEx");
		//DnsTraceServerConfig = GetProcAddress(dll, "DnsTraceServerConfig");
		DnsUnicodeToUtf8 = GetProcAddress(dll, "DnsUnicodeToUtf8");
		DnsUpdate = GetProcAddress(dll, "DnsUpdate");
		//DnsUpdateMachinePresence = GetProcAddress(dll, "DnsUpdateMachinePresence");
		DnsUpdateTest_A = GetProcAddress(dll, "DnsUpdateTest_A");
		DnsUpdateTest_UTF8 = GetProcAddress(dll, "DnsUpdateTest_UTF8");
		DnsUpdateTest_W = GetProcAddress(dll, "DnsUpdateTest_W");
		DnsUtf8ToUnicode = GetProcAddress(dll, "DnsUtf8ToUnicode");
		DnsValidateNameOrIp_TempW = GetProcAddress(dll, "DnsValidateNameOrIp_TempW");
		DnsValidateName_A = GetProcAddress(dll, "DnsValidateName_A");
		DnsValidateName_UTF8 = GetProcAddress(dll, "DnsValidateName_UTF8");
		DnsValidateName_W = GetProcAddress(dll, "DnsValidateName_W");
		//DnsValidateServerArray_A = GetProcAddress(dll, "DnsValidateServerArray_A");
		//DnsValidateServerArray_W = GetProcAddress(dll, "DnsValidateServerArray_W");
		//DnsValidateServerStatus = GetProcAddress(dll, "DnsValidateServerStatus");
		//DnsValidateServer_A = GetProcAddress(dll, "DnsValidateServer_A");
		//DnsValidateServer_W = GetProcAddress(dll, "DnsValidateServer_W");
		DnsValidateUtf8Byte = GetProcAddress(dll, "DnsValidateUtf8Byte");
		DnsWriteQuestionToBuffer_UTF8 = GetProcAddress(dll, "DnsWriteQuestionToBuffer_UTF8");
		DnsWriteQuestionToBuffer_W = GetProcAddress(dll, "DnsWriteQuestionToBuffer_W");
		DnsWriteReverseNameStringForIpAddress = GetProcAddress(dll, "DnsWriteReverseNameStringForIpAddress");
		Dns_AddRecordsToMessage = GetProcAddress(dll, "Dns_AddRecordsToMessage");
		Dns_AllocateMsgBuf = GetProcAddress(dll, "Dns_AllocateMsgBuf");
		Dns_BuildPacket = GetProcAddress(dll, "Dns_BuildPacket");
		Dns_CleanupWinsock = GetProcAddress(dll, "Dns_CleanupWinsock");
		Dns_CloseConnection = GetProcAddress(dll, "Dns_CloseConnection");
		Dns_CloseSocket = GetProcAddress(dll, "Dns_CloseSocket");
		Dns_CreateMulticastSocket = GetProcAddress(dll, "Dns_CreateMulticastSocket");
		Dns_CreateSocket = GetProcAddress(dll, "Dns_CreateSocket");
		Dns_CreateSocketEx = GetProcAddress(dll, "Dns_CreateSocketEx");
		Dns_ExtractRecordsFromMessage = GetProcAddress(dll, "Dns_ExtractRecordsFromMessage");
		Dns_FindAuthoritativeZoneLib = GetProcAddress(dll, "Dns_FindAuthoritativeZoneLib");
		Dns_FreeMsgBuf = GetProcAddress(dll, "Dns_FreeMsgBuf");
		Dns_GetRandomXid = GetProcAddress(dll, "Dns_GetRandomXid");
		Dns_InitializeMsgBuf = GetProcAddress(dll, "Dns_InitializeMsgBuf");
		Dns_InitializeMsgRemoteSockaddr = GetProcAddress(dll, "Dns_InitializeMsgRemoteSockaddr");
		Dns_InitializeWinsock = GetProcAddress(dll, "Dns_InitializeWinsock");
		Dns_OpenTcpConnectionAndSend = GetProcAddress(dll, "Dns_OpenTcpConnectionAndSend");
		Dns_ParseMessage = GetProcAddress(dll, "Dns_ParseMessage");
		Dns_ParsePacketRecord = GetProcAddress(dll, "Dns_ParsePacketRecord");
		Dns_PingAdapterServers = GetProcAddress(dll, "Dns_PingAdapterServers");
		Dns_ReadPacketName = GetProcAddress(dll, "Dns_ReadPacketName");
		Dns_ReadPacketNameAllocate = GetProcAddress(dll, "Dns_ReadPacketNameAllocate");
		Dns_ReadRecordStructureFromPacket = GetProcAddress(dll, "Dns_ReadRecordStructureFromPacket");
		Dns_RecvTcp = GetProcAddress(dll, "Dns_RecvTcp");
		Dns_ResetNetworkInfo = GetProcAddress(dll, "Dns_ResetNetworkInfo");
		Dns_SendAndRecvUdp = GetProcAddress(dll, "Dns_SendAndRecvUdp");
		Dns_SendEx = GetProcAddress(dll, "Dns_SendEx");
		Dns_SetRecordDatalength = GetProcAddress(dll, "Dns_SetRecordDatalength");
		Dns_SetRecordsSection = GetProcAddress(dll, "Dns_SetRecordsSection");
		Dns_SetRecordsTtl = GetProcAddress(dll, "Dns_SetRecordsTtl");
		Dns_SkipPacketName = GetProcAddress(dll, "Dns_SkipPacketName");
		Dns_SkipToRecord = GetProcAddress(dll, "Dns_SkipToRecord");
		Dns_UpdateLib = GetProcAddress(dll, "Dns_UpdateLib");
		Dns_UpdateLibEx = GetProcAddress(dll, "Dns_UpdateLibEx");
		Dns_WriteDottedNameToPacket = GetProcAddress(dll, "Dns_WriteDottedNameToPacket");
		Dns_WriteQuestionToMessage = GetProcAddress(dll, "Dns_WriteQuestionToMessage");
		Dns_WriteRecordStructureToPacketEx = GetProcAddress(dll, "Dns_WriteRecordStructureToPacketEx");
		ExtraInfo_Init = GetProcAddress(dll, "ExtraInfo_Init");
		Faz_AreServerListsInSameNameSpace = GetProcAddress(dll, "Faz_AreServerListsInSameNameSpace");
		//FlushDnsPolicyUnreachableStatus = GetProcAddress(dll, "FlushDnsPolicyUnreachableStatus");
		GetCurrentTimeInSeconds = GetProcAddress(dll, "GetCurrentTimeInSeconds");
		HostsFile_Close = GetProcAddress(dll, "HostsFile_Close");
		HostsFile_Open = GetProcAddress(dll, "HostsFile_Open");
		HostsFile_ReadLine = GetProcAddress(dll, "HostsFile_ReadLine");
		IpHelp_IsAddrOnLink = GetProcAddress(dll, "IpHelp_IsAddrOnLink");
		Local_GetRecordsForLocalName = GetProcAddress(dll, "Local_GetRecordsForLocalName");
		Local_GetRecordsForLocalNameEx = GetProcAddress(dll, "Local_GetRecordsForLocalNameEx");
		NetInfo_Build = GetProcAddress(dll, "NetInfo_Build");
		NetInfo_Clean = GetProcAddress(dll, "NetInfo_Clean");
		NetInfo_Copy = GetProcAddress(dll, "NetInfo_Copy");
		NetInfo_Free = GetProcAddress(dll, "NetInfo_Free");
		NetInfo_GetAdapterByAddress = GetProcAddress(dll, "NetInfo_GetAdapterByAddress");
		NetInfo_GetAdapterByInterfaceIndex = GetProcAddress(dll, "NetInfo_GetAdapterByInterfaceIndex");
		NetInfo_GetAdapterByName = GetProcAddress(dll, "NetInfo_GetAdapterByName");
		NetInfo_IsAddrConfig = GetProcAddress(dll, "NetInfo_IsAddrConfig");
		NetInfo_IsForUpdate = GetProcAddress(dll, "NetInfo_IsForUpdate");
		NetInfo_ResetServerPriorities = GetProcAddress(dll, "NetInfo_ResetServerPriorities");
		//NetInfo_UpdateServerReachability = GetProcAddress(dll, "NetInfo_UpdateServerReachability");
		QueryDirectEx = GetProcAddress(dll, "QueryDirectEx");
		Query_Main = GetProcAddress(dll, "Query_Main");
		Reg_FreeUpdateInfo = GetProcAddress(dll, "Reg_FreeUpdateInfo");
		Reg_GetValueEx = GetProcAddress(dll, "Reg_GetValueEx");
		Reg_ReadGlobalsEx = GetProcAddress(dll, "Reg_ReadGlobalsEx");
		Reg_ReadUpdateInfo = GetProcAddress(dll, "Reg_ReadUpdateInfo");
		Security_ContextListTimeout = GetProcAddress(dll, "Security_ContextListTimeout");
		Send_AndRecvUdpWithParam = GetProcAddress(dll, "Send_AndRecvUdpWithParam");
		Send_MessagePrivate = GetProcAddress(dll, "Send_MessagePrivate");
		Send_OpenTcpConnectionAndSend = GetProcAddress(dll, "Send_OpenTcpConnectionAndSend");
		Socket_CacheCleanup = GetProcAddress(dll, "Socket_CacheCleanup");
		Socket_CacheInit = GetProcAddress(dll, "Socket_CacheInit");
		Socket_CleanupWinsock = GetProcAddress(dll, "Socket_CleanupWinsock");
		Socket_ClearMessageSockets = GetProcAddress(dll, "Socket_ClearMessageSockets");
		Socket_CloseEx = GetProcAddress(dll, "Socket_CloseEx");
		Socket_CloseMessageSockets = GetProcAddress(dll, "Socket_CloseMessageSockets");
		Socket_Create = GetProcAddress(dll, "Socket_Create");
		Socket_CreateMulticast = GetProcAddress(dll, "Socket_CreateMulticast");
		Socket_InitWinsock = GetProcAddress(dll, "Socket_InitWinsock");
		Socket_JoinMulticast = GetProcAddress(dll, "Socket_JoinMulticast");
		Socket_RecvFrom = GetProcAddress(dll, "Socket_RecvFrom");
		Socket_SetMulticastInterface = GetProcAddress(dll, "Socket_SetMulticastInterface");
		Socket_SetMulticastLoopBack = GetProcAddress(dll, "Socket_SetMulticastLoopBack");
		Socket_SetTtl = GetProcAddress(dll, "Socket_SetTtl");
		Socket_TcpListen = GetProcAddress(dll, "Socket_TcpListen");
		//Trace_Reset = GetProcAddress(dll, "Trace_Reset");
		Update_ReplaceAddressRecordsW = GetProcAddress(dll, "Update_ReplaceAddressRecordsW");
		Util_IsIp6Running = GetProcAddress(dll, "Util_IsIp6Running");


		// if entry points aren't found, GetProcAddress should return null
		if (DnsQueryEx == NULL) { DnsQueryEx = (FARPROC)&DnsQueryExStub; };
		if (DnsCancelQuery == NULL) { DnsCancelQuery = (FARPROC)&DnsCancelQueryStub; };
	}
} dnsapi;


#if X64
#include <dsound.h>
#endif
#if !X64
#include <MemoryModule\MemoryModule.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

struct vorbisfile_dll
{
    HMEMORYMODULE dll;
    FARPROC ov_bitrate;
    FARPROC ov_bitrate_instant;
    FARPROC ov_clear;
    FARPROC ov_comment;
    FARPROC ov_crosslap;
    FARPROC ov_fopen;
    FARPROC ov_halfrate;
    FARPROC ov_halfrate_p;
    FARPROC ov_info;
    FARPROC ov_open;
    FARPROC ov_open_callbacks;
    FARPROC ov_pcm_seek;
    FARPROC ov_pcm_seek_lap;
    FARPROC ov_pcm_seek_page;
    FARPROC ov_pcm_seek_page_lap;
    FARPROC ov_pcm_tell;
    FARPROC ov_pcm_total;
    FARPROC ov_raw_seek;
    FARPROC ov_raw_seek_lap;
    FARPROC ov_raw_tell;
    FARPROC ov_raw_total;
    FARPROC ov_read;
    FARPROC ov_read_float;
    FARPROC ov_seekable;
    FARPROC ov_serialnumber;
    FARPROC ov_streams;
    FARPROC ov_test;
    FARPROC ov_test_callbacks;
    FARPROC ov_test_open;
    FARPROC ov_time_seek;
    FARPROC ov_time_seek_lap;
    FARPROC ov_time_seek_page;
    FARPROC ov_time_seek_page_lap;
    FARPROC ov_time_tell;
    FARPROC ov_time_total;

    void LoadOriginalLibrary(HMEMORYMODULE module, bool bIsMemory)
    {
        dll = module;

        auto AutoGetProcAddress = [&bIsMemory](HMEMORYMODULE lib, LPCSTR s) -> FARPROC
        {
            if (bIsMemory)
                return MemoryGetProcAddress(lib, s);
            else
                return GetProcAddress((HMODULE)lib, s);
        };

        ov_bitrate = AutoGetProcAddress(dll, "ov_bitrate");
        ov_bitrate_instant = AutoGetProcAddress(dll, "ov_bitrate_instant");
        ov_clear = AutoGetProcAddress(dll, "ov_clear");
        ov_comment = AutoGetProcAddress(dll, "ov_comment");
        ov_crosslap = AutoGetProcAddress(dll, "ov_crosslap");
        ov_fopen = AutoGetProcAddress(dll, "ov_fopen");
        ov_halfrate = AutoGetProcAddress(dll, "ov_halfrate");
        ov_halfrate_p = AutoGetProcAddress(dll, "ov_halfrate_p");
        ov_info = AutoGetProcAddress(dll, "ov_info");
        ov_open = AutoGetProcAddress(dll, "ov_open");
        ov_open_callbacks = AutoGetProcAddress(dll, "ov_open_callbacks");
        ov_pcm_seek = AutoGetProcAddress(dll, "ov_pcm_seek");
        ov_pcm_seek_lap = AutoGetProcAddress(dll, "ov_pcm_seek_lap");
        ov_pcm_seek_page = AutoGetProcAddress(dll, "ov_pcm_seek_page");
        ov_pcm_seek_page_lap = AutoGetProcAddress(dll, "ov_pcm_seek_page_lap");
        ov_pcm_tell = AutoGetProcAddress(dll, "ov_pcm_tell");
        ov_pcm_total = AutoGetProcAddress(dll, "ov_pcm_total");
        ov_raw_seek = AutoGetProcAddress(dll, "ov_raw_seek");
        ov_raw_seek_lap = AutoGetProcAddress(dll, "ov_raw_seek_lap");
        ov_raw_tell = AutoGetProcAddress(dll, "ov_raw_tell");
        ov_raw_total = AutoGetProcAddress(dll, "ov_raw_total");
        ov_read = AutoGetProcAddress(dll, "ov_read");
        ov_read_float = AutoGetProcAddress(dll, "ov_read_float");
        ov_seekable = AutoGetProcAddress(dll, "ov_seekable");
        ov_serialnumber = AutoGetProcAddress(dll, "ov_serialnumber");
        ov_streams = AutoGetProcAddress(dll, "ov_streams");
        ov_test = AutoGetProcAddress(dll, "ov_test");
        ov_test_callbacks = AutoGetProcAddress(dll, "ov_test_callbacks");
        ov_test_open = AutoGetProcAddress(dll, "ov_test_open");
        ov_time_seek = AutoGetProcAddress(dll, "ov_time_seek");
        ov_time_seek_lap = AutoGetProcAddress(dll, "ov_time_seek_lap");
        ov_time_seek_page = AutoGetProcAddress(dll, "ov_time_seek_page");
        ov_time_seek_page_lap = AutoGetProcAddress(dll, "ov_time_seek_page_lap");
        ov_time_tell = AutoGetProcAddress(dll, "ov_time_tell");
        ov_time_total = AutoGetProcAddress(dll, "ov_time_total");
    }
} vorbisfile;
#endif

struct dinput8_dll
{
    HMODULE dll;
    FARPROC DirectInput8Create;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        DirectInput8Create = GetProcAddress(dll, "DirectInput8Create");
    }
} dinput8;

struct dsound_dll
{
    HMODULE dll;
    FARPROC DirectSoundCaptureCreate;
    FARPROC DirectSoundCaptureCreate8;
    FARPROC DirectSoundCaptureEnumerateA;
    FARPROC DirectSoundCaptureEnumerateW;
    FARPROC DirectSoundCreate;
    FARPROC DirectSoundCreate8;
    FARPROC DirectSoundEnumerateA;
    FARPROC DirectSoundEnumerateW;
    FARPROC DirectSoundFullDuplexCreate;
    FARPROC GetDeviceID;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        DirectSoundCaptureCreate = GetProcAddress(dll, "DirectSoundCaptureCreate");
        DirectSoundCaptureCreate8 = GetProcAddress(dll, "DirectSoundCaptureCreate8");
        DirectSoundCaptureEnumerateA = GetProcAddress(dll, "DirectSoundCaptureEnumerateA");
        DirectSoundCaptureEnumerateW = GetProcAddress(dll, "DirectSoundCaptureEnumerateW");
        DirectSoundCreate = GetProcAddress(dll, "DirectSoundCreate");
        DirectSoundCreate8 = GetProcAddress(dll, "DirectSoundCreate8");
        DirectSoundEnumerateA = GetProcAddress(dll, "DirectSoundEnumerateA");
        DirectSoundEnumerateW = GetProcAddress(dll, "DirectSoundEnumerateW");
        DirectSoundFullDuplexCreate = GetProcAddress(dll, "DirectSoundFullDuplexCreate");
        GetDeviceID = GetProcAddress(dll, "GetDeviceID");
    }
} dsound;

struct wininet_dll
{
    HMODULE dll;
    FARPROC AppCacheCheckManifest;
    FARPROC AppCacheCloseHandle;
    FARPROC AppCacheCreateAndCommitFile;
    FARPROC AppCacheDeleteGroup;
    FARPROC AppCacheDeleteIEGroup;
    FARPROC AppCacheDuplicateHandle;
    FARPROC AppCacheFinalize;
    FARPROC AppCacheFreeDownloadList;
    FARPROC AppCacheFreeGroupList;
    FARPROC AppCacheFreeIESpace;
    FARPROC AppCacheFreeSpace;
    FARPROC AppCacheGetDownloadList;
    FARPROC AppCacheGetFallbackUrl;
    FARPROC AppCacheGetGroupList;
    FARPROC AppCacheGetIEGroupList;
    FARPROC AppCacheGetInfo;
    FARPROC AppCacheGetManifestUrl;
    FARPROC AppCacheLookup;
    FARPROC CommitUrlCacheEntryA;
    FARPROC CommitUrlCacheEntryBinaryBlob;
    FARPROC CommitUrlCacheEntryW;
    FARPROC CreateMD5SSOHash;
    FARPROC CreateUrlCacheContainerA;
    FARPROC CreateUrlCacheContainerW;
    FARPROC CreateUrlCacheEntryA;
    FARPROC CreateUrlCacheEntryExW;
    FARPROC CreateUrlCacheEntryW;
    FARPROC CreateUrlCacheGroup;
    FARPROC DeleteIE3Cache;
    FARPROC DeleteUrlCacheContainerA;
    FARPROC DeleteUrlCacheContainerW;
    FARPROC DeleteUrlCacheEntry;
    FARPROC DeleteUrlCacheEntryA;
    FARPROC DeleteUrlCacheEntryW;
    FARPROC DeleteUrlCacheGroup;
    FARPROC DeleteWpadCacheForNetworks;
    FARPROC DetectAutoProxyUrl;
    FARPROC DispatchAPICall;
    FARPROC DllInstall;
    FARPROC FindCloseUrlCache;
    FARPROC FindFirstUrlCacheContainerA;
    FARPROC FindFirstUrlCacheContainerW;
    FARPROC FindFirstUrlCacheEntryA;
    FARPROC FindFirstUrlCacheEntryExA;
    FARPROC FindFirstUrlCacheEntryExW;
    FARPROC FindFirstUrlCacheEntryW;
    FARPROC FindFirstUrlCacheGroup;
    FARPROC FindNextUrlCacheContainerA;
    FARPROC FindNextUrlCacheContainerW;
    FARPROC FindNextUrlCacheEntryA;
    FARPROC FindNextUrlCacheEntryExA;
    FARPROC FindNextUrlCacheEntryExW;
    FARPROC FindNextUrlCacheEntryW;
    FARPROC FindNextUrlCacheGroup;
    FARPROC ForceNexusLookup;
    FARPROC ForceNexusLookupExW;
    FARPROC FreeUrlCacheSpaceA;
    FARPROC FreeUrlCacheSpaceW;
    FARPROC FtpCommandA;
    FARPROC FtpCommandW;
    FARPROC FtpCreateDirectoryA;
    FARPROC FtpCreateDirectoryW;
    FARPROC FtpDeleteFileA;
    FARPROC FtpDeleteFileW;
    FARPROC FtpFindFirstFileA;
    FARPROC FtpFindFirstFileW;
    FARPROC FtpGetCurrentDirectoryA;
    FARPROC FtpGetCurrentDirectoryW;
    FARPROC FtpGetFileA;
    FARPROC FtpGetFileEx;
    FARPROC FtpGetFileSize;
    FARPROC FtpGetFileW;
    FARPROC FtpOpenFileA;
    FARPROC FtpOpenFileW;
    FARPROC FtpPutFileA;
    FARPROC FtpPutFileEx;
    FARPROC FtpPutFileW;
    FARPROC FtpRemoveDirectoryA;
    FARPROC FtpRemoveDirectoryW;
    FARPROC FtpRenameFileA;
    FARPROC FtpRenameFileW;
    FARPROC FtpSetCurrentDirectoryA;
    FARPROC FtpSetCurrentDirectoryW;
    FARPROC _GetFileExtensionFromUrl;
    FARPROC GetProxyDllInfo;
    FARPROC GetUrlCacheConfigInfoA;
    FARPROC GetUrlCacheConfigInfoW;
    FARPROC GetUrlCacheEntryBinaryBlob;
    FARPROC GetUrlCacheEntryInfoA;
    FARPROC GetUrlCacheEntryInfoExA;
    FARPROC GetUrlCacheEntryInfoExW;
    FARPROC GetUrlCacheEntryInfoW;
    FARPROC GetUrlCacheGroupAttributeA;
    FARPROC GetUrlCacheGroupAttributeW;
    FARPROC GetUrlCacheHeaderData;
    FARPROC GopherCreateLocatorA;
    FARPROC GopherCreateLocatorW;
    FARPROC GopherFindFirstFileA;
    FARPROC GopherFindFirstFileW;
    FARPROC GopherGetAttributeA;
    FARPROC GopherGetAttributeW;
    FARPROC GopherGetLocatorTypeA;
    FARPROC GopherGetLocatorTypeW;
    FARPROC GopherOpenFileA;
    FARPROC GopherOpenFileW;
    FARPROC HttpAddRequestHeadersA;
    FARPROC HttpAddRequestHeadersW;
    FARPROC HttpCheckDavCompliance;
    FARPROC HttpCloseDependencyHandle;
    FARPROC HttpDuplicateDependencyHandle;
    FARPROC HttpEndRequestA;
    FARPROC HttpEndRequestW;
    FARPROC HttpGetServerCredentials;
    FARPROC HttpGetTunnelSocket;
    FARPROC HttpIsHostHstsEnabled;
    FARPROC HttpOpenDependencyHandle;
    FARPROC HttpOpenRequestA;
    FARPROC HttpOpenRequestW;
    FARPROC HttpPushClose;
    FARPROC HttpPushEnable;
    FARPROC HttpPushWait;
    FARPROC HttpQueryInfoA;
    FARPROC HttpQueryInfoW;
    FARPROC HttpSendRequestA;
    FARPROC HttpSendRequestExA;
    FARPROC HttpSendRequestExW;
    FARPROC HttpSendRequestW;
    FARPROC HttpWebSocketClose;
    FARPROC HttpWebSocketCompleteUpgrade;
    FARPROC HttpWebSocketQueryCloseStatus;
    FARPROC HttpWebSocketReceive;
    FARPROC HttpWebSocketSend;
    FARPROC HttpWebSocketShutdown;
    FARPROC IncrementUrlCacheHeaderData;
    FARPROC InternetAlgIdToStringA;
    FARPROC InternetAlgIdToStringW;
    FARPROC InternetAttemptConnect;
    FARPROC InternetAutodial;
    FARPROC InternetAutodialCallback;
    FARPROC InternetAutodialHangup;
    FARPROC InternetCanonicalizeUrlA;
    FARPROC InternetCanonicalizeUrlW;
    FARPROC InternetCheckConnectionA;
    FARPROC InternetCheckConnectionW;
    FARPROC InternetClearAllPerSiteCookieDecisions;
    FARPROC InternetCloseHandle;
    FARPROC InternetCombineUrlA;
    FARPROC InternetCombineUrlW;
    FARPROC InternetConfirmZoneCrossing;
    FARPROC InternetConfirmZoneCrossingA;
    FARPROC InternetConfirmZoneCrossingW;
    FARPROC InternetConnectA;
    FARPROC InternetConnectW;
    FARPROC InternetConvertUrlFromWireToWideChar;
    FARPROC InternetCrackUrlA;
    FARPROC InternetCrackUrlW;
    FARPROC InternetCreateUrlA;
    FARPROC InternetCreateUrlW;
    FARPROC InternetDial;
    FARPROC InternetDialA;
    FARPROC InternetDialW;
    FARPROC InternetEnumPerSiteCookieDecisionA;
    FARPROC InternetEnumPerSiteCookieDecisionW;
    FARPROC InternetErrorDlg;
    FARPROC InternetFindNextFileA;
    FARPROC InternetFindNextFileW;
    FARPROC InternetFortezzaCommand;
    FARPROC InternetFreeCookies;
    FARPROC InternetFreeProxyInfoList;
    FARPROC InternetGetCertByURL;
    FARPROC InternetGetCertByURLA;
    FARPROC InternetGetConnectedState;
    FARPROC InternetGetConnectedStateEx;
    FARPROC InternetGetConnectedStateExA;
    FARPROC InternetGetConnectedStateExW;
    FARPROC InternetGetCookieA;
    FARPROC InternetGetCookieEx2;
    FARPROC InternetGetCookieExA;
    FARPROC InternetGetCookieExW;
    FARPROC InternetGetCookieW;
    FARPROC InternetGetLastResponseInfoA;
    FARPROC InternetGetLastResponseInfoW;
    FARPROC InternetGetPerSiteCookieDecisionA;
    FARPROC InternetGetPerSiteCookieDecisionW;
    FARPROC InternetGetProxyForUrl;
    FARPROC InternetGetSecurityInfoByURL;
    FARPROC InternetGetSecurityInfoByURLA;
    FARPROC InternetGetSecurityInfoByURLW;
    FARPROC InternetGoOnline;
    FARPROC InternetGoOnlineA;
    FARPROC InternetGoOnlineW;
    FARPROC InternetHangUp;
    FARPROC InternetInitializeAutoProxyDll;
    FARPROC InternetLockRequestFile;
    FARPROC InternetOpenA;
    FARPROC InternetOpenUrlA;
    FARPROC InternetOpenUrlW;
    FARPROC InternetOpenW;
    FARPROC InternetQueryDataAvailable;
    FARPROC InternetQueryFortezzaStatus;
    FARPROC InternetQueryOptionA;
    FARPROC InternetQueryOptionW;
    FARPROC InternetReadFile;
    FARPROC InternetReadFileExA;
    FARPROC InternetReadFileExW;
    FARPROC InternetSecurityProtocolToStringA;
    FARPROC InternetSecurityProtocolToStringW;
    FARPROC InternetSetCookieA;
    FARPROC InternetSetCookieEx2;
    FARPROC InternetSetCookieExA;
    FARPROC InternetSetCookieExW;
    FARPROC InternetSetCookieW;
    FARPROC InternetSetDialState;
    FARPROC InternetSetDialStateA;
    FARPROC InternetSetDialStateW;
    FARPROC InternetSetFilePointer;
    FARPROC InternetSetOptionA;
    FARPROC InternetSetOptionExA;
    FARPROC InternetSetOptionExW;
    FARPROC InternetSetOptionW;
    FARPROC InternetSetPerSiteCookieDecisionA;
    FARPROC InternetSetPerSiteCookieDecisionW;
    FARPROC InternetSetStatusCallback;
    FARPROC InternetSetStatusCallbackA;
    FARPROC InternetSetStatusCallbackW;
    FARPROC InternetShowSecurityInfoByURL;
    FARPROC InternetShowSecurityInfoByURLA;
    FARPROC InternetShowSecurityInfoByURLW;
    FARPROC InternetTimeFromSystemTime;
    FARPROC InternetTimeFromSystemTimeA;
    FARPROC InternetTimeFromSystemTimeW;
    FARPROC InternetTimeToSystemTime;
    FARPROC InternetTimeToSystemTimeA;
    FARPROC InternetTimeToSystemTimeW;
    FARPROC InternetUnlockRequestFile;
    FARPROC InternetWriteFile;
    FARPROC InternetWriteFileExA;
    FARPROC InternetWriteFileExW;
    FARPROC IsHostInProxyBypassList;
    FARPROC IsUrlCacheEntryExpiredA;
    FARPROC IsUrlCacheEntryExpiredW;
    FARPROC LoadUrlCacheContent;
    FARPROC ParseX509EncodedCertificateForListBoxEntry;
    FARPROC PrivacyGetZonePreferenceW;
    FARPROC PrivacySetZonePreferenceW;
    FARPROC ReadUrlCacheEntryStream;
    FARPROC ReadUrlCacheEntryStreamEx;
    FARPROC RegisterUrlCacheNotification;
    FARPROC ResumeSuspendedDownload;
    FARPROC RetrieveUrlCacheEntryFileA;
    FARPROC RetrieveUrlCacheEntryFileW;
    FARPROC RetrieveUrlCacheEntryStreamA;
    FARPROC RetrieveUrlCacheEntryStreamW;
    FARPROC RunOnceUrlCache;
    FARPROC SetUrlCacheConfigInfoA;
    FARPROC SetUrlCacheConfigInfoW;
    FARPROC SetUrlCacheEntryGroup;
    FARPROC SetUrlCacheEntryGroupA;
    FARPROC SetUrlCacheEntryGroupW;
    FARPROC SetUrlCacheEntryInfoA;
    FARPROC SetUrlCacheEntryInfoW;
    FARPROC SetUrlCacheGroupAttributeA;
    FARPROC SetUrlCacheGroupAttributeW;
    FARPROC SetUrlCacheHeaderData;
    FARPROC ShowCertificate;
    FARPROC ShowClientAuthCerts;
    FARPROC ShowSecurityInfo;
    FARPROC ShowX509EncodedCertificate;
    FARPROC UnlockUrlCacheEntryFile;
    FARPROC UnlockUrlCacheEntryFileA;
    FARPROC UnlockUrlCacheEntryFileW;
    FARPROC UnlockUrlCacheEntryStream;
    FARPROC UpdateUrlCacheContentPath;
    FARPROC UrlCacheCheckEntriesExist;
    FARPROC UrlCacheCloseEntryHandle;
    FARPROC UrlCacheContainerSetEntryMaximumAge;
    FARPROC UrlCacheCreateContainer;
    FARPROC UrlCacheFindFirstEntry;
    FARPROC UrlCacheFindNextEntry;
    FARPROC UrlCacheFreeEntryInfo;
    FARPROC UrlCacheFreeGlobalSpace;
    FARPROC UrlCacheGetContentPaths;
    FARPROC UrlCacheGetEntryInfo;
    FARPROC UrlCacheGetGlobalCacheSize;
    FARPROC UrlCacheGetGlobalLimit;
    FARPROC UrlCacheReadEntryStream;
    FARPROC UrlCacheReloadSettings;
    FARPROC UrlCacheRetrieveEntryFile;
    FARPROC UrlCacheRetrieveEntryStream;
    FARPROC UrlCacheServer;
    FARPROC UrlCacheSetGlobalLimit;
    FARPROC UrlCacheUpdateEntryExtraData;
    FARPROC UrlZonesDetach;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        AppCacheCheckManifest = GetProcAddress(dll, "AppCacheCheckManifest");
        AppCacheCloseHandle = GetProcAddress(dll, "AppCacheCloseHandle");
        AppCacheCreateAndCommitFile = GetProcAddress(dll, "AppCacheCreateAndCommitFile");
        AppCacheDeleteGroup = GetProcAddress(dll, "AppCacheDeleteGroup");
        AppCacheDeleteIEGroup = GetProcAddress(dll, "AppCacheDeleteIEGroup");
        AppCacheDuplicateHandle = GetProcAddress(dll, "AppCacheDuplicateHandle");
        AppCacheFinalize = GetProcAddress(dll, "AppCacheFinalize");
        AppCacheFreeDownloadList = GetProcAddress(dll, "AppCacheFreeDownloadList");
        AppCacheFreeGroupList = GetProcAddress(dll, "AppCacheFreeGroupList");
        AppCacheFreeIESpace = GetProcAddress(dll, "AppCacheFreeIESpace");
        AppCacheFreeSpace = GetProcAddress(dll, "AppCacheFreeSpace");
        AppCacheGetDownloadList = GetProcAddress(dll, "AppCacheGetDownloadList");
        AppCacheGetFallbackUrl = GetProcAddress(dll, "AppCacheGetFallbackUrl");
        AppCacheGetGroupList = GetProcAddress(dll, "AppCacheGetGroupList");
        AppCacheGetIEGroupList = GetProcAddress(dll, "AppCacheGetIEGroupList");
        AppCacheGetInfo = GetProcAddress(dll, "AppCacheGetInfo");
        AppCacheGetManifestUrl = GetProcAddress(dll, "AppCacheGetManifestUrl");
        AppCacheLookup = GetProcAddress(dll, "AppCacheLookup");
        CommitUrlCacheEntryA = GetProcAddress(dll, "CommitUrlCacheEntryA");
        CommitUrlCacheEntryBinaryBlob = GetProcAddress(dll, "CommitUrlCacheEntryBinaryBlob");
        CommitUrlCacheEntryW = GetProcAddress(dll, "CommitUrlCacheEntryW");
        CreateMD5SSOHash = GetProcAddress(dll, "CreateMD5SSOHash");
        CreateUrlCacheContainerA = GetProcAddress(dll, "CreateUrlCacheContainerA");
        CreateUrlCacheContainerW = GetProcAddress(dll, "CreateUrlCacheContainerW");
        CreateUrlCacheEntryA = GetProcAddress(dll, "CreateUrlCacheEntryA");
        CreateUrlCacheEntryExW = GetProcAddress(dll, "CreateUrlCacheEntryExW");
        CreateUrlCacheEntryW = GetProcAddress(dll, "CreateUrlCacheEntryW");
        CreateUrlCacheGroup = GetProcAddress(dll, "CreateUrlCacheGroup");
        DeleteIE3Cache = GetProcAddress(dll, "DeleteIE3Cache");
        DeleteUrlCacheContainerA = GetProcAddress(dll, "DeleteUrlCacheContainerA");
        DeleteUrlCacheContainerW = GetProcAddress(dll, "DeleteUrlCacheContainerW");
        DeleteUrlCacheEntry = GetProcAddress(dll, "DeleteUrlCacheEntry");
        DeleteUrlCacheEntryA = GetProcAddress(dll, "DeleteUrlCacheEntryA");
        DeleteUrlCacheEntryW = GetProcAddress(dll, "DeleteUrlCacheEntryW");
        DeleteUrlCacheGroup = GetProcAddress(dll, "DeleteUrlCacheGroup");
        DeleteWpadCacheForNetworks = GetProcAddress(dll, "DeleteWpadCacheForNetworks");
        DetectAutoProxyUrl = GetProcAddress(dll, "DetectAutoProxyUrl");
        DispatchAPICall = GetProcAddress(dll, "DispatchAPICall");
        DllInstall = GetProcAddress(dll, "DllInstall");
        FindCloseUrlCache = GetProcAddress(dll, "FindCloseUrlCache");
        FindFirstUrlCacheContainerA = GetProcAddress(dll, "FindFirstUrlCacheContainerA");
        FindFirstUrlCacheContainerW = GetProcAddress(dll, "FindFirstUrlCacheContainerW");
        FindFirstUrlCacheEntryA = GetProcAddress(dll, "FindFirstUrlCacheEntryA");
        FindFirstUrlCacheEntryExA = GetProcAddress(dll, "FindFirstUrlCacheEntryExA");
        FindFirstUrlCacheEntryExW = GetProcAddress(dll, "FindFirstUrlCacheEntryExW");
        FindFirstUrlCacheEntryW = GetProcAddress(dll, "FindFirstUrlCacheEntryW");
        FindFirstUrlCacheGroup = GetProcAddress(dll, "FindFirstUrlCacheGroup");
        FindNextUrlCacheContainerA = GetProcAddress(dll, "FindNextUrlCacheContainerA");
        FindNextUrlCacheContainerW = GetProcAddress(dll, "FindNextUrlCacheContainerW");
        FindNextUrlCacheEntryA = GetProcAddress(dll, "FindNextUrlCacheEntryA");
        FindNextUrlCacheEntryExA = GetProcAddress(dll, "FindNextUrlCacheEntryExA");
        FindNextUrlCacheEntryExW = GetProcAddress(dll, "FindNextUrlCacheEntryExW");
        FindNextUrlCacheEntryW = GetProcAddress(dll, "FindNextUrlCacheEntryW");
        FindNextUrlCacheGroup = GetProcAddress(dll, "FindNextUrlCacheGroup");
        ForceNexusLookup = GetProcAddress(dll, "ForceNexusLookup");
        ForceNexusLookupExW = GetProcAddress(dll, "ForceNexusLookupExW");
        FreeUrlCacheSpaceA = GetProcAddress(dll, "FreeUrlCacheSpaceA");
        FreeUrlCacheSpaceW = GetProcAddress(dll, "FreeUrlCacheSpaceW");
        FtpCommandA = GetProcAddress(dll, "FtpCommandA");
        FtpCommandW = GetProcAddress(dll, "FtpCommandW");
        FtpCreateDirectoryA = GetProcAddress(dll, "FtpCreateDirectoryA");
        FtpCreateDirectoryW = GetProcAddress(dll, "FtpCreateDirectoryW");
        FtpDeleteFileA = GetProcAddress(dll, "FtpDeleteFileA");
        FtpDeleteFileW = GetProcAddress(dll, "FtpDeleteFileW");
        FtpFindFirstFileA = GetProcAddress(dll, "FtpFindFirstFileA");
        FtpFindFirstFileW = GetProcAddress(dll, "FtpFindFirstFileW");
        FtpGetCurrentDirectoryA = GetProcAddress(dll, "FtpGetCurrentDirectoryA");
        FtpGetCurrentDirectoryW = GetProcAddress(dll, "FtpGetCurrentDirectoryW");
        FtpGetFileA = GetProcAddress(dll, "FtpGetFileA");
        FtpGetFileEx = GetProcAddress(dll, "FtpGetFileEx");
        FtpGetFileSize = GetProcAddress(dll, "FtpGetFileSize");
        FtpGetFileW = GetProcAddress(dll, "FtpGetFileW");
        FtpOpenFileA = GetProcAddress(dll, "FtpOpenFileA");
        FtpOpenFileW = GetProcAddress(dll, "FtpOpenFileW");
        FtpPutFileA = GetProcAddress(dll, "FtpPutFileA");
        FtpPutFileEx = GetProcAddress(dll, "FtpPutFileEx");
        FtpPutFileW = GetProcAddress(dll, "FtpPutFileW");
        FtpRemoveDirectoryA = GetProcAddress(dll, "FtpRemoveDirectoryA");
        FtpRemoveDirectoryW = GetProcAddress(dll, "FtpRemoveDirectoryW");
        FtpRenameFileA = GetProcAddress(dll, "FtpRenameFileA");
        FtpRenameFileW = GetProcAddress(dll, "FtpRenameFileW");
        FtpSetCurrentDirectoryA = GetProcAddress(dll, "FtpSetCurrentDirectoryA");
        FtpSetCurrentDirectoryW = GetProcAddress(dll, "FtpSetCurrentDirectoryW");
        _GetFileExtensionFromUrl = GetProcAddress(dll, "_GetFileExtensionFromUrl");
        GetProxyDllInfo = GetProcAddress(dll, "GetProxyDllInfo");
        GetUrlCacheConfigInfoA = GetProcAddress(dll, "GetUrlCacheConfigInfoA");
        GetUrlCacheConfigInfoW = GetProcAddress(dll, "GetUrlCacheConfigInfoW");
        GetUrlCacheEntryBinaryBlob = GetProcAddress(dll, "GetUrlCacheEntryBinaryBlob");
        GetUrlCacheEntryInfoA = GetProcAddress(dll, "GetUrlCacheEntryInfoA");
        GetUrlCacheEntryInfoExA = GetProcAddress(dll, "GetUrlCacheEntryInfoExA");
        GetUrlCacheEntryInfoExW = GetProcAddress(dll, "GetUrlCacheEntryInfoExW");
        GetUrlCacheEntryInfoW = GetProcAddress(dll, "GetUrlCacheEntryInfoW");
        GetUrlCacheGroupAttributeA = GetProcAddress(dll, "GetUrlCacheGroupAttributeA");
        GetUrlCacheGroupAttributeW = GetProcAddress(dll, "GetUrlCacheGroupAttributeW");
        GetUrlCacheHeaderData = GetProcAddress(dll, "GetUrlCacheHeaderData");
        GopherCreateLocatorA = GetProcAddress(dll, "GopherCreateLocatorA");
        GopherCreateLocatorW = GetProcAddress(dll, "GopherCreateLocatorW");
        GopherFindFirstFileA = GetProcAddress(dll, "GopherFindFirstFileA");
        GopherFindFirstFileW = GetProcAddress(dll, "GopherFindFirstFileW");
        GopherGetAttributeA = GetProcAddress(dll, "GopherGetAttributeA");
        GopherGetAttributeW = GetProcAddress(dll, "GopherGetAttributeW");
        GopherGetLocatorTypeA = GetProcAddress(dll, "GopherGetLocatorTypeA");
        GopherGetLocatorTypeW = GetProcAddress(dll, "GopherGetLocatorTypeW");
        GopherOpenFileA = GetProcAddress(dll, "GopherOpenFileA");
        GopherOpenFileW = GetProcAddress(dll, "GopherOpenFileW");
        HttpAddRequestHeadersA = GetProcAddress(dll, "HttpAddRequestHeadersA");
        HttpAddRequestHeadersW = GetProcAddress(dll, "HttpAddRequestHeadersW");
        HttpCheckDavCompliance = GetProcAddress(dll, "HttpCheckDavCompliance");
        HttpCloseDependencyHandle = GetProcAddress(dll, "HttpCloseDependencyHandle");
        HttpDuplicateDependencyHandle = GetProcAddress(dll, "HttpDuplicateDependencyHandle");
        HttpEndRequestA = GetProcAddress(dll, "HttpEndRequestA");
        HttpEndRequestW = GetProcAddress(dll, "HttpEndRequestW");
        HttpGetServerCredentials = GetProcAddress(dll, "HttpGetServerCredentials");
        HttpGetTunnelSocket = GetProcAddress(dll, "HttpGetTunnelSocket");
        HttpIsHostHstsEnabled = GetProcAddress(dll, "HttpIsHostHstsEnabled");
        HttpOpenDependencyHandle = GetProcAddress(dll, "HttpOpenDependencyHandle");
        HttpOpenRequestA = GetProcAddress(dll, "HttpOpenRequestA");
        HttpOpenRequestW = GetProcAddress(dll, "HttpOpenRequestW");
        HttpPushClose = GetProcAddress(dll, "HttpPushClose");
        HttpPushEnable = GetProcAddress(dll, "HttpPushEnable");
        HttpPushWait = GetProcAddress(dll, "HttpPushWait");
        HttpQueryInfoA = GetProcAddress(dll, "HttpQueryInfoA");
        HttpQueryInfoW = GetProcAddress(dll, "HttpQueryInfoW");
        HttpSendRequestA = GetProcAddress(dll, "HttpSendRequestA");
        HttpSendRequestExA = GetProcAddress(dll, "HttpSendRequestExA");
        HttpSendRequestExW = GetProcAddress(dll, "HttpSendRequestExW");
        HttpSendRequestW = GetProcAddress(dll, "HttpSendRequestW");
        HttpWebSocketClose = GetProcAddress(dll, "HttpWebSocketClose");
        HttpWebSocketCompleteUpgrade = GetProcAddress(dll, "HttpWebSocketCompleteUpgrade");
        HttpWebSocketQueryCloseStatus = GetProcAddress(dll, "HttpWebSocketQueryCloseStatus");
        HttpWebSocketReceive = GetProcAddress(dll, "HttpWebSocketReceive");
        HttpWebSocketSend = GetProcAddress(dll, "HttpWebSocketSend");
        HttpWebSocketShutdown = GetProcAddress(dll, "HttpWebSocketShutdown");
        IncrementUrlCacheHeaderData = GetProcAddress(dll, "IncrementUrlCacheHeaderData");
        InternetAlgIdToStringA = GetProcAddress(dll, "InternetAlgIdToStringA");
        InternetAlgIdToStringW = GetProcAddress(dll, "InternetAlgIdToStringW");
        InternetAttemptConnect = GetProcAddress(dll, "InternetAttemptConnect");
        InternetAutodial = GetProcAddress(dll, "InternetAutodial");
        InternetAutodialCallback = GetProcAddress(dll, "InternetAutodialCallback");
        InternetAutodialHangup = GetProcAddress(dll, "InternetAutodialHangup");
        InternetCanonicalizeUrlA = GetProcAddress(dll, "InternetCanonicalizeUrlA");
        InternetCanonicalizeUrlW = GetProcAddress(dll, "InternetCanonicalizeUrlW");
        InternetCheckConnectionA = GetProcAddress(dll, "InternetCheckConnectionA");
        InternetCheckConnectionW = GetProcAddress(dll, "InternetCheckConnectionW");
        InternetClearAllPerSiteCookieDecisions = GetProcAddress(dll, "InternetClearAllPerSiteCookieDecisions");
        InternetCloseHandle = GetProcAddress(dll, "InternetCloseHandle");
        InternetCombineUrlA = GetProcAddress(dll, "InternetCombineUrlA");
        InternetCombineUrlW = GetProcAddress(dll, "InternetCombineUrlW");
        InternetConfirmZoneCrossing = GetProcAddress(dll, "InternetConfirmZoneCrossing");
        InternetConfirmZoneCrossingA = GetProcAddress(dll, "InternetConfirmZoneCrossingA");
        InternetConfirmZoneCrossingW = GetProcAddress(dll, "InternetConfirmZoneCrossingW");
        InternetConnectA = GetProcAddress(dll, "InternetConnectA");
        InternetConnectW = GetProcAddress(dll, "InternetConnectW");
        InternetConvertUrlFromWireToWideChar = GetProcAddress(dll, "InternetConvertUrlFromWireToWideChar");
        InternetCrackUrlA = GetProcAddress(dll, "InternetCrackUrlA");
        InternetCrackUrlW = GetProcAddress(dll, "InternetCrackUrlW");
        InternetCreateUrlA = GetProcAddress(dll, "InternetCreateUrlA");
        InternetCreateUrlW = GetProcAddress(dll, "InternetCreateUrlW");
        InternetDial = GetProcAddress(dll, "InternetDial");
        InternetDialA = GetProcAddress(dll, "InternetDialA");
        InternetDialW = GetProcAddress(dll, "InternetDialW");
        InternetEnumPerSiteCookieDecisionA = GetProcAddress(dll, "InternetEnumPerSiteCookieDecisionA");
        InternetEnumPerSiteCookieDecisionW = GetProcAddress(dll, "InternetEnumPerSiteCookieDecisionW");
        InternetErrorDlg = GetProcAddress(dll, "InternetErrorDlg");
        InternetFindNextFileA = GetProcAddress(dll, "InternetFindNextFileA");
        InternetFindNextFileW = GetProcAddress(dll, "InternetFindNextFileW");
        InternetFortezzaCommand = GetProcAddress(dll, "InternetFortezzaCommand");
        InternetFreeCookies = GetProcAddress(dll, "InternetFreeCookies");
        InternetFreeProxyInfoList = GetProcAddress(dll, "InternetFreeProxyInfoList");
        InternetGetCertByURL = GetProcAddress(dll, "InternetGetCertByURL");
        InternetGetCertByURLA = GetProcAddress(dll, "InternetGetCertByURLA");
        InternetGetConnectedState = GetProcAddress(dll, "InternetGetConnectedState");
        InternetGetConnectedStateEx = GetProcAddress(dll, "InternetGetConnectedStateEx");
        InternetGetConnectedStateExA = GetProcAddress(dll, "InternetGetConnectedStateExA");
        InternetGetConnectedStateExW = GetProcAddress(dll, "InternetGetConnectedStateExW");
        InternetGetCookieA = GetProcAddress(dll, "InternetGetCookieA");
        InternetGetCookieEx2 = GetProcAddress(dll, "InternetGetCookieEx2");
        InternetGetCookieExA = GetProcAddress(dll, "InternetGetCookieExA");
        InternetGetCookieExW = GetProcAddress(dll, "InternetGetCookieExW");
        InternetGetCookieW = GetProcAddress(dll, "InternetGetCookieW");
        InternetGetLastResponseInfoA = GetProcAddress(dll, "InternetGetLastResponseInfoA");
        InternetGetLastResponseInfoW = GetProcAddress(dll, "InternetGetLastResponseInfoW");
        InternetGetPerSiteCookieDecisionA = GetProcAddress(dll, "InternetGetPerSiteCookieDecisionA");
        InternetGetPerSiteCookieDecisionW = GetProcAddress(dll, "InternetGetPerSiteCookieDecisionW");
        InternetGetProxyForUrl = GetProcAddress(dll, "InternetGetProxyForUrl");
        InternetGetSecurityInfoByURL = GetProcAddress(dll, "InternetGetSecurityInfoByURL");
        InternetGetSecurityInfoByURLA = GetProcAddress(dll, "InternetGetSecurityInfoByURLA");
        InternetGetSecurityInfoByURLW = GetProcAddress(dll, "InternetGetSecurityInfoByURLW");
        InternetGoOnline = GetProcAddress(dll, "InternetGoOnline");
        InternetGoOnlineA = GetProcAddress(dll, "InternetGoOnlineA");
        InternetGoOnlineW = GetProcAddress(dll, "InternetGoOnlineW");
        InternetHangUp = GetProcAddress(dll, "InternetHangUp");
        InternetInitializeAutoProxyDll = GetProcAddress(dll, "InternetInitializeAutoProxyDll");
        InternetLockRequestFile = GetProcAddress(dll, "InternetLockRequestFile");
        InternetOpenA = GetProcAddress(dll, "InternetOpenA");
        InternetOpenUrlA = GetProcAddress(dll, "InternetOpenUrlA");
        InternetOpenUrlW = GetProcAddress(dll, "InternetOpenUrlW");
        InternetOpenW = GetProcAddress(dll, "InternetOpenW");
        InternetQueryDataAvailable = GetProcAddress(dll, "InternetQueryDataAvailable");
        InternetQueryFortezzaStatus = GetProcAddress(dll, "InternetQueryFortezzaStatus");
        InternetQueryOptionA = GetProcAddress(dll, "InternetQueryOptionA");
        InternetQueryOptionW = GetProcAddress(dll, "InternetQueryOptionW");
        InternetReadFile = GetProcAddress(dll, "InternetReadFile");
        InternetReadFileExA = GetProcAddress(dll, "InternetReadFileExA");
        InternetReadFileExW = GetProcAddress(dll, "InternetReadFileExW");
        InternetSecurityProtocolToStringA = GetProcAddress(dll, "InternetSecurityProtocolToStringA");
        InternetSecurityProtocolToStringW = GetProcAddress(dll, "InternetSecurityProtocolToStringW");
        InternetSetCookieA = GetProcAddress(dll, "InternetSetCookieA");
        InternetSetCookieEx2 = GetProcAddress(dll, "InternetSetCookieEx2");
        InternetSetCookieExA = GetProcAddress(dll, "InternetSetCookieExA");
        InternetSetCookieExW = GetProcAddress(dll, "InternetSetCookieExW");
        InternetSetCookieW = GetProcAddress(dll, "InternetSetCookieW");
        InternetSetDialState = GetProcAddress(dll, "InternetSetDialState");
        InternetSetDialStateA = GetProcAddress(dll, "InternetSetDialStateA");
        InternetSetDialStateW = GetProcAddress(dll, "InternetSetDialStateW");
        InternetSetFilePointer = GetProcAddress(dll, "InternetSetFilePointer");
        InternetSetOptionA = GetProcAddress(dll, "InternetSetOptionA");
        InternetSetOptionExA = GetProcAddress(dll, "InternetSetOptionExA");
        InternetSetOptionExW = GetProcAddress(dll, "InternetSetOptionExW");
        InternetSetOptionW = GetProcAddress(dll, "InternetSetOptionW");
        InternetSetPerSiteCookieDecisionA = GetProcAddress(dll, "InternetSetPerSiteCookieDecisionA");
        InternetSetPerSiteCookieDecisionW = GetProcAddress(dll, "InternetSetPerSiteCookieDecisionW");
        InternetSetStatusCallback = GetProcAddress(dll, "InternetSetStatusCallback");
        InternetSetStatusCallbackA = GetProcAddress(dll, "InternetSetStatusCallbackA");
        InternetSetStatusCallbackW = GetProcAddress(dll, "InternetSetStatusCallbackW");
        InternetShowSecurityInfoByURL = GetProcAddress(dll, "InternetShowSecurityInfoByURL");
        InternetShowSecurityInfoByURLA = GetProcAddress(dll, "InternetShowSecurityInfoByURLA");
        InternetShowSecurityInfoByURLW = GetProcAddress(dll, "InternetShowSecurityInfoByURLW");
        InternetTimeFromSystemTime = GetProcAddress(dll, "InternetTimeFromSystemTime");
        InternetTimeFromSystemTimeA = GetProcAddress(dll, "InternetTimeFromSystemTimeA");
        InternetTimeFromSystemTimeW = GetProcAddress(dll, "InternetTimeFromSystemTimeW");
        InternetTimeToSystemTime = GetProcAddress(dll, "InternetTimeToSystemTime");
        InternetTimeToSystemTimeA = GetProcAddress(dll, "InternetTimeToSystemTimeA");
        InternetTimeToSystemTimeW = GetProcAddress(dll, "InternetTimeToSystemTimeW");
        InternetUnlockRequestFile = GetProcAddress(dll, "InternetUnlockRequestFile");
        InternetWriteFile = GetProcAddress(dll, "InternetWriteFile");
        InternetWriteFileExA = GetProcAddress(dll, "InternetWriteFileExA");
        InternetWriteFileExW = GetProcAddress(dll, "InternetWriteFileExW");
        IsHostInProxyBypassList = GetProcAddress(dll, "IsHostInProxyBypassList");
        IsUrlCacheEntryExpiredA = GetProcAddress(dll, "IsUrlCacheEntryExpiredA");
        IsUrlCacheEntryExpiredW = GetProcAddress(dll, "IsUrlCacheEntryExpiredW");
        LoadUrlCacheContent = GetProcAddress(dll, "LoadUrlCacheContent");
        ParseX509EncodedCertificateForListBoxEntry = GetProcAddress(dll, "ParseX509EncodedCertificateForListBoxEntry");
        PrivacyGetZonePreferenceW = GetProcAddress(dll, "PrivacyGetZonePreferenceW");
        PrivacySetZonePreferenceW = GetProcAddress(dll, "PrivacySetZonePreferenceW");
        ReadUrlCacheEntryStream = GetProcAddress(dll, "ReadUrlCacheEntryStream");
        ReadUrlCacheEntryStreamEx = GetProcAddress(dll, "ReadUrlCacheEntryStreamEx");
        RegisterUrlCacheNotification = GetProcAddress(dll, "RegisterUrlCacheNotification");
        ResumeSuspendedDownload = GetProcAddress(dll, "ResumeSuspendedDownload");
        RetrieveUrlCacheEntryFileA = GetProcAddress(dll, "RetrieveUrlCacheEntryFileA");
        RetrieveUrlCacheEntryFileW = GetProcAddress(dll, "RetrieveUrlCacheEntryFileW");
        RetrieveUrlCacheEntryStreamA = GetProcAddress(dll, "RetrieveUrlCacheEntryStreamA");
        RetrieveUrlCacheEntryStreamW = GetProcAddress(dll, "RetrieveUrlCacheEntryStreamW");
        RunOnceUrlCache = GetProcAddress(dll, "RunOnceUrlCache");
        SetUrlCacheConfigInfoA = GetProcAddress(dll, "SetUrlCacheConfigInfoA");
        SetUrlCacheConfigInfoW = GetProcAddress(dll, "SetUrlCacheConfigInfoW");
        SetUrlCacheEntryGroup = GetProcAddress(dll, "SetUrlCacheEntryGroup");
        SetUrlCacheEntryGroupA = GetProcAddress(dll, "SetUrlCacheEntryGroupA");
        SetUrlCacheEntryGroupW = GetProcAddress(dll, "SetUrlCacheEntryGroupW");
        SetUrlCacheEntryInfoA = GetProcAddress(dll, "SetUrlCacheEntryInfoA");
        SetUrlCacheEntryInfoW = GetProcAddress(dll, "SetUrlCacheEntryInfoW");
        SetUrlCacheGroupAttributeA = GetProcAddress(dll, "SetUrlCacheGroupAttributeA");
        SetUrlCacheGroupAttributeW = GetProcAddress(dll, "SetUrlCacheGroupAttributeW");
        SetUrlCacheHeaderData = GetProcAddress(dll, "SetUrlCacheHeaderData");
        ShowCertificate = GetProcAddress(dll, "ShowCertificate");
        ShowClientAuthCerts = GetProcAddress(dll, "ShowClientAuthCerts");
        ShowSecurityInfo = GetProcAddress(dll, "ShowSecurityInfo");
        ShowX509EncodedCertificate = GetProcAddress(dll, "ShowX509EncodedCertificate");
        UnlockUrlCacheEntryFile = GetProcAddress(dll, "UnlockUrlCacheEntryFile");
        UnlockUrlCacheEntryFileA = GetProcAddress(dll, "UnlockUrlCacheEntryFileA");
        UnlockUrlCacheEntryFileW = GetProcAddress(dll, "UnlockUrlCacheEntryFileW");
        UnlockUrlCacheEntryStream = GetProcAddress(dll, "UnlockUrlCacheEntryStream");
        UpdateUrlCacheContentPath = GetProcAddress(dll, "UpdateUrlCacheContentPath");
        UrlCacheCheckEntriesExist = GetProcAddress(dll, "UrlCacheCheckEntriesExist");
        UrlCacheCloseEntryHandle = GetProcAddress(dll, "UrlCacheCloseEntryHandle");
        UrlCacheContainerSetEntryMaximumAge = GetProcAddress(dll, "UrlCacheContainerSetEntryMaximumAge");
        UrlCacheCreateContainer = GetProcAddress(dll, "UrlCacheCreateContainer");
        UrlCacheFindFirstEntry = GetProcAddress(dll, "UrlCacheFindFirstEntry");
        UrlCacheFindNextEntry = GetProcAddress(dll, "UrlCacheFindNextEntry");
        UrlCacheFreeEntryInfo = GetProcAddress(dll, "UrlCacheFreeEntryInfo");
        UrlCacheFreeGlobalSpace = GetProcAddress(dll, "UrlCacheFreeGlobalSpace");
        UrlCacheGetContentPaths = GetProcAddress(dll, "UrlCacheGetContentPaths");
        UrlCacheGetEntryInfo = GetProcAddress(dll, "UrlCacheGetEntryInfo");
        UrlCacheGetGlobalCacheSize = GetProcAddress(dll, "UrlCacheGetGlobalCacheSize");
        UrlCacheGetGlobalLimit = GetProcAddress(dll, "UrlCacheGetGlobalLimit");
        UrlCacheReadEntryStream = GetProcAddress(dll, "UrlCacheReadEntryStream");
        UrlCacheReloadSettings = GetProcAddress(dll, "UrlCacheReloadSettings");
        UrlCacheRetrieveEntryFile = GetProcAddress(dll, "UrlCacheRetrieveEntryFile");
        UrlCacheRetrieveEntryStream = GetProcAddress(dll, "UrlCacheRetrieveEntryStream");
        UrlCacheServer = GetProcAddress(dll, "UrlCacheServer");
        UrlCacheSetGlobalLimit = GetProcAddress(dll, "UrlCacheSetGlobalLimit");
        UrlCacheUpdateEntryExtraData = GetProcAddress(dll, "UrlCacheUpdateEntryExtraData");
        UrlZonesDetach = GetProcAddress(dll, "UrlZonesDetach");
    }
} wininet;

struct version_dll
{
    HMODULE dll;
    FARPROC GetFileVersionInfoA;
    FARPROC GetFileVersionInfoByHandle;
    FARPROC GetFileVersionInfoExA;
    FARPROC GetFileVersionInfoExW;
    FARPROC GetFileVersionInfoSizeA;
    FARPROC GetFileVersionInfoSizeExA;
    FARPROC GetFileVersionInfoSizeExW;
    FARPROC GetFileVersionInfoSizeW;
    FARPROC GetFileVersionInfoW;
    FARPROC VerFindFileA;
    FARPROC VerFindFileW;
    FARPROC VerInstallFileA;
    FARPROC VerInstallFileW;
    FARPROC VerLanguageNameA;
    FARPROC VerLanguageNameW;
    FARPROC VerQueryValueA;
    FARPROC VerQueryValueW;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        GetFileVersionInfoA = GetProcAddress(dll, "GetFileVersionInfoA");
        GetFileVersionInfoByHandle = GetProcAddress(dll, "GetFileVersionInfoByHandle");
        GetFileVersionInfoExA = GetProcAddress(dll, "GetFileVersionInfoExA");
        GetFileVersionInfoExW = GetProcAddress(dll, "GetFileVersionInfoExW");
        GetFileVersionInfoSizeA = GetProcAddress(dll, "GetFileVersionInfoSizeA");
        GetFileVersionInfoSizeExA = GetProcAddress(dll, "GetFileVersionInfoSizeExA");
        GetFileVersionInfoSizeExW = GetProcAddress(dll, "GetFileVersionInfoSizeExW");
        GetFileVersionInfoSizeW = GetProcAddress(dll, "GetFileVersionInfoSizeW");
        GetFileVersionInfoW = GetProcAddress(dll, "GetFileVersionInfoW");
        VerFindFileA = GetProcAddress(dll, "VerFindFileA");
        VerFindFileW = GetProcAddress(dll, "VerFindFileW");
        VerInstallFileA = GetProcAddress(dll, "VerInstallFileA");
        VerInstallFileW = GetProcAddress(dll, "VerInstallFileW");
        VerLanguageNameA = GetProcAddress(dll, "VerLanguageNameA");
        VerLanguageNameW = GetProcAddress(dll, "VerLanguageNameW");
        VerQueryValueA = GetProcAddress(dll, "VerQueryValueA");
        VerQueryValueW = GetProcAddress(dll, "VerQueryValueW");
    }
} version;

#if !X64
struct dinput_dll
{
    HMODULE dll;
    FARPROC DirectInputCreateA;
    FARPROC DirectInputCreateEx;
    FARPROC DirectInputCreateW;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        DirectInputCreateA = GetProcAddress(dll, "DirectInputCreateA");
        DirectInputCreateEx = GetProcAddress(dll, "DirectInputCreateEx");
        DirectInputCreateW = GetProcAddress(dll, "DirectInputCreateW");
    }
} dinput;

struct d3d8_dll
{
    HMODULE dll;
    FARPROC DebugSetMute;
    FARPROC Direct3D8EnableMaximizedWindowedModeShim;
    FARPROC Direct3DCreate8;
    FARPROC ValidatePixelShader;
    FARPROC ValidateVertexShader;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        DebugSetMute = GetProcAddress(dll, "DebugSetMute");
        Direct3D8EnableMaximizedWindowedModeShim = GetProcAddress(dll, "Direct3D8EnableMaximizedWindowedModeShim");
        Direct3DCreate8 = GetProcAddress(dll, "Direct3DCreate8");
        ValidatePixelShader = GetProcAddress(dll, "ValidatePixelShader");
        ValidateVertexShader = GetProcAddress(dll, "ValidateVertexShader");
    }
} d3d8;

struct d3d9_dll
{
    HMODULE dll;
    FARPROC D3DPERF_BeginEvent;
    FARPROC D3DPERF_EndEvent;
    FARPROC D3DPERF_GetStatus;
    FARPROC D3DPERF_QueryRepeatFrame;
    FARPROC D3DPERF_SetMarker;
    FARPROC D3DPERF_SetOptions;
    FARPROC D3DPERF_SetRegion;
    FARPROC DebugSetLevel;
    FARPROC DebugSetMute;
    FARPROC Direct3D9EnableMaximizedWindowedModeShim;
    FARPROC Direct3DCreate9;
    FARPROC Direct3DCreate9Ex;
    FARPROC Direct3DShaderValidatorCreate9;
    FARPROC PSGPError;
    FARPROC PSGPSampleTexture;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        D3DPERF_BeginEvent = GetProcAddress(dll, "D3DPERF_BeginEvent");
        D3DPERF_EndEvent = GetProcAddress(dll, "D3DPERF_EndEvent");
        D3DPERF_GetStatus = GetProcAddress(dll, "D3DPERF_GetStatus");
        D3DPERF_QueryRepeatFrame = GetProcAddress(dll, "D3DPERF_QueryRepeatFrame");
        D3DPERF_SetMarker = GetProcAddress(dll, "D3DPERF_SetMarker");
        D3DPERF_SetOptions = GetProcAddress(dll, "D3DPERF_SetOptions");
        D3DPERF_SetRegion = GetProcAddress(dll, "D3DPERF_SetRegion");
        DebugSetLevel = GetProcAddress(dll, "DebugSetLevel");
        DebugSetMute = GetProcAddress(dll, "DebugSetMute");
        Direct3D9EnableMaximizedWindowedModeShim = GetProcAddress(dll, "Direct3D9EnableMaximizedWindowedModeShim");
        Direct3DCreate9 = GetProcAddress(dll, "Direct3DCreate9");
        Direct3DCreate9Ex = GetProcAddress(dll, "Direct3DCreate9Ex");
        Direct3DShaderValidatorCreate9 = GetProcAddress(dll, "Direct3DShaderValidatorCreate9");
        PSGPError = GetProcAddress(dll, "PSGPError");
        PSGPSampleTexture = GetProcAddress(dll, "PSGPSampleTexture");
    }
} d3d9;

struct d3d11_dll
{
    HMODULE dll;
    FARPROC D3D11CoreCreateDevice;
    FARPROC D3D11CoreCreateLayeredDevice;
    FARPROC D3D11CoreGetLayeredDeviceSize;
    FARPROC D3D11CoreRegisterLayers;
    FARPROC D3D11CreateDevice;
    FARPROC D3D11CreateDeviceAndSwapChain;
    FARPROC D3DKMTCloseAdapter;
    FARPROC D3DKMTCreateAllocation;
    FARPROC D3DKMTCreateContext;
    FARPROC D3DKMTCreateDevice;
    FARPROC D3DKMTCreateSynchronizationObject;
    FARPROC D3DKMTDestroyAllocation;
    FARPROC D3DKMTDestroyContext;
    FARPROC D3DKMTDestroyDevice;
    FARPROC D3DKMTDestroySynchronizationObject;
    FARPROC D3DKMTEscape;
    FARPROC D3DKMTGetContextSchedulingPriority;
    FARPROC D3DKMTGetDeviceState;
    FARPROC D3DKMTGetDisplayModeList;
    FARPROC D3DKMTGetMultisampleMethodList;
    FARPROC D3DKMTGetRuntimeData;
    FARPROC D3DKMTGetSharedPrimaryHandle;
    FARPROC D3DKMTLock;
    FARPROC D3DKMTOpenAdapterFromHdc;
    FARPROC D3DKMTOpenResource;
    FARPROC D3DKMTPresent;
    FARPROC D3DKMTQueryAdapterInfo;
    FARPROC D3DKMTQueryAllocationResidency;
    FARPROC D3DKMTQueryResourceInfo;
    FARPROC D3DKMTRender;
    FARPROC D3DKMTSetAllocationPriority;
    FARPROC D3DKMTSetContextSchedulingPriority;
    FARPROC D3DKMTSetDisplayMode;
    FARPROC D3DKMTSetDisplayPrivateDriverFormat;
    FARPROC D3DKMTSetGammaRamp;
    FARPROC D3DKMTSetVidPnSourceOwner;
    FARPROC D3DKMTSignalSynchronizationObject;
    FARPROC D3DKMTUnlock;
    FARPROC D3DKMTWaitForSynchronizationObject;
    FARPROC D3DKMTWaitForVerticalBlankEvent;
    FARPROC D3DPerformance_BeginEvent;
    FARPROC D3DPerformance_EndEvent;
    FARPROC D3DPerformance_GetStatus;
    FARPROC D3DPerformance_SetMarker;
    FARPROC EnableFeatureLevelUpgrade;
    FARPROC OpenAdapter10;
    FARPROC OpenAdapter10_2;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        D3D11CoreCreateDevice = GetProcAddress(dll, "D3D11CoreCreateDevice");
        D3D11CoreCreateLayeredDevice = GetProcAddress(dll, "D3D11CoreCreateLayeredDevice");
        D3D11CoreGetLayeredDeviceSize = GetProcAddress(dll, "D3D11CoreGetLayeredDeviceSize");
        D3D11CoreRegisterLayers = GetProcAddress(dll, "D3D11CoreRegisterLayers");
        D3D11CreateDevice = GetProcAddress(dll, "D3D11CreateDevice");
        D3D11CreateDeviceAndSwapChain = GetProcAddress(dll, "D3D11CreateDeviceAndSwapChain");
        D3DKMTCloseAdapter = GetProcAddress(dll, "D3DKMTCloseAdapter");
        D3DKMTCreateAllocation = GetProcAddress(dll, "D3DKMTCreateAllocation");
        D3DKMTCreateContext = GetProcAddress(dll, "D3DKMTCreateContext");
        D3DKMTCreateDevice = GetProcAddress(dll, "D3DKMTCreateDevice");
        D3DKMTCreateSynchronizationObject = GetProcAddress(dll, "D3DKMTCreateSynchronizationObject");
        D3DKMTDestroyAllocation = GetProcAddress(dll, "D3DKMTDestroyAllocation");
        D3DKMTDestroyContext = GetProcAddress(dll, "D3DKMTDestroyContext");
        D3DKMTDestroyDevice = GetProcAddress(dll, "D3DKMTDestroyDevice");
        D3DKMTDestroySynchronizationObject = GetProcAddress(dll, "D3DKMTDestroySynchronizationObject");
        D3DKMTEscape = GetProcAddress(dll, "D3DKMTEscape");
        D3DKMTGetContextSchedulingPriority = GetProcAddress(dll, "D3DKMTGetContextSchedulingPriority");
        D3DKMTGetDeviceState = GetProcAddress(dll, "D3DKMTGetDeviceState");
        D3DKMTGetDisplayModeList = GetProcAddress(dll, "D3DKMTGetDisplayModeList");
        D3DKMTGetMultisampleMethodList = GetProcAddress(dll, "D3DKMTGetMultisampleMethodList");
        D3DKMTGetRuntimeData = GetProcAddress(dll, "D3DKMTGetRuntimeData");
        D3DKMTGetSharedPrimaryHandle = GetProcAddress(dll, "D3DKMTGetSharedPrimaryHandle");
        D3DKMTLock = GetProcAddress(dll, "D3DKMTLock");
        D3DKMTOpenAdapterFromHdc = GetProcAddress(dll, "D3DKMTOpenAdapterFromHdc");
        D3DKMTOpenResource = GetProcAddress(dll, "D3DKMTOpenResource");
        D3DKMTPresent = GetProcAddress(dll, "D3DKMTPresent");
        D3DKMTQueryAdapterInfo = GetProcAddress(dll, "D3DKMTQueryAdapterInfo");
        D3DKMTQueryAllocationResidency = GetProcAddress(dll, "D3DKMTQueryAllocationResidency");
        D3DKMTQueryResourceInfo = GetProcAddress(dll, "D3DKMTQueryResourceInfo");
        D3DKMTRender = GetProcAddress(dll, "D3DKMTRender");
        D3DKMTSetAllocationPriority = GetProcAddress(dll, "D3DKMTSetAllocationPriority");
        D3DKMTSetContextSchedulingPriority = GetProcAddress(dll, "D3DKMTSetContextSchedulingPriority");
        D3DKMTSetDisplayMode = GetProcAddress(dll, "D3DKMTSetDisplayMode");
        D3DKMTSetDisplayPrivateDriverFormat = GetProcAddress(dll, "D3DKMTSetDisplayPrivateDriverFormat");
        D3DKMTSetGammaRamp = GetProcAddress(dll, "D3DKMTSetGammaRamp");
        D3DKMTSetVidPnSourceOwner = GetProcAddress(dll, "D3DKMTSetVidPnSourceOwner");
        D3DKMTSignalSynchronizationObject = GetProcAddress(dll, "D3DKMTSignalSynchronizationObject");
        D3DKMTUnlock = GetProcAddress(dll, "D3DKMTUnlock");
        D3DKMTWaitForSynchronizationObject = GetProcAddress(dll, "D3DKMTWaitForSynchronizationObject");
        D3DKMTWaitForVerticalBlankEvent = GetProcAddress(dll, "D3DKMTWaitForVerticalBlankEvent");
        D3DPerformance_BeginEvent = GetProcAddress(dll, "D3DPerformance_BeginEvent");
        D3DPerformance_EndEvent = GetProcAddress(dll, "D3DPerformance_EndEvent");
        D3DPerformance_GetStatus = GetProcAddress(dll, "D3DPerformance_GetStatus");
        D3DPerformance_SetMarker = GetProcAddress(dll, "D3DPerformance_SetMarker");
        EnableFeatureLevelUpgrade = GetProcAddress(dll, "EnableFeatureLevelUpgrade");
        OpenAdapter10 = GetProcAddress(dll, "OpenAdapter10");
        OpenAdapter10_2 = GetProcAddress(dll, "OpenAdapter10_2");
    }
} d3d11;

struct ddraw_dll
{
    HMODULE dll;
    FARPROC AcquireDDThreadLock;
    FARPROC CompleteCreateSysmemSurface;
    FARPROC D3DParseUnknownCommand;
    FARPROC DDGetAttachedSurfaceLcl;
    FARPROC DDInternalLock;
    FARPROC DDInternalUnlock;
    FARPROC DSoundHelp;
    FARPROC DirectDrawCreate;
    FARPROC DirectDrawCreateClipper;
    FARPROC DirectDrawCreateEx;
    FARPROC DirectDrawEnumerateA;
    FARPROC DirectDrawEnumerateExA;
    FARPROC DirectDrawEnumerateExW;
    FARPROC DirectDrawEnumerateW;
    FARPROC GetDDSurfaceLocal;
    FARPROC GetOLEThunkData;
    FARPROC GetSurfaceFromDC;
    FARPROC RegisterSpecialCase;
    FARPROC ReleaseDDThreadLock;
    FARPROC SetAppCompatData;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        AcquireDDThreadLock = GetProcAddress(dll, "AcquireDDThreadLock");
        CompleteCreateSysmemSurface = GetProcAddress(dll, "CompleteCreateSysmemSurface");
        D3DParseUnknownCommand = GetProcAddress(dll, "D3DParseUnknownCommand");
        DDGetAttachedSurfaceLcl = GetProcAddress(dll, "DDGetAttachedSurfaceLcl");
        DDInternalLock = GetProcAddress(dll, "DDInternalLock");
        DDInternalUnlock = GetProcAddress(dll, "DDInternalUnlock");
        DSoundHelp = GetProcAddress(dll, "DSoundHelp");
        DirectDrawCreate = GetProcAddress(dll, "DirectDrawCreate");
        DirectDrawCreateClipper = GetProcAddress(dll, "DirectDrawCreateClipper");
        DirectDrawCreateEx = GetProcAddress(dll, "DirectDrawCreateEx");
        DirectDrawEnumerateA = GetProcAddress(dll, "DirectDrawEnumerateA");
        DirectDrawEnumerateExA = GetProcAddress(dll, "DirectDrawEnumerateExA");
        DirectDrawEnumerateExW = GetProcAddress(dll, "DirectDrawEnumerateExW");
        DirectDrawEnumerateW = GetProcAddress(dll, "DirectDrawEnumerateW");
        GetDDSurfaceLocal = GetProcAddress(dll, "GetDDSurfaceLocal");
        GetOLEThunkData = GetProcAddress(dll, "GetOLEThunkData");
        GetSurfaceFromDC = GetProcAddress(dll, "GetSurfaceFromDC");
        RegisterSpecialCase = GetProcAddress(dll, "RegisterSpecialCase");
        ReleaseDDThreadLock = GetProcAddress(dll, "ReleaseDDThreadLock");
        SetAppCompatData = GetProcAddress(dll, "SetAppCompatData");
    }
} ddraw;

#undef PlaySound
struct winmmbase_dll
{
    HMODULE dll;
    FARPROC CloseDriver;
    FARPROC DefDriverProc;
    FARPROC DriverCallback;
    FARPROC DrvGetModuleHandle;
    FARPROC GetDriverModuleHandle;
    FARPROC NotifyCallbackData;
    FARPROC OpenDriver;
    FARPROC PlaySound;
    FARPROC PlaySoundA;
    FARPROC PlaySoundW;
    FARPROC SendDriverMessage;
    FARPROC WOW32DriverCallback;
    FARPROC WOW32ResolveMultiMediaHandle;
    FARPROC WOWAppExit;
    FARPROC aux32Message;
    FARPROC auxGetDevCapsA;
    FARPROC auxGetDevCapsW;
    FARPROC auxGetNumDevs;
    FARPROC auxGetVolume;
    FARPROC auxOutMessage;
    FARPROC auxSetVolume;
    FARPROC joy32Message;
    FARPROC joyConfigChanged;
    FARPROC joyGetDevCapsA;
    FARPROC joyGetDevCapsW;
    FARPROC joyGetNumDevs;
    FARPROC joyGetPos;
    FARPROC joyGetPosEx;
    FARPROC joyGetThreshold;
    FARPROC joyReleaseCapture;
    FARPROC joySetCapture;
    FARPROC joySetThreshold;
    FARPROC mci32Message;
    FARPROC mciDriverNotify;
    FARPROC mciDriverYield;
    FARPROC mciExecute;
    FARPROC mciFreeCommandResource;
    FARPROC mciGetCreatorTask;
    FARPROC mciGetDeviceIDA;
    FARPROC mciGetDeviceIDFromElementIDA;
    FARPROC mciGetDeviceIDFromElementIDW;
    FARPROC mciGetDeviceIDW;
    FARPROC mciGetDriverData;
    FARPROC mciGetErrorStringA;
    FARPROC mciGetErrorStringW;
    FARPROC mciGetYieldProc;
    FARPROC mciLoadCommandResource;
    FARPROC mciSendCommandA;
    FARPROC mciSendCommandW;
    FARPROC mciSendStringA;
    FARPROC mciSendStringW;
    FARPROC mciSetDriverData;
    FARPROC mciSetYieldProc;
    FARPROC mid32Message;
    FARPROC midiConnect;
    FARPROC midiDisconnect;
    FARPROC midiInAddBuffer;
    FARPROC midiInClose;
    FARPROC midiInGetDevCapsA;
    FARPROC midiInGetDevCapsW;
    FARPROC midiInGetErrorTextA;
    FARPROC midiInGetErrorTextW;
    FARPROC midiInGetID;
    FARPROC midiInGetNumDevs;
    FARPROC midiInMessage;
    FARPROC midiInOpen;
    FARPROC midiInPrepareHeader;
    FARPROC midiInReset;
    FARPROC midiInStart;
    FARPROC midiInStop;
    FARPROC midiInUnprepareHeader;
    FARPROC midiOutCacheDrumPatches;
    FARPROC midiOutCachePatches;
    FARPROC midiOutClose;
    FARPROC midiOutGetDevCapsA;
    FARPROC midiOutGetDevCapsW;
    FARPROC midiOutGetErrorTextA;
    FARPROC midiOutGetErrorTextW;
    FARPROC midiOutGetID;
    FARPROC midiOutGetNumDevs;
    FARPROC midiOutGetVolume;
    FARPROC midiOutLongMsg;
    FARPROC midiOutMessage;
    FARPROC midiOutOpen;
    FARPROC midiOutPrepareHeader;
    FARPROC midiOutReset;
    FARPROC midiOutSetVolume;
    FARPROC midiOutShortMsg;
    FARPROC midiOutUnprepareHeader;
    FARPROC midiStreamClose;
    FARPROC midiStreamOpen;
    FARPROC midiStreamOut;
    FARPROC midiStreamPause;
    FARPROC midiStreamPosition;
    FARPROC midiStreamProperty;
    FARPROC midiStreamRestart;
    FARPROC midiStreamStop;
    FARPROC mixerClose;
    FARPROC mixerGetControlDetailsA;
    FARPROC mixerGetControlDetailsW;
    FARPROC mixerGetDevCapsA;
    FARPROC mixerGetDevCapsW;
    FARPROC mixerGetID;
    FARPROC mixerGetLineControlsA;
    FARPROC mixerGetLineControlsW;
    FARPROC mixerGetLineInfoA;
    FARPROC mixerGetLineInfoW;
    FARPROC mixerGetNumDevs;
    FARPROC mixerMessage;
    FARPROC mixerOpen;
    FARPROC mixerSetControlDetails;
    FARPROC mmDrvInstall;
    FARPROC mmGetCurrentTask;
    FARPROC mmTaskBlock;
    FARPROC mmTaskCreate;
    FARPROC mmTaskSignal;
    FARPROC mmTaskYield;
    FARPROC mmioAdvance;
    FARPROC mmioAscend;
    FARPROC mmioClose;
    FARPROC mmioCreateChunk;
    FARPROC mmioDescend;
    FARPROC mmioFlush;
    FARPROC mmioGetInfo;
    FARPROC mmioInstallIOProcA;
    FARPROC mmioInstallIOProcW;
    FARPROC mmioOpenA;
    FARPROC mmioOpenW;
    FARPROC mmioRead;
    FARPROC mmioRenameA;
    FARPROC mmioRenameW;
    FARPROC mmioSeek;
    FARPROC mmioSendMessage;
    FARPROC mmioSetBuffer;
    FARPROC mmioSetInfo;
    FARPROC mmioStringToFOURCCA;
    FARPROC mmioStringToFOURCCW;
    FARPROC mmioWrite;
    FARPROC mmsystemGetVersion;
    FARPROC mod32Message;
    FARPROC mxd32Message;
    FARPROC sndPlaySoundA;
    FARPROC sndPlaySoundW;
    FARPROC tid32Message;
    FARPROC timeBeginPeriod;
    FARPROC timeEndPeriod;
    FARPROC timeGetDevCaps;
    FARPROC timeGetSystemTime;
    FARPROC timeGetTime;
    FARPROC timeKillEvent;
    FARPROC timeSetEvent;
    FARPROC waveInAddBuffer;
    FARPROC waveInClose;
    FARPROC waveInGetDevCapsA;
    FARPROC waveInGetDevCapsW;
    FARPROC waveInGetErrorTextA;
    FARPROC waveInGetErrorTextW;
    FARPROC waveInGetID;
    FARPROC waveInGetNumDevs;
    FARPROC waveInGetPosition;
    FARPROC waveInMessage;
    FARPROC waveInOpen;
    FARPROC waveInPrepareHeader;
    FARPROC waveInReset;
    FARPROC waveInStart;
    FARPROC waveInStop;
    FARPROC waveInUnprepareHeader;
    FARPROC waveOutBreakLoop;
    FARPROC waveOutClose;
    FARPROC waveOutGetDevCapsA;
    FARPROC waveOutGetDevCapsW;
    FARPROC waveOutGetErrorTextA;
    FARPROC waveOutGetErrorTextW;
    FARPROC waveOutGetID;
    FARPROC waveOutGetNumDevs;
    FARPROC waveOutGetPitch;
    FARPROC waveOutGetPlaybackRate;
    FARPROC waveOutGetPosition;
    FARPROC waveOutGetVolume;
    FARPROC waveOutMessage;
    FARPROC waveOutOpen;
    FARPROC waveOutPause;
    FARPROC waveOutPrepareHeader;
    FARPROC waveOutReset;
    FARPROC waveOutRestart;
    FARPROC waveOutSetPitch;
    FARPROC waveOutSetPlaybackRate;
    FARPROC waveOutSetVolume;
    FARPROC waveOutUnprepareHeader;
    FARPROC waveOutWrite;
    FARPROC wid32Message;
    FARPROC wod32Message;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        CloseDriver = GetProcAddress(dll, "CloseDriver");
        DefDriverProc = GetProcAddress(dll, "DefDriverProc");
        DriverCallback = GetProcAddress(dll, "DriverCallback");
        DrvGetModuleHandle = GetProcAddress(dll, "DrvGetModuleHandle");
        GetDriverModuleHandle = GetProcAddress(dll, "GetDriverModuleHandle");
        NotifyCallbackData = GetProcAddress(dll, "NotifyCallbackData");
        OpenDriver = GetProcAddress(dll, "OpenDriver");
        PlaySound = GetProcAddress(dll, "PlaySound");
        PlaySoundA = GetProcAddress(dll, "PlaySoundA");
        PlaySoundW = GetProcAddress(dll, "PlaySoundW");
        SendDriverMessage = GetProcAddress(dll, "SendDriverMessage");
        WOW32DriverCallback = GetProcAddress(dll, "WOW32DriverCallback");
        WOW32ResolveMultiMediaHandle = GetProcAddress(dll, "WOW32ResolveMultiMediaHandle");
        WOWAppExit = GetProcAddress(dll, "WOWAppExit");
        aux32Message = GetProcAddress(dll, "aux32Message");
        auxGetDevCapsA = GetProcAddress(dll, "auxGetDevCapsA");
        auxGetDevCapsW = GetProcAddress(dll, "auxGetDevCapsW");
        auxGetNumDevs = GetProcAddress(dll, "auxGetNumDevs");
        auxGetVolume = GetProcAddress(dll, "auxGetVolume");
        auxOutMessage = GetProcAddress(dll, "auxOutMessage");
        auxSetVolume = GetProcAddress(dll, "auxSetVolume");
        joy32Message = GetProcAddress(dll, "joy32Message");
        joyConfigChanged = GetProcAddress(dll, "joyConfigChanged");
        joyGetDevCapsA = GetProcAddress(dll, "joyGetDevCapsA");
        joyGetDevCapsW = GetProcAddress(dll, "joyGetDevCapsW");
        joyGetNumDevs = GetProcAddress(dll, "joyGetNumDevs");
        joyGetPos = GetProcAddress(dll, "joyGetPos");
        joyGetPosEx = GetProcAddress(dll, "joyGetPosEx");
        joyGetThreshold = GetProcAddress(dll, "joyGetThreshold");
        joyReleaseCapture = GetProcAddress(dll, "joyReleaseCapture");
        joySetCapture = GetProcAddress(dll, "joySetCapture");
        joySetThreshold = GetProcAddress(dll, "joySetThreshold");
        mci32Message = GetProcAddress(dll, "mci32Message");
        mciDriverNotify = GetProcAddress(dll, "mciDriverNotify");
        mciDriverYield = GetProcAddress(dll, "mciDriverYield");
        mciExecute = GetProcAddress(dll, "mciExecute");
        mciFreeCommandResource = GetProcAddress(dll, "mciFreeCommandResource");
        mciGetCreatorTask = GetProcAddress(dll, "mciGetCreatorTask");
        mciGetDeviceIDA = GetProcAddress(dll, "mciGetDeviceIDA");
        mciGetDeviceIDFromElementIDA = GetProcAddress(dll, "mciGetDeviceIDFromElementIDA");
        mciGetDeviceIDFromElementIDW = GetProcAddress(dll, "mciGetDeviceIDFromElementIDW");
        mciGetDeviceIDW = GetProcAddress(dll, "mciGetDeviceIDW");
        mciGetDriverData = GetProcAddress(dll, "mciGetDriverData");
        mciGetErrorStringA = GetProcAddress(dll, "mciGetErrorStringA");
        mciGetErrorStringW = GetProcAddress(dll, "mciGetErrorStringW");
        mciGetYieldProc = GetProcAddress(dll, "mciGetYieldProc");
        mciLoadCommandResource = GetProcAddress(dll, "mciLoadCommandResource");
        mciSendCommandA = GetProcAddress(dll, "mciSendCommandA");
        mciSendCommandW = GetProcAddress(dll, "mciSendCommandW");
        mciSendStringA = GetProcAddress(dll, "mciSendStringA");
        mciSendStringW = GetProcAddress(dll, "mciSendStringW");
        mciSetDriverData = GetProcAddress(dll, "mciSetDriverData");
        mciSetYieldProc = GetProcAddress(dll, "mciSetYieldProc");
        mid32Message = GetProcAddress(dll, "mid32Message");
        midiConnect = GetProcAddress(dll, "midiConnect");
        midiDisconnect = GetProcAddress(dll, "midiDisconnect");
        midiInAddBuffer = GetProcAddress(dll, "midiInAddBuffer");
        midiInClose = GetProcAddress(dll, "midiInClose");
        midiInGetDevCapsA = GetProcAddress(dll, "midiInGetDevCapsA");
        midiInGetDevCapsW = GetProcAddress(dll, "midiInGetDevCapsW");
        midiInGetErrorTextA = GetProcAddress(dll, "midiInGetErrorTextA");
        midiInGetErrorTextW = GetProcAddress(dll, "midiInGetErrorTextW");
        midiInGetID = GetProcAddress(dll, "midiInGetID");
        midiInGetNumDevs = GetProcAddress(dll, "midiInGetNumDevs");
        midiInMessage = GetProcAddress(dll, "midiInMessage");
        midiInOpen = GetProcAddress(dll, "midiInOpen");
        midiInPrepareHeader = GetProcAddress(dll, "midiInPrepareHeader");
        midiInReset = GetProcAddress(dll, "midiInReset");
        midiInStart = GetProcAddress(dll, "midiInStart");
        midiInStop = GetProcAddress(dll, "midiInStop");
        midiInUnprepareHeader = GetProcAddress(dll, "midiInUnprepareHeader");
        midiOutCacheDrumPatches = GetProcAddress(dll, "midiOutCacheDrumPatches");
        midiOutCachePatches = GetProcAddress(dll, "midiOutCachePatches");
        midiOutClose = GetProcAddress(dll, "midiOutClose");
        midiOutGetDevCapsA = GetProcAddress(dll, "midiOutGetDevCapsA");
        midiOutGetDevCapsW = GetProcAddress(dll, "midiOutGetDevCapsW");
        midiOutGetErrorTextA = GetProcAddress(dll, "midiOutGetErrorTextA");
        midiOutGetErrorTextW = GetProcAddress(dll, "midiOutGetErrorTextW");
        midiOutGetID = GetProcAddress(dll, "midiOutGetID");
        midiOutGetNumDevs = GetProcAddress(dll, "midiOutGetNumDevs");
        midiOutGetVolume = GetProcAddress(dll, "midiOutGetVolume");
        midiOutLongMsg = GetProcAddress(dll, "midiOutLongMsg");
        midiOutMessage = GetProcAddress(dll, "midiOutMessage");
        midiOutOpen = GetProcAddress(dll, "midiOutOpen");
        midiOutPrepareHeader = GetProcAddress(dll, "midiOutPrepareHeader");
        midiOutReset = GetProcAddress(dll, "midiOutReset");
        midiOutSetVolume = GetProcAddress(dll, "midiOutSetVolume");
        midiOutShortMsg = GetProcAddress(dll, "midiOutShortMsg");
        midiOutUnprepareHeader = GetProcAddress(dll, "midiOutUnprepareHeader");
        midiStreamClose = GetProcAddress(dll, "midiStreamClose");
        midiStreamOpen = GetProcAddress(dll, "midiStreamOpen");
        midiStreamOut = GetProcAddress(dll, "midiStreamOut");
        midiStreamPause = GetProcAddress(dll, "midiStreamPause");
        midiStreamPosition = GetProcAddress(dll, "midiStreamPosition");
        midiStreamProperty = GetProcAddress(dll, "midiStreamProperty");
        midiStreamRestart = GetProcAddress(dll, "midiStreamRestart");
        midiStreamStop = GetProcAddress(dll, "midiStreamStop");
        mixerClose = GetProcAddress(dll, "mixerClose");
        mixerGetControlDetailsA = GetProcAddress(dll, "mixerGetControlDetailsA");
        mixerGetControlDetailsW = GetProcAddress(dll, "mixerGetControlDetailsW");
        mixerGetDevCapsA = GetProcAddress(dll, "mixerGetDevCapsA");
        mixerGetDevCapsW = GetProcAddress(dll, "mixerGetDevCapsW");
        mixerGetID = GetProcAddress(dll, "mixerGetID");
        mixerGetLineControlsA = GetProcAddress(dll, "mixerGetLineControlsA");
        mixerGetLineControlsW = GetProcAddress(dll, "mixerGetLineControlsW");
        mixerGetLineInfoA = GetProcAddress(dll, "mixerGetLineInfoA");
        mixerGetLineInfoW = GetProcAddress(dll, "mixerGetLineInfoW");
        mixerGetNumDevs = GetProcAddress(dll, "mixerGetNumDevs");
        mixerMessage = GetProcAddress(dll, "mixerMessage");
        mixerOpen = GetProcAddress(dll, "mixerOpen");
        mixerSetControlDetails = GetProcAddress(dll, "mixerSetControlDetails");
        mmDrvInstall = GetProcAddress(dll, "mmDrvInstall");
        mmGetCurrentTask = GetProcAddress(dll, "mmGetCurrentTask");
        mmTaskBlock = GetProcAddress(dll, "mmTaskBlock");
        mmTaskCreate = GetProcAddress(dll, "mmTaskCreate");
        mmTaskSignal = GetProcAddress(dll, "mmTaskSignal");
        mmTaskYield = GetProcAddress(dll, "mmTaskYield");
        mmioAdvance = GetProcAddress(dll, "mmioAdvance");
        mmioAscend = GetProcAddress(dll, "mmioAscend");
        mmioClose = GetProcAddress(dll, "mmioClose");
        mmioCreateChunk = GetProcAddress(dll, "mmioCreateChunk");
        mmioDescend = GetProcAddress(dll, "mmioDescend");
        mmioFlush = GetProcAddress(dll, "mmioFlush");
        mmioGetInfo = GetProcAddress(dll, "mmioGetInfo");
        mmioInstallIOProcA = GetProcAddress(dll, "mmioInstallIOProcA");
        mmioInstallIOProcW = GetProcAddress(dll, "mmioInstallIOProcW");
        mmioOpenA = GetProcAddress(dll, "mmioOpenA");
        mmioOpenW = GetProcAddress(dll, "mmioOpenW");
        mmioRead = GetProcAddress(dll, "mmioRead");
        mmioRenameA = GetProcAddress(dll, "mmioRenameA");
        mmioRenameW = GetProcAddress(dll, "mmioRenameW");
        mmioSeek = GetProcAddress(dll, "mmioSeek");
        mmioSendMessage = GetProcAddress(dll, "mmioSendMessage");
        mmioSetBuffer = GetProcAddress(dll, "mmioSetBuffer");
        mmioSetInfo = GetProcAddress(dll, "mmioSetInfo");
        mmioStringToFOURCCA = GetProcAddress(dll, "mmioStringToFOURCCA");
        mmioStringToFOURCCW = GetProcAddress(dll, "mmioStringToFOURCCW");
        mmioWrite = GetProcAddress(dll, "mmioWrite");
        mmsystemGetVersion = GetProcAddress(dll, "mmsystemGetVersion");
        mod32Message = GetProcAddress(dll, "mod32Message");
        mxd32Message = GetProcAddress(dll, "mxd32Message");
        sndPlaySoundA = GetProcAddress(dll, "sndPlaySoundA");
        sndPlaySoundW = GetProcAddress(dll, "sndPlaySoundW");
        tid32Message = GetProcAddress(dll, "tid32Message");
        timeBeginPeriod = GetProcAddress(dll, "timeBeginPeriod");
        timeEndPeriod = GetProcAddress(dll, "timeEndPeriod");
        timeGetDevCaps = GetProcAddress(dll, "timeGetDevCaps");
        timeGetSystemTime = GetProcAddress(dll, "timeGetSystemTime");
        timeGetTime = GetProcAddress(dll, "timeGetTime");
        timeKillEvent = GetProcAddress(dll, "timeKillEvent");
        timeSetEvent = GetProcAddress(dll, "timeSetEvent");
        waveInAddBuffer = GetProcAddress(dll, "waveInAddBuffer");
        waveInClose = GetProcAddress(dll, "waveInClose");
        waveInGetDevCapsA = GetProcAddress(dll, "waveInGetDevCapsA");
        waveInGetDevCapsW = GetProcAddress(dll, "waveInGetDevCapsW");
        waveInGetErrorTextA = GetProcAddress(dll, "waveInGetErrorTextA");
        waveInGetErrorTextW = GetProcAddress(dll, "waveInGetErrorTextW");
        waveInGetID = GetProcAddress(dll, "waveInGetID");
        waveInGetNumDevs = GetProcAddress(dll, "waveInGetNumDevs");
        waveInGetPosition = GetProcAddress(dll, "waveInGetPosition");
        waveInMessage = GetProcAddress(dll, "waveInMessage");
        waveInOpen = GetProcAddress(dll, "waveInOpen");
        waveInPrepareHeader = GetProcAddress(dll, "waveInPrepareHeader");
        waveInReset = GetProcAddress(dll, "waveInReset");
        waveInStart = GetProcAddress(dll, "waveInStart");
        waveInStop = GetProcAddress(dll, "waveInStop");
        waveInUnprepareHeader = GetProcAddress(dll, "waveInUnprepareHeader");
        waveOutBreakLoop = GetProcAddress(dll, "waveOutBreakLoop");
        waveOutClose = GetProcAddress(dll, "waveOutClose");
        waveOutGetDevCapsA = GetProcAddress(dll, "waveOutGetDevCapsA");
        waveOutGetDevCapsW = GetProcAddress(dll, "waveOutGetDevCapsW");
        waveOutGetErrorTextA = GetProcAddress(dll, "waveOutGetErrorTextA");
        waveOutGetErrorTextW = GetProcAddress(dll, "waveOutGetErrorTextW");
        waveOutGetID = GetProcAddress(dll, "waveOutGetID");
        waveOutGetNumDevs = GetProcAddress(dll, "waveOutGetNumDevs");
        waveOutGetPitch = GetProcAddress(dll, "waveOutGetPitch");
        waveOutGetPlaybackRate = GetProcAddress(dll, "waveOutGetPlaybackRate");
        waveOutGetPosition = GetProcAddress(dll, "waveOutGetPosition");
        waveOutGetVolume = GetProcAddress(dll, "waveOutGetVolume");
        waveOutMessage = GetProcAddress(dll, "waveOutMessage");
        waveOutOpen = GetProcAddress(dll, "waveOutOpen");
        waveOutPause = GetProcAddress(dll, "waveOutPause");
        waveOutPrepareHeader = GetProcAddress(dll, "waveOutPrepareHeader");
        waveOutReset = GetProcAddress(dll, "waveOutReset");
        waveOutRestart = GetProcAddress(dll, "waveOutRestart");
        waveOutSetPitch = GetProcAddress(dll, "waveOutSetPitch");
        waveOutSetPlaybackRate = GetProcAddress(dll, "waveOutSetPlaybackRate");
        waveOutSetVolume = GetProcAddress(dll, "waveOutSetVolume");
        waveOutUnprepareHeader = GetProcAddress(dll, "waveOutUnprepareHeader");
        waveOutWrite = GetProcAddress(dll, "waveOutWrite");
        wid32Message = GetProcAddress(dll, "wid32Message");
        wod32Message = GetProcAddress(dll, "wod32Message");
    }
} winmm;

struct msacm32_dll
{
    HMODULE dll;
    FARPROC acmDriverAddA;
    FARPROC acmDriverAddW;
    FARPROC acmDriverClose;
    FARPROC acmDriverDetailsA;
    FARPROC acmDriverDetailsW;
    FARPROC acmDriverEnum;
    FARPROC acmDriverID;
    FARPROC acmDriverMessage;
    FARPROC acmDriverOpen;
    FARPROC acmDriverPriority;
    FARPROC acmDriverRemove;
    FARPROC acmFilterChooseA;
    FARPROC acmFilterChooseW;
    FARPROC acmFilterDetailsA;
    FARPROC acmFilterDetailsW;
    FARPROC acmFilterEnumA;
    FARPROC acmFilterEnumW;
    FARPROC acmFilterTagDetailsA;
    FARPROC acmFilterTagDetailsW;
    FARPROC acmFilterTagEnumA;
    FARPROC acmFilterTagEnumW;
    FARPROC acmFormatChooseA;
    FARPROC acmFormatChooseW;
    FARPROC acmFormatDetailsA;
    FARPROC acmFormatDetailsW;
    FARPROC acmFormatEnumA;
    FARPROC acmFormatEnumW;
    FARPROC acmFormatSuggest;
    FARPROC acmFormatTagDetailsA;
    FARPROC acmFormatTagDetailsW;
    FARPROC acmFormatTagEnumA;
    FARPROC acmFormatTagEnumW;
    FARPROC acmGetVersion;
    FARPROC acmMetrics;
    FARPROC acmStreamClose;
    FARPROC acmStreamConvert;
    FARPROC acmStreamMessage;
    FARPROC acmStreamOpen;
    FARPROC acmStreamPrepareHeader;
    FARPROC acmStreamReset;
    FARPROC acmStreamSize;
    FARPROC acmStreamUnprepareHeader;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        acmDriverAddA = GetProcAddress(dll, "acmDriverAddA");
        acmDriverAddW = GetProcAddress(dll, "acmDriverAddW");
        acmDriverClose = GetProcAddress(dll, "acmDriverClose");
        acmDriverDetailsA = GetProcAddress(dll, "acmDriverDetailsA");
        acmDriverDetailsW = GetProcAddress(dll, "acmDriverDetailsW");
        acmDriverEnum = GetProcAddress(dll, "acmDriverEnum");
        acmDriverID = GetProcAddress(dll, "acmDriverID");
        acmDriverMessage = GetProcAddress(dll, "acmDriverMessage");
        acmDriverOpen = GetProcAddress(dll, "acmDriverOpen");
        acmDriverPriority = GetProcAddress(dll, "acmDriverPriority");
        acmDriverRemove = GetProcAddress(dll, "acmDriverRemove");
        acmFilterChooseA = GetProcAddress(dll, "acmFilterChooseA");
        acmFilterChooseW = GetProcAddress(dll, "acmFilterChooseW");
        acmFilterDetailsA = GetProcAddress(dll, "acmFilterDetailsA");
        acmFilterDetailsW = GetProcAddress(dll, "acmFilterDetailsW");
        acmFilterEnumA = GetProcAddress(dll, "acmFilterEnumA");
        acmFilterEnumW = GetProcAddress(dll, "acmFilterEnumW");
        acmFilterTagDetailsA = GetProcAddress(dll, "acmFilterTagDetailsA");
        acmFilterTagDetailsW = GetProcAddress(dll, "acmFilterTagDetailsW");
        acmFilterTagEnumA = GetProcAddress(dll, "acmFilterTagEnumA");
        acmFilterTagEnumW = GetProcAddress(dll, "acmFilterTagEnumW");
        acmFormatChooseA = GetProcAddress(dll, "acmFormatChooseA");
        acmFormatChooseW = GetProcAddress(dll, "acmFormatChooseW");
        acmFormatDetailsA = GetProcAddress(dll, "acmFormatDetailsA");
        acmFormatDetailsW = GetProcAddress(dll, "acmFormatDetailsW");
        acmFormatEnumA = GetProcAddress(dll, "acmFormatEnumA");
        acmFormatEnumW = GetProcAddress(dll, "acmFormatEnumW");
        acmFormatSuggest = GetProcAddress(dll, "acmFormatSuggest");
        acmFormatTagDetailsA = GetProcAddress(dll, "acmFormatTagDetailsA");
        acmFormatTagDetailsW = GetProcAddress(dll, "acmFormatTagDetailsW");
        acmFormatTagEnumA = GetProcAddress(dll, "acmFormatTagEnumA");
        acmFormatTagEnumW = GetProcAddress(dll, "acmFormatTagEnumW");
        acmGetVersion = GetProcAddress(dll, "acmGetVersion");
        acmMetrics = GetProcAddress(dll, "acmMetrics");
        acmStreamClose = GetProcAddress(dll, "acmStreamClose");
        acmStreamConvert = GetProcAddress(dll, "acmStreamConvert");
        acmStreamMessage = GetProcAddress(dll, "acmStreamMessage");
        acmStreamOpen = GetProcAddress(dll, "acmStreamOpen");
        acmStreamPrepareHeader = GetProcAddress(dll, "acmStreamPrepareHeader");
        acmStreamReset = GetProcAddress(dll, "acmStreamReset");
        acmStreamSize = GetProcAddress(dll, "acmStreamSize");
        acmStreamUnprepareHeader = GetProcAddress(dll, "acmStreamUnprepareHeader");
    }
} msacm32;

struct msvfw32_dll
{
    HMODULE dll;
    FARPROC DrawDibBegin;
    FARPROC DrawDibChangePalette;
    FARPROC DrawDibClose;
    FARPROC DrawDibDraw;
    FARPROC DrawDibEnd;
    FARPROC DrawDibGetBuffer;
    FARPROC DrawDibGetPalette;
    FARPROC DrawDibOpen;
    FARPROC DrawDibProfileDisplay;
    FARPROC DrawDibRealize;
    FARPROC DrawDibSetPalette;
    FARPROC DrawDibStart;
    FARPROC DrawDibStop;
    FARPROC DrawDibTime;
    FARPROC GetOpenFileNamePreview;
    FARPROC GetOpenFileNamePreviewA;
    FARPROC GetOpenFileNamePreviewW;
    FARPROC GetSaveFileNamePreviewA;
    FARPROC GetSaveFileNamePreviewW;
    FARPROC ICClose;
    FARPROC ICCompress;
    FARPROC ICCompressorChoose;
    FARPROC ICCompressorFree;
    FARPROC ICDecompress;
    FARPROC ICDraw;
    FARPROC ICDrawBegin;
    FARPROC ICGetDisplayFormat;
    FARPROC ICGetInfo;
    FARPROC ICImageCompress;
    FARPROC ICImageDecompress;
    FARPROC ICInfo;
    FARPROC ICInstall;
    FARPROC ICLocate;
    FARPROC ICMThunk32;
    FARPROC ICOpen;
    FARPROC ICOpenFunction;
    FARPROC ICRemove;
    FARPROC ICSendMessage;
    FARPROC ICSeqCompressFrame;
    FARPROC ICSeqCompressFrameEnd;
    FARPROC ICSeqCompressFrameStart;
    FARPROC MCIWndCreate;
    FARPROC MCIWndCreateA;
    FARPROC MCIWndCreateW;
    FARPROC MCIWndRegisterClass;
    FARPROC StretchDIB;
    FARPROC VideoForWindowsVersion;

    void LoadOriginalLibrary(HMODULE module)
    {
        dll = module;
        shared.LoadOriginalLibrary(dll);
        DrawDibBegin = GetProcAddress(dll, "DrawDibBegin");
        DrawDibChangePalette = GetProcAddress(dll, "DrawDibChangePalette");
        DrawDibClose = GetProcAddress(dll, "DrawDibClose");
        DrawDibDraw = GetProcAddress(dll, "DrawDibDraw");
        DrawDibEnd = GetProcAddress(dll, "DrawDibEnd");
        DrawDibGetBuffer = GetProcAddress(dll, "DrawDibGetBuffer");
        DrawDibGetPalette = GetProcAddress(dll, "DrawDibGetPalette");
        DrawDibOpen = GetProcAddress(dll, "DrawDibOpen");
        DrawDibProfileDisplay = GetProcAddress(dll, "DrawDibProfileDisplay");
        DrawDibRealize = GetProcAddress(dll, "DrawDibRealize");
        DrawDibSetPalette = GetProcAddress(dll, "DrawDibSetPalette");
        DrawDibStart = GetProcAddress(dll, "DrawDibStart");
        DrawDibStop = GetProcAddress(dll, "DrawDibStop");
        DrawDibTime = GetProcAddress(dll, "DrawDibTime");
        GetOpenFileNamePreview = GetProcAddress(dll, "GetOpenFileNamePreview");
        GetOpenFileNamePreviewA = GetProcAddress(dll, "GetOpenFileNamePreviewA");
        GetOpenFileNamePreviewW = GetProcAddress(dll, "GetOpenFileNamePreviewW");
        GetSaveFileNamePreviewA = GetProcAddress(dll, "GetSaveFileNamePreviewA");
        GetSaveFileNamePreviewW = GetProcAddress(dll, "GetSaveFileNamePreviewW");
        ICClose = GetProcAddress(dll, "ICClose");
        ICCompress = GetProcAddress(dll, "ICCompress");
        ICCompressorChoose = GetProcAddress(dll, "ICCompressorChoose");
        ICCompressorFree = GetProcAddress(dll, "ICCompressorFree");
        ICDecompress = GetProcAddress(dll, "ICDecompress");
        ICDraw = GetProcAddress(dll, "ICDraw");
        ICDrawBegin = GetProcAddress(dll, "ICDrawBegin");
        ICGetDisplayFormat = GetProcAddress(dll, "ICGetDisplayFormat");
        ICGetInfo = GetProcAddress(dll, "ICGetInfo");
        ICImageCompress = GetProcAddress(dll, "ICImageCompress");
        ICImageDecompress = GetProcAddress(dll, "ICImageDecompress");
        ICInfo = GetProcAddress(dll, "ICInfo");
        ICInstall = GetProcAddress(dll, "ICInstall");
        ICLocate = GetProcAddress(dll, "ICLocate");
        ICMThunk32 = GetProcAddress(dll, "ICMThunk32");
        ICOpen = GetProcAddress(dll, "ICOpen");
        ICOpenFunction = GetProcAddress(dll, "ICOpenFunction");
        ICRemove = GetProcAddress(dll, "ICRemove");
        ICSendMessage = GetProcAddress(dll, "ICSendMessage");
        ICSeqCompressFrame = GetProcAddress(dll, "ICSeqCompressFrame");
        ICSeqCompressFrameEnd = GetProcAddress(dll, "ICSeqCompressFrameEnd");
        ICSeqCompressFrameStart = GetProcAddress(dll, "ICSeqCompressFrameStart");
        MCIWndCreate = GetProcAddress(dll, "MCIWndCreate");
        MCIWndCreateA = GetProcAddress(dll, "MCIWndCreateA");
        MCIWndCreateW = GetProcAddress(dll, "MCIWndCreateW");
        MCIWndRegisterClass = GetProcAddress(dll, "MCIWndRegisterClass");
        StretchDIB = GetProcAddress(dll, "StretchDIB");
        VideoForWindowsVersion = GetProcAddress(dll, "VideoForWindowsVersion");
    }
} msvfw32;

struct binkw32_dll
{
    HMEMORYMODULE dll;
    FARPROC BinkBufferBlit;
    FARPROC BinkBufferCheckWinPos;
    FARPROC BinkBufferClear;
    FARPROC BinkBufferClose;
    FARPROC BinkBufferGetDescription;
    FARPROC BinkBufferGetError;
    FARPROC BinkBufferLock;
    FARPROC BinkBufferOpen;
    FARPROC BinkBufferSetDirectDraw;
    FARPROC BinkBufferSetHWND;
    FARPROC BinkBufferSetOffset;
    FARPROC BinkBufferSetResolution;
    FARPROC BinkBufferSetScale;
    FARPROC BinkBufferUnlock;
    FARPROC BinkCheckCursor;
    FARPROC BinkClose;
    FARPROC BinkCloseTrack;
    FARPROC BinkControlBackgroundIO;
    FARPROC BinkControlPlatformFeatures;
    FARPROC BinkCopyToBuffer;
    FARPROC BinkCopyToBufferRect;
    FARPROC BinkDDSurfaceType;
    FARPROC BinkDX8SurfaceType;
    FARPROC BinkDX9SurfaceType;
    FARPROC BinkDoFrame;
    FARPROC BinkDoFrameAsync;
    FARPROC BinkDoFrameAsyncWait;
    FARPROC BinkDoFramePlane;
    FARPROC BinkFreeGlobals;
    FARPROC BinkGetError;
    FARPROC BinkGetFrameBuffersInfo;
    FARPROC BinkGetKeyFrame;
    FARPROC BinkGetPalette;
    FARPROC BinkGetPlatformInfo;
    FARPROC BinkGetRealtime;
    FARPROC BinkGetRects;
    FARPROC BinkGetSummary;
    FARPROC BinkGetTrackData;
    FARPROC BinkGetTrackID;
    FARPROC BinkGetTrackMaxSize;
    FARPROC BinkGetTrackType;
    FARPROC BinkGoto;
    FARPROC BinkIsSoftwareCursor;
    FARPROC BinkLogoAddress;
    FARPROC BinkNextFrame;
    FARPROC BinkOpen;
    FARPROC BinkOpenDirectSound;
    FARPROC BinkOpenMiles;
    FARPROC BinkOpenTrack;
    FARPROC BinkOpenWaveOut;
    FARPROC BinkOpenWithOptions;
    FARPROC BinkOpenXAudio2;
    FARPROC BinkPause;
    FARPROC BinkRegisterFrameBuffers;
    FARPROC BinkRequestStopAsyncThread;
    FARPROC BinkRestoreCursor;
    FARPROC BinkService;
    FARPROC BinkServiceSound;
    FARPROC BinkSetError;
    FARPROC BinkSetFileOffset;
    FARPROC BinkSetFrameRate;
    FARPROC BinkSetIO;
    FARPROC BinkSetIOSize;
    FARPROC BinkSetMemory;
    FARPROC BinkSetMixBinVolumes;
    FARPROC BinkSetMixBins;
    FARPROC BinkSetPan;
    FARPROC BinkSetSimulate;
    FARPROC BinkSetSoundOnOff;
    FARPROC BinkSetSoundSystem;
    FARPROC BinkSetSoundTrack;
    FARPROC BinkSetSpeakerVolumes;
    FARPROC BinkSetVideoOnOff;
    FARPROC BinkSetVolume;
    FARPROC BinkSetWillLoop;
    FARPROC BinkShouldSkip;
    FARPROC BinkStartAsyncThread;
    FARPROC BinkUseTelemetry;
    FARPROC BinkUseTmLite;
    FARPROC BinkWait;
    FARPROC BinkWaitStopAsyncThread;
    FARPROC RADSetMemory;
    FARPROC RADTimerRead;
    FARPROC YUV_blit_16a1bpp40;
    FARPROC YUV_blit_16a1bpp52;
    FARPROC YUV_blit_16a1bpp_mask48;
    FARPROC YUV_blit_16a1bpp_mask60;
    FARPROC YUV_blit_16a4bpp40;
    FARPROC YUV_blit_16a4bpp52;
    FARPROC YUV_blit_16a4bpp_mask48;
    FARPROC YUV_blit_16a4bpp_mask60;
    FARPROC YUV_blit_16bpp40;
    FARPROC YUV_blit_16bpp48;
    FARPROC YUV_blit_16bpp52;
    FARPROC YUV_blit_16bpp_mask48;
    FARPROC YUV_blit_16bpp_mask56;
    FARPROC YUV_blit_16bpp_mask60;
    FARPROC YUV_blit_24bpp40;
    FARPROC YUV_blit_24bpp48;
    FARPROC YUV_blit_24bpp52;
    FARPROC YUV_blit_24bpp_mask48;
    FARPROC YUV_blit_24bpp_mask56;
    FARPROC YUV_blit_24bpp_mask60;
    FARPROC YUV_blit_24rbpp40;
    FARPROC YUV_blit_24rbpp48;
    FARPROC YUV_blit_24rbpp52;
    FARPROC YUV_blit_24rbpp_mask48;
    FARPROC YUV_blit_24rbpp_mask56;
    FARPROC YUV_blit_24rbpp_mask60;
    FARPROC YUV_blit_32abpp40;
    FARPROC YUV_blit_32abpp52;
    FARPROC YUV_blit_32abpp_mask48;
    FARPROC YUV_blit_32abpp_mask60;
    FARPROC YUV_blit_32bpp40;
    FARPROC YUV_blit_32bpp48;
    FARPROC YUV_blit_32bpp52;
    FARPROC YUV_blit_32bpp_mask48;
    FARPROC YUV_blit_32bpp_mask56;
    FARPROC YUV_blit_32bpp_mask60;
    FARPROC YUV_blit_32rabpp40;
    FARPROC YUV_blit_32rabpp52;
    FARPROC YUV_blit_32rabpp_mask48;
    FARPROC YUV_blit_32rabpp_mask60;
    FARPROC YUV_blit_32rbpp40;
    FARPROC YUV_blit_32rbpp48;
    FARPROC YUV_blit_32rbpp52;
    FARPROC YUV_blit_32rbpp_mask48;
    FARPROC YUV_blit_32rbpp_mask56;
    FARPROC YUV_blit_32rbpp_mask60;
    FARPROC YUV_blit_UYVY40;
    FARPROC YUV_blit_UYVY48;
    FARPROC YUV_blit_UYVY52;
    FARPROC YUV_blit_UYVY_mask48;
    FARPROC YUV_blit_UYVY_mask56;
    FARPROC YUV_blit_UYVY_mask60;
    FARPROC YUV_blit_YUY240;
    FARPROC YUV_blit_YUY248;
    FARPROC YUV_blit_YUY252;
    FARPROC YUV_blit_YUY2_mask48;
    FARPROC YUV_blit_YUY2_mask56;
    FARPROC YUV_blit_YUY2_mask60;
    FARPROC YUV_blit_YV1244;
    FARPROC YUV_blit_YV1252;
    FARPROC YUV_blit_YV1256;
    FARPROC YUV_init4;
    FARPROC radfree;
    FARPROC radmalloc;

    void LoadOriginalLibrary(HMEMORYMODULE module, bool bIsMemory)
    {
        dll = module;

        auto AutoGetProcAddress = [&bIsMemory](HMEMORYMODULE lib, LPCSTR s) -> FARPROC
        {
            if (bIsMemory)
                return MemoryGetProcAddress(lib, s);
            else
                return GetProcAddress((HMODULE)lib, s);
        };

        BinkBufferBlit = AutoGetProcAddress(dll, "_BinkBufferBlit@12");
        BinkBufferCheckWinPos = AutoGetProcAddress(dll, "_BinkBufferCheckWinPos@12");
        BinkBufferClear = AutoGetProcAddress(dll, "_BinkBufferClear@8");
        BinkBufferClose = AutoGetProcAddress(dll, "_BinkBufferClose@4");
        BinkBufferGetDescription = AutoGetProcAddress(dll, "_BinkBufferGetDescription@4");
        BinkBufferGetError = AutoGetProcAddress(dll, "_BinkBufferGetError@0");
        BinkBufferLock = AutoGetProcAddress(dll, "_BinkBufferLock@4");
        BinkBufferOpen = AutoGetProcAddress(dll, "_BinkBufferOpen@16");
        BinkBufferSetDirectDraw = AutoGetProcAddress(dll, "_BinkBufferSetDirectDraw@8");
        BinkBufferSetHWND = AutoGetProcAddress(dll, "_BinkBufferSetHWND@8");
        BinkBufferSetOffset = AutoGetProcAddress(dll, "_BinkBufferSetOffset@12");
        BinkBufferSetResolution = AutoGetProcAddress(dll, "_BinkBufferSetResolution@12");
        BinkBufferSetScale = AutoGetProcAddress(dll, "_BinkBufferSetScale@12");
        BinkBufferUnlock = AutoGetProcAddress(dll, "_BinkBufferUnlock@4");
        BinkCheckCursor = AutoGetProcAddress(dll, "_BinkCheckCursor@20");
        BinkClose = AutoGetProcAddress(dll, "_BinkClose@4");
        BinkCloseTrack = AutoGetProcAddress(dll, "_BinkCloseTrack@4");
        BinkControlBackgroundIO = AutoGetProcAddress(dll, "_BinkControlBackgroundIO@8");
        BinkControlPlatformFeatures = AutoGetProcAddress(dll, "_BinkControlPlatformFeatures@8");
        BinkCopyToBuffer = AutoGetProcAddress(dll, "_BinkCopyToBuffer@28");
        BinkCopyToBufferRect = AutoGetProcAddress(dll, "_BinkCopyToBufferRect@44");
        BinkDDSurfaceType = AutoGetProcAddress(dll, "_BinkDDSurfaceType@4");
        BinkDX8SurfaceType = AutoGetProcAddress(dll, "_BinkDX8SurfaceType@4");
        BinkDX9SurfaceType = AutoGetProcAddress(dll, "_BinkDX9SurfaceType@4");
        BinkDoFrame = AutoGetProcAddress(dll, "_BinkDoFrame@4");
        BinkDoFrameAsync = AutoGetProcAddress(dll, "_BinkDoFrameAsync@12");
        BinkDoFrameAsyncWait = AutoGetProcAddress(dll, "_BinkDoFrameAsyncWait@8");
        BinkDoFramePlane = AutoGetProcAddress(dll, "_BinkDoFramePlane@8");
        BinkFreeGlobals = AutoGetProcAddress(dll, "_BinkFreeGlobals@0");
        BinkGetError = AutoGetProcAddress(dll, "_BinkGetError@0");
        BinkGetFrameBuffersInfo = AutoGetProcAddress(dll, "_BinkGetFrameBuffersInfo@8");
        BinkGetKeyFrame = AutoGetProcAddress(dll, "_BinkGetKeyFrame@12");
        BinkGetPalette = AutoGetProcAddress(dll, "_BinkGetPalette@4");
        BinkGetPlatformInfo = AutoGetProcAddress(dll, "_BinkGetPlatformInfo@8");
        BinkGetRealtime = AutoGetProcAddress(dll, "_BinkGetRealtime@12");
        BinkGetRects = AutoGetProcAddress(dll, "_BinkGetRects@8");
        BinkGetSummary = AutoGetProcAddress(dll, "_BinkGetSummary@8");
        BinkGetTrackData = AutoGetProcAddress(dll, "_BinkGetTrackData@8");
        BinkGetTrackID = AutoGetProcAddress(dll, "_BinkGetTrackID@8");
        BinkGetTrackMaxSize = AutoGetProcAddress(dll, "_BinkGetTrackMaxSize@8");
        BinkGetTrackType = AutoGetProcAddress(dll, "_BinkGetTrackType@8");
        BinkGoto = AutoGetProcAddress(dll, "_BinkGoto@12");
        BinkIsSoftwareCursor = AutoGetProcAddress(dll, "_BinkIsSoftwareCursor@8");
        BinkLogoAddress = AutoGetProcAddress(dll, "_BinkLogoAddress@0");
        BinkNextFrame = AutoGetProcAddress(dll, "_BinkNextFrame@4");
        BinkOpen = AutoGetProcAddress(dll, "_BinkOpen@8");
        BinkOpenDirectSound = AutoGetProcAddress(dll, "_BinkOpenDirectSound@4");
        BinkOpenMiles = AutoGetProcAddress(dll, "_BinkOpenMiles@4");
        BinkOpenTrack = AutoGetProcAddress(dll, "_BinkOpenTrack@8");
        BinkOpenWaveOut = AutoGetProcAddress(dll, "_BinkOpenWaveOut@4");
        BinkOpenWithOptions = AutoGetProcAddress(dll, "_BinkOpenWithOptions@12");
        BinkOpenXAudio2 = AutoGetProcAddress(dll, "_BinkOpenXAudio2@4");
        BinkPause = AutoGetProcAddress(dll, "_BinkPause@8");
        BinkRegisterFrameBuffers = AutoGetProcAddress(dll, "_BinkRegisterFrameBuffers@8");
        BinkRequestStopAsyncThread = AutoGetProcAddress(dll, "_BinkRequestStopAsyncThread@4");
        BinkRestoreCursor = AutoGetProcAddress(dll, "_BinkRestoreCursor@4");
        BinkService = AutoGetProcAddress(dll, "_BinkService@4");
        BinkServiceSound = AutoGetProcAddress(dll, "_BinkServiceSound@0");
        BinkSetError = AutoGetProcAddress(dll, "_BinkSetError@4");
        BinkSetFileOffset = AutoGetProcAddress(dll, "_BinkSetFileOffset@8");
        BinkSetFrameRate = AutoGetProcAddress(dll, "_BinkSetFrameRate@8");
        BinkSetIO = AutoGetProcAddress(dll, "_BinkSetIO@4");
        BinkSetIOSize = AutoGetProcAddress(dll, "_BinkSetIOSize@4");
        BinkSetMemory = AutoGetProcAddress(dll, "_BinkSetMemory@8");
        BinkSetMixBinVolumes = AutoGetProcAddress(dll, "_BinkSetMixBinVolumes@20");
        BinkSetMixBins = AutoGetProcAddress(dll, "_BinkSetMixBins@16");
        BinkSetPan = AutoGetProcAddress(dll, "_BinkSetPan@12");
        BinkSetSimulate = AutoGetProcAddress(dll, "_BinkSetSimulate@4");
        BinkSetSoundOnOff = AutoGetProcAddress(dll, "_BinkSetSoundOnOff@8");
        BinkSetSoundSystem = AutoGetProcAddress(dll, "_BinkSetSoundSystem@8");
        BinkSetSoundTrack = AutoGetProcAddress(dll, "_BinkSetSoundTrack@8");
        BinkSetSpeakerVolumes = AutoGetProcAddress(dll, "_BinkSetSpeakerVolumes@20");
        BinkSetVideoOnOff = AutoGetProcAddress(dll, "_BinkSetVideoOnOff@8");
        BinkSetVolume = AutoGetProcAddress(dll, "_BinkSetVolume@12");
        BinkSetWillLoop = AutoGetProcAddress(dll, "_BinkSetWillLoop@8");
        BinkShouldSkip = AutoGetProcAddress(dll, "_BinkShouldSkip@4");
        BinkStartAsyncThread = AutoGetProcAddress(dll, "_BinkStartAsyncThread@8");
        BinkUseTelemetry = AutoGetProcAddress(dll, "_BinkUseTelemetry@4");
        BinkUseTmLite = AutoGetProcAddress(dll, "_BinkUseTmLite@4");
        BinkWait = AutoGetProcAddress(dll, "_BinkWait@4");
        BinkWaitStopAsyncThread = AutoGetProcAddress(dll, "_BinkWaitStopAsyncThread@4");
        RADSetMemory = AutoGetProcAddress(dll, "_RADSetMemory@8");
        RADTimerRead = AutoGetProcAddress(dll, "_RADTimerRead@0");
        YUV_blit_16a1bpp40 = AutoGetProcAddress(dll, "_YUV_blit_16a1bpp@40");
        YUV_blit_16a1bpp52 = AutoGetProcAddress(dll, "_YUV_blit_16a1bpp@52");
        YUV_blit_16a1bpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_16a1bpp_mask@48");
        YUV_blit_16a1bpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_16a1bpp_mask@60");
        YUV_blit_16a4bpp40 = AutoGetProcAddress(dll, "_YUV_blit_16a4bpp@40");
        YUV_blit_16a4bpp52 = AutoGetProcAddress(dll, "_YUV_blit_16a4bpp@52");
        YUV_blit_16a4bpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_16a4bpp_mask@48");
        YUV_blit_16a4bpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_16a4bpp_mask@60");
        YUV_blit_16bpp40 = AutoGetProcAddress(dll, "_YUV_blit_16bpp@40");
        YUV_blit_16bpp48 = AutoGetProcAddress(dll, "_YUV_blit_16bpp@48");
        YUV_blit_16bpp52 = AutoGetProcAddress(dll, "_YUV_blit_16bpp@52");
        YUV_blit_16bpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_16bpp_mask@48");
        YUV_blit_16bpp_mask56 = AutoGetProcAddress(dll, "_YUV_blit_16bpp_mask@56");
        YUV_blit_16bpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_16bpp_mask@60");
        YUV_blit_24bpp40 = AutoGetProcAddress(dll, "_YUV_blit_24bpp@40");
        YUV_blit_24bpp48 = AutoGetProcAddress(dll, "_YUV_blit_24bpp@48");
        YUV_blit_24bpp52 = AutoGetProcAddress(dll, "_YUV_blit_24bpp@52");
        YUV_blit_24bpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_24bpp_mask@48");
        YUV_blit_24bpp_mask56 = AutoGetProcAddress(dll, "_YUV_blit_24bpp_mask@56");
        YUV_blit_24bpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_24bpp_mask@60");
        YUV_blit_24rbpp40 = AutoGetProcAddress(dll, "_YUV_blit_24rbpp@40");
        YUV_blit_24rbpp48 = AutoGetProcAddress(dll, "_YUV_blit_24rbpp@48");
        YUV_blit_24rbpp52 = AutoGetProcAddress(dll, "_YUV_blit_24rbpp@52");
        YUV_blit_24rbpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_24rbpp_mask@48");
        YUV_blit_24rbpp_mask56 = AutoGetProcAddress(dll, "_YUV_blit_24rbpp_mask@56");
        YUV_blit_24rbpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_24rbpp_mask@60");
        YUV_blit_32abpp40 = AutoGetProcAddress(dll, "_YUV_blit_32abpp@40");
        YUV_blit_32abpp52 = AutoGetProcAddress(dll, "_YUV_blit_32abpp@52");
        YUV_blit_32abpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_32abpp_mask@48");
        YUV_blit_32abpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_32abpp_mask@60");
        YUV_blit_32bpp40 = AutoGetProcAddress(dll, "_YUV_blit_32bpp@40");
        YUV_blit_32bpp48 = AutoGetProcAddress(dll, "_YUV_blit_32bpp@48");
        YUV_blit_32bpp52 = AutoGetProcAddress(dll, "_YUV_blit_32bpp@52");
        YUV_blit_32bpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_32bpp_mask@48");
        YUV_blit_32bpp_mask56 = AutoGetProcAddress(dll, "_YUV_blit_32bpp_mask@56");
        YUV_blit_32bpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_32bpp_mask@60");
        YUV_blit_32rabpp40 = AutoGetProcAddress(dll, "_YUV_blit_32rabpp@40");
        YUV_blit_32rabpp52 = AutoGetProcAddress(dll, "_YUV_blit_32rabpp@52");
        YUV_blit_32rabpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_32rabpp_mask@48");
        YUV_blit_32rabpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_32rabpp_mask@60");
        YUV_blit_32rbpp40 = AutoGetProcAddress(dll, "_YUV_blit_32rbpp@40");
        YUV_blit_32rbpp48 = AutoGetProcAddress(dll, "_YUV_blit_32rbpp@48");
        YUV_blit_32rbpp52 = AutoGetProcAddress(dll, "_YUV_blit_32rbpp@52");
        YUV_blit_32rbpp_mask48 = AutoGetProcAddress(dll, "_YUV_blit_32rbpp_mask@48");
        YUV_blit_32rbpp_mask56 = AutoGetProcAddress(dll, "_YUV_blit_32rbpp_mask@56");
        YUV_blit_32rbpp_mask60 = AutoGetProcAddress(dll, "_YUV_blit_32rbpp_mask@60");
        YUV_blit_UYVY40 = AutoGetProcAddress(dll, "_YUV_blit_UYVY@40");
        YUV_blit_UYVY48 = AutoGetProcAddress(dll, "_YUV_blit_UYVY@48");
        YUV_blit_UYVY52 = AutoGetProcAddress(dll, "_YUV_blit_UYVY@52");
        YUV_blit_UYVY_mask48 = AutoGetProcAddress(dll, "_YUV_blit_UYVY_mask@48");
        YUV_blit_UYVY_mask56 = AutoGetProcAddress(dll, "_YUV_blit_UYVY_mask@56");
        YUV_blit_UYVY_mask60 = AutoGetProcAddress(dll, "_YUV_blit_UYVY_mask@60");
        YUV_blit_YUY240 = AutoGetProcAddress(dll, "_YUV_blit_YUY2@40");
        YUV_blit_YUY248 = AutoGetProcAddress(dll, "_YUV_blit_YUY2@48");
        YUV_blit_YUY252 = AutoGetProcAddress(dll, "_YUV_blit_YUY2@52");
        YUV_blit_YUY2_mask48 = AutoGetProcAddress(dll, "_YUV_blit_YUY2_mask@48");
        YUV_blit_YUY2_mask56 = AutoGetProcAddress(dll, "_YUV_blit_YUY2_mask@56");
        YUV_blit_YUY2_mask60 = AutoGetProcAddress(dll, "_YUV_blit_YUY2_mask@60");
        YUV_blit_YV1244 = AutoGetProcAddress(dll, "_YUV_blit_YV12@44");
        YUV_blit_YV1252 = AutoGetProcAddress(dll, "_YUV_blit_YV12@52");
        YUV_blit_YV1256 = AutoGetProcAddress(dll, "_YUV_blit_YV12@56");
        YUV_init4 = AutoGetProcAddress(dll, "_YUV_init@4");
        radfree = AutoGetProcAddress(dll, "_radfree@4");
        radmalloc = AutoGetProcAddress(dll, "_radmalloc@4");
    }
} binkw32;

// not sure if these all work -- there's a very real possibility some of these will need more full definitions to not break stack parameters
// (see https://github.com/ThirteenAG/Ultimate-ASI-Loader/blob/master/source/dllmain.h#L2870 for reference)
__declspec(naked) void _BreakRecordsIntoBlob() { dnsapi.BreakRecordsIntoBlob(); }
__declspec(naked) void _CombineRecordsInBlob() { dnsapi.CombineRecordsInBlob(); }
__declspec(naked) void _DnsAcquireContextHandle_A() { dnsapi.DnsAcquireContextHandle_A(); }
__declspec(naked) void _DnsAcquireContextHandle_W() { dnsapi.DnsAcquireContextHandle_W(); }
__declspec(naked) void _DnsAllocateRecord() { dnsapi.DnsAllocateRecord(); }
__declspec(naked) void _DnsApiAlloc() { dnsapi.DnsApiAlloc(); }
__declspec(naked) void _DnsApiAllocZero() { dnsapi.DnsApiAllocZero(); }
__declspec(naked) void _DnsApiFree() { dnsapi.DnsApiFree(); }
__declspec(naked) void _DnsApiHeapReset() { dnsapi.DnsApiHeapReset(); }
__declspec(naked) void _DnsApiRealloc() { dnsapi.DnsApiRealloc(); }
__declspec(naked) void _DnsApiSetDebugGlobals() { dnsapi.DnsApiSetDebugGlobals(); }
__declspec(naked) void _DnsAsyncRegisterHostAddrs() { dnsapi.DnsAsyncRegisterHostAddrs(); }
__declspec(naked) void _DnsAsyncRegisterInit() { dnsapi.DnsAsyncRegisterInit(); }
__declspec(naked) void _DnsAsyncRegisterTerm() { dnsapi.DnsAsyncRegisterTerm(); }
__declspec(naked) void _DnsCancelQuery() { dnsapi.DnsCancelQuery(); }
__declspec(naked) void _DnsCopyStringEx() { dnsapi.DnsCopyStringEx(); }
__declspec(naked) void _DnsCreateReverseNameStringForIpAddress() { dnsapi.DnsCreateReverseNameStringForIpAddress(); }
__declspec(naked) void _DnsCreateStandardDnsNameCopy() { dnsapi.DnsCreateStandardDnsNameCopy(); }
__declspec(naked) void _DnsCreateStringCopy() { dnsapi.DnsCreateStringCopy(); }
__declspec(naked) void _DnsDhcpRegisterAddrs() { dnsapi.DnsDhcpRegisterAddrs(); }
__declspec(naked) void _DnsDhcpRegisterHostAddrs() { dnsapi.DnsDhcpRegisterHostAddrs(); }
__declspec(naked) void _DnsDhcpRegisterInit() { dnsapi.DnsDhcpRegisterInit(); }
__declspec(naked) void _DnsDhcpRegisterTerm() { dnsapi.DnsDhcpRegisterTerm(); }
__declspec(naked) void _DnsDhcpRemoveRegistrations() { dnsapi.DnsDhcpRemoveRegistrations(); }
__declspec(naked) void _DnsDhcpSrvRegisterHostAddr() { dnsapi.DnsDhcpSrvRegisterHostAddr(); }
//__declspec(naked) void _DnsDhcpSrvRegisterHostAddrEx() { dnsapi.DnsDhcpSrvRegisterHostAddrEx(); }
__declspec(naked) void _DnsDhcpSrvRegisterHostName() { dnsapi.DnsDhcpSrvRegisterHostName(); }
//__declspec(naked) void _DnsDhcpSrvRegisterHostNameEx() { dnsapi.DnsDhcpSrvRegisterHostNameEx(); }
__declspec(naked) void _DnsDhcpSrvRegisterInit() { dnsapi.DnsDhcpSrvRegisterInit(); }
__declspec(naked) void _DnsDhcpSrvRegisterInitialize() { dnsapi.DnsDhcpSrvRegisterInitialize(); }
__declspec(naked) void _DnsDhcpSrvRegisterTerm() { dnsapi.DnsDhcpSrvRegisterTerm(); }
__declspec(naked) void _DnsDowncaseDnsNameLabel() { dnsapi.DnsDowncaseDnsNameLabel(); }
__declspec(naked) void _DnsExtractRecordsFromMessage_UTF8() { dnsapi.DnsExtractRecordsFromMessage_UTF8(); }
__declspec(naked) void _DnsExtractRecordsFromMessage_W() { dnsapi.DnsExtractRecordsFromMessage_W(); }
__declspec(naked) void _DnsFindAuthoritativeZone() { dnsapi.DnsFindAuthoritativeZone(); }
__declspec(naked) void _DnsFlushResolverCache() { dnsapi.DnsFlushResolverCache(); }
__declspec(naked) void _DnsFlushResolverCacheEntry_A() { dnsapi.DnsFlushResolverCacheEntry_A(); }
__declspec(naked) void _DnsFlushResolverCacheEntry_UTF8() { dnsapi.DnsFlushResolverCacheEntry_UTF8(); }
__declspec(naked) void _DnsFlushResolverCacheEntry_W() { dnsapi.DnsFlushResolverCacheEntry_W(); }
__declspec(naked) void _DnsFree() { dnsapi.DnsFree(); }
__declspec(naked) void _DnsFreeConfigStructure() { dnsapi.DnsFreeConfigStructure(); }
//__declspec(naked) void _DnsFreePolicyConfig() { dnsapi.DnsFreePolicyConfig(); }
//__declspec(naked) void _DnsFreeProxyName() { dnsapi.DnsFreeProxyName(); }
__declspec(naked) void _DnsGetBufferLengthForStringCopy() { dnsapi.DnsGetBufferLengthForStringCopy(); }
__declspec(naked) void _DnsGetCacheDataTable() { dnsapi.DnsGetCacheDataTable(); }
__declspec(naked) void _DnsGetDnsServerList() { dnsapi.DnsGetDnsServerList(); }
__declspec(naked) void _DnsGetDomainName() { dnsapi.DnsGetDomainName(); }
__declspec(naked) void _DnsGetLastFailedUpdateInfo() { dnsapi.DnsGetLastFailedUpdateInfo(); }
//__declspec(naked) void _DnsGetPolicyTableInfo() { dnsapi.DnsGetPolicyTableInfo(); }
//__declspec(naked) void _DnsGetPolicyTableInfoPrivate() { dnsapi.DnsGetPolicyTableInfoPrivate(); }
__declspec(naked) void _DnsGetPrimaryDomainName_A() { dnsapi.DnsGetPrimaryDomainName_A(); }
//__declspec(naked) void _DnsGetProxyInfoPrivate() { dnsapi.DnsGetProxyInfoPrivate(); }
//__declspec(naked) void _DnsGetProxyInformation() { dnsapi.DnsGetProxyInformation(); }
__declspec(naked) void _DnsGlobals() { dnsapi.DnsGlobals(); }
__declspec(naked) void _DnsIpv6AddressToString() { dnsapi.DnsIpv6AddressToString(); }
__declspec(naked) void _DnsIpv6StringToAddress() { dnsapi.DnsIpv6StringToAddress(); }
__declspec(naked) void _DnsIsAMailboxType() { dnsapi.DnsIsAMailboxType(); }
__declspec(naked) void _DnsIsStatusRcode() { dnsapi.DnsIsStatusRcode(); }
__declspec(naked) void _DnsIsStringCountValidForTextType() { dnsapi.DnsIsStringCountValidForTextType(); }
__declspec(naked) void _DnsLogEvent() { dnsapi.DnsLogEvent(); }
__declspec(naked) void _DnsLogIn() { dnsapi.DnsLogIn(); }
__declspec(naked) void _DnsLogInit() { dnsapi.DnsLogInit(); }
__declspec(naked) void _DnsLogIt() { dnsapi.DnsLogIt(); }
__declspec(naked) void _DnsLogOut() { dnsapi.DnsLogOut(); }
__declspec(naked) void _DnsLogTime() { dnsapi.DnsLogTime(); }
__declspec(naked) void _DnsMapRcodeToStatus() { dnsapi.DnsMapRcodeToStatus(); }
__declspec(naked) void _DnsModifyRecordsInSet_A() { dnsapi.DnsModifyRecordsInSet_A(); }
__declspec(naked) void _DnsModifyRecordsInSet_UTF8() { dnsapi.DnsModifyRecordsInSet_UTF8(); }
__declspec(naked) void _DnsModifyRecordsInSet_W() { dnsapi.DnsModifyRecordsInSet_W(); }
__declspec(naked) void _DnsNameCompareEx_A() { dnsapi.DnsNameCompareEx_A(); }
__declspec(naked) void _DnsNameCompareEx_UTF8() { dnsapi.DnsNameCompareEx_UTF8(); }
__declspec(naked) void _DnsNameCompareEx_W() { dnsapi.DnsNameCompareEx_W(); }
__declspec(naked) void _DnsNameCompare_A() { dnsapi.DnsNameCompare_A(); }
__declspec(naked) void _DnsNameCompare_UTF8() { dnsapi.DnsNameCompare_UTF8(); }
__declspec(naked) void _DnsNameCompare_W() { dnsapi.DnsNameCompare_W(); }
__declspec(naked) void _DnsNameCopy() { dnsapi.DnsNameCopy(); }
__declspec(naked) void _DnsNameCopyAllocate() { dnsapi.DnsNameCopyAllocate(); }
__declspec(naked) void _DnsNetworkInfo_CreateFromFAZ() { dnsapi.DnsNetworkInfo_CreateFromFAZ(); }
__declspec(naked) void _DnsNetworkInformation_CreateFromFAZ() { dnsapi.DnsNetworkInformation_CreateFromFAZ(); }
__declspec(naked) void _DnsNotifyResolver() { dnsapi.DnsNotifyResolver(); }
__declspec(naked) void _DnsNotifyResolverClusterIp() { dnsapi.DnsNotifyResolverClusterIp(); }
__declspec(naked) void _DnsNotifyResolverEx() { dnsapi.DnsNotifyResolverEx(); }
__declspec(naked) void _DnsQueryConfig() { dnsapi.DnsQueryConfig(); }
__declspec(naked) void _DnsQueryConfigAllocEx() { dnsapi.DnsQueryConfigAllocEx(); }
__declspec(naked) void _DnsQueryConfigDword() { dnsapi.DnsQueryConfigDword(); }
__declspec(naked) void _DnsQueryEx() { dnsapi.DnsQueryEx(); }
__declspec(naked) void _DnsQueryExA() { dnsapi.DnsQueryExA(); }
__declspec(naked) void _DnsQueryExUTF8() { dnsapi.DnsQueryExUTF8(); }
__declspec(naked) void _DnsQueryExW() { dnsapi.DnsQueryExW(); }
__declspec(naked) void _DnsQuery_A() { dnsapi.DnsQuery_A(); }
__declspec(naked) void _DnsQuery_UTF8() { dnsapi.DnsQuery_UTF8(); }
__declspec(naked) void _DnsQuery_W() { dnsapi.DnsQuery_W(); }
__declspec(naked) void _DnsRecordBuild_UTF8() { dnsapi.DnsRecordBuild_UTF8(); }
__declspec(naked) void _DnsRecordBuild_W() { dnsapi.DnsRecordBuild_W(); }
__declspec(naked) void _DnsRecordCompare() { dnsapi.DnsRecordCompare(); }
__declspec(naked) void _DnsRecordCopyEx() { dnsapi.DnsRecordCopyEx(); }
__declspec(naked) void _DnsRecordListFree() { dnsapi.DnsRecordListFree(); }
__declspec(naked) void _DnsRecordSetCompare() { dnsapi.DnsRecordSetCompare(); }
__declspec(naked) void _DnsRecordSetCopyEx() { dnsapi.DnsRecordSetCopyEx(); }
__declspec(naked) void _DnsRecordSetDetach() { dnsapi.DnsRecordSetDetach(); }
__declspec(naked) void _DnsRecordStringForType() { dnsapi.DnsRecordStringForType(); }
__declspec(naked) void _DnsRecordStringForWritableType() { dnsapi.DnsRecordStringForWritableType(); }
__declspec(naked) void _DnsRecordTypeForName() { dnsapi.DnsRecordTypeForName(); }
__declspec(naked) void _DnsRegisterClusterAddress() { dnsapi.DnsRegisterClusterAddress(); }
__declspec(naked) void _DnsReleaseContextHandle() { dnsapi.DnsReleaseContextHandle(); }
__declspec(naked) void _DnsRemoveRegistrations() { dnsapi.DnsRemoveRegistrations(); }
__declspec(naked) void _DnsReplaceRecordSetA() { dnsapi.DnsReplaceRecordSetA(); }
__declspec(naked) void _DnsReplaceRecordSetUTF8() { dnsapi.DnsReplaceRecordSetUTF8(); }
__declspec(naked) void _DnsReplaceRecordSetW() { dnsapi.DnsReplaceRecordSetW(); }
__declspec(naked) void _DnsResolverOp() { dnsapi.DnsResolverOp(); }
__declspec(naked) void _DnsScreenLocalAddrsForRegistration() { dnsapi.DnsScreenLocalAddrsForRegistration(); }
__declspec(naked) void _DnsSetConfigDword() { dnsapi.DnsSetConfigDword(); }
__declspec(naked) void _DnsStatusString() { dnsapi.DnsStatusString(); }
__declspec(naked) void _DnsStringCopyAllocateEx() { dnsapi.DnsStringCopyAllocateEx(); }
//__declspec(naked) void _DnsTraceServerConfig() { dnsapi.DnsTraceServerConfig(); }
__declspec(naked) void _DnsUnicodeToUtf8() { dnsapi.DnsUnicodeToUtf8(); }
__declspec(naked) void _DnsUpdate() { dnsapi.DnsUpdate(); }
//__declspec(naked) void _DnsUpdateMachinePresence() { dnsapi.DnsUpdateMachinePresence(); }
__declspec(naked) void _DnsUpdateTest_A() { dnsapi.DnsUpdateTest_A(); }
__declspec(naked) void _DnsUpdateTest_UTF8() { dnsapi.DnsUpdateTest_UTF8(); }
__declspec(naked) void _DnsUpdateTest_W() { dnsapi.DnsUpdateTest_W(); }
__declspec(naked) void _DnsUtf8ToUnicode() { dnsapi.DnsUtf8ToUnicode(); }
__declspec(naked) void _DnsValidateNameOrIp_TempW() { dnsapi.DnsValidateNameOrIp_TempW(); }
__declspec(naked) void _DnsValidateName_A() { dnsapi.DnsValidateName_A(); }
__declspec(naked) void _DnsValidateName_UTF8() { dnsapi.DnsValidateName_UTF8(); }
__declspec(naked) void _DnsValidateName_W() { dnsapi.DnsValidateName_W(); }
//__declspec(naked) void _DnsValidateServerArray_A() { dnsapi.DnsValidateServerArray_A(); }
//__declspec(naked) void _DnsValidateServerArray_W() { dnsapi.DnsValidateServerArray_W(); }
//__declspec(naked) void _DnsValidateServerStatus() { dnsapi.DnsValidateServerStatus(); }
//__declspec(naked) void _DnsValidateServer_A() { dnsapi.DnsValidateServer_A(); }
//__declspec(naked) void _DnsValidateServer_W() { dnsapi.DnsValidateServer_W(); }
__declspec(naked) void _DnsValidateUtf8Byte() { dnsapi.DnsValidateUtf8Byte(); }
__declspec(naked) void _DnsWriteQuestionToBuffer_UTF8() { dnsapi.DnsWriteQuestionToBuffer_UTF8(); }
__declspec(naked) void _DnsWriteQuestionToBuffer_W() { dnsapi.DnsWriteQuestionToBuffer_W(); }
__declspec(naked) void _DnsWriteReverseNameStringForIpAddress() { dnsapi.DnsWriteReverseNameStringForIpAddress(); }
__declspec(naked) void _Dns_AddRecordsToMessage() { dnsapi.Dns_AddRecordsToMessage(); }
__declspec(naked) void _Dns_AllocateMsgBuf() { dnsapi.Dns_AllocateMsgBuf(); }
__declspec(naked) void _Dns_BuildPacket() { dnsapi.Dns_BuildPacket(); }
__declspec(naked) void _Dns_CleanupWinsock() { dnsapi.Dns_CleanupWinsock(); }
__declspec(naked) void _Dns_CloseConnection() { dnsapi.Dns_CloseConnection(); }
__declspec(naked) void _Dns_CloseSocket() { dnsapi.Dns_CloseSocket(); }
__declspec(naked) void _Dns_CreateMulticastSocket() { dnsapi.Dns_CreateMulticastSocket(); }
__declspec(naked) void _Dns_CreateSocket() { dnsapi.Dns_CreateSocket(); }
__declspec(naked) void _Dns_CreateSocketEx() { dnsapi.Dns_CreateSocketEx(); }
__declspec(naked) void _Dns_ExtractRecordsFromMessage() { dnsapi.Dns_ExtractRecordsFromMessage(); }
__declspec(naked) void _Dns_FindAuthoritativeZoneLib() { dnsapi.Dns_FindAuthoritativeZoneLib(); }
__declspec(naked) void _Dns_FreeMsgBuf() { dnsapi.Dns_FreeMsgBuf(); }
__declspec(naked) void _Dns_GetRandomXid() { dnsapi.Dns_GetRandomXid(); }
__declspec(naked) void _Dns_InitializeMsgBuf() { dnsapi.Dns_InitializeMsgBuf(); }
__declspec(naked) void _Dns_InitializeMsgRemoteSockaddr() { dnsapi.Dns_InitializeMsgRemoteSockaddr(); }
__declspec(naked) void _Dns_InitializeWinsock() { dnsapi.Dns_InitializeWinsock(); }
__declspec(naked) void _Dns_OpenTcpConnectionAndSend() { dnsapi.Dns_OpenTcpConnectionAndSend(); }
__declspec(naked) void _Dns_ParseMessage() { dnsapi.Dns_ParseMessage(); }
__declspec(naked) void _Dns_ParsePacketRecord() { dnsapi.Dns_ParsePacketRecord(); }
__declspec(naked) void _Dns_PingAdapterServers() { dnsapi.Dns_PingAdapterServers(); }
__declspec(naked) void _Dns_ReadPacketName() { dnsapi.Dns_ReadPacketName(); }
__declspec(naked) void _Dns_ReadPacketNameAllocate() { dnsapi.Dns_ReadPacketNameAllocate(); }
__declspec(naked) void _Dns_ReadRecordStructureFromPacket() { dnsapi.Dns_ReadRecordStructureFromPacket(); }
__declspec(naked) void _Dns_RecvTcp() { dnsapi.Dns_RecvTcp(); }
__declspec(naked) void _Dns_ResetNetworkInfo() { dnsapi.Dns_ResetNetworkInfo(); }
__declspec(naked) void _Dns_SendAndRecvUdp() { dnsapi.Dns_SendAndRecvUdp(); }
__declspec(naked) void _Dns_SendEx() { dnsapi.Dns_SendEx(); }
__declspec(naked) void _Dns_SetRecordDatalength() { dnsapi.Dns_SetRecordDatalength(); }
__declspec(naked) void _Dns_SetRecordsSection() { dnsapi.Dns_SetRecordsSection(); }
__declspec(naked) void _Dns_SetRecordsTtl() { dnsapi.Dns_SetRecordsTtl(); }
__declspec(naked) void _Dns_SkipPacketName() { dnsapi.Dns_SkipPacketName(); }
__declspec(naked) void _Dns_SkipToRecord() { dnsapi.Dns_SkipToRecord(); }
__declspec(naked) void _Dns_UpdateLib() { dnsapi.Dns_UpdateLib(); }
__declspec(naked) void _Dns_UpdateLibEx() { dnsapi.Dns_UpdateLibEx(); }
__declspec(naked) void _Dns_WriteDottedNameToPacket() { dnsapi.Dns_WriteDottedNameToPacket(); }
__declspec(naked) void _Dns_WriteQuestionToMessage() { dnsapi.Dns_WriteQuestionToMessage(); }
__declspec(naked) void _Dns_WriteRecordStructureToPacketEx() { dnsapi.Dns_WriteRecordStructureToPacketEx(); }
__declspec(naked) void _ExtraInfo_Init() { dnsapi.ExtraInfo_Init(); }
__declspec(naked) void _Faz_AreServerListsInSameNameSpace() { dnsapi.Faz_AreServerListsInSameNameSpace(); }
//__declspec(naked) void _FlushDnsPolicyUnreachableStatus() { dnsapi.FlushDnsPolicyUnreachableStatus(); }
__declspec(naked) void _GetCurrentTimeInSeconds() { dnsapi.GetCurrentTimeInSeconds(); }
__declspec(naked) void _HostsFile_Close() { dnsapi.HostsFile_Close(); }
__declspec(naked) void _HostsFile_Open() { dnsapi.HostsFile_Open(); }
__declspec(naked) void _HostsFile_ReadLine() { dnsapi.HostsFile_ReadLine(); }
__declspec(naked) void _IpHelp_IsAddrOnLink() { dnsapi.IpHelp_IsAddrOnLink(); }
__declspec(naked) void _Local_GetRecordsForLocalName() { dnsapi.Local_GetRecordsForLocalName(); }
__declspec(naked) void _Local_GetRecordsForLocalNameEx() { dnsapi.Local_GetRecordsForLocalNameEx(); }
__declspec(naked) void _NetInfo_Build() { dnsapi.NetInfo_Build(); }
__declspec(naked) void _NetInfo_Clean() { dnsapi.NetInfo_Clean(); }
__declspec(naked) void _NetInfo_Copy() { dnsapi.NetInfo_Copy(); }
__declspec(naked) void _NetInfo_Free() { dnsapi.NetInfo_Free(); }
__declspec(naked) void _NetInfo_GetAdapterByAddress() { dnsapi.NetInfo_GetAdapterByAddress(); }
__declspec(naked) void _NetInfo_GetAdapterByInterfaceIndex() { dnsapi.NetInfo_GetAdapterByInterfaceIndex(); }
__declspec(naked) void _NetInfo_GetAdapterByName() { dnsapi.NetInfo_GetAdapterByName(); }
__declspec(naked) void _NetInfo_IsAddrConfig() { dnsapi.NetInfo_IsAddrConfig(); }
__declspec(naked) void _NetInfo_IsForUpdate() { dnsapi.NetInfo_IsForUpdate(); }
__declspec(naked) void _NetInfo_ResetServerPriorities() { dnsapi.NetInfo_ResetServerPriorities(); }
//__declspec(naked) void _NetInfo_UpdateServerReachability() { dnsapi.NetInfo_UpdateServerReachability(); }
__declspec(naked) void _QueryDirectEx() { dnsapi.QueryDirectEx(); }
__declspec(naked) void _Query_Main() { dnsapi.Query_Main(); }
__declspec(naked) void _Reg_FreeUpdateInfo() { dnsapi.Reg_FreeUpdateInfo(); }
__declspec(naked) void _Reg_GetValueEx() { dnsapi.Reg_GetValueEx(); }
__declspec(naked) void _Reg_ReadGlobalsEx() { dnsapi.Reg_ReadGlobalsEx(); }
__declspec(naked) void _Reg_ReadUpdateInfo() { dnsapi.Reg_ReadUpdateInfo(); }
__declspec(naked) void _Security_ContextListTimeout() { dnsapi.Security_ContextListTimeout(); }
__declspec(naked) void _Send_AndRecvUdpWithParam() { dnsapi.Send_AndRecvUdpWithParam(); }
__declspec(naked) void _Send_MessagePrivate() { dnsapi.Send_MessagePrivate(); }
__declspec(naked) void _Send_OpenTcpConnectionAndSend() { dnsapi.Send_OpenTcpConnectionAndSend(); }
__declspec(naked) void _Socket_CacheCleanup() { dnsapi.Socket_CacheCleanup(); }
__declspec(naked) void _Socket_CacheInit() { dnsapi.Socket_CacheInit(); }
__declspec(naked) void _Socket_CleanupWinsock() { dnsapi.Socket_CleanupWinsock(); }
__declspec(naked) void _Socket_ClearMessageSockets() { dnsapi.Socket_ClearMessageSockets(); }
__declspec(naked) void _Socket_CloseEx() { dnsapi.Socket_CloseEx(); }
__declspec(naked) void _Socket_CloseMessageSockets() { dnsapi.Socket_CloseMessageSockets(); }
__declspec(naked) void _Socket_Create() { dnsapi.Socket_Create(); }
__declspec(naked) void _Socket_CreateMulticast() { dnsapi.Socket_CreateMulticast(); }
__declspec(naked) void _Socket_InitWinsock() { dnsapi.Socket_InitWinsock(); }
__declspec(naked) void _Socket_JoinMulticast() { dnsapi.Socket_JoinMulticast(); }
__declspec(naked) void _Socket_RecvFrom() { dnsapi.Socket_RecvFrom(); }
__declspec(naked) void _Socket_SetMulticastInterface() { dnsapi.Socket_SetMulticastInterface(); }
__declspec(naked) void _Socket_SetMulticastLoopBack() { dnsapi.Socket_SetMulticastLoopBack(); }
__declspec(naked) void _Socket_SetTtl() { dnsapi.Socket_SetTtl(); }
__declspec(naked) void _Socket_TcpListen() { dnsapi.Socket_TcpListen(); }
//__declspec(naked) void _Trace_Reset() { dnsapi.Trace_Reset(); }
__declspec(naked) void _Update_ReplaceAddressRecordsW() { dnsapi.Update_ReplaceAddressRecordsW(); }
__declspec(naked) void _Util_IsIp6Running() { dnsapi.Util_IsIp6Running(); }

__declspec(naked) void _ov_bitrate() { _asm { jmp[vorbisfile.ov_bitrate] } }
__declspec(naked) void _ov_bitrate_instant() { _asm { jmp[vorbisfile.ov_bitrate_instant] } }
__declspec(naked) void _ov_clear() { _asm { jmp[vorbisfile.ov_clear] } }
__declspec(naked) void _ov_comment() { _asm { jmp[vorbisfile.ov_comment] } }
__declspec(naked) void _ov_crosslap() { _asm { jmp[vorbisfile.ov_crosslap] } }
__declspec(naked) void _ov_fopen() { _asm { jmp[vorbisfile.ov_fopen] } }
__declspec(naked) void _ov_halfrate() { _asm { jmp[vorbisfile.ov_halfrate] } }
__declspec(naked) void _ov_halfrate_p() { _asm { jmp[vorbisfile.ov_halfrate_p] } }
__declspec(naked) void _ov_info() { _asm { jmp[vorbisfile.ov_info] } }
__declspec(naked) void _ov_open() { _asm { jmp[vorbisfile.ov_open] } }
__declspec(naked) void _ov_open_callbacks() { _asm { jmp[vorbisfile.ov_open_callbacks] } }
__declspec(naked) void _ov_pcm_seek() { _asm { jmp[vorbisfile.ov_pcm_seek] } }
__declspec(naked) void _ov_pcm_seek_lap() { _asm { jmp[vorbisfile.ov_pcm_seek_lap] } }
__declspec(naked) void _ov_pcm_seek_page() { _asm { jmp[vorbisfile.ov_pcm_seek_page] } }
__declspec(naked) void _ov_pcm_seek_page_lap() { _asm { jmp[vorbisfile.ov_pcm_seek_page_lap] } }
__declspec(naked) void _ov_pcm_tell() { _asm { jmp[vorbisfile.ov_pcm_tell] } }
__declspec(naked) void _ov_pcm_total() { _asm { jmp[vorbisfile.ov_pcm_total] } }
__declspec(naked) void _ov_raw_seek() { _asm { jmp[vorbisfile.ov_raw_seek] } }
__declspec(naked) void _ov_raw_seek_lap() { _asm { jmp[vorbisfile.ov_raw_seek_lap] } }
__declspec(naked) void _ov_raw_tell() { _asm { jmp[vorbisfile.ov_raw_tell] } }
__declspec(naked) void _ov_raw_total() { _asm { jmp[vorbisfile.ov_raw_total] } }
__declspec(naked) void _ov_read() { _asm { jmp[vorbisfile.ov_read] } }
__declspec(naked) void _ov_read_float() { _asm { jmp[vorbisfile.ov_read_float] } }
__declspec(naked) void _ov_seekable() { _asm { jmp[vorbisfile.ov_seekable] } }
__declspec(naked) void _ov_serialnumber() { _asm { jmp[vorbisfile.ov_serialnumber] } }
__declspec(naked) void _ov_streams() { _asm { jmp[vorbisfile.ov_streams] } }
__declspec(naked) void _ov_test() { _asm { jmp[vorbisfile.ov_test] } }
__declspec(naked) void _ov_test_callbacks() { _asm { jmp[vorbisfile.ov_test_callbacks] } }
__declspec(naked) void _ov_test_open() { _asm { jmp[vorbisfile.ov_test_open] } }
__declspec(naked) void _ov_time_seek() { _asm { jmp[vorbisfile.ov_time_seek] } }
__declspec(naked) void _ov_time_seek_lap() { _asm { jmp[vorbisfile.ov_time_seek_lap] } }
__declspec(naked) void _ov_time_seek_page() { _asm { jmp[vorbisfile.ov_time_seek_page] } }
__declspec(naked) void _ov_time_seek_page_lap() { _asm { jmp[vorbisfile.ov_time_seek_page_lap] } }
__declspec(naked) void _ov_time_tell() { _asm { jmp[vorbisfile.ov_time_tell] } }
__declspec(naked) void _ov_time_total() { _asm { jmp[vorbisfile.ov_time_total] } }

__declspec(naked) void _DirectInput8Create() { _asm { jmp[dinput8.DirectInput8Create] } }

__declspec(naked) void _DirectInputCreateA() { _asm { jmp[dinput.DirectInputCreateA] } }
__declspec(naked) void _DirectInputCreateEx() { _asm { jmp[dinput.DirectInputCreateEx] } }
__declspec(naked) void _DirectInputCreateW() { _asm { jmp[dinput.DirectInputCreateW] } }

__declspec(naked) void _DllCanUnloadNow() { _asm { jmp[shared.DllCanUnloadNow] } }
__declspec(naked) void _DllGetClassObject() { _asm { jmp[shared.DllGetClassObject] } }
__declspec(naked) void _DllRegisterServer() { _asm { jmp[shared.DllRegisterServer] } }
__declspec(naked) void _DllUnregisterServer() { _asm { jmp[shared.DllUnregisterServer] } }
__declspec(naked) void _DebugSetMute() { _asm { jmp[shared.DebugSetMute] } }

__declspec(naked) void _DirectSoundCaptureCreate() { _asm { jmp[dsound.DirectSoundCaptureCreate] } }
__declspec(naked) void _DirectSoundCaptureCreate8() { _asm { jmp[dsound.DirectSoundCaptureCreate8] } }
__declspec(naked) void _DirectSoundCaptureEnumerateA() { _asm { jmp[dsound.DirectSoundCaptureEnumerateA] } }
__declspec(naked) void _DirectSoundCaptureEnumerateW() { _asm { jmp[dsound.DirectSoundCaptureEnumerateW] } }
__declspec(naked) void _DirectSoundCreate() { _asm { jmp[dsound.DirectSoundCreate] } }
__declspec(naked) void _DirectSoundCreate8() { _asm { jmp[dsound.DirectSoundCreate8] } }
__declspec(naked) void _DirectSoundEnumerateA() { _asm { jmp[dsound.DirectSoundEnumerateA] } }
__declspec(naked) void _DirectSoundEnumerateW() { _asm { jmp[dsound.DirectSoundEnumerateW] } }
__declspec(naked) void _DirectSoundFullDuplexCreate() { _asm { jmp[dsound.DirectSoundFullDuplexCreate] } }
//__declspec(naked) void _DllCanUnloadNow() { _asm { jmp[dsound.DllCanUnloadNow] } }
//__declspec(naked) void _DllGetClassObject() { _asm { jmp[dsound.DllGetClassObject] } }
__declspec(naked) void _GetDeviceID() { _asm { jmp[dsound.GetDeviceID] } }

//__declspec(naked) void _DebugSetMute() { _asm { jmp[d3d8.DebugSetMute] } }
__declspec(naked) void _Direct3D8EnableMaximizedWindowedModeShim() { _asm { jmp[d3d8.Direct3D8EnableMaximizedWindowedModeShim] } }
__declspec(naked) void _Direct3DCreate8() { _asm { jmp[d3d8.Direct3DCreate8] } }
__declspec(naked) void _ValidatePixelShader() { _asm { jmp[d3d8.ValidatePixelShader] } }
__declspec(naked) void _ValidateVertexShader() { _asm { jmp[d3d8.ValidateVertexShader] } }

__declspec(naked) void _D3DPERF_BeginEvent() { _asm { jmp[d3d9.D3DPERF_BeginEvent] } }
__declspec(naked) void _D3DPERF_EndEvent() { _asm { jmp[d3d9.D3DPERF_EndEvent] } }
__declspec(naked) void _D3DPERF_GetStatus() { _asm { jmp[d3d9.D3DPERF_GetStatus] } }
__declspec(naked) void _D3DPERF_QueryRepeatFrame() { _asm { jmp[d3d9.D3DPERF_QueryRepeatFrame] } }
__declspec(naked) void _D3DPERF_SetMarker() { _asm { jmp[d3d9.D3DPERF_SetMarker] } }
__declspec(naked) void _D3DPERF_SetOptions() { _asm { jmp[d3d9.D3DPERF_SetOptions] } }
__declspec(naked) void _D3DPERF_SetRegion() { _asm { jmp[d3d9.D3DPERF_SetRegion] } }
__declspec(naked) void _DebugSetLevel() { _asm { jmp[d3d9.DebugSetLevel] } }
//__declspec(naked) void _DebugSetMute() { _asm { jmp[d3d9.DebugSetMute] } }
__declspec(naked) void _Direct3D9EnableMaximizedWindowedModeShim() { _asm { jmp[d3d9.Direct3D9EnableMaximizedWindowedModeShim] } }
__declspec(naked) void _Direct3DCreate9() { _asm { jmp[d3d9.Direct3DCreate9] } }
__declspec(naked) void _Direct3DCreate9Ex() { _asm { jmp[d3d9.Direct3DCreate9Ex] } }
__declspec(naked) void _Direct3DShaderValidatorCreate9() { _asm { jmp[d3d9.Direct3DShaderValidatorCreate9] } }
__declspec(naked) void _PSGPError() { _asm { jmp[d3d9.PSGPError] } }
__declspec(naked) void _PSGPSampleTexture() { _asm { jmp[d3d9.PSGPSampleTexture] } }

__declspec(naked) void _D3D11CoreCreateDevice() { _asm { jmp[d3d11.D3D11CoreCreateDevice] } }
__declspec(naked) void _D3D11CoreCreateLayeredDevice() { _asm { jmp[d3d11.D3D11CoreCreateLayeredDevice] } }
__declspec(naked) void _D3D11CoreGetLayeredDeviceSize() { _asm { jmp[d3d11.D3D11CoreGetLayeredDeviceSize] } }
__declspec(naked) void _D3D11CoreRegisterLayers() { _asm { jmp[d3d11.D3D11CoreRegisterLayers] } }
__declspec(naked) void _D3D11CreateDevice() { _asm { jmp[d3d11.D3D11CreateDevice] } }
__declspec(naked) void _D3D11CreateDeviceAndSwapChain() { _asm { jmp[d3d11.D3D11CreateDeviceAndSwapChain] } }
__declspec(naked) void _D3DKMTCloseAdapter() { _asm { jmp[d3d11.D3DKMTCloseAdapter] } }
__declspec(naked) void _D3DKMTCreateAllocation() { _asm { jmp[d3d11.D3DKMTCreateAllocation] } }
__declspec(naked) void _D3DKMTCreateContext() { _asm { jmp[d3d11.D3DKMTCreateContext] } }
__declspec(naked) void _D3DKMTCreateDevice() { _asm { jmp[d3d11.D3DKMTCreateDevice] } }
__declspec(naked) void _D3DKMTCreateSynchronizationObject() { _asm { jmp[d3d11.D3DKMTCreateSynchronizationObject] } }
__declspec(naked) void _D3DKMTDestroyAllocation() { _asm { jmp[d3d11.D3DKMTDestroyAllocation] } }
__declspec(naked) void _D3DKMTDestroyContext() { _asm { jmp[d3d11.D3DKMTDestroyContext] } }
__declspec(naked) void _D3DKMTDestroyDevice() { _asm { jmp[d3d11.D3DKMTDestroyDevice] } }
__declspec(naked) void _D3DKMTDestroySynchronizationObject() { _asm { jmp[d3d11.D3DKMTDestroySynchronizationObject] } }
__declspec(naked) void _D3DKMTEscape() { _asm { jmp[d3d11.D3DKMTEscape] } }
__declspec(naked) void _D3DKMTGetContextSchedulingPriority() { _asm { jmp[d3d11.D3DKMTGetContextSchedulingPriority] } }
__declspec(naked) void _D3DKMTGetDeviceState() { _asm { jmp[d3d11.D3DKMTGetDeviceState] } }
__declspec(naked) void _D3DKMTGetDisplayModeList() { _asm { jmp[d3d11.D3DKMTGetDisplayModeList] } }
__declspec(naked) void _D3DKMTGetMultisampleMethodList() { _asm { jmp[d3d11.D3DKMTGetMultisampleMethodList] } }
__declspec(naked) void _D3DKMTGetRuntimeData() { _asm { jmp[d3d11.D3DKMTGetRuntimeData] } }
__declspec(naked) void _D3DKMTGetSharedPrimaryHandle() { _asm { jmp[d3d11.D3DKMTGetSharedPrimaryHandle] } }
__declspec(naked) void _D3DKMTLock() { _asm { jmp[d3d11.D3DKMTLock] } }
__declspec(naked) void _D3DKMTOpenAdapterFromHdc() { _asm { jmp[d3d11.D3DKMTOpenAdapterFromHdc] } }
__declspec(naked) void _D3DKMTOpenResource() { _asm { jmp[d3d11.D3DKMTOpenResource] } }
__declspec(naked) void _D3DKMTPresent() { _asm { jmp[d3d11.D3DKMTPresent] } }
__declspec(naked) void _D3DKMTQueryAdapterInfo() { _asm { jmp[d3d11.D3DKMTQueryAdapterInfo] } }
__declspec(naked) void _D3DKMTQueryAllocationResidency() { _asm { jmp[d3d11.D3DKMTQueryAllocationResidency] } }
__declspec(naked) void _D3DKMTQueryResourceInfo() { _asm { jmp[d3d11.D3DKMTQueryResourceInfo] } }
__declspec(naked) void _D3DKMTRender() { _asm { jmp[d3d11.D3DKMTRender] } }
__declspec(naked) void _D3DKMTSetAllocationPriority() { _asm { jmp[d3d11.D3DKMTSetAllocationPriority] } }
__declspec(naked) void _D3DKMTSetContextSchedulingPriority() { _asm { jmp[d3d11.D3DKMTSetContextSchedulingPriority] } }
__declspec(naked) void _D3DKMTSetDisplayMode() { _asm { jmp[d3d11.D3DKMTSetDisplayMode] } }
__declspec(naked) void _D3DKMTSetDisplayPrivateDriverFormat() { _asm { jmp[d3d11.D3DKMTSetDisplayPrivateDriverFormat] } }
__declspec(naked) void _D3DKMTSetGammaRamp() { _asm { jmp[d3d11.D3DKMTSetGammaRamp] } }
__declspec(naked) void _D3DKMTSetVidPnSourceOwner() { _asm { jmp[d3d11.D3DKMTSetVidPnSourceOwner] } }
__declspec(naked) void _D3DKMTSignalSynchronizationObject() { _asm { jmp[d3d11.D3DKMTSignalSynchronizationObject] } }
__declspec(naked) void _D3DKMTUnlock() { _asm { jmp[d3d11.D3DKMTUnlock] } }
__declspec(naked) void _D3DKMTWaitForSynchronizationObject() { _asm { jmp[d3d11.D3DKMTWaitForSynchronizationObject] } }
__declspec(naked) void _D3DKMTWaitForVerticalBlankEvent() { _asm { jmp[d3d11.D3DKMTWaitForVerticalBlankEvent] } }
__declspec(naked) void _D3DPerformance_BeginEvent() { _asm { jmp[d3d11.D3DPerformance_BeginEvent] } }
__declspec(naked) void _D3DPerformance_EndEvent() { _asm { jmp[d3d11.D3DPerformance_EndEvent] } }
__declspec(naked) void _D3DPerformance_GetStatus() { _asm { jmp[d3d11.D3DPerformance_GetStatus] } }
__declspec(naked) void _D3DPerformance_SetMarker() { _asm { jmp[d3d11.D3DPerformance_SetMarker] } }
__declspec(naked) void _EnableFeatureLevelUpgrade() { _asm { jmp[d3d11.EnableFeatureLevelUpgrade] } }
__declspec(naked) void _OpenAdapter10() { _asm { jmp[d3d11.OpenAdapter10] } }
__declspec(naked) void _OpenAdapter10_2() { _asm { jmp[d3d11.OpenAdapter10_2] } }

__declspec(naked) void _AcquireDDThreadLock() { _asm { jmp[ddraw.AcquireDDThreadLock] } }
__declspec(naked) void _CompleteCreateSysmemSurface() { _asm { jmp[ddraw.CompleteCreateSysmemSurface] } }
__declspec(naked) void _D3DParseUnknownCommand() { _asm { jmp[ddraw.D3DParseUnknownCommand] } }
__declspec(naked) void _DDGetAttachedSurfaceLcl() { _asm { jmp[ddraw.DDGetAttachedSurfaceLcl] } }
__declspec(naked) void _DDInternalLock() { _asm { jmp[ddraw.DDInternalLock] } }
__declspec(naked) void _DDInternalUnlock() { _asm { jmp[ddraw.DDInternalUnlock] } }
__declspec(naked) void _DSoundHelp() { _asm { jmp[ddraw.DSoundHelp] } }
__declspec(naked) void _DirectDrawCreate() { _asm { jmp[ddraw.DirectDrawCreate] } }
__declspec(naked) void _DirectDrawCreateClipper() { _asm { jmp[ddraw.DirectDrawCreateClipper] } }
__declspec(naked) void _DirectDrawCreateEx() { _asm { jmp[ddraw.DirectDrawCreateEx] } }
__declspec(naked) void _DirectDrawEnumerateA() { _asm { jmp[ddraw.DirectDrawEnumerateA] } }
__declspec(naked) void _DirectDrawEnumerateExA() { _asm { jmp[ddraw.DirectDrawEnumerateExA] } }
__declspec(naked) void _DirectDrawEnumerateExW() { _asm { jmp[ddraw.DirectDrawEnumerateExW] } }
__declspec(naked) void _DirectDrawEnumerateW() { _asm { jmp[ddraw.DirectDrawEnumerateW] } }
//__declspec(naked) void _DllCanUnloadNow() { _asm { jmp[ddraw.DllCanUnloadNow] } }
//__declspec(naked) void _DllGetClassObject() { _asm { jmp[ddraw.DllGetClassObject] } }
__declspec(naked) void _GetDDSurfaceLocal() { _asm { jmp[ddraw.GetDDSurfaceLocal] } }
__declspec(naked) void _GetOLEThunkData() { _asm { jmp[ddraw.GetOLEThunkData] } }
__declspec(naked) void _GetSurfaceFromDC() { _asm { jmp[ddraw.GetSurfaceFromDC] } }
__declspec(naked) void _RegisterSpecialCase() { _asm { jmp[ddraw.RegisterSpecialCase] } }
__declspec(naked) void _ReleaseDDThreadLock() { _asm { jmp[ddraw.ReleaseDDThreadLock] } }
__declspec(naked) void _SetAppCompatData() { _asm { jmp[ddraw.SetAppCompatData] } }

__declspec(naked) void _CloseDriver() { _asm { jmp[winmm.CloseDriver] } }
__declspec(naked) void _DefDriverProc() { _asm { jmp[winmm.DefDriverProc] } }
__declspec(naked) void _DriverCallback() { _asm { jmp[winmm.DriverCallback] } }
__declspec(naked) void _DrvGetModuleHandle() { _asm { jmp[winmm.DrvGetModuleHandle] } }
__declspec(naked) void _GetDriverModuleHandle() { _asm { jmp[winmm.GetDriverModuleHandle] } }
__declspec(naked) void _NotifyCallbackData() { _asm { jmp[winmm.NotifyCallbackData] } }
__declspec(naked) void _OpenDriver() { _asm { jmp[winmm.OpenDriver] } }
__declspec(naked) void _PlaySound() { _asm { jmp[winmm.PlaySound] } }
__declspec(naked) void _PlaySoundA() { _asm { jmp[winmm.PlaySoundA] } }
__declspec(naked) void _PlaySoundW() { _asm { jmp[winmm.PlaySoundW] } }
__declspec(naked) void _SendDriverMessage() { _asm { jmp[winmm.SendDriverMessage] } }
__declspec(naked) void _WOW32DriverCallback() { _asm { jmp[winmm.WOW32DriverCallback] } }
__declspec(naked) void _WOW32ResolveMultiMediaHandle() { _asm { jmp[winmm.WOW32ResolveMultiMediaHandle] } }
__declspec(naked) void _WOWAppExit() { _asm { jmp[winmm.WOWAppExit] } }
__declspec(naked) void _aux32Message() { _asm { jmp[winmm.aux32Message] } }
__declspec(naked) void _auxGetDevCapsA() { _asm { jmp[winmm.auxGetDevCapsA] } }
__declspec(naked) void _auxGetDevCapsW() { _asm { jmp[winmm.auxGetDevCapsW] } }
__declspec(naked) void _auxGetNumDevs() { _asm { jmp[winmm.auxGetNumDevs] } }
__declspec(naked) void _auxGetVolume() { _asm { jmp[winmm.auxGetVolume] } }
__declspec(naked) void _auxOutMessage() { _asm { jmp[winmm.auxOutMessage] } }
__declspec(naked) void _auxSetVolume() { _asm { jmp[winmm.auxSetVolume] } }
__declspec(naked) void _joy32Message() { _asm { jmp[winmm.joy32Message] } }
__declspec(naked) void _joyConfigChanged() { _asm { jmp[winmm.joyConfigChanged] } }
__declspec(naked) void _joyGetDevCapsA() { _asm { jmp[winmm.joyGetDevCapsA] } }
__declspec(naked) void _joyGetDevCapsW() { _asm { jmp[winmm.joyGetDevCapsW] } }
__declspec(naked) void _joyGetNumDevs() { _asm { jmp[winmm.joyGetNumDevs] } }
__declspec(naked) void _joyGetPos() { _asm { jmp[winmm.joyGetPos] } }
__declspec(naked) void _joyGetPosEx() { _asm { jmp[winmm.joyGetPosEx] } }
__declspec(naked) void _joyGetThreshold() { _asm { jmp[winmm.joyGetThreshold] } }
__declspec(naked) void _joyReleaseCapture() { _asm { jmp[winmm.joyReleaseCapture] } }
__declspec(naked) void _joySetCapture() { _asm { jmp[winmm.joySetCapture] } }
__declspec(naked) void _joySetThreshold() { _asm { jmp[winmm.joySetThreshold] } }
__declspec(naked) void _mci32Message() { _asm { jmp[winmm.mci32Message] } }
__declspec(naked) void _mciDriverNotify() { _asm { jmp[winmm.mciDriverNotify] } }
__declspec(naked) void _mciDriverYield() { _asm { jmp[winmm.mciDriverYield] } }
__declspec(naked) void _mciExecute() { _asm { jmp[winmm.mciExecute] } }
__declspec(naked) void _mciFreeCommandResource() { _asm { jmp[winmm.mciFreeCommandResource] } }
__declspec(naked) void _mciGetCreatorTask() { _asm { jmp[winmm.mciGetCreatorTask] } }
__declspec(naked) void _mciGetDeviceIDA() { _asm { jmp[winmm.mciGetDeviceIDA] } }
__declspec(naked) void _mciGetDeviceIDFromElementIDA() { _asm { jmp[winmm.mciGetDeviceIDFromElementIDA] } }
__declspec(naked) void _mciGetDeviceIDFromElementIDW() { _asm { jmp[winmm.mciGetDeviceIDFromElementIDW] } }
__declspec(naked) void _mciGetDeviceIDW() { _asm { jmp[winmm.mciGetDeviceIDW] } }
__declspec(naked) void _mciGetDriverData() { _asm { jmp[winmm.mciGetDriverData] } }
__declspec(naked) void _mciGetErrorStringA() { _asm { jmp[winmm.mciGetErrorStringA] } }
__declspec(naked) void _mciGetErrorStringW() { _asm { jmp[winmm.mciGetErrorStringW] } }
__declspec(naked) void _mciGetYieldProc() { _asm { jmp[winmm.mciGetYieldProc] } }
__declspec(naked) void _mciLoadCommandResource() { _asm { jmp[winmm.mciLoadCommandResource] } }
__declspec(naked) void _mciSendCommandA() { _asm { jmp[winmm.mciSendCommandA] } }
__declspec(naked) void _mciSendCommandW() { _asm { jmp[winmm.mciSendCommandW] } }
__declspec(naked) void _mciSendStringA() { _asm { jmp[winmm.mciSendStringA] } }
__declspec(naked) void _mciSendStringW() { _asm { jmp[winmm.mciSendStringW] } }
__declspec(naked) void _mciSetDriverData() { _asm { jmp[winmm.mciSetDriverData] } }
__declspec(naked) void _mciSetYieldProc() { _asm { jmp[winmm.mciSetYieldProc] } }
__declspec(naked) void _mid32Message() { _asm { jmp[winmm.mid32Message] } }
__declspec(naked) void _midiConnect() { _asm { jmp[winmm.midiConnect] } }
__declspec(naked) void _midiDisconnect() { _asm { jmp[winmm.midiDisconnect] } }
__declspec(naked) void _midiInAddBuffer() { _asm { jmp[winmm.midiInAddBuffer] } }
__declspec(naked) void _midiInClose() { _asm { jmp[winmm.midiInClose] } }
__declspec(naked) void _midiInGetDevCapsA() { _asm { jmp[winmm.midiInGetDevCapsA] } }
__declspec(naked) void _midiInGetDevCapsW() { _asm { jmp[winmm.midiInGetDevCapsW] } }
__declspec(naked) void _midiInGetErrorTextA() { _asm { jmp[winmm.midiInGetErrorTextA] } }
__declspec(naked) void _midiInGetErrorTextW() { _asm { jmp[winmm.midiInGetErrorTextW] } }
__declspec(naked) void _midiInGetID() { _asm { jmp[winmm.midiInGetID] } }
__declspec(naked) void _midiInGetNumDevs() { _asm { jmp[winmm.midiInGetNumDevs] } }
__declspec(naked) void _midiInMessage() { _asm { jmp[winmm.midiInMessage] } }
__declspec(naked) void _midiInOpen() { _asm { jmp[winmm.midiInOpen] } }
__declspec(naked) void _midiInPrepareHeader() { _asm { jmp[winmm.midiInPrepareHeader] } }
__declspec(naked) void _midiInReset() { _asm { jmp[winmm.midiInReset] } }
__declspec(naked) void _midiInStart() { _asm { jmp[winmm.midiInStart] } }
__declspec(naked) void _midiInStop() { _asm { jmp[winmm.midiInStop] } }
__declspec(naked) void _midiInUnprepareHeader() { _asm { jmp[winmm.midiInUnprepareHeader] } }
__declspec(naked) void _midiOutCacheDrumPatches() { _asm { jmp[winmm.midiOutCacheDrumPatches] } }
__declspec(naked) void _midiOutCachePatches() { _asm { jmp[winmm.midiOutCachePatches] } }
__declspec(naked) void _midiOutClose() { _asm { jmp[winmm.midiOutClose] } }
__declspec(naked) void _midiOutGetDevCapsA() { _asm { jmp[winmm.midiOutGetDevCapsA] } }
__declspec(naked) void _midiOutGetDevCapsW() { _asm { jmp[winmm.midiOutGetDevCapsW] } }
__declspec(naked) void _midiOutGetErrorTextA() { _asm { jmp[winmm.midiOutGetErrorTextA] } }
__declspec(naked) void _midiOutGetErrorTextW() { _asm { jmp[winmm.midiOutGetErrorTextW] } }
__declspec(naked) void _midiOutGetID() { _asm { jmp[winmm.midiOutGetID] } }
__declspec(naked) void _midiOutGetNumDevs() { _asm { jmp[winmm.midiOutGetNumDevs] } }
__declspec(naked) void _midiOutGetVolume() { _asm { jmp[winmm.midiOutGetVolume] } }
__declspec(naked) void _midiOutLongMsg() { _asm { jmp[winmm.midiOutLongMsg] } }
__declspec(naked) void _midiOutMessage() { _asm { jmp[winmm.midiOutMessage] } }
__declspec(naked) void _midiOutOpen() { _asm { jmp[winmm.midiOutOpen] } }
__declspec(naked) void _midiOutPrepareHeader() { _asm { jmp[winmm.midiOutPrepareHeader] } }
__declspec(naked) void _midiOutReset() { _asm { jmp[winmm.midiOutReset] } }
__declspec(naked) void _midiOutSetVolume() { _asm { jmp[winmm.midiOutSetVolume] } }
__declspec(naked) void _midiOutShortMsg() { _asm { jmp[winmm.midiOutShortMsg] } }
__declspec(naked) void _midiOutUnprepareHeader() { _asm { jmp[winmm.midiOutUnprepareHeader] } }
__declspec(naked) void _midiStreamClose() { _asm { jmp[winmm.midiStreamClose] } }
__declspec(naked) void _midiStreamOpen() { _asm { jmp[winmm.midiStreamOpen] } }
__declspec(naked) void _midiStreamOut() { _asm { jmp[winmm.midiStreamOut] } }
__declspec(naked) void _midiStreamPause() { _asm { jmp[winmm.midiStreamPause] } }
__declspec(naked) void _midiStreamPosition() { _asm { jmp[winmm.midiStreamPosition] } }
__declspec(naked) void _midiStreamProperty() { _asm { jmp[winmm.midiStreamProperty] } }
__declspec(naked) void _midiStreamRestart() { _asm { jmp[winmm.midiStreamRestart] } }
__declspec(naked) void _midiStreamStop() { _asm { jmp[winmm.midiStreamStop] } }
__declspec(naked) void _mixerClose() { _asm { jmp[winmm.mixerClose] } }
__declspec(naked) void _mixerGetControlDetailsA() { _asm { jmp[winmm.mixerGetControlDetailsA] } }
__declspec(naked) void _mixerGetControlDetailsW() { _asm { jmp[winmm.mixerGetControlDetailsW] } }
__declspec(naked) void _mixerGetDevCapsA() { _asm { jmp[winmm.mixerGetDevCapsA] } }
__declspec(naked) void _mixerGetDevCapsW() { _asm { jmp[winmm.mixerGetDevCapsW] } }
__declspec(naked) void _mixerGetID() { _asm { jmp[winmm.mixerGetID] } }
__declspec(naked) void _mixerGetLineControlsA() { _asm { jmp[winmm.mixerGetLineControlsA] } }
__declspec(naked) void _mixerGetLineControlsW() { _asm { jmp[winmm.mixerGetLineControlsW] } }
__declspec(naked) void _mixerGetLineInfoA() { _asm { jmp[winmm.mixerGetLineInfoA] } }
__declspec(naked) void _mixerGetLineInfoW() { _asm { jmp[winmm.mixerGetLineInfoW] } }
__declspec(naked) void _mixerGetNumDevs() { _asm { jmp[winmm.mixerGetNumDevs] } }
__declspec(naked) void _mixerMessage() { _asm { jmp[winmm.mixerMessage] } }
__declspec(naked) void _mixerOpen() { _asm { jmp[winmm.mixerOpen] } }
__declspec(naked) void _mixerSetControlDetails() { _asm { jmp[winmm.mixerSetControlDetails] } }
__declspec(naked) void _mmDrvInstall() { _asm { jmp[winmm.mmDrvInstall] } }
__declspec(naked) void _mmGetCurrentTask() { _asm { jmp[winmm.mmGetCurrentTask] } }
__declspec(naked) void _mmTaskBlock() { _asm { jmp[winmm.mmTaskBlock] } }
__declspec(naked) void _mmTaskCreate() { _asm { jmp[winmm.mmTaskCreate] } }
__declspec(naked) void _mmTaskSignal() { _asm { jmp[winmm.mmTaskSignal] } }
__declspec(naked) void _mmTaskYield() { _asm { jmp[winmm.mmTaskYield] } }
__declspec(naked) void _mmioAdvance() { _asm { jmp[winmm.mmioAdvance] } }
__declspec(naked) void _mmioAscend() { _asm { jmp[winmm.mmioAscend] } }
__declspec(naked) void _mmioClose() { _asm { jmp[winmm.mmioClose] } }
__declspec(naked) void _mmioCreateChunk() { _asm { jmp[winmm.mmioCreateChunk] } }
__declspec(naked) void _mmioDescend() { _asm { jmp[winmm.mmioDescend] } }
__declspec(naked) void _mmioFlush() { _asm { jmp[winmm.mmioFlush] } }
__declspec(naked) void _mmioGetInfo() { _asm { jmp[winmm.mmioGetInfo] } }
__declspec(naked) void _mmioInstallIOProcA() { _asm { jmp[winmm.mmioInstallIOProcA] } }
__declspec(naked) void _mmioInstallIOProcW() { _asm { jmp[winmm.mmioInstallIOProcW] } }
__declspec(naked) void _mmioOpenA() { _asm { jmp[winmm.mmioOpenA] } }
__declspec(naked) void _mmioOpenW() { _asm { jmp[winmm.mmioOpenW] } }
__declspec(naked) void _mmioRead() { _asm { jmp[winmm.mmioRead] } }
__declspec(naked) void _mmioRenameA() { _asm { jmp[winmm.mmioRenameA] } }
__declspec(naked) void _mmioRenameW() { _asm { jmp[winmm.mmioRenameW] } }
__declspec(naked) void _mmioSeek() { _asm { jmp[winmm.mmioSeek] } }
__declspec(naked) void _mmioSendMessage() { _asm { jmp[winmm.mmioSendMessage] } }
__declspec(naked) void _mmioSetBuffer() { _asm { jmp[winmm.mmioSetBuffer] } }
__declspec(naked) void _mmioSetInfo() { _asm { jmp[winmm.mmioSetInfo] } }
__declspec(naked) void _mmioStringToFOURCCA() { _asm { jmp[winmm.mmioStringToFOURCCA] } }
__declspec(naked) void _mmioStringToFOURCCW() { _asm { jmp[winmm.mmioStringToFOURCCW] } }
__declspec(naked) void _mmioWrite() { _asm { jmp[winmm.mmioWrite] } }
__declspec(naked) void _mmsystemGetVersion() { _asm { jmp[winmm.mmsystemGetVersion] } }
__declspec(naked) void _mod32Message() { _asm { jmp[winmm.mod32Message] } }
__declspec(naked) void _mxd32Message() { _asm { jmp[winmm.mxd32Message] } }
__declspec(naked) void _sndPlaySoundA() { _asm { jmp[winmm.sndPlaySoundA] } }
__declspec(naked) void _sndPlaySoundW() { _asm { jmp[winmm.sndPlaySoundW] } }
__declspec(naked) void _tid32Message() { _asm { jmp[winmm.tid32Message] } }
__declspec(naked) void _timeBeginPeriod() { _asm { jmp[winmm.timeBeginPeriod] } }
__declspec(naked) void _timeEndPeriod() { _asm { jmp[winmm.timeEndPeriod] } }
__declspec(naked) void _timeGetDevCaps() { _asm { jmp[winmm.timeGetDevCaps] } }
__declspec(naked) void _timeGetSystemTime() { _asm { jmp[winmm.timeGetSystemTime] } }
__declspec(naked) void _timeGetTime() { _asm { jmp[winmm.timeGetTime] } }
__declspec(naked) void _timeKillEvent() { _asm { jmp[winmm.timeKillEvent] } }
__declspec(naked) void _timeSetEvent() { _asm { jmp[winmm.timeSetEvent] } }
__declspec(naked) void _waveInAddBuffer() { _asm { jmp[winmm.waveInAddBuffer] } }
__declspec(naked) void _waveInClose() { _asm { jmp[winmm.waveInClose] } }
__declspec(naked) void _waveInGetDevCapsA() { _asm { jmp[winmm.waveInGetDevCapsA] } }
__declspec(naked) void _waveInGetDevCapsW() { _asm { jmp[winmm.waveInGetDevCapsW] } }
__declspec(naked) void _waveInGetErrorTextA() { _asm { jmp[winmm.waveInGetErrorTextA] } }
__declspec(naked) void _waveInGetErrorTextW() { _asm { jmp[winmm.waveInGetErrorTextW] } }
__declspec(naked) void _waveInGetID() { _asm { jmp[winmm.waveInGetID] } }
__declspec(naked) void _waveInGetNumDevs() { _asm { jmp[winmm.waveInGetNumDevs] } }
__declspec(naked) void _waveInGetPosition() { _asm { jmp[winmm.waveInGetPosition] } }
__declspec(naked) void _waveInMessage() { _asm { jmp[winmm.waveInMessage] } }
__declspec(naked) void _waveInOpen() { _asm { jmp[winmm.waveInOpen] } }
__declspec(naked) void _waveInPrepareHeader() { _asm { jmp[winmm.waveInPrepareHeader] } }
__declspec(naked) void _waveInReset() { _asm { jmp[winmm.waveInReset] } }
__declspec(naked) void _waveInStart() { _asm { jmp[winmm.waveInStart] } }
__declspec(naked) void _waveInStop() { _asm { jmp[winmm.waveInStop] } }
__declspec(naked) void _waveInUnprepareHeader() { _asm { jmp[winmm.waveInUnprepareHeader] } }
__declspec(naked) void _waveOutBreakLoop() { _asm { jmp[winmm.waveOutBreakLoop] } }
__declspec(naked) void _waveOutClose() { _asm { jmp[winmm.waveOutClose] } }
__declspec(naked) void _waveOutGetDevCapsA() { _asm { jmp[winmm.waveOutGetDevCapsA] } }
__declspec(naked) void _waveOutGetDevCapsW() { _asm { jmp[winmm.waveOutGetDevCapsW] } }
__declspec(naked) void _waveOutGetErrorTextA() { _asm { jmp[winmm.waveOutGetErrorTextA] } }
__declspec(naked) void _waveOutGetErrorTextW() { _asm { jmp[winmm.waveOutGetErrorTextW] } }
__declspec(naked) void _waveOutGetID() { _asm { jmp[winmm.waveOutGetID] } }
__declspec(naked) void _waveOutGetNumDevs() { _asm { jmp[winmm.waveOutGetNumDevs] } }
__declspec(naked) void _waveOutGetPitch() { _asm { jmp[winmm.waveOutGetPitch] } }
__declspec(naked) void _waveOutGetPlaybackRate() { _asm { jmp[winmm.waveOutGetPlaybackRate] } }
__declspec(naked) void _waveOutGetPosition() { _asm { jmp[winmm.waveOutGetPosition] } }
__declspec(naked) void _waveOutGetVolume() { _asm { jmp[winmm.waveOutGetVolume] } }
__declspec(naked) void _waveOutMessage() { _asm { jmp[winmm.waveOutMessage] } }
__declspec(naked) void _waveOutOpen() { _asm { jmp[winmm.waveOutOpen] } }
__declspec(naked) void _waveOutPause() { _asm { jmp[winmm.waveOutPause] } }
__declspec(naked) void _waveOutPrepareHeader() { _asm { jmp[winmm.waveOutPrepareHeader] } }
__declspec(naked) void _waveOutReset() { _asm { jmp[winmm.waveOutReset] } }
__declspec(naked) void _waveOutRestart() { _asm { jmp[winmm.waveOutRestart] } }
__declspec(naked) void _waveOutSetPitch() { _asm { jmp[winmm.waveOutSetPitch] } }
__declspec(naked) void _waveOutSetPlaybackRate() { _asm { jmp[winmm.waveOutSetPlaybackRate] } }
__declspec(naked) void _waveOutSetVolume() { _asm { jmp[winmm.waveOutSetVolume] } }
__declspec(naked) void _waveOutUnprepareHeader() { _asm { jmp[winmm.waveOutUnprepareHeader] } }
__declspec(naked) void _waveOutWrite() { _asm { jmp[winmm.waveOutWrite] } }
__declspec(naked) void _wid32Message() { _asm { jmp[winmm.wid32Message] } }
__declspec(naked) void _wod32Message() { _asm { jmp[winmm.wod32Message] } }

__declspec(naked) void _acmDriverAddA() { _asm { jmp[msacm32.acmDriverAddA] } }
__declspec(naked) void _acmDriverAddW() { _asm { jmp[msacm32.acmDriverAddW] } }
__declspec(naked) void _acmDriverClose() { _asm { jmp[msacm32.acmDriverClose] } }
__declspec(naked) void _acmDriverDetailsA() { _asm { jmp[msacm32.acmDriverDetailsA] } }
__declspec(naked) void _acmDriverDetailsW() { _asm { jmp[msacm32.acmDriverDetailsW] } }
__declspec(naked) void _acmDriverEnum() { _asm { jmp[msacm32.acmDriverEnum] } }
__declspec(naked) void _acmDriverID() { _asm { jmp[msacm32.acmDriverID] } }
__declspec(naked) void _acmDriverMessage() { _asm { jmp[msacm32.acmDriverMessage] } }
__declspec(naked) void _acmDriverOpen() { _asm { jmp[msacm32.acmDriverOpen] } }
__declspec(naked) void _acmDriverPriority() { _asm { jmp[msacm32.acmDriverPriority] } }
__declspec(naked) void _acmDriverRemove() { _asm { jmp[msacm32.acmDriverRemove] } }
__declspec(naked) void _acmFilterChooseA() { _asm { jmp[msacm32.acmFilterChooseA] } }
__declspec(naked) void _acmFilterChooseW() { _asm { jmp[msacm32.acmFilterChooseW] } }
__declspec(naked) void _acmFilterDetailsA() { _asm { jmp[msacm32.acmFilterDetailsA] } }
__declspec(naked) void _acmFilterDetailsW() { _asm { jmp[msacm32.acmFilterDetailsW] } }
__declspec(naked) void _acmFilterEnumA() { _asm { jmp[msacm32.acmFilterEnumA] } }
__declspec(naked) void _acmFilterEnumW() { _asm { jmp[msacm32.acmFilterEnumW] } }
__declspec(naked) void _acmFilterTagDetailsA() { _asm { jmp[msacm32.acmFilterTagDetailsA] } }
__declspec(naked) void _acmFilterTagDetailsW() { _asm { jmp[msacm32.acmFilterTagDetailsW] } }
__declspec(naked) void _acmFilterTagEnumA() { _asm { jmp[msacm32.acmFilterTagEnumA] } }
__declspec(naked) void _acmFilterTagEnumW() { _asm { jmp[msacm32.acmFilterTagEnumW] } }
__declspec(naked) void _acmFormatChooseA() { _asm { jmp[msacm32.acmFormatChooseA] } }
__declspec(naked) void _acmFormatChooseW() { _asm { jmp[msacm32.acmFormatChooseW] } }
__declspec(naked) void _acmFormatDetailsA() { _asm { jmp[msacm32.acmFormatDetailsA] } }
__declspec(naked) void _acmFormatDetailsW() { _asm { jmp[msacm32.acmFormatDetailsW] } }
__declspec(naked) void _acmFormatEnumA() { _asm { jmp[msacm32.acmFormatEnumA] } }
__declspec(naked) void _acmFormatEnumW() { _asm { jmp[msacm32.acmFormatEnumW] } }
__declspec(naked) void _acmFormatSuggest() { _asm { jmp[msacm32.acmFormatSuggest] } }
__declspec(naked) void _acmFormatTagDetailsA() { _asm { jmp[msacm32.acmFormatTagDetailsA] } }
__declspec(naked) void _acmFormatTagDetailsW() { _asm { jmp[msacm32.acmFormatTagDetailsW] } }
__declspec(naked) void _acmFormatTagEnumA() { _asm { jmp[msacm32.acmFormatTagEnumA] } }
__declspec(naked) void _acmFormatTagEnumW() { _asm { jmp[msacm32.acmFormatTagEnumW] } }
__declspec(naked) void _acmGetVersion() { _asm { jmp[msacm32.acmGetVersion] } }
__declspec(naked) void _acmMetrics() { _asm { jmp[msacm32.acmMetrics] } }
__declspec(naked) void _acmStreamClose() { _asm { jmp[msacm32.acmStreamClose] } }
__declspec(naked) void _acmStreamConvert() { _asm { jmp[msacm32.acmStreamConvert] } }
__declspec(naked) void _acmStreamMessage() { _asm { jmp[msacm32.acmStreamMessage] } }
__declspec(naked) void _acmStreamOpen() { _asm { jmp[msacm32.acmStreamOpen] } }
__declspec(naked) void _acmStreamPrepareHeader() { _asm { jmp[msacm32.acmStreamPrepareHeader] } }
__declspec(naked) void _acmStreamReset() { _asm { jmp[msacm32.acmStreamReset] } }
__declspec(naked) void _acmStreamSize() { _asm { jmp[msacm32.acmStreamSize] } }
__declspec(naked) void _acmStreamUnprepareHeader() { _asm { jmp[msacm32.acmStreamUnprepareHeader] } }

__declspec(naked) void _DrawDibBegin() { _asm { jmp[msvfw32.DrawDibBegin] } }
__declspec(naked) void _DrawDibChangePalette() { _asm { jmp[msvfw32.DrawDibChangePalette] } }
__declspec(naked) void _DrawDibClose() { _asm { jmp[msvfw32.DrawDibClose] } }
__declspec(naked) void _DrawDibDraw() { _asm { jmp[msvfw32.DrawDibDraw] } }
__declspec(naked) void _DrawDibEnd() { _asm { jmp[msvfw32.DrawDibEnd] } }
__declspec(naked) void _DrawDibGetBuffer() { _asm { jmp[msvfw32.DrawDibGetBuffer] } }
__declspec(naked) void _DrawDibGetPalette() { _asm { jmp[msvfw32.DrawDibGetPalette] } }
__declspec(naked) void _DrawDibOpen() { _asm { jmp[msvfw32.DrawDibOpen] } }
__declspec(naked) void _DrawDibProfileDisplay() { _asm { jmp[msvfw32.DrawDibProfileDisplay] } }
__declspec(naked) void _DrawDibRealize() { _asm { jmp[msvfw32.DrawDibRealize] } }
__declspec(naked) void _DrawDibSetPalette() { _asm { jmp[msvfw32.DrawDibSetPalette] } }
__declspec(naked) void _DrawDibStart() { _asm { jmp[msvfw32.DrawDibStart] } }
__declspec(naked) void _DrawDibStop() { _asm { jmp[msvfw32.DrawDibStop] } }
__declspec(naked) void _DrawDibTime() { _asm { jmp[msvfw32.DrawDibTime] } }
__declspec(naked) void _GetOpenFileNamePreview() { _asm { jmp[msvfw32.GetOpenFileNamePreview] } }
__declspec(naked) void _GetOpenFileNamePreviewA() { _asm { jmp[msvfw32.GetOpenFileNamePreviewA] } }
__declspec(naked) void _GetOpenFileNamePreviewW() { _asm { jmp[msvfw32.GetOpenFileNamePreviewW] } }
__declspec(naked) void _GetSaveFileNamePreviewA() { _asm { jmp[msvfw32.GetSaveFileNamePreviewA] } }
__declspec(naked) void _GetSaveFileNamePreviewW() { _asm { jmp[msvfw32.GetSaveFileNamePreviewW] } }
__declspec(naked) void _ICClose() { _asm { jmp[msvfw32.ICClose] } }
__declspec(naked) void _ICCompress() { _asm { jmp[msvfw32.ICCompress] } }
__declspec(naked) void _ICCompressorChoose() { _asm { jmp[msvfw32.ICCompressorChoose] } }
__declspec(naked) void _ICCompressorFree() { _asm { jmp[msvfw32.ICCompressorFree] } }
__declspec(naked) void _ICDecompress() { _asm { jmp[msvfw32.ICDecompress] } }
__declspec(naked) void _ICDraw() { _asm { jmp[msvfw32.ICDraw] } }
__declspec(naked) void _ICDrawBegin() { _asm { jmp[msvfw32.ICDrawBegin] } }
__declspec(naked) void _ICGetDisplayFormat() { _asm { jmp[msvfw32.ICGetDisplayFormat] } }
__declspec(naked) void _ICGetInfo() { _asm { jmp[msvfw32.ICGetInfo] } }
__declspec(naked) void _ICImageCompress() { _asm { jmp[msvfw32.ICImageCompress] } }
__declspec(naked) void _ICImageDecompress() { _asm { jmp[msvfw32.ICImageDecompress] } }
__declspec(naked) void _ICInfo() { _asm { jmp[msvfw32.ICInfo] } }
__declspec(naked) void _ICInstall() { _asm { jmp[msvfw32.ICInstall] } }
__declspec(naked) void _ICLocate() { _asm { jmp[msvfw32.ICLocate] } }
__declspec(naked) void _ICMThunk32() { _asm { jmp[msvfw32.ICMThunk32] } }
__declspec(naked) void _ICOpen() { _asm { jmp[msvfw32.ICOpen] } }
__declspec(naked) void _ICOpenFunction() { _asm { jmp[msvfw32.ICOpenFunction] } }
__declspec(naked) void _ICRemove() { _asm { jmp[msvfw32.ICRemove] } }
__declspec(naked) void _ICSendMessage() { _asm { jmp[msvfw32.ICSendMessage] } }
__declspec(naked) void _ICSeqCompressFrame() { _asm { jmp[msvfw32.ICSeqCompressFrame] } }
__declspec(naked) void _ICSeqCompressFrameEnd() { _asm { jmp[msvfw32.ICSeqCompressFrameEnd] } }
__declspec(naked) void _ICSeqCompressFrameStart() { _asm { jmp[msvfw32.ICSeqCompressFrameStart] } }
__declspec(naked) void _MCIWndCreate() { _asm { jmp[msvfw32.MCIWndCreate] } }
__declspec(naked) void _MCIWndCreateA() { _asm { jmp[msvfw32.MCIWndCreateA] } }
__declspec(naked) void _MCIWndCreateW() { _asm { jmp[msvfw32.MCIWndCreateW] } }
__declspec(naked) void _MCIWndRegisterClass() { _asm { jmp[msvfw32.MCIWndRegisterClass] } }
__declspec(naked) void _StretchDIB() { _asm { jmp[msvfw32.StretchDIB] } }
__declspec(naked) void _VideoForWindowsVersion() { _asm { jmp[msvfw32.VideoForWindowsVersion] } }

__declspec(naked) void _AppCacheCheckManifest() { _asm { jmp[wininet.AppCacheCheckManifest] } }
__declspec(naked) void _AppCacheCloseHandle() { _asm { jmp[wininet.AppCacheCloseHandle] } }
__declspec(naked) void _AppCacheCreateAndCommitFile() { _asm { jmp[wininet.AppCacheCreateAndCommitFile] } }
__declspec(naked) void _AppCacheDeleteGroup() { _asm { jmp[wininet.AppCacheDeleteGroup] } }
__declspec(naked) void _AppCacheDeleteIEGroup() { _asm { jmp[wininet.AppCacheDeleteIEGroup] } }
__declspec(naked) void _AppCacheDuplicateHandle() { _asm { jmp[wininet.AppCacheDuplicateHandle] } }
__declspec(naked) void _AppCacheFinalize() { _asm { jmp[wininet.AppCacheFinalize] } }
__declspec(naked) void _AppCacheFreeDownloadList() { _asm { jmp[wininet.AppCacheFreeDownloadList] } }
__declspec(naked) void _AppCacheFreeGroupList() { _asm { jmp[wininet.AppCacheFreeGroupList] } }
__declspec(naked) void _AppCacheFreeIESpace() { _asm { jmp[wininet.AppCacheFreeIESpace] } }
__declspec(naked) void _AppCacheFreeSpace() { _asm { jmp[wininet.AppCacheFreeSpace] } }
__declspec(naked) void _AppCacheGetDownloadList() { _asm { jmp[wininet.AppCacheGetDownloadList] } }
__declspec(naked) void _AppCacheGetFallbackUrl() { _asm { jmp[wininet.AppCacheGetFallbackUrl] } }
__declspec(naked) void _AppCacheGetGroupList() { _asm { jmp[wininet.AppCacheGetGroupList] } }
__declspec(naked) void _AppCacheGetIEGroupList() { _asm { jmp[wininet.AppCacheGetIEGroupList] } }
__declspec(naked) void _AppCacheGetInfo() { _asm { jmp[wininet.AppCacheGetInfo] } }
__declspec(naked) void _AppCacheGetManifestUrl() { _asm { jmp[wininet.AppCacheGetManifestUrl] } }
__declspec(naked) void _AppCacheLookup() { _asm { jmp[wininet.AppCacheLookup] } }
__declspec(naked) void _CommitUrlCacheEntryA() { _asm { jmp[wininet.CommitUrlCacheEntryA] } }
__declspec(naked) void _CommitUrlCacheEntryBinaryBlob() { _asm { jmp[wininet.CommitUrlCacheEntryBinaryBlob] } }
__declspec(naked) void _CommitUrlCacheEntryW() { _asm { jmp[wininet.CommitUrlCacheEntryW] } }
__declspec(naked) void _CreateMD5SSOHash() { _asm { jmp[wininet.CreateMD5SSOHash] } }
__declspec(naked) void _CreateUrlCacheContainerA() { _asm { jmp[wininet.CreateUrlCacheContainerA] } }
__declspec(naked) void _CreateUrlCacheContainerW() { _asm { jmp[wininet.CreateUrlCacheContainerW] } }
__declspec(naked) void _CreateUrlCacheEntryA() { _asm { jmp[wininet.CreateUrlCacheEntryA] } }
__declspec(naked) void _CreateUrlCacheEntryExW() { _asm { jmp[wininet.CreateUrlCacheEntryExW] } }
__declspec(naked) void _CreateUrlCacheEntryW() { _asm { jmp[wininet.CreateUrlCacheEntryW] } }
__declspec(naked) void _CreateUrlCacheGroup() { _asm { jmp[wininet.CreateUrlCacheGroup] } }
__declspec(naked) void _DeleteIE3Cache() { _asm { jmp[wininet.DeleteIE3Cache] } }
__declspec(naked) void _DeleteUrlCacheContainerA() { _asm { jmp[wininet.DeleteUrlCacheContainerA] } }
__declspec(naked) void _DeleteUrlCacheContainerW() { _asm { jmp[wininet.DeleteUrlCacheContainerW] } }
__declspec(naked) void _DeleteUrlCacheEntry() { _asm { jmp[wininet.DeleteUrlCacheEntry] } }
__declspec(naked) void _DeleteUrlCacheEntryA() { _asm { jmp[wininet.DeleteUrlCacheEntryA] } }
__declspec(naked) void _DeleteUrlCacheEntryW() { _asm { jmp[wininet.DeleteUrlCacheEntryW] } }
__declspec(naked) void _DeleteUrlCacheGroup() { _asm { jmp[wininet.DeleteUrlCacheGroup] } }
__declspec(naked) void _DeleteWpadCacheForNetworks() { _asm { jmp[wininet.DeleteWpadCacheForNetworks] } }
__declspec(naked) void _DetectAutoProxyUrl() { _asm { jmp[wininet.DetectAutoProxyUrl] } }
__declspec(naked) void _DispatchAPICall() { _asm { jmp[wininet.DispatchAPICall] } }
//__declspec(naked) void _DllCanUnloadNow() { _asm { jmp[wininet.DllCanUnloadNow] } }
//__declspec(naked) void _DllGetClassObject() { _asm { jmp[wininet.DllGetClassObject] } }
__declspec(naked) void _DllInstall() { _asm { jmp[wininet.DllInstall] } }
//__declspec(naked) void _DllRegisterServer() { _asm { jmp[wininet.DllRegisterServer] } }
//__declspec(naked) void _DllUnregisterServer() { _asm { jmp[wininet.DllUnregisterServer] } }
__declspec(naked) void _FindCloseUrlCache() { _asm { jmp[wininet.FindCloseUrlCache] } }
__declspec(naked) void _FindFirstUrlCacheContainerA() { _asm { jmp[wininet.FindFirstUrlCacheContainerA] } }
__declspec(naked) void _FindFirstUrlCacheContainerW() { _asm { jmp[wininet.FindFirstUrlCacheContainerW] } }
__declspec(naked) void _FindFirstUrlCacheEntryA() { _asm { jmp[wininet.FindFirstUrlCacheEntryA] } }
__declspec(naked) void _FindFirstUrlCacheEntryExA() { _asm { jmp[wininet.FindFirstUrlCacheEntryExA] } }
__declspec(naked) void _FindFirstUrlCacheEntryExW() { _asm { jmp[wininet.FindFirstUrlCacheEntryExW] } }
__declspec(naked) void _FindFirstUrlCacheEntryW() { _asm { jmp[wininet.FindFirstUrlCacheEntryW] } }
__declspec(naked) void _FindFirstUrlCacheGroup() { _asm { jmp[wininet.FindFirstUrlCacheGroup] } }
__declspec(naked) void _FindNextUrlCacheContainerA() { _asm { jmp[wininet.FindNextUrlCacheContainerA] } }
__declspec(naked) void _FindNextUrlCacheContainerW() { _asm { jmp[wininet.FindNextUrlCacheContainerW] } }
__declspec(naked) void _FindNextUrlCacheEntryA() { _asm { jmp[wininet.FindNextUrlCacheEntryA] } }
__declspec(naked) void _FindNextUrlCacheEntryExA() { _asm { jmp[wininet.FindNextUrlCacheEntryExA] } }
__declspec(naked) void _FindNextUrlCacheEntryExW() { _asm { jmp[wininet.FindNextUrlCacheEntryExW] } }
__declspec(naked) void _FindNextUrlCacheEntryW() { _asm { jmp[wininet.FindNextUrlCacheEntryW] } }
__declspec(naked) void _FindNextUrlCacheGroup() { _asm { jmp[wininet.FindNextUrlCacheGroup] } }
__declspec(naked) void _ForceNexusLookup() { _asm { jmp[wininet.ForceNexusLookup] } }
__declspec(naked) void _ForceNexusLookupExW() { _asm { jmp[wininet.ForceNexusLookupExW] } }
__declspec(naked) void _FreeUrlCacheSpaceA() { _asm { jmp[wininet.FreeUrlCacheSpaceA] } }
__declspec(naked) void _FreeUrlCacheSpaceW() { _asm { jmp[wininet.FreeUrlCacheSpaceW] } }
__declspec(naked) void _FtpCommandA() { _asm { jmp[wininet.FtpCommandA] } }
__declspec(naked) void _FtpCommandW() { _asm { jmp[wininet.FtpCommandW] } }
__declspec(naked) void _FtpCreateDirectoryA() { _asm { jmp[wininet.FtpCreateDirectoryA] } }
__declspec(naked) void _FtpCreateDirectoryW() { _asm { jmp[wininet.FtpCreateDirectoryW] } }
__declspec(naked) void _FtpDeleteFileA() { _asm { jmp[wininet.FtpDeleteFileA] } }
__declspec(naked) void _FtpDeleteFileW() { _asm { jmp[wininet.FtpDeleteFileW] } }
__declspec(naked) void _FtpFindFirstFileA() { _asm { jmp[wininet.FtpFindFirstFileA] } }
__declspec(naked) void _FtpFindFirstFileW() { _asm { jmp[wininet.FtpFindFirstFileW] } }
__declspec(naked) void _FtpGetCurrentDirectoryA() { _asm { jmp[wininet.FtpGetCurrentDirectoryA] } }
__declspec(naked) void _FtpGetCurrentDirectoryW() { _asm { jmp[wininet.FtpGetCurrentDirectoryW] } }
__declspec(naked) void _FtpGetFileA() { _asm { jmp[wininet.FtpGetFileA] } }
__declspec(naked) void _FtpGetFileEx() { _asm { jmp[wininet.FtpGetFileEx] } }
__declspec(naked) void _FtpGetFileSize() { _asm { jmp[wininet.FtpGetFileSize] } }
__declspec(naked) void _FtpGetFileW() { _asm { jmp[wininet.FtpGetFileW] } }
__declspec(naked) void _FtpOpenFileA() { _asm { jmp[wininet.FtpOpenFileA] } }
__declspec(naked) void _FtpOpenFileW() { _asm { jmp[wininet.FtpOpenFileW] } }
__declspec(naked) void _FtpPutFileA() { _asm { jmp[wininet.FtpPutFileA] } }
__declspec(naked) void _FtpPutFileEx() { _asm { jmp[wininet.FtpPutFileEx] } }
__declspec(naked) void _FtpPutFileW() { _asm { jmp[wininet.FtpPutFileW] } }
__declspec(naked) void _FtpRemoveDirectoryA() { _asm { jmp[wininet.FtpRemoveDirectoryA] } }
__declspec(naked) void _FtpRemoveDirectoryW() { _asm { jmp[wininet.FtpRemoveDirectoryW] } }
__declspec(naked) void _FtpRenameFileA() { _asm { jmp[wininet.FtpRenameFileA] } }
__declspec(naked) void _FtpRenameFileW() { _asm { jmp[wininet.FtpRenameFileW] } }
__declspec(naked) void _FtpSetCurrentDirectoryA() { _asm { jmp[wininet.FtpSetCurrentDirectoryA] } }
__declspec(naked) void _FtpSetCurrentDirectoryW() { _asm { jmp[wininet.FtpSetCurrentDirectoryW] } }
__declspec(naked) void __GetFileExtensionFromUrl() { _asm { jmp[wininet._GetFileExtensionFromUrl] } }
__declspec(naked) void _GetProxyDllInfo() { _asm { jmp[wininet.GetProxyDllInfo] } }
__declspec(naked) void _GetUrlCacheConfigInfoA() { _asm { jmp[wininet.GetUrlCacheConfigInfoA] } }
__declspec(naked) void _GetUrlCacheConfigInfoW() { _asm { jmp[wininet.GetUrlCacheConfigInfoW] } }
__declspec(naked) void _GetUrlCacheEntryBinaryBlob() { _asm { jmp[wininet.GetUrlCacheEntryBinaryBlob] } }
__declspec(naked) void _GetUrlCacheEntryInfoA() { _asm { jmp[wininet.GetUrlCacheEntryInfoA] } }
__declspec(naked) void _GetUrlCacheEntryInfoExA() { _asm { jmp[wininet.GetUrlCacheEntryInfoExA] } }
__declspec(naked) void _GetUrlCacheEntryInfoExW() { _asm { jmp[wininet.GetUrlCacheEntryInfoExW] } }
__declspec(naked) void _GetUrlCacheEntryInfoW() { _asm { jmp[wininet.GetUrlCacheEntryInfoW] } }
__declspec(naked) void _GetUrlCacheGroupAttributeA() { _asm { jmp[wininet.GetUrlCacheGroupAttributeA] } }
__declspec(naked) void _GetUrlCacheGroupAttributeW() { _asm { jmp[wininet.GetUrlCacheGroupAttributeW] } }
__declspec(naked) void _GetUrlCacheHeaderData() { _asm { jmp[wininet.GetUrlCacheHeaderData] } }
__declspec(naked) void _GopherCreateLocatorA() { _asm { jmp[wininet.GopherCreateLocatorA] } }
__declspec(naked) void _GopherCreateLocatorW() { _asm { jmp[wininet.GopherCreateLocatorW] } }
__declspec(naked) void _GopherFindFirstFileA() { _asm { jmp[wininet.GopherFindFirstFileA] } }
__declspec(naked) void _GopherFindFirstFileW() { _asm { jmp[wininet.GopherFindFirstFileW] } }
__declspec(naked) void _GopherGetAttributeA() { _asm { jmp[wininet.GopherGetAttributeA] } }
__declspec(naked) void _GopherGetAttributeW() { _asm { jmp[wininet.GopherGetAttributeW] } }
__declspec(naked) void _GopherGetLocatorTypeA() { _asm { jmp[wininet.GopherGetLocatorTypeA] } }
__declspec(naked) void _GopherGetLocatorTypeW() { _asm { jmp[wininet.GopherGetLocatorTypeW] } }
__declspec(naked) void _GopherOpenFileA() { _asm { jmp[wininet.GopherOpenFileA] } }
__declspec(naked) void _GopherOpenFileW() { _asm { jmp[wininet.GopherOpenFileW] } }
__declspec(naked) void _HttpAddRequestHeadersA() { _asm { jmp[wininet.HttpAddRequestHeadersA] } }
__declspec(naked) void _HttpAddRequestHeadersW() { _asm { jmp[wininet.HttpAddRequestHeadersW] } }
__declspec(naked) void _HttpCheckDavCompliance() { _asm { jmp[wininet.HttpCheckDavCompliance] } }
__declspec(naked) void _HttpCloseDependencyHandle() { _asm { jmp[wininet.HttpCloseDependencyHandle] } }
__declspec(naked) void _HttpDuplicateDependencyHandle() { _asm { jmp[wininet.HttpDuplicateDependencyHandle] } }
__declspec(naked) void _HttpEndRequestA() { _asm { jmp[wininet.HttpEndRequestA] } }
__declspec(naked) void _HttpEndRequestW() { _asm { jmp[wininet.HttpEndRequestW] } }
__declspec(naked) void _HttpGetServerCredentials() { _asm { jmp[wininet.HttpGetServerCredentials] } }
__declspec(naked) void _HttpGetTunnelSocket() { _asm { jmp[wininet.HttpGetTunnelSocket] } }
__declspec(naked) void _HttpIsHostHstsEnabled() { _asm { jmp[wininet.HttpIsHostHstsEnabled] } }
__declspec(naked) void _HttpOpenDependencyHandle() { _asm { jmp[wininet.HttpOpenDependencyHandle] } }
__declspec(naked) void _HttpOpenRequestA() { _asm { jmp[wininet.HttpOpenRequestA] } }
__declspec(naked) void _HttpOpenRequestW() { _asm { jmp[wininet.HttpOpenRequestW] } }
__declspec(naked) void _HttpPushClose() { _asm { jmp[wininet.HttpPushClose] } }
__declspec(naked) void _HttpPushEnable() { _asm { jmp[wininet.HttpPushEnable] } }
__declspec(naked) void _HttpPushWait() { _asm { jmp[wininet.HttpPushWait] } }
__declspec(naked) void _HttpQueryInfoA() { _asm { jmp[wininet.HttpQueryInfoA] } }
__declspec(naked) void _HttpQueryInfoW() { _asm { jmp[wininet.HttpQueryInfoW] } }
__declspec(naked) void _HttpSendRequestA() { _asm { jmp[wininet.HttpSendRequestA] } }
__declspec(naked) void _HttpSendRequestExA() { _asm { jmp[wininet.HttpSendRequestExA] } }
__declspec(naked) void _HttpSendRequestExW() { _asm { jmp[wininet.HttpSendRequestExW] } }
__declspec(naked) void _HttpSendRequestW() { _asm { jmp[wininet.HttpSendRequestW] } }
__declspec(naked) void _HttpWebSocketClose() { _asm { jmp[wininet.HttpWebSocketClose] } }
__declspec(naked) void _HttpWebSocketCompleteUpgrade() { _asm { jmp[wininet.HttpWebSocketCompleteUpgrade] } }
__declspec(naked) void _HttpWebSocketQueryCloseStatus() { _asm { jmp[wininet.HttpWebSocketQueryCloseStatus] } }
__declspec(naked) void _HttpWebSocketReceive() { _asm { jmp[wininet.HttpWebSocketReceive] } }
__declspec(naked) void _HttpWebSocketSend() { _asm { jmp[wininet.HttpWebSocketSend] } }
__declspec(naked) void _HttpWebSocketShutdown() { _asm { jmp[wininet.HttpWebSocketShutdown] } }
__declspec(naked) void _IncrementUrlCacheHeaderData() { _asm { jmp[wininet.IncrementUrlCacheHeaderData] } }
__declspec(naked) void _InternetAlgIdToStringA() { _asm { jmp[wininet.InternetAlgIdToStringA] } }
__declspec(naked) void _InternetAlgIdToStringW() { _asm { jmp[wininet.InternetAlgIdToStringW] } }
__declspec(naked) void _InternetAttemptConnect() { _asm { jmp[wininet.InternetAttemptConnect] } }
__declspec(naked) void _InternetAutodial() { _asm { jmp[wininet.InternetAutodial] } }
__declspec(naked) void _InternetAutodialCallback() { _asm { jmp[wininet.InternetAutodialCallback] } }
__declspec(naked) void _InternetAutodialHangup() { _asm { jmp[wininet.InternetAutodialHangup] } }
__declspec(naked) void _InternetCanonicalizeUrlA() { _asm { jmp[wininet.InternetCanonicalizeUrlA] } }
__declspec(naked) void _InternetCanonicalizeUrlW() { _asm { jmp[wininet.InternetCanonicalizeUrlW] } }
__declspec(naked) void _InternetCheckConnectionA() { _asm { jmp[wininet.InternetCheckConnectionA] } }
__declspec(naked) void _InternetCheckConnectionW() { _asm { jmp[wininet.InternetCheckConnectionW] } }
__declspec(naked) void _InternetClearAllPerSiteCookieDecisions() { _asm { jmp[wininet.InternetClearAllPerSiteCookieDecisions] } }
__declspec(naked) void _InternetCloseHandle() { _asm { jmp[wininet.InternetCloseHandle] } }
__declspec(naked) void _InternetCombineUrlA() { _asm { jmp[wininet.InternetCombineUrlA] } }
__declspec(naked) void _InternetCombineUrlW() { _asm { jmp[wininet.InternetCombineUrlW] } }
__declspec(naked) void _InternetConfirmZoneCrossing() { _asm { jmp[wininet.InternetConfirmZoneCrossing] } }
__declspec(naked) void _InternetConfirmZoneCrossingA() { _asm { jmp[wininet.InternetConfirmZoneCrossingA] } }
__declspec(naked) void _InternetConfirmZoneCrossingW() { _asm { jmp[wininet.InternetConfirmZoneCrossingW] } }
__declspec(naked) void _InternetConnectA() { _asm { jmp[wininet.InternetConnectA] } }
__declspec(naked) void _InternetConnectW() { _asm { jmp[wininet.InternetConnectW] } }
__declspec(naked) void _InternetConvertUrlFromWireToWideChar() { _asm { jmp[wininet.InternetConvertUrlFromWireToWideChar] } }
__declspec(naked) void _InternetCrackUrlA() { _asm { jmp[wininet.InternetCrackUrlA] } }
__declspec(naked) void _InternetCrackUrlW() { _asm { jmp[wininet.InternetCrackUrlW] } }
__declspec(naked) void _InternetCreateUrlA() { _asm { jmp[wininet.InternetCreateUrlA] } }
__declspec(naked) void _InternetCreateUrlW() { _asm { jmp[wininet.InternetCreateUrlW] } }
__declspec(naked) void _InternetDial() { _asm { jmp[wininet.InternetDial] } }
__declspec(naked) void _InternetDialA() { _asm { jmp[wininet.InternetDialA] } }
__declspec(naked) void _InternetDialW() { _asm { jmp[wininet.InternetDialW] } }
__declspec(naked) void _InternetEnumPerSiteCookieDecisionA() { _asm { jmp[wininet.InternetEnumPerSiteCookieDecisionA] } }
__declspec(naked) void _InternetEnumPerSiteCookieDecisionW() { _asm { jmp[wininet.InternetEnumPerSiteCookieDecisionW] } }
__declspec(naked) void _InternetErrorDlg() { _asm { jmp[wininet.InternetErrorDlg] } }
__declspec(naked) void _InternetFindNextFileA() { _asm { jmp[wininet.InternetFindNextFileA] } }
__declspec(naked) void _InternetFindNextFileW() { _asm { jmp[wininet.InternetFindNextFileW] } }
__declspec(naked) void _InternetFortezzaCommand() { _asm { jmp[wininet.InternetFortezzaCommand] } }
__declspec(naked) void _InternetFreeCookies() { _asm { jmp[wininet.InternetFreeCookies] } }
__declspec(naked) void _InternetFreeProxyInfoList() { _asm { jmp[wininet.InternetFreeProxyInfoList] } }
__declspec(naked) void _InternetGetCertByURL() { _asm { jmp[wininet.InternetGetCertByURL] } }
__declspec(naked) void _InternetGetCertByURLA() { _asm { jmp[wininet.InternetGetCertByURLA] } }
__declspec(naked) void _InternetGetConnectedState() { _asm { jmp[wininet.InternetGetConnectedState] } }
__declspec(naked) void _InternetGetConnectedStateEx() { _asm { jmp[wininet.InternetGetConnectedStateEx] } }
__declspec(naked) void _InternetGetConnectedStateExA() { _asm { jmp[wininet.InternetGetConnectedStateExA] } }
__declspec(naked) void _InternetGetConnectedStateExW() { _asm { jmp[wininet.InternetGetConnectedStateExW] } }
__declspec(naked) void _InternetGetCookieA() { _asm { jmp[wininet.InternetGetCookieA] } }
__declspec(naked) void _InternetGetCookieEx2() { _asm { jmp[wininet.InternetGetCookieEx2] } }
__declspec(naked) void _InternetGetCookieExA() { _asm { jmp[wininet.InternetGetCookieExA] } }
__declspec(naked) void _InternetGetCookieExW() { _asm { jmp[wininet.InternetGetCookieExW] } }
__declspec(naked) void _InternetGetCookieW() { _asm { jmp[wininet.InternetGetCookieW] } }
__declspec(naked) void _InternetGetLastResponseInfoA() { _asm { jmp[wininet.InternetGetLastResponseInfoA] } }
__declspec(naked) void _InternetGetLastResponseInfoW() { _asm { jmp[wininet.InternetGetLastResponseInfoW] } }
__declspec(naked) void _InternetGetPerSiteCookieDecisionA() { _asm { jmp[wininet.InternetGetPerSiteCookieDecisionA] } }
__declspec(naked) void _InternetGetPerSiteCookieDecisionW() { _asm { jmp[wininet.InternetGetPerSiteCookieDecisionW] } }
__declspec(naked) void _InternetGetProxyForUrl() { _asm { jmp[wininet.InternetGetProxyForUrl] } }
__declspec(naked) void _InternetGetSecurityInfoByURL() { _asm { jmp[wininet.InternetGetSecurityInfoByURL] } }
__declspec(naked) void _InternetGetSecurityInfoByURLA() { _asm { jmp[wininet.InternetGetSecurityInfoByURLA] } }
__declspec(naked) void _InternetGetSecurityInfoByURLW() { _asm { jmp[wininet.InternetGetSecurityInfoByURLW] } }
__declspec(naked) void _InternetGoOnline() { _asm { jmp[wininet.InternetGoOnline] } }
__declspec(naked) void _InternetGoOnlineA() { _asm { jmp[wininet.InternetGoOnlineA] } }
__declspec(naked) void _InternetGoOnlineW() { _asm { jmp[wininet.InternetGoOnlineW] } }
__declspec(naked) void _InternetHangUp() { _asm { jmp[wininet.InternetHangUp] } }
__declspec(naked) void _InternetInitializeAutoProxyDll() { _asm { jmp[wininet.InternetInitializeAutoProxyDll] } }
__declspec(naked) void _InternetLockRequestFile() { _asm { jmp[wininet.InternetLockRequestFile] } }
__declspec(naked) void _InternetOpenA() { _asm { jmp[wininet.InternetOpenA] } }
__declspec(naked) void _InternetOpenUrlA() { _asm { jmp[wininet.InternetOpenUrlA] } }
__declspec(naked) void _InternetOpenUrlW() { _asm { jmp[wininet.InternetOpenUrlW] } }
__declspec(naked) void _InternetOpenW() { _asm { jmp[wininet.InternetOpenW] } }
__declspec(naked) void _InternetQueryDataAvailable() { _asm { jmp[wininet.InternetQueryDataAvailable] } }
__declspec(naked) void _InternetQueryFortezzaStatus() { _asm { jmp[wininet.InternetQueryFortezzaStatus] } }
__declspec(naked) void _InternetQueryOptionA() { _asm { jmp[wininet.InternetQueryOptionA] } }
__declspec(naked) void _InternetQueryOptionW() { _asm { jmp[wininet.InternetQueryOptionW] } }
__declspec(naked) void _InternetReadFile() { _asm { jmp[wininet.InternetReadFile] } }
__declspec(naked) void _InternetReadFileExA() { _asm { jmp[wininet.InternetReadFileExA] } }
__declspec(naked) void _InternetReadFileExW() { _asm { jmp[wininet.InternetReadFileExW] } }
__declspec(naked) void _InternetSecurityProtocolToStringA() { _asm { jmp[wininet.InternetSecurityProtocolToStringA] } }
__declspec(naked) void _InternetSecurityProtocolToStringW() { _asm { jmp[wininet.InternetSecurityProtocolToStringW] } }
__declspec(naked) void _InternetSetCookieA() { _asm { jmp[wininet.InternetSetCookieA] } }
__declspec(naked) void _InternetSetCookieEx2() { _asm { jmp[wininet.InternetSetCookieEx2] } }
__declspec(naked) void _InternetSetCookieExA() { _asm { jmp[wininet.InternetSetCookieExA] } }
__declspec(naked) void _InternetSetCookieExW() { _asm { jmp[wininet.InternetSetCookieExW] } }
__declspec(naked) void _InternetSetCookieW() { _asm { jmp[wininet.InternetSetCookieW] } }
__declspec(naked) void _InternetSetDialState() { _asm { jmp[wininet.InternetSetDialState] } }
__declspec(naked) void _InternetSetDialStateA() { _asm { jmp[wininet.InternetSetDialStateA] } }
__declspec(naked) void _InternetSetDialStateW() { _asm { jmp[wininet.InternetSetDialStateW] } }
__declspec(naked) void _InternetSetFilePointer() { _asm { jmp[wininet.InternetSetFilePointer] } }
__declspec(naked) void _InternetSetOptionA() { _asm { jmp[wininet.InternetSetOptionA] } }
__declspec(naked) void _InternetSetOptionExA() { _asm { jmp[wininet.InternetSetOptionExA] } }
__declspec(naked) void _InternetSetOptionExW() { _asm { jmp[wininet.InternetSetOptionExW] } }
__declspec(naked) void _InternetSetOptionW() { _asm { jmp[wininet.InternetSetOptionW] } }
__declspec(naked) void _InternetSetPerSiteCookieDecisionA() { _asm { jmp[wininet.InternetSetPerSiteCookieDecisionA] } }
__declspec(naked) void _InternetSetPerSiteCookieDecisionW() { _asm { jmp[wininet.InternetSetPerSiteCookieDecisionW] } }
__declspec(naked) void _InternetSetStatusCallback() { _asm { jmp[wininet.InternetSetStatusCallback] } }
__declspec(naked) void _InternetSetStatusCallbackA() { _asm { jmp[wininet.InternetSetStatusCallbackA] } }
__declspec(naked) void _InternetSetStatusCallbackW() { _asm { jmp[wininet.InternetSetStatusCallbackW] } }
__declspec(naked) void _InternetShowSecurityInfoByURL() { _asm { jmp[wininet.InternetShowSecurityInfoByURL] } }
__declspec(naked) void _InternetShowSecurityInfoByURLA() { _asm { jmp[wininet.InternetShowSecurityInfoByURLA] } }
__declspec(naked) void _InternetShowSecurityInfoByURLW() { _asm { jmp[wininet.InternetShowSecurityInfoByURLW] } }
__declspec(naked) void _InternetTimeFromSystemTime() { _asm { jmp[wininet.InternetTimeFromSystemTime] } }
__declspec(naked) void _InternetTimeFromSystemTimeA() { _asm { jmp[wininet.InternetTimeFromSystemTimeA] } }
__declspec(naked) void _InternetTimeFromSystemTimeW() { _asm { jmp[wininet.InternetTimeFromSystemTimeW] } }
__declspec(naked) void _InternetTimeToSystemTime() { _asm { jmp[wininet.InternetTimeToSystemTime] } }
__declspec(naked) void _InternetTimeToSystemTimeA() { _asm { jmp[wininet.InternetTimeToSystemTimeA] } }
__declspec(naked) void _InternetTimeToSystemTimeW() { _asm { jmp[wininet.InternetTimeToSystemTimeW] } }
__declspec(naked) void _InternetUnlockRequestFile() { _asm { jmp[wininet.InternetUnlockRequestFile] } }
__declspec(naked) void _InternetWriteFile() { _asm { jmp[wininet.InternetWriteFile] } }
__declspec(naked) void _InternetWriteFileExA() { _asm { jmp[wininet.InternetWriteFileExA] } }
__declspec(naked) void _InternetWriteFileExW() { _asm { jmp[wininet.InternetWriteFileExW] } }
__declspec(naked) void _IsHostInProxyBypassList() { _asm { jmp[wininet.IsHostInProxyBypassList] } }
__declspec(naked) void _IsUrlCacheEntryExpiredA() { _asm { jmp[wininet.IsUrlCacheEntryExpiredA] } }
__declspec(naked) void _IsUrlCacheEntryExpiredW() { _asm { jmp[wininet.IsUrlCacheEntryExpiredW] } }
__declspec(naked) void _LoadUrlCacheContent() { _asm { jmp[wininet.LoadUrlCacheContent] } }
__declspec(naked) void _ParseX509EncodedCertificateForListBoxEntry() { _asm { jmp[wininet.ParseX509EncodedCertificateForListBoxEntry] } }
__declspec(naked) void _PrivacyGetZonePreferenceW() { _asm { jmp[wininet.PrivacyGetZonePreferenceW] } }
__declspec(naked) void _PrivacySetZonePreferenceW() { _asm { jmp[wininet.PrivacySetZonePreferenceW] } }
__declspec(naked) void _ReadUrlCacheEntryStream() { _asm { jmp[wininet.ReadUrlCacheEntryStream] } }
__declspec(naked) void _ReadUrlCacheEntryStreamEx() { _asm { jmp[wininet.ReadUrlCacheEntryStreamEx] } }
__declspec(naked) void _RegisterUrlCacheNotification() { _asm { jmp[wininet.RegisterUrlCacheNotification] } }
__declspec(naked) void _ResumeSuspendedDownload() { _asm { jmp[wininet.ResumeSuspendedDownload] } }
__declspec(naked) void _RetrieveUrlCacheEntryFileA() { _asm { jmp[wininet.RetrieveUrlCacheEntryFileA] } }
__declspec(naked) void _RetrieveUrlCacheEntryFileW() { _asm { jmp[wininet.RetrieveUrlCacheEntryFileW] } }
__declspec(naked) void _RetrieveUrlCacheEntryStreamA() { _asm { jmp[wininet.RetrieveUrlCacheEntryStreamA] } }
__declspec(naked) void _RetrieveUrlCacheEntryStreamW() { _asm { jmp[wininet.RetrieveUrlCacheEntryStreamW] } }
__declspec(naked) void _RunOnceUrlCache() { _asm { jmp[wininet.RunOnceUrlCache] } }
__declspec(naked) void _SetUrlCacheConfigInfoA() { _asm { jmp[wininet.SetUrlCacheConfigInfoA] } }
__declspec(naked) void _SetUrlCacheConfigInfoW() { _asm { jmp[wininet.SetUrlCacheConfigInfoW] } }
__declspec(naked) void _SetUrlCacheEntryGroup() { _asm { jmp[wininet.SetUrlCacheEntryGroup] } }
__declspec(naked) void _SetUrlCacheEntryGroupA() { _asm { jmp[wininet.SetUrlCacheEntryGroupA] } }
__declspec(naked) void _SetUrlCacheEntryGroupW() { _asm { jmp[wininet.SetUrlCacheEntryGroupW] } }
__declspec(naked) void _SetUrlCacheEntryInfoA() { _asm { jmp[wininet.SetUrlCacheEntryInfoA] } }
__declspec(naked) void _SetUrlCacheEntryInfoW() { _asm { jmp[wininet.SetUrlCacheEntryInfoW] } }
__declspec(naked) void _SetUrlCacheGroupAttributeA() { _asm { jmp[wininet.SetUrlCacheGroupAttributeA] } }
__declspec(naked) void _SetUrlCacheGroupAttributeW() { _asm { jmp[wininet.SetUrlCacheGroupAttributeW] } }
__declspec(naked) void _SetUrlCacheHeaderData() { _asm { jmp[wininet.SetUrlCacheHeaderData] } }
__declspec(naked) void _ShowCertificate() { _asm { jmp[wininet.ShowCertificate] } }
__declspec(naked) void _ShowClientAuthCerts() { _asm { jmp[wininet.ShowClientAuthCerts] } }
__declspec(naked) void _ShowSecurityInfo() { _asm { jmp[wininet.ShowSecurityInfo] } }
__declspec(naked) void _ShowX509EncodedCertificate() { _asm { jmp[wininet.ShowX509EncodedCertificate] } }
__declspec(naked) void _UnlockUrlCacheEntryFile() { _asm { jmp[wininet.UnlockUrlCacheEntryFile] } }
__declspec(naked) void _UnlockUrlCacheEntryFileA() { _asm { jmp[wininet.UnlockUrlCacheEntryFileA] } }
__declspec(naked) void _UnlockUrlCacheEntryFileW() { _asm { jmp[wininet.UnlockUrlCacheEntryFileW] } }
__declspec(naked) void _UnlockUrlCacheEntryStream() { _asm { jmp[wininet.UnlockUrlCacheEntryStream] } }
__declspec(naked) void _UpdateUrlCacheContentPath() { _asm { jmp[wininet.UpdateUrlCacheContentPath] } }
__declspec(naked) void _UrlCacheCheckEntriesExist() { _asm { jmp[wininet.UrlCacheCheckEntriesExist] } }
__declspec(naked) void _UrlCacheCloseEntryHandle() { _asm { jmp[wininet.UrlCacheCloseEntryHandle] } }
__declspec(naked) void _UrlCacheContainerSetEntryMaximumAge() { _asm { jmp[wininet.UrlCacheContainerSetEntryMaximumAge] } }
__declspec(naked) void _UrlCacheCreateContainer() { _asm { jmp[wininet.UrlCacheCreateContainer] } }
__declspec(naked) void _UrlCacheFindFirstEntry() { _asm { jmp[wininet.UrlCacheFindFirstEntry] } }
__declspec(naked) void _UrlCacheFindNextEntry() { _asm { jmp[wininet.UrlCacheFindNextEntry] } }
__declspec(naked) void _UrlCacheFreeEntryInfo() { _asm { jmp[wininet.UrlCacheFreeEntryInfo] } }
__declspec(naked) void _UrlCacheFreeGlobalSpace() { _asm { jmp[wininet.UrlCacheFreeGlobalSpace] } }
__declspec(naked) void _UrlCacheGetContentPaths() { _asm { jmp[wininet.UrlCacheGetContentPaths] } }
__declspec(naked) void _UrlCacheGetEntryInfo() { _asm { jmp[wininet.UrlCacheGetEntryInfo] } }
__declspec(naked) void _UrlCacheGetGlobalCacheSize() { _asm { jmp[wininet.UrlCacheGetGlobalCacheSize] } }
__declspec(naked) void _UrlCacheGetGlobalLimit() { _asm { jmp[wininet.UrlCacheGetGlobalLimit] } }
__declspec(naked) void _UrlCacheReadEntryStream() { _asm { jmp[wininet.UrlCacheReadEntryStream] } }
__declspec(naked) void _UrlCacheReloadSettings() { _asm { jmp[wininet.UrlCacheReloadSettings] } }
__declspec(naked) void _UrlCacheRetrieveEntryFile() { _asm { jmp[wininet.UrlCacheRetrieveEntryFile] } }
__declspec(naked) void _UrlCacheRetrieveEntryStream() { _asm { jmp[wininet.UrlCacheRetrieveEntryStream] } }
__declspec(naked) void _UrlCacheServer() { _asm { jmp[wininet.UrlCacheServer] } }
__declspec(naked) void _UrlCacheSetGlobalLimit() { _asm { jmp[wininet.UrlCacheSetGlobalLimit] } }
__declspec(naked) void _UrlCacheUpdateEntryExtraData() { _asm { jmp[wininet.UrlCacheUpdateEntryExtraData] } }
__declspec(naked) void _UrlZonesDetach() { _asm { jmp[wininet.UrlZonesDetach] } }

__declspec(naked) void _GetFileVersionInfoA() { _asm { jmp[version.GetFileVersionInfoA] } }
__declspec(naked) void _GetFileVersionInfoByHandle() { _asm { jmp[version.GetFileVersionInfoByHandle] } }
__declspec(naked) void _GetFileVersionInfoExA() { _asm { jmp[version.GetFileVersionInfoExA] } }
__declspec(naked) void _GetFileVersionInfoExW() { _asm { jmp[version.GetFileVersionInfoExW] } }
__declspec(naked) void _GetFileVersionInfoSizeA() { _asm { jmp[version.GetFileVersionInfoSizeA] } }
__declspec(naked) void _GetFileVersionInfoSizeExA() { _asm { jmp[version.GetFileVersionInfoSizeExA] } }
__declspec(naked) void _GetFileVersionInfoSizeExW() { _asm { jmp[version.GetFileVersionInfoSizeExW] } }
__declspec(naked) void _GetFileVersionInfoSizeW() { _asm { jmp[version.GetFileVersionInfoSizeW] } }
__declspec(naked) void _GetFileVersionInfoW() { _asm { jmp[version.GetFileVersionInfoW] } }
__declspec(naked) void _VerFindFileA() { _asm { jmp[version.VerFindFileA] } }
__declspec(naked) void _VerFindFileW() { _asm { jmp[version.VerFindFileW] } }
__declspec(naked) void _VerInstallFileA() { _asm { jmp[version.VerInstallFileA] } }
__declspec(naked) void _VerInstallFileW() { _asm { jmp[version.VerInstallFileW] } }
__declspec(naked) void _VerLanguageNameA() { _asm { jmp[version.VerLanguageNameA] } }
__declspec(naked) void _VerLanguageNameW() { _asm { jmp[version.VerLanguageNameW] } }
__declspec(naked) void _VerQueryValueA() { _asm { jmp[version.VerQueryValueA] } }
__declspec(naked) void _VerQueryValueW() { _asm { jmp[version.VerQueryValueW] } }

extern "C" __declspec(naked) void __stdcall _BinkBufferBlit(int, int, int) { _asm { jmp[binkw32.BinkBufferBlit] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferCheckWinPos(int, int, int) { _asm { jmp[binkw32.BinkBufferCheckWinPos] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferClear(int, int) { _asm { jmp[binkw32.BinkBufferClear] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferClose(int) { _asm { jmp[binkw32.BinkBufferClose] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferGetDescription(int) { _asm { jmp[binkw32.BinkBufferGetDescription] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferGetError() { _asm { jmp[binkw32.BinkBufferGetError] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferLock(int) { _asm { jmp[binkw32.BinkBufferLock] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferOpen(int, int, int, int) { _asm { jmp[binkw32.BinkBufferOpen] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferSetDirectDraw(int, int) { _asm { jmp[binkw32.BinkBufferSetDirectDraw] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferSetHWND(int, int) { _asm { jmp[binkw32.BinkBufferSetHWND] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferSetOffset(int, int, int) { _asm { jmp[binkw32.BinkBufferSetOffset] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferSetResolution(int, int, int) { _asm { jmp[binkw32.BinkBufferSetResolution] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferSetScale(int, int, int) { _asm { jmp[binkw32.BinkBufferSetScale] } }
extern "C" __declspec(naked) void __stdcall _BinkBufferUnlock(int) { _asm { jmp[binkw32.BinkBufferUnlock] } }
extern "C" __declspec(naked) void __stdcall _BinkCheckCursor(int, int, int, int, int) { _asm { jmp[binkw32.BinkCheckCursor] } }
extern "C" __declspec(naked) void __stdcall _BinkClose(int) { _asm { jmp[binkw32.BinkClose] } }
extern "C" __declspec(naked) void __stdcall _BinkCloseTrack(int) { _asm { jmp[binkw32.BinkCloseTrack] } }
extern "C" __declspec(naked) void __stdcall _BinkControlBackgroundIO(int, int) { _asm { jmp[binkw32.BinkControlBackgroundIO] } }
extern "C" __declspec(naked) void __stdcall _BinkControlPlatformFeatures(int, int) { _asm { jmp[binkw32.BinkControlPlatformFeatures] } }
extern "C" __declspec(naked) void __stdcall _BinkCopyToBuffer(int, int, int, int, int, int, int) { _asm { jmp[binkw32.BinkCopyToBuffer] } }
extern "C" __declspec(naked) void __stdcall _BinkCopyToBufferRect(int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.BinkCopyToBufferRect] } }
extern "C" __declspec(naked) void __stdcall _BinkDDSurfaceType(int) { _asm { jmp[binkw32.BinkDDSurfaceType] } }
extern "C" __declspec(naked) void __stdcall _BinkDX8SurfaceType(int) { _asm { jmp[binkw32.BinkDX8SurfaceType] } }
extern "C" __declspec(naked) void __stdcall _BinkDX9SurfaceType(int) { _asm { jmp[binkw32.BinkDX9SurfaceType] } }
extern "C" __declspec(naked) void __stdcall _BinkDoFrame(int) { _asm { jmp[binkw32.BinkDoFrame] } }
extern "C" __declspec(naked) void __stdcall _BinkDoFrameAsync(int, int, int) { _asm { jmp[binkw32.BinkDoFrameAsync] } }
extern "C" __declspec(naked) void __stdcall _BinkDoFrameAsyncWait(int, int) { _asm { jmp[binkw32.BinkDoFrameAsyncWait] } }
extern "C" __declspec(naked) void __stdcall _BinkDoFramePlane(int, int) { _asm { jmp[binkw32.BinkDoFramePlane] } }
extern "C" __declspec(naked) void __stdcall _BinkFreeGlobals() { _asm { jmp[binkw32.BinkFreeGlobals] } }
extern "C" __declspec(naked) void __stdcall _BinkGetError() { _asm { jmp[binkw32.BinkGetError] } }
extern "C" __declspec(naked) void __stdcall _BinkGetFrameBuffersInfo(int, int) { _asm { jmp[binkw32.BinkGetFrameBuffersInfo] } }
extern "C" __declspec(naked) void __stdcall _BinkGetKeyFrame(int, int, int) { _asm { jmp[binkw32.BinkGetKeyFrame] } }
extern "C" __declspec(naked) void __stdcall _BinkGetPalette(int) { _asm { jmp[binkw32.BinkGetPalette] } }
extern "C" __declspec(naked) void __stdcall _BinkGetPlatformInfo(int, int) { _asm { jmp[binkw32.BinkGetPlatformInfo] } }
extern "C" __declspec(naked) void __stdcall _BinkGetRealtime(int, int, int) { _asm { jmp[binkw32.BinkGetRealtime] } }
extern "C" __declspec(naked) void __stdcall _BinkGetRects(int, int) { _asm { jmp[binkw32.BinkGetRects] } }
extern "C" __declspec(naked) void __stdcall _BinkGetSummary(int, int) { _asm { jmp[binkw32.BinkGetSummary] } }
extern "C" __declspec(naked) void __stdcall _BinkGetTrackData(int, int) { _asm { jmp[binkw32.BinkGetTrackData] } }
extern "C" __declspec(naked) void __stdcall _BinkGetTrackID(int, int) { _asm { jmp[binkw32.BinkGetTrackID] } }
extern "C" __declspec(naked) void __stdcall _BinkGetTrackMaxSize(int, int) { _asm { jmp[binkw32.BinkGetTrackMaxSize] } }
extern "C" __declspec(naked) void __stdcall _BinkGetTrackType(int, int) { _asm { jmp[binkw32.BinkGetTrackType] } }
extern "C" __declspec(naked) void __stdcall _BinkGoto(int, int, int) { _asm { jmp[binkw32.BinkGoto] } }
extern "C" __declspec(naked) void __stdcall _BinkIsSoftwareCursor(int, int) { _asm { jmp[binkw32.BinkIsSoftwareCursor] } }
extern "C" __declspec(naked) void __stdcall _BinkLogoAddress() { _asm { jmp[binkw32.BinkLogoAddress] } }
extern "C" __declspec(naked) void __stdcall _BinkNextFrame(int) { _asm { jmp[binkw32.BinkNextFrame] } }
extern "C" __declspec(naked) void __stdcall _BinkOpen(int, int) { _asm { jmp[binkw32.BinkOpen] } }
extern "C" __declspec(naked) void __stdcall _BinkOpenDirectSound(int) { _asm { jmp[binkw32.BinkOpenDirectSound] } }
extern "C" __declspec(naked) void __stdcall _BinkOpenMiles(int) { _asm { jmp[binkw32.BinkOpenMiles] } }
extern "C" __declspec(naked) void __stdcall _BinkOpenTrack(int, int) { _asm { jmp[binkw32.BinkOpenTrack] } }
extern "C" __declspec(naked) void __stdcall _BinkOpenWaveOut(int) { _asm { jmp[binkw32.BinkOpenWaveOut] } }
extern "C" __declspec(naked) void __stdcall _BinkOpenWithOptions(int, int, int) { _asm { jmp[binkw32.BinkOpenWithOptions] } }
extern "C" __declspec(naked) void __stdcall _BinkOpenXAudio2(int) { _asm { jmp[binkw32.BinkOpenXAudio2] } }
extern "C" __declspec(naked) void __stdcall _BinkPause(int, int) { _asm { jmp[binkw32.BinkPause] } }
extern "C" __declspec(naked) void __stdcall _BinkRegisterFrameBuffers(int, int) { _asm { jmp[binkw32.BinkRegisterFrameBuffers] } }
extern "C" __declspec(naked) void __stdcall _BinkRequestStopAsyncThread(int) { _asm { jmp[binkw32.BinkRequestStopAsyncThread] } }
extern "C" __declspec(naked) void __stdcall _BinkRestoreCursor(int) { _asm { jmp[binkw32.BinkRestoreCursor] } }
extern "C" __declspec(naked) void __stdcall _BinkService(int) { _asm { jmp[binkw32.BinkService] } }
extern "C" __declspec(naked) void __stdcall _BinkServiceSound() { _asm { jmp[binkw32.BinkServiceSound] } }
extern "C" __declspec(naked) void __stdcall _BinkSetError(int) { _asm { jmp[binkw32.BinkSetError] } }
extern "C" __declspec(naked) void __stdcall _BinkSetFileOffset(int, int) { _asm { jmp[binkw32.BinkSetFileOffset] } }
extern "C" __declspec(naked) void __stdcall _BinkSetFrameRate(int, int) { _asm { jmp[binkw32.BinkSetFrameRate] } }
extern "C" __declspec(naked) void __stdcall _BinkSetIO(int) { _asm { jmp[binkw32.BinkSetIO] } }
extern "C" __declspec(naked) void __stdcall _BinkSetIOSize(int) { _asm { jmp[binkw32.BinkSetIOSize] } }
extern "C" __declspec(naked) void __stdcall _BinkSetMemory(int, int) { _asm { jmp[binkw32.BinkSetMemory] } }
extern "C" __declspec(naked) void __stdcall _BinkSetMixBinVolumes(int, int, int, int, int) { _asm { jmp[binkw32.BinkSetMixBinVolumes] } }
extern "C" __declspec(naked) void __stdcall _BinkSetMixBins(int, int, int, int) { _asm { jmp[binkw32.BinkSetMixBins] } }
extern "C" __declspec(naked) void __stdcall _BinkSetPan(int, int, int) { _asm { jmp[binkw32.BinkSetPan] } }
extern "C" __declspec(naked) void __stdcall _BinkSetSimulate(int) { _asm { jmp[binkw32.BinkSetSimulate] } }
extern "C" __declspec(naked) void __stdcall _BinkSetSoundOnOff(int, int) { _asm { jmp[binkw32.BinkSetSoundOnOff] } }
extern "C" __declspec(naked) void __stdcall _BinkSetSoundSystem(int, int) { _asm { jmp[binkw32.BinkSetSoundSystem] } }
extern "C" __declspec(naked) void __stdcall _BinkSetSoundTrack(int, int) { _asm { jmp[binkw32.BinkSetSoundTrack] } }
extern "C" __declspec(naked) void __stdcall _BinkSetSpeakerVolumes(int, int, int, int, int) { _asm { jmp[binkw32.BinkSetSpeakerVolumes] } }
extern "C" __declspec(naked) void __stdcall _BinkSetVideoOnOff(int, int) { _asm { jmp[binkw32.BinkSetVideoOnOff] } }
extern "C" __declspec(naked) void __stdcall _BinkSetVolume(int, int, int) { _asm { jmp[binkw32.BinkSetVolume] } }
extern "C" __declspec(naked) void __stdcall _BinkSetWillLoop(int, int) { _asm { jmp[binkw32.BinkSetWillLoop] } }
extern "C" __declspec(naked) void __stdcall _BinkShouldSkip(int) { _asm { jmp[binkw32.BinkShouldSkip] } }
extern "C" __declspec(naked) void __stdcall _BinkStartAsyncThread(int, int) { _asm { jmp[binkw32.BinkStartAsyncThread] } }
extern "C" __declspec(naked) void __stdcall _BinkUseTelemetry(int) { _asm { jmp[binkw32.BinkUseTelemetry] } }
extern "C" __declspec(naked) void __stdcall _BinkUseTmLite(int) { _asm { jmp[binkw32.BinkUseTmLite] } }
extern "C" __declspec(naked) void __stdcall _BinkWait(int) { _asm { jmp[binkw32.BinkWait] } }
extern "C" __declspec(naked) void __stdcall _BinkWaitStopAsyncThread(int) { _asm { jmp[binkw32.BinkWaitStopAsyncThread] } }
extern "C" __declspec(naked) void __stdcall _RADSetMemory(int, int) { _asm { jmp[binkw32.RADSetMemory] } }
extern "C" __declspec(naked) void __stdcall _RADTimerRead() { _asm { jmp[binkw32.RADTimerRead] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a1bpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a1bpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a1bpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a1bpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a1bpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a1bpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a1bpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a1bpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a4bpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a4bpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a4bpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a4bpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a4bpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a4bpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16a4bpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16a4bpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16bpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16bpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16bpp48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16bpp48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16bpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16bpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16bpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16bpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16bpp_mask56(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16bpp_mask56] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_16bpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_16bpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24bpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24bpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24bpp48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24bpp48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24bpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24bpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24bpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24bpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24bpp_mask56(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24bpp_mask56] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24bpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24bpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24rbpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24rbpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24rbpp48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24rbpp48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24rbpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24rbpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24rbpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24rbpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24rbpp_mask56(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24rbpp_mask56] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_24rbpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_24rbpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32abpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32abpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32abpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32abpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32abpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32abpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32abpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32abpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32bpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32bpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32bpp48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32bpp48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32bpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32bpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32bpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32bpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32bpp_mask56(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32bpp_mask56] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32bpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32bpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rabpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rabpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rabpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rabpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rabpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rabpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rabpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rabpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rbpp40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rbpp40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rbpp48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rbpp48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rbpp52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rbpp52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rbpp_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rbpp_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rbpp_mask56(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rbpp_mask56] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_32rbpp_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_32rbpp_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_UYVY40(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_UYVY40] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_UYVY48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_UYVY48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_UYVY52(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_UYVY52] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_UYVY_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_UYVY_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_UYVY_mask56(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_UYVY_mask56] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_UYVY_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_UYVY_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YUY240(int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YUY240] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YUY248(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YUY248] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YUY252(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YUY252] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YUY2_mask48(int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YUY2_mask48] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YUY2_mask56(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YUY2_mask56] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YUY2_mask60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YUY2_mask60] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YV1244(int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YV1244] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YV1252(int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YV1252] } }
extern "C" __declspec(naked) void __stdcall _YUV_blit_YV1256(int, int, int, int, int, int, int, int, int, int, int, int, int, int) { _asm { jmp[binkw32.YUV_blit_YV1256] } }
extern "C" __declspec(naked) void __stdcall _YUV_init4(int) { _asm { jmp[binkw32.YUV_init4] } }
extern "C" __declspec(naked) void __stdcall _radfree(int) { _asm { jmp[binkw32.radfree] } }
extern "C" __declspec(naked) void __stdcall _radmalloc(int) { _asm { jmp[binkw32.radmalloc] } }



#endif

#if X64
#pragma runtime_checks( "", off )

#ifdef _DEBUG
#pragma message ("You are compiling the code in Debug - be warned that wrappers for export functions may not have correct code generated")
#endif

// not sure if these all work -- there's a very real possibility some of these will need more full definitions to not break stack parameters
// (see https://github.com/ThirteenAG/Ultimate-ASI-Loader/blob/master/source/dllmain.h#L2870 for reference)
void _BreakRecordsIntoBlob() { dnsapi.BreakRecordsIntoBlob(); }
void _CombineRecordsInBlob() { dnsapi.CombineRecordsInBlob(); }
void _DnsAcquireContextHandle_A() { dnsapi.DnsAcquireContextHandle_A(); }
void _DnsAcquireContextHandle_W() { dnsapi.DnsAcquireContextHandle_W(); }
void _DnsAllocateRecord() { dnsapi.DnsAllocateRecord(); }
void _DnsApiAlloc() { dnsapi.DnsApiAlloc(); }
void _DnsApiAllocZero() { dnsapi.DnsApiAllocZero(); }
void _DnsApiFree() { dnsapi.DnsApiFree(); }
void _DnsApiHeapReset() { dnsapi.DnsApiHeapReset(); }
void _DnsApiRealloc() { dnsapi.DnsApiRealloc(); }
void _DnsApiSetDebugGlobals() { dnsapi.DnsApiSetDebugGlobals(); }
void _DnsAsyncRegisterHostAddrs() { dnsapi.DnsAsyncRegisterHostAddrs(); }
void _DnsAsyncRegisterInit() { dnsapi.DnsAsyncRegisterInit(); }
void _DnsAsyncRegisterTerm() { dnsapi.DnsAsyncRegisterTerm(); }
void _DnsCancelQuery() { dnsapi.DnsCancelQuery(); }
void _DnsCopyStringEx() { dnsapi.DnsCopyStringEx(); }
void _DnsCreateReverseNameStringForIpAddress() { dnsapi.DnsCreateReverseNameStringForIpAddress(); }
void _DnsCreateStandardDnsNameCopy() { dnsapi.DnsCreateStandardDnsNameCopy(); }
void _DnsCreateStringCopy() { dnsapi.DnsCreateStringCopy(); }
void _DnsDhcpRegisterAddrs() { dnsapi.DnsDhcpRegisterAddrs(); }
void _DnsDhcpRegisterHostAddrs() { dnsapi.DnsDhcpRegisterHostAddrs(); }
void _DnsDhcpRegisterInit() { dnsapi.DnsDhcpRegisterInit(); }
void _DnsDhcpRegisterTerm() { dnsapi.DnsDhcpRegisterTerm(); }
void _DnsDhcpRemoveRegistrations() { dnsapi.DnsDhcpRemoveRegistrations(); }
void _DnsDhcpSrvRegisterHostAddr() { dnsapi.DnsDhcpSrvRegisterHostAddr(); }
//void _DnsDhcpSrvRegisterHostAddrEx() { dnsapi.DnsDhcpSrvRegisterHostAddrEx(); }
void _DnsDhcpSrvRegisterHostName() { dnsapi.DnsDhcpSrvRegisterHostName(); }
//void _DnsDhcpSrvRegisterHostNameEx() { dnsapi.DnsDhcpSrvRegisterHostNameEx(); }
void _DnsDhcpSrvRegisterInit() { dnsapi.DnsDhcpSrvRegisterInit(); }
void _DnsDhcpSrvRegisterInitialize() { dnsapi.DnsDhcpSrvRegisterInitialize(); }
void _DnsDhcpSrvRegisterTerm() { dnsapi.DnsDhcpSrvRegisterTerm(); }
void _DnsDowncaseDnsNameLabel() { dnsapi.DnsDowncaseDnsNameLabel(); }
void _DnsExtractRecordsFromMessage_UTF8() { dnsapi.DnsExtractRecordsFromMessage_UTF8(); }
void _DnsExtractRecordsFromMessage_W() { dnsapi.DnsExtractRecordsFromMessage_W(); }
void _DnsFindAuthoritativeZone() { dnsapi.DnsFindAuthoritativeZone(); }
void _DnsFlushResolverCache() { dnsapi.DnsFlushResolverCache(); }
void _DnsFlushResolverCacheEntry_A() { dnsapi.DnsFlushResolverCacheEntry_A(); }
void _DnsFlushResolverCacheEntry_UTF8() { dnsapi.DnsFlushResolverCacheEntry_UTF8(); }
void _DnsFlushResolverCacheEntry_W() { dnsapi.DnsFlushResolverCacheEntry_W(); }
void _DnsFree() { dnsapi.DnsFree(); }
void _DnsFreeConfigStructure() { dnsapi.DnsFreeConfigStructure(); }
//void _DnsFreePolicyConfig() { dnsapi.DnsFreePolicyConfig(); }
//void _DnsFreeProxyName() { dnsapi.DnsFreeProxyName(); }
void _DnsGetBufferLengthForStringCopy() { dnsapi.DnsGetBufferLengthForStringCopy(); }
void _DnsGetCacheDataTable() { dnsapi.DnsGetCacheDataTable(); }
void _DnsGetDnsServerList() { dnsapi.DnsGetDnsServerList(); }
void _DnsGetDomainName() { dnsapi.DnsGetDomainName(); }
void _DnsGetLastFailedUpdateInfo() { dnsapi.DnsGetLastFailedUpdateInfo(); }
//void _DnsGetPolicyTableInfo() { dnsapi.DnsGetPolicyTableInfo(); }
//void _DnsGetPolicyTableInfoPrivate() { dnsapi.DnsGetPolicyTableInfoPrivate(); }
void _DnsGetPrimaryDomainName_A() { dnsapi.DnsGetPrimaryDomainName_A(); }
//void _DnsGetProxyInfoPrivate() { dnsapi.DnsGetProxyInfoPrivate(); }
//void _DnsGetProxyInformation() { dnsapi.DnsGetProxyInformation(); }
void _DnsGlobals() { dnsapi.DnsGlobals(); }
void _DnsIpv6AddressToString() { dnsapi.DnsIpv6AddressToString(); }
void _DnsIpv6StringToAddress() { dnsapi.DnsIpv6StringToAddress(); }
void _DnsIsAMailboxType() { dnsapi.DnsIsAMailboxType(); }
void _DnsIsStatusRcode() { dnsapi.DnsIsStatusRcode(); }
void _DnsIsStringCountValidForTextType() { dnsapi.DnsIsStringCountValidForTextType(); }
void _DnsLogEvent() { dnsapi.DnsLogEvent(); }
void _DnsLogIn() { dnsapi.DnsLogIn(); }
void _DnsLogInit() { dnsapi.DnsLogInit(); }
void _DnsLogIt() { dnsapi.DnsLogIt(); }
void _DnsLogOut() { dnsapi.DnsLogOut(); }
void _DnsLogTime() { dnsapi.DnsLogTime(); }
void _DnsMapRcodeToStatus() { dnsapi.DnsMapRcodeToStatus(); }
void _DnsModifyRecordsInSet_A() { dnsapi.DnsModifyRecordsInSet_A(); }
void _DnsModifyRecordsInSet_UTF8() { dnsapi.DnsModifyRecordsInSet_UTF8(); }
void _DnsModifyRecordsInSet_W() { dnsapi.DnsModifyRecordsInSet_W(); }
void _DnsNameCompareEx_A() { dnsapi.DnsNameCompareEx_A(); }
void _DnsNameCompareEx_UTF8() { dnsapi.DnsNameCompareEx_UTF8(); }
void _DnsNameCompareEx_W() { dnsapi.DnsNameCompareEx_W(); }
void _DnsNameCompare_A() { dnsapi.DnsNameCompare_A(); }
void _DnsNameCompare_UTF8() { dnsapi.DnsNameCompare_UTF8(); }
void _DnsNameCompare_W() { dnsapi.DnsNameCompare_W(); }
void _DnsNameCopy() { dnsapi.DnsNameCopy(); }
void _DnsNameCopyAllocate() { dnsapi.DnsNameCopyAllocate(); }
void _DnsNetworkInfo_CreateFromFAZ() { dnsapi.DnsNetworkInfo_CreateFromFAZ(); }
void _DnsNetworkInformation_CreateFromFAZ() { dnsapi.DnsNetworkInformation_CreateFromFAZ(); }
void _DnsNotifyResolver() { dnsapi.DnsNotifyResolver(); }
void _DnsNotifyResolverClusterIp() { dnsapi.DnsNotifyResolverClusterIp(); }
void _DnsNotifyResolverEx() { dnsapi.DnsNotifyResolverEx(); }
void _DnsQueryConfig() { dnsapi.DnsQueryConfig(); }
void _DnsQueryConfigAllocEx() { dnsapi.DnsQueryConfigAllocEx(); }
void _DnsQueryConfigDword() { dnsapi.DnsQueryConfigDword(); }
void _DnsQueryEx() { dnsapi.DnsQueryEx(); }
void _DnsQueryExA() { dnsapi.DnsQueryExA(); }
void _DnsQueryExUTF8() { dnsapi.DnsQueryExUTF8(); }
void _DnsQueryExW() { dnsapi.DnsQueryExW(); }
void _DnsQuery_A() { dnsapi.DnsQuery_A(); }
void _DnsQuery_UTF8() { dnsapi.DnsQuery_UTF8(); }
void _DnsQuery_W() { dnsapi.DnsQuery_W(); }
void _DnsRecordBuild_UTF8() { dnsapi.DnsRecordBuild_UTF8(); }
void _DnsRecordBuild_W() { dnsapi.DnsRecordBuild_W(); }
void _DnsRecordCompare() { dnsapi.DnsRecordCompare(); }
void _DnsRecordCopyEx() { dnsapi.DnsRecordCopyEx(); }
void _DnsRecordListFree() { dnsapi.DnsRecordListFree(); }
void _DnsRecordSetCompare() { dnsapi.DnsRecordSetCompare(); }
void _DnsRecordSetCopyEx() { dnsapi.DnsRecordSetCopyEx(); }
void _DnsRecordSetDetach() { dnsapi.DnsRecordSetDetach(); }
void _DnsRecordStringForType() { dnsapi.DnsRecordStringForType(); }
void _DnsRecordStringForWritableType() { dnsapi.DnsRecordStringForWritableType(); }
void _DnsRecordTypeForName() { dnsapi.DnsRecordTypeForName(); }
void _DnsRegisterClusterAddress() { dnsapi.DnsRegisterClusterAddress(); }
void _DnsReleaseContextHandle() { dnsapi.DnsReleaseContextHandle(); }
void _DnsRemoveRegistrations() { dnsapi.DnsRemoveRegistrations(); }
void _DnsReplaceRecordSetA() { dnsapi.DnsReplaceRecordSetA(); }
void _DnsReplaceRecordSetUTF8() { dnsapi.DnsReplaceRecordSetUTF8(); }
void _DnsReplaceRecordSetW() { dnsapi.DnsReplaceRecordSetW(); }
void _DnsResolverOp() { dnsapi.DnsResolverOp(); }
void _DnsScreenLocalAddrsForRegistration() { dnsapi.DnsScreenLocalAddrsForRegistration(); }
void _DnsSetConfigDword() { dnsapi.DnsSetConfigDword(); }
void _DnsStatusString() { dnsapi.DnsStatusString(); }
void _DnsStringCopyAllocateEx() { dnsapi.DnsStringCopyAllocateEx(); }
//void _DnsTraceServerConfig() { dnsapi.DnsTraceServerConfig(); }
void _DnsUnicodeToUtf8() { dnsapi.DnsUnicodeToUtf8(); }
void _DnsUpdate() { dnsapi.DnsUpdate(); }
//void _DnsUpdateMachinePresence() { dnsapi.DnsUpdateMachinePresence(); }
void _DnsUpdateTest_A() { dnsapi.DnsUpdateTest_A(); }
void _DnsUpdateTest_UTF8() { dnsapi.DnsUpdateTest_UTF8(); }
void _DnsUpdateTest_W() { dnsapi.DnsUpdateTest_W(); }
void _DnsUtf8ToUnicode() { dnsapi.DnsUtf8ToUnicode(); }
void _DnsValidateNameOrIp_TempW() { dnsapi.DnsValidateNameOrIp_TempW(); }
void _DnsValidateName_A() { dnsapi.DnsValidateName_A(); }
void _DnsValidateName_UTF8() { dnsapi.DnsValidateName_UTF8(); }
void _DnsValidateName_W() { dnsapi.DnsValidateName_W(); }
//void _DnsValidateServerArray_A() { dnsapi.DnsValidateServerArray_A(); }
//void _DnsValidateServerArray_W() { dnsapi.DnsValidateServerArray_W(); }
//void _DnsValidateServerStatus() { dnsapi.DnsValidateServerStatus(); }
//void _DnsValidateServer_A() { dnsapi.DnsValidateServer_A(); }
//void _DnsValidateServer_W() { dnsapi.DnsValidateServer_W(); }
void _DnsValidateUtf8Byte() { dnsapi.DnsValidateUtf8Byte(); }
void _DnsWriteQuestionToBuffer_UTF8() { dnsapi.DnsWriteQuestionToBuffer_UTF8(); }
void _DnsWriteQuestionToBuffer_W() { dnsapi.DnsWriteQuestionToBuffer_W(); }
void _DnsWriteReverseNameStringForIpAddress() { dnsapi.DnsWriteReverseNameStringForIpAddress(); }
void _Dns_AddRecordsToMessage() { dnsapi.Dns_AddRecordsToMessage(); }
void _Dns_AllocateMsgBuf() { dnsapi.Dns_AllocateMsgBuf(); }
void _Dns_BuildPacket() { dnsapi.Dns_BuildPacket(); }
void _Dns_CleanupWinsock() { dnsapi.Dns_CleanupWinsock(); }
void _Dns_CloseConnection() { dnsapi.Dns_CloseConnection(); }
void _Dns_CloseSocket() { dnsapi.Dns_CloseSocket(); }
void _Dns_CreateMulticastSocket() { dnsapi.Dns_CreateMulticastSocket(); }
void _Dns_CreateSocket() { dnsapi.Dns_CreateSocket(); }
void _Dns_CreateSocketEx() { dnsapi.Dns_CreateSocketEx(); }
void _Dns_ExtractRecordsFromMessage() { dnsapi.Dns_ExtractRecordsFromMessage(); }
void _Dns_FindAuthoritativeZoneLib() { dnsapi.Dns_FindAuthoritativeZoneLib(); }
void _Dns_FreeMsgBuf() { dnsapi.Dns_FreeMsgBuf(); }
void _Dns_GetRandomXid() { dnsapi.Dns_GetRandomXid(); }
void _Dns_InitializeMsgBuf() { dnsapi.Dns_InitializeMsgBuf(); }
void _Dns_InitializeMsgRemoteSockaddr() { dnsapi.Dns_InitializeMsgRemoteSockaddr(); }
void _Dns_InitializeWinsock() { dnsapi.Dns_InitializeWinsock(); }
void _Dns_OpenTcpConnectionAndSend() { dnsapi.Dns_OpenTcpConnectionAndSend(); }
void _Dns_ParseMessage() { dnsapi.Dns_ParseMessage(); }
void _Dns_ParsePacketRecord() { dnsapi.Dns_ParsePacketRecord(); }
void _Dns_PingAdapterServers() { dnsapi.Dns_PingAdapterServers(); }
void _Dns_ReadPacketName() { dnsapi.Dns_ReadPacketName(); }
void _Dns_ReadPacketNameAllocate() { dnsapi.Dns_ReadPacketNameAllocate(); }
void _Dns_ReadRecordStructureFromPacket() { dnsapi.Dns_ReadRecordStructureFromPacket(); }
void _Dns_RecvTcp() { dnsapi.Dns_RecvTcp(); }
void _Dns_ResetNetworkInfo() { dnsapi.Dns_ResetNetworkInfo(); }
void _Dns_SendAndRecvUdp() { dnsapi.Dns_SendAndRecvUdp(); }
void _Dns_SendEx() { dnsapi.Dns_SendEx(); }
void _Dns_SetRecordDatalength() { dnsapi.Dns_SetRecordDatalength(); }
void _Dns_SetRecordsSection() { dnsapi.Dns_SetRecordsSection(); }
void _Dns_SetRecordsTtl() { dnsapi.Dns_SetRecordsTtl(); }
void _Dns_SkipPacketName() { dnsapi.Dns_SkipPacketName(); }
void _Dns_SkipToRecord() { dnsapi.Dns_SkipToRecord(); }
void _Dns_UpdateLib() { dnsapi.Dns_UpdateLib(); }
void _Dns_UpdateLibEx() { dnsapi.Dns_UpdateLibEx(); }
void _Dns_WriteDottedNameToPacket() { dnsapi.Dns_WriteDottedNameToPacket(); }
void _Dns_WriteQuestionToMessage() { dnsapi.Dns_WriteQuestionToMessage(); }
void _Dns_WriteRecordStructureToPacketEx() { dnsapi.Dns_WriteRecordStructureToPacketEx(); }
void _ExtraInfo_Init() { dnsapi.ExtraInfo_Init(); }
void _Faz_AreServerListsInSameNameSpace() { dnsapi.Faz_AreServerListsInSameNameSpace(); }
//void _FlushDnsPolicyUnreachableStatus() { dnsapi.FlushDnsPolicyUnreachableStatus(); }
void _GetCurrentTimeInSeconds() { dnsapi.GetCurrentTimeInSeconds(); }
void _HostsFile_Close() { dnsapi.HostsFile_Close(); }
void _HostsFile_Open() { dnsapi.HostsFile_Open(); }
void _HostsFile_ReadLine() { dnsapi.HostsFile_ReadLine(); }
void _IpHelp_IsAddrOnLink() { dnsapi.IpHelp_IsAddrOnLink(); }
void _Local_GetRecordsForLocalName() { dnsapi.Local_GetRecordsForLocalName(); }
void _Local_GetRecordsForLocalNameEx() { dnsapi.Local_GetRecordsForLocalNameEx(); }
void _NetInfo_Build() { dnsapi.NetInfo_Build(); }
void _NetInfo_Clean() { dnsapi.NetInfo_Clean(); }
void _NetInfo_Copy() { dnsapi.NetInfo_Copy(); }
void _NetInfo_Free() { dnsapi.NetInfo_Free(); }
void _NetInfo_GetAdapterByAddress() { dnsapi.NetInfo_GetAdapterByAddress(); }
void _NetInfo_GetAdapterByInterfaceIndex() { dnsapi.NetInfo_GetAdapterByInterfaceIndex(); }
void _NetInfo_GetAdapterByName() { dnsapi.NetInfo_GetAdapterByName(); }
void _NetInfo_IsAddrConfig() { dnsapi.NetInfo_IsAddrConfig(); }
void _NetInfo_IsForUpdate() { dnsapi.NetInfo_IsForUpdate(); }
void _NetInfo_ResetServerPriorities() { dnsapi.NetInfo_ResetServerPriorities(); }
//void _NetInfo_UpdateServerReachability() { dnsapi.NetInfo_UpdateServerReachability(); }
void _QueryDirectEx() { dnsapi.QueryDirectEx(); }
void _Query_Main() { dnsapi.Query_Main(); }
void _Reg_FreeUpdateInfo() { dnsapi.Reg_FreeUpdateInfo(); }
void _Reg_GetValueEx() { dnsapi.Reg_GetValueEx(); }
void _Reg_ReadGlobalsEx() { dnsapi.Reg_ReadGlobalsEx(); }
void _Reg_ReadUpdateInfo() { dnsapi.Reg_ReadUpdateInfo(); }
void _Security_ContextListTimeout() { dnsapi.Security_ContextListTimeout(); }
void _Send_AndRecvUdpWithParam() { dnsapi.Send_AndRecvUdpWithParam(); }
void _Send_MessagePrivate() { dnsapi.Send_MessagePrivate(); }
void _Send_OpenTcpConnectionAndSend() { dnsapi.Send_OpenTcpConnectionAndSend(); }
void _Socket_CacheCleanup() { dnsapi.Socket_CacheCleanup(); }
void _Socket_CacheInit() { dnsapi.Socket_CacheInit(); }
void _Socket_CleanupWinsock() { dnsapi.Socket_CleanupWinsock(); }
void _Socket_ClearMessageSockets() { dnsapi.Socket_ClearMessageSockets(); }
void _Socket_CloseEx() { dnsapi.Socket_CloseEx(); }
void _Socket_CloseMessageSockets() { dnsapi.Socket_CloseMessageSockets(); }
void _Socket_Create() { dnsapi.Socket_Create(); }
void _Socket_CreateMulticast() { dnsapi.Socket_CreateMulticast(); }
void _Socket_InitWinsock() { dnsapi.Socket_InitWinsock(); }
void _Socket_JoinMulticast() { dnsapi.Socket_JoinMulticast(); }
void _Socket_RecvFrom() { dnsapi.Socket_RecvFrom(); }
void _Socket_SetMulticastInterface() { dnsapi.Socket_SetMulticastInterface(); }
void _Socket_SetMulticastLoopBack() { dnsapi.Socket_SetMulticastLoopBack(); }
void _Socket_SetTtl() { dnsapi.Socket_SetTtl(); }
void _Socket_TcpListen() { dnsapi.Socket_TcpListen(); }
//void _Trace_Reset() { dnsapi.Trace_Reset(); }
void _Update_ReplaceAddressRecordsW() { dnsapi.Update_ReplaceAddressRecordsW(); }
void _Util_IsIp6Running() { dnsapi.Util_IsIp6Running(); }

typedef HRESULT(*fn_DirectSoundCaptureCreate)(LPGUID lpGUID, LPDIRECTSOUNDCAPTURE *lplpDSC, LPUNKNOWN pUnkOuter);
void _DirectSoundCaptureCreate() { (fn_DirectSoundCaptureCreate)dsound.DirectSoundCaptureCreate(); }

typedef HRESULT(*fn_DirectSoundCaptureCreate8)(LPCGUID lpcGUID, LPDIRECTSOUNDCAPTURE8 * lplpDSC, LPUNKNOWN pUnkOuter);
void _DirectSoundCaptureCreate8() { (fn_DirectSoundCaptureCreate8)dsound.DirectSoundCaptureCreate8(); }

typedef HRESULT(*fn_DirectSoundCaptureEnumerateA)(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext);
void _DirectSoundCaptureEnumerateA() { (fn_DirectSoundCaptureEnumerateA)dsound.DirectSoundCaptureEnumerateA(); }

typedef HRESULT(*fn_DirectSoundCaptureEnumerateW)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
void _DirectSoundCaptureEnumerateW() { (fn_DirectSoundCaptureEnumerateW)dsound.DirectSoundCaptureEnumerateW(); }

typedef HRESULT(*fn_DirectSoundCreate)(LPCGUID lpcGUID, LPDIRECTSOUND* ppDS, IUnknown* pUnkOuter);
void _DirectSoundCreate() { (fn_DirectSoundCreate)dsound.DirectSoundCreate(); }

typedef HRESULT(*fn_DirectSoundCreate8)(LPCGUID lpcGUID, LPDIRECTSOUND8* ppDS, IUnknown* pUnkOuter);
void _DirectSoundCreate8() { (fn_DirectSoundCreate8)dsound.DirectSoundCreate8(); }

typedef HRESULT(*fn_DirectSoundEnumerateA)(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext);
void _DirectSoundEnumerateA() { (fn_DirectSoundEnumerateA)dsound.DirectSoundEnumerateA(); }

typedef HRESULT(*fn_DirectSoundEnumerateW)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
void _DirectSoundEnumerateW() { (fn_DirectSoundEnumerateW)dsound.DirectSoundEnumerateW(); }

typedef HRESULT(*fn_DirectSoundFullDuplexCreate)(const GUID* capture_dev, const GUID* render_dev, const DSCBUFFERDESC* cbufdesc, const DSBUFFERDESC* bufdesc, HWND  hwnd, DWORD level, IDirectSoundFullDuplex**  dsfd, IDirectSoundCaptureBuffer8** dscb8, IDirectSoundBuffer8** dsb8, IUnknown* outer_unk);
void _DirectSoundFullDuplexCreate() { (fn_DirectSoundFullDuplexCreate)dsound.DirectSoundFullDuplexCreate(); }

typedef HRESULT(*fn_GetDeviceID)(LPCGUID pGuidSrc, LPGUID pGuidDest);
void _GetDeviceID() { (fn_GetDeviceID)dsound.GetDeviceID(); }


typedef HRESULT(*fn_DirectInput8Create)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter);
void _DirectInput8Create() { (fn_DirectInput8Create)dinput8.DirectInput8Create(); }

void _DllRegisterServer() { shared.DllRegisterServer(); }
void _DllUnregisterServer() { shared.DllUnregisterServer(); }
void _DllCanUnloadNow() { shared.DllCanUnloadNow(); }
void _DllGetClassObject() { shared.DllGetClassObject(); }

void _AppCacheCheckManifest() { wininet.AppCacheCheckManifest(); }
void _AppCacheCloseHandle() { wininet.AppCacheCloseHandle(); }
void _AppCacheCreateAndCommitFile() { wininet.AppCacheCreateAndCommitFile(); }
void _AppCacheDeleteGroup() { wininet.AppCacheDeleteGroup(); }
void _AppCacheDeleteIEGroup() { wininet.AppCacheDeleteIEGroup(); }
void _AppCacheDuplicateHandle() { wininet.AppCacheDuplicateHandle(); }
void _AppCacheFinalize() { wininet.AppCacheFinalize(); }
void _AppCacheFreeDownloadList() { wininet.AppCacheFreeDownloadList(); }
void _AppCacheFreeGroupList() { wininet.AppCacheFreeGroupList(); }
void _AppCacheFreeIESpace() { wininet.AppCacheFreeIESpace(); }
void _AppCacheFreeSpace() { wininet.AppCacheFreeSpace(); }
void _AppCacheGetDownloadList() { wininet.AppCacheGetDownloadList(); }
void _AppCacheGetFallbackUrl() { wininet.AppCacheGetFallbackUrl(); }
void _AppCacheGetGroupList() { wininet.AppCacheGetGroupList(); }
void _AppCacheGetIEGroupList() { wininet.AppCacheGetIEGroupList(); }
void _AppCacheGetInfo() { wininet.AppCacheGetInfo(); }
void _AppCacheGetManifestUrl() { wininet.AppCacheGetManifestUrl(); }
void _AppCacheLookup() { wininet.AppCacheLookup(); }
void _CommitUrlCacheEntryA() { wininet.CommitUrlCacheEntryA(); }
void _CommitUrlCacheEntryBinaryBlob() { wininet.CommitUrlCacheEntryBinaryBlob(); }
void _CommitUrlCacheEntryW() { wininet.CommitUrlCacheEntryW(); }
void _CreateMD5SSOHash() { wininet.CreateMD5SSOHash(); }
void _CreateUrlCacheContainerA() { wininet.CreateUrlCacheContainerA(); }
void _CreateUrlCacheContainerW() { wininet.CreateUrlCacheContainerW(); }
void _CreateUrlCacheEntryA() { wininet.CreateUrlCacheEntryA(); }
void _CreateUrlCacheEntryExW() { wininet.CreateUrlCacheEntryExW(); }
void _CreateUrlCacheEntryW() { wininet.CreateUrlCacheEntryW(); }
void _CreateUrlCacheGroup() { wininet.CreateUrlCacheGroup(); }
void _DeleteIE3Cache() { wininet.DeleteIE3Cache(); }
void _DeleteUrlCacheContainerA() { wininet.DeleteUrlCacheContainerA(); }
void _DeleteUrlCacheContainerW() { wininet.DeleteUrlCacheContainerW(); }
void _DeleteUrlCacheEntry() { wininet.DeleteUrlCacheEntry(); }
void _DeleteUrlCacheEntryA() { wininet.DeleteUrlCacheEntryA(); }
void _DeleteUrlCacheEntryW() { wininet.DeleteUrlCacheEntryW(); }
void _DeleteUrlCacheGroup() { wininet.DeleteUrlCacheGroup(); }
void _DeleteWpadCacheForNetworks() { wininet.DeleteWpadCacheForNetworks(); }
void _DetectAutoProxyUrl() { wininet.DetectAutoProxyUrl(); }
void _DispatchAPICall() { wininet.DispatchAPICall(); }
void _DllInstall() { wininet.DllInstall(); }
void _FindCloseUrlCache() { wininet.FindCloseUrlCache(); }
void _FindFirstUrlCacheContainerA() { wininet.FindFirstUrlCacheContainerA(); }
void _FindFirstUrlCacheContainerW() { wininet.FindFirstUrlCacheContainerW(); }
void _FindFirstUrlCacheEntryA() { wininet.FindFirstUrlCacheEntryA(); }
void _FindFirstUrlCacheEntryExA() { wininet.FindFirstUrlCacheEntryExA(); }
void _FindFirstUrlCacheEntryExW() { wininet.FindFirstUrlCacheEntryExW(); }
void _FindFirstUrlCacheEntryW() { wininet.FindFirstUrlCacheEntryW(); }
void _FindFirstUrlCacheGroup() { wininet.FindFirstUrlCacheGroup(); }
void _FindNextUrlCacheContainerA() { wininet.FindNextUrlCacheContainerA(); }
void _FindNextUrlCacheContainerW() { wininet.FindNextUrlCacheContainerW(); }
void _FindNextUrlCacheEntryA() { wininet.FindNextUrlCacheEntryA(); }
void _FindNextUrlCacheEntryExA() { wininet.FindNextUrlCacheEntryExA(); }
void _FindNextUrlCacheEntryExW() { wininet.FindNextUrlCacheEntryExW(); }
void _FindNextUrlCacheEntryW() { wininet.FindNextUrlCacheEntryW(); }
void _FindNextUrlCacheGroup() { wininet.FindNextUrlCacheGroup(); }
void _ForceNexusLookup() { wininet.ForceNexusLookup(); }
void _ForceNexusLookupExW() { wininet.ForceNexusLookupExW(); }
void _FreeUrlCacheSpaceA() { wininet.FreeUrlCacheSpaceA(); }
void _FreeUrlCacheSpaceW() { wininet.FreeUrlCacheSpaceW(); }
void _FtpCommandA() { wininet.FtpCommandA(); }
void _FtpCommandW() { wininet.FtpCommandW(); }
void _FtpCreateDirectoryA() { wininet.FtpCreateDirectoryA(); }
void _FtpCreateDirectoryW() { wininet.FtpCreateDirectoryW(); }
void _FtpDeleteFileA() { wininet.FtpDeleteFileA(); }
void _FtpDeleteFileW() { wininet.FtpDeleteFileW(); }
void _FtpFindFirstFileA() { wininet.FtpFindFirstFileA(); }
void _FtpFindFirstFileW() { wininet.FtpFindFirstFileW(); }
void _FtpGetCurrentDirectoryA() { wininet.FtpGetCurrentDirectoryA(); }
void _FtpGetCurrentDirectoryW() { wininet.FtpGetCurrentDirectoryW(); }
void _FtpGetFileA() { wininet.FtpGetFileA(); }
void _FtpGetFileEx() { wininet.FtpGetFileEx(); }
void _FtpGetFileSize() { wininet.FtpGetFileSize(); }
void _FtpGetFileW() { wininet.FtpGetFileW(); }
void _FtpOpenFileA() { wininet.FtpOpenFileA(); }
void _FtpOpenFileW() { wininet.FtpOpenFileW(); }
void _FtpPutFileA() { wininet.FtpPutFileA(); }
void _FtpPutFileEx() { wininet.FtpPutFileEx(); }
void _FtpPutFileW() { wininet.FtpPutFileW(); }
void _FtpRemoveDirectoryA() { wininet.FtpRemoveDirectoryA(); }
void _FtpRemoveDirectoryW() { wininet.FtpRemoveDirectoryW(); }
void _FtpRenameFileA() { wininet.FtpRenameFileA(); }
void _FtpRenameFileW() { wininet.FtpRenameFileW(); }
void _FtpSetCurrentDirectoryA() { wininet.FtpSetCurrentDirectoryA(); }
void _FtpSetCurrentDirectoryW() { wininet.FtpSetCurrentDirectoryW(); }
void __GetFileExtensionFromUrl() { wininet._GetFileExtensionFromUrl(); }
void _GetProxyDllInfo() { wininet.GetProxyDllInfo(); }
void _GetUrlCacheConfigInfoA() { wininet.GetUrlCacheConfigInfoA(); }
void _GetUrlCacheConfigInfoW() { wininet.GetUrlCacheConfigInfoW(); }
void _GetUrlCacheEntryBinaryBlob() { wininet.GetUrlCacheEntryBinaryBlob(); }
void _GetUrlCacheEntryInfoA() { wininet.GetUrlCacheEntryInfoA(); }
void _GetUrlCacheEntryInfoExA() { wininet.GetUrlCacheEntryInfoExA(); }
void _GetUrlCacheEntryInfoExW() { wininet.GetUrlCacheEntryInfoExW(); }
void _GetUrlCacheEntryInfoW() { wininet.GetUrlCacheEntryInfoW(); }
void _GetUrlCacheGroupAttributeA() { wininet.GetUrlCacheGroupAttributeA(); }
void _GetUrlCacheGroupAttributeW() { wininet.GetUrlCacheGroupAttributeW(); }
void _GetUrlCacheHeaderData() { wininet.GetUrlCacheHeaderData(); }
void _GopherCreateLocatorA() { wininet.GopherCreateLocatorA(); }
void _GopherCreateLocatorW() { wininet.GopherCreateLocatorW(); }
void _GopherFindFirstFileA() { wininet.GopherFindFirstFileA(); }
void _GopherFindFirstFileW() { wininet.GopherFindFirstFileW(); }
void _GopherGetAttributeA() { wininet.GopherGetAttributeA(); }
void _GopherGetAttributeW() { wininet.GopherGetAttributeW(); }
void _GopherGetLocatorTypeA() { wininet.GopherGetLocatorTypeA(); }
void _GopherGetLocatorTypeW() { wininet.GopherGetLocatorTypeW(); }
void _GopherOpenFileA() { wininet.GopherOpenFileA(); }
void _GopherOpenFileW() { wininet.GopherOpenFileW(); }
void _HttpAddRequestHeadersA() { wininet.HttpAddRequestHeadersA(); }
void _HttpAddRequestHeadersW() { wininet.HttpAddRequestHeadersW(); }
void _HttpCheckDavCompliance() { wininet.HttpCheckDavCompliance(); }
void _HttpCloseDependencyHandle() { wininet.HttpCloseDependencyHandle(); }
void _HttpDuplicateDependencyHandle() { wininet.HttpDuplicateDependencyHandle(); }
void _HttpEndRequestA() { wininet.HttpEndRequestA(); }
void _HttpEndRequestW() { wininet.HttpEndRequestW(); }
void _HttpGetServerCredentials() { wininet.HttpGetServerCredentials(); }
void _HttpGetTunnelSocket() { wininet.HttpGetTunnelSocket(); }
void _HttpIsHostHstsEnabled() { wininet.HttpIsHostHstsEnabled(); }
void _HttpOpenDependencyHandle() { wininet.HttpOpenDependencyHandle(); }
void _HttpOpenRequestA() { wininet.HttpOpenRequestA(); }
void _HttpOpenRequestW() { wininet.HttpOpenRequestW(); }
void _HttpPushClose() { wininet.HttpPushClose(); }
void _HttpPushEnable() { wininet.HttpPushEnable(); }
void _HttpPushWait() { wininet.HttpPushWait(); }
void _HttpQueryInfoA() { wininet.HttpQueryInfoA(); }
void _HttpQueryInfoW() { wininet.HttpQueryInfoW(); }
void _HttpSendRequestA() { wininet.HttpSendRequestA(); }
void _HttpSendRequestExA() { wininet.HttpSendRequestExA(); }
void _HttpSendRequestExW() { wininet.HttpSendRequestExW(); }
void _HttpSendRequestW() { wininet.HttpSendRequestW(); }
void _HttpWebSocketClose() { wininet.HttpWebSocketClose(); }
void _HttpWebSocketCompleteUpgrade() { wininet.HttpWebSocketCompleteUpgrade(); }
void _HttpWebSocketQueryCloseStatus() { wininet.HttpWebSocketQueryCloseStatus(); }
void _HttpWebSocketReceive() { wininet.HttpWebSocketReceive(); }
void _HttpWebSocketSend() { wininet.HttpWebSocketSend(); }
void _HttpWebSocketShutdown() { wininet.HttpWebSocketShutdown(); }
void _IncrementUrlCacheHeaderData() { wininet.IncrementUrlCacheHeaderData(); }
void _InternetAlgIdToStringA() { wininet.InternetAlgIdToStringA(); }
void _InternetAlgIdToStringW() { wininet.InternetAlgIdToStringW(); }
void _InternetAttemptConnect() { wininet.InternetAttemptConnect(); }
void _InternetAutodial() { wininet.InternetAutodial(); }
void _InternetAutodialCallback() { wininet.InternetAutodialCallback(); }
void _InternetAutodialHangup() { wininet.InternetAutodialHangup(); }
void _InternetCanonicalizeUrlA() { wininet.InternetCanonicalizeUrlA(); }
void _InternetCanonicalizeUrlW() { wininet.InternetCanonicalizeUrlW(); }
void _InternetCheckConnectionA() { wininet.InternetCheckConnectionA(); }
void _InternetCheckConnectionW() { wininet.InternetCheckConnectionW(); }
void _InternetClearAllPerSiteCookieDecisions() { wininet.InternetClearAllPerSiteCookieDecisions(); }
void _InternetCloseHandle() { wininet.InternetCloseHandle(); }
void _InternetCombineUrlA() { wininet.InternetCombineUrlA(); }
void _InternetCombineUrlW() { wininet.InternetCombineUrlW(); }
void _InternetConfirmZoneCrossing() { wininet.InternetConfirmZoneCrossing(); }
void _InternetConfirmZoneCrossingA() { wininet.InternetConfirmZoneCrossingA(); }
void _InternetConfirmZoneCrossingW() { wininet.InternetConfirmZoneCrossingW(); }
void _InternetConnectA() { wininet.InternetConnectA(); }
void _InternetConnectW() { wininet.InternetConnectW(); }
void _InternetConvertUrlFromWireToWideChar() { wininet.InternetConvertUrlFromWireToWideChar(); }
void _InternetCrackUrlA() { wininet.InternetCrackUrlA(); }
void _InternetCrackUrlW() { wininet.InternetCrackUrlW(); }
void _InternetCreateUrlA() { wininet.InternetCreateUrlA(); }
void _InternetCreateUrlW() { wininet.InternetCreateUrlW(); }
void _InternetDial() { wininet.InternetDial(); }
void _InternetDialA() { wininet.InternetDialA(); }
void _InternetDialW() { wininet.InternetDialW(); }
void _InternetEnumPerSiteCookieDecisionA() { wininet.InternetEnumPerSiteCookieDecisionA(); }
void _InternetEnumPerSiteCookieDecisionW() { wininet.InternetEnumPerSiteCookieDecisionW(); }
void _InternetErrorDlg() { wininet.InternetErrorDlg(); }
void _InternetFindNextFileA() { wininet.InternetFindNextFileA(); }
void _InternetFindNextFileW() { wininet.InternetFindNextFileW(); }
void _InternetFortezzaCommand() { wininet.InternetFortezzaCommand(); }
void _InternetFreeCookies() { wininet.InternetFreeCookies(); }
void _InternetFreeProxyInfoList() { wininet.InternetFreeProxyInfoList(); }
void _InternetGetCertByURL() { wininet.InternetGetCertByURL(); }
void _InternetGetCertByURLA() { wininet.InternetGetCertByURLA(); }
void _InternetGetConnectedState() { wininet.InternetGetConnectedState(); }
void _InternetGetConnectedStateEx() { wininet.InternetGetConnectedStateEx(); }
void _InternetGetConnectedStateExA() { wininet.InternetGetConnectedStateExA(); }
void _InternetGetConnectedStateExW() { wininet.InternetGetConnectedStateExW(); }
void _InternetGetCookieA() { wininet.InternetGetCookieA(); }
void _InternetGetCookieEx2() { wininet.InternetGetCookieEx2(); }
void _InternetGetCookieExA() { wininet.InternetGetCookieExA(); }
void _InternetGetCookieExW() { wininet.InternetGetCookieExW(); }
void _InternetGetCookieW() { wininet.InternetGetCookieW(); }
void _InternetGetLastResponseInfoA() { wininet.InternetGetLastResponseInfoA(); }
void _InternetGetLastResponseInfoW() { wininet.InternetGetLastResponseInfoW(); }
void _InternetGetPerSiteCookieDecisionA() { wininet.InternetGetPerSiteCookieDecisionA(); }
void _InternetGetPerSiteCookieDecisionW() { wininet.InternetGetPerSiteCookieDecisionW(); }
void _InternetGetProxyForUrl() { wininet.InternetGetProxyForUrl(); }
void _InternetGetSecurityInfoByURL() { wininet.InternetGetSecurityInfoByURL(); }
void _InternetGetSecurityInfoByURLA() { wininet.InternetGetSecurityInfoByURLA(); }
void _InternetGetSecurityInfoByURLW() { wininet.InternetGetSecurityInfoByURLW(); }
void _InternetGoOnline() { wininet.InternetGoOnline(); }
void _InternetGoOnlineA() { wininet.InternetGoOnlineA(); }
void _InternetGoOnlineW() { wininet.InternetGoOnlineW(); }
void _InternetHangUp() { wininet.InternetHangUp(); }
void _InternetInitializeAutoProxyDll() { wininet.InternetInitializeAutoProxyDll(); }
void _InternetLockRequestFile() { wininet.InternetLockRequestFile(); }
void _InternetOpenA() { wininet.InternetOpenA(); }
void _InternetOpenUrlA() { wininet.InternetOpenUrlA(); }
void _InternetOpenUrlW() { wininet.InternetOpenUrlW(); }
void _InternetOpenW() { wininet.InternetOpenW(); }
void _InternetQueryDataAvailable() { wininet.InternetQueryDataAvailable(); }
void _InternetQueryFortezzaStatus() { wininet.InternetQueryFortezzaStatus(); }
void _InternetQueryOptionA() { wininet.InternetQueryOptionA(); }
void _InternetQueryOptionW() { wininet.InternetQueryOptionW(); }
void _InternetReadFile() { wininet.InternetReadFile(); }
void _InternetReadFileExA() { wininet.InternetReadFileExA(); }
void _InternetReadFileExW() { wininet.InternetReadFileExW(); }
void _InternetSecurityProtocolToStringA() { wininet.InternetSecurityProtocolToStringA(); }
void _InternetSecurityProtocolToStringW() { wininet.InternetSecurityProtocolToStringW(); }
void _InternetSetCookieA() { wininet.InternetSetCookieA(); }
void _InternetSetCookieEx2() { wininet.InternetSetCookieEx2(); }
void _InternetSetCookieExA() { wininet.InternetSetCookieExA(); }
void _InternetSetCookieExW() { wininet.InternetSetCookieExW(); }
void _InternetSetCookieW() { wininet.InternetSetCookieW(); }
void _InternetSetDialState() { wininet.InternetSetDialState(); }
void _InternetSetDialStateA() { wininet.InternetSetDialStateA(); }
void _InternetSetDialStateW() { wininet.InternetSetDialStateW(); }
void _InternetSetFilePointer() { wininet.InternetSetFilePointer(); }
void _InternetSetOptionA() { wininet.InternetSetOptionA(); }
void _InternetSetOptionExA() { wininet.InternetSetOptionExA(); }
void _InternetSetOptionExW() { wininet.InternetSetOptionExW(); }
void _InternetSetOptionW() { wininet.InternetSetOptionW(); }
void _InternetSetPerSiteCookieDecisionA() { wininet.InternetSetPerSiteCookieDecisionA(); }
void _InternetSetPerSiteCookieDecisionW() { wininet.InternetSetPerSiteCookieDecisionW(); }
void _InternetSetStatusCallback() { wininet.InternetSetStatusCallback(); }
void _InternetSetStatusCallbackA() { wininet.InternetSetStatusCallbackA(); }
void _InternetSetStatusCallbackW() { wininet.InternetSetStatusCallbackW(); }
void _InternetShowSecurityInfoByURL() { wininet.InternetShowSecurityInfoByURL(); }
void _InternetShowSecurityInfoByURLA() { wininet.InternetShowSecurityInfoByURLA(); }
void _InternetShowSecurityInfoByURLW() { wininet.InternetShowSecurityInfoByURLW(); }
void _InternetTimeFromSystemTime() { wininet.InternetTimeFromSystemTime(); }
void _InternetTimeFromSystemTimeA() { wininet.InternetTimeFromSystemTimeA(); }
void _InternetTimeFromSystemTimeW() { wininet.InternetTimeFromSystemTimeW(); }
void _InternetTimeToSystemTime() { wininet.InternetTimeToSystemTime(); }
void _InternetTimeToSystemTimeA() { wininet.InternetTimeToSystemTimeA(); }
void _InternetTimeToSystemTimeW() { wininet.InternetTimeToSystemTimeW(); }
void _InternetUnlockRequestFile() { wininet.InternetUnlockRequestFile(); }
void _InternetWriteFile() { wininet.InternetWriteFile(); }
void _InternetWriteFileExA() { wininet.InternetWriteFileExA(); }
void _InternetWriteFileExW() { wininet.InternetWriteFileExW(); }
void _IsHostInProxyBypassList() { wininet.IsHostInProxyBypassList(); }
void _IsUrlCacheEntryExpiredA() { wininet.IsUrlCacheEntryExpiredA(); }
void _IsUrlCacheEntryExpiredW() { wininet.IsUrlCacheEntryExpiredW(); }
void _LoadUrlCacheContent() { wininet.LoadUrlCacheContent(); }
void _ParseX509EncodedCertificateForListBoxEntry() { wininet.ParseX509EncodedCertificateForListBoxEntry(); }
void _PrivacyGetZonePreferenceW() { wininet.PrivacyGetZonePreferenceW(); }
void _PrivacySetZonePreferenceW() { wininet.PrivacySetZonePreferenceW(); }
void _ReadUrlCacheEntryStream() { wininet.ReadUrlCacheEntryStream(); }
void _ReadUrlCacheEntryStreamEx() { wininet.ReadUrlCacheEntryStreamEx(); }
void _RegisterUrlCacheNotification() { wininet.RegisterUrlCacheNotification(); }
void _ResumeSuspendedDownload() { wininet.ResumeSuspendedDownload(); }
void _RetrieveUrlCacheEntryFileA() { wininet.RetrieveUrlCacheEntryFileA(); }
void _RetrieveUrlCacheEntryFileW() { wininet.RetrieveUrlCacheEntryFileW(); }
void _RetrieveUrlCacheEntryStreamA() { wininet.RetrieveUrlCacheEntryStreamA(); }
void _RetrieveUrlCacheEntryStreamW() { wininet.RetrieveUrlCacheEntryStreamW(); }
void _RunOnceUrlCache() { wininet.RunOnceUrlCache(); }
void _SetUrlCacheConfigInfoA() { wininet.SetUrlCacheConfigInfoA(); }
void _SetUrlCacheConfigInfoW() { wininet.SetUrlCacheConfigInfoW(); }
void _SetUrlCacheEntryGroup() { wininet.SetUrlCacheEntryGroup(); }
void _SetUrlCacheEntryGroupA() { wininet.SetUrlCacheEntryGroupA(); }
void _SetUrlCacheEntryGroupW() { wininet.SetUrlCacheEntryGroupW(); }
void _SetUrlCacheEntryInfoA() { wininet.SetUrlCacheEntryInfoA(); }
void _SetUrlCacheEntryInfoW() { wininet.SetUrlCacheEntryInfoW(); }
void _SetUrlCacheGroupAttributeA() { wininet.SetUrlCacheGroupAttributeA(); }
void _SetUrlCacheGroupAttributeW() { wininet.SetUrlCacheGroupAttributeW(); }
void _SetUrlCacheHeaderData() { wininet.SetUrlCacheHeaderData(); }
void _ShowCertificate() { wininet.ShowCertificate(); }
void _ShowClientAuthCerts() { wininet.ShowClientAuthCerts(); }
void _ShowSecurityInfo() { wininet.ShowSecurityInfo(); }
void _ShowX509EncodedCertificate() { wininet.ShowX509EncodedCertificate(); }
void _UnlockUrlCacheEntryFile() { wininet.UnlockUrlCacheEntryFile(); }
void _UnlockUrlCacheEntryFileA() { wininet.UnlockUrlCacheEntryFileA(); }
void _UnlockUrlCacheEntryFileW() { wininet.UnlockUrlCacheEntryFileW(); }
void _UnlockUrlCacheEntryStream() { wininet.UnlockUrlCacheEntryStream(); }
void _UpdateUrlCacheContentPath() { wininet.UpdateUrlCacheContentPath(); }
void _UrlCacheCheckEntriesExist() { wininet.UrlCacheCheckEntriesExist(); }
void _UrlCacheCloseEntryHandle() { wininet.UrlCacheCloseEntryHandle(); }
void _UrlCacheContainerSetEntryMaximumAge() { wininet.UrlCacheContainerSetEntryMaximumAge(); }
void _UrlCacheCreateContainer() { wininet.UrlCacheCreateContainer(); }
void _UrlCacheFindFirstEntry() { wininet.UrlCacheFindFirstEntry(); }
void _UrlCacheFindNextEntry() { wininet.UrlCacheFindNextEntry(); }
void _UrlCacheFreeEntryInfo() { wininet.UrlCacheFreeEntryInfo(); }
void _UrlCacheFreeGlobalSpace() { wininet.UrlCacheFreeGlobalSpace(); }
void _UrlCacheGetContentPaths() { wininet.UrlCacheGetContentPaths(); }
void _UrlCacheGetEntryInfo() { wininet.UrlCacheGetEntryInfo(); }
void _UrlCacheGetGlobalCacheSize() { wininet.UrlCacheGetGlobalCacheSize(); }
void _UrlCacheGetGlobalLimit() { wininet.UrlCacheGetGlobalLimit(); }
void _UrlCacheReadEntryStream() { wininet.UrlCacheReadEntryStream(); }
void _UrlCacheReloadSettings() { wininet.UrlCacheReloadSettings(); }
void _UrlCacheRetrieveEntryFile() { wininet.UrlCacheRetrieveEntryFile(); }
void _UrlCacheRetrieveEntryStream() { wininet.UrlCacheRetrieveEntryStream(); }
void _UrlCacheServer() { wininet.UrlCacheServer(); }
void _UrlCacheSetGlobalLimit() { wininet.UrlCacheSetGlobalLimit(); }
void _UrlCacheUpdateEntryExtraData() { wininet.UrlCacheUpdateEntryExtraData(); }
void _UrlZonesDetach() { wininet.UrlZonesDetach(); }

void _GetFileVersionInfoA() { version.GetFileVersionInfoA(); }
void _GetFileVersionInfoByHandle() { version.GetFileVersionInfoByHandle(); }
void _GetFileVersionInfoExA() { version.GetFileVersionInfoExA(); }
void _GetFileVersionInfoExW() { version.GetFileVersionInfoExW(); }
void _GetFileVersionInfoSizeA() { version.GetFileVersionInfoSizeA(); }
void _GetFileVersionInfoSizeExA() { version.GetFileVersionInfoSizeExA(); }
void _GetFileVersionInfoSizeExW() { version.GetFileVersionInfoSizeExW(); }
void _GetFileVersionInfoSizeW() { version.GetFileVersionInfoSizeW(); }
void _GetFileVersionInfoW() { version.GetFileVersionInfoW(); }
void _VerFindFileA() { version.VerFindFileA(); }
void _VerFindFileW() { version.VerFindFileW(); }
void _VerInstallFileA() { version.VerInstallFileA(); }
void _VerInstallFileW() { version.VerInstallFileW(); }
void _VerLanguageNameA() { version.VerLanguageNameA(); }
void _VerLanguageNameW() { version.VerLanguageNameW(); }
void _VerQueryValueA() { version.VerQueryValueA(); }
void _VerQueryValueW() { version.VerQueryValueW(); }

#pragma runtime_checks( "", restore )
#endif