/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _LMERRLOG_
#define _LMERRLOG_

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct _ERROR_LOG {
    DWORD el_len;
    DWORD el_reserved;
    DWORD el_time;
    DWORD el_error;
    LPWSTR el_name;
    LPWSTR el_text;
    LPBYTE el_data;
    DWORD el_data_size;
    DWORD el_nstrings;
  } ERROR_LOG,*PERROR_LOG,*LPERROR_LOG;

#define REVISED_ERROR_LOG_STRUCT

#ifndef _LMHLOGDEFINED_
#define _LMHLOGDEFINED_
  typedef struct _HLOG {
    DWORD time;
    DWORD last_flags;
    DWORD offset;
    DWORD rec_offset;
  } HLOG,*PHLOG,*LPHLOG;

#define LOGFLAGS_FORWARD 0
#define LOGFLAGS_BACKWARD 0x1
#define LOGFLAGS_SEEK 0x2
#endif

  NET_API_STATUS WINAPI NetErrorLogClear(LPCWSTR server,LPCWSTR backupfile,LPBYTE reserved);
  NET_API_STATUS WINAPI NetErrorLogRead(LPCWSTR server,LPWSTR reserved1,LPHLOG errloghandle,DWORD offset,LPDWORD reserved2,DWORD reserved3,DWORD offsetflag,LPBYTE *bufptr,DWORD prefmaxlen,LPDWORD bytesread,LPDWORD totalbytes);
  NET_API_STATUS WINAPI NetErrorLogWrite(LPBYTE reserved1,DWORD code,LPCWSTR component,LPBYTE buffer,DWORD numbytes,LPBYTE msgbuf,DWORD strcount,LPBYTE reserved2);

#define ERRLOG_BASE 3100

#define NELOG_Internal_Error (ERRLOG_BASE + 0)
#define NELOG_Resource_Shortage (ERRLOG_BASE + 1)
#define NELOG_Unable_To_Lock_Segment (ERRLOG_BASE + 2)
#define NELOG_Unable_To_Unlock_Segment (ERRLOG_BASE + 3)
#define NELOG_Uninstall_Service (ERRLOG_BASE + 4)
#define NELOG_Init_Exec_Fail (ERRLOG_BASE + 5)
#define NELOG_Ncb_Error (ERRLOG_BASE + 6)
#define NELOG_Net_Not_Started (ERRLOG_BASE + 7)
#define NELOG_Ioctl_Error (ERRLOG_BASE + 8)
#define NELOG_System_Semaphore (ERRLOG_BASE + 9)
#define NELOG_Init_OpenCreate_Err (ERRLOG_BASE + 10)
#define NELOG_NetBios (ERRLOG_BASE + 11)
#define NELOG_SMB_Illegal (ERRLOG_BASE + 12)
#define NELOG_Service_Fail (ERRLOG_BASE + 13)
#define NELOG_Entries_Lost (ERRLOG_BASE + 14)
#define NELOG_Init_Seg_Overflow (ERRLOG_BASE + 20)
#define NELOG_Srv_No_Mem_Grow (ERRLOG_BASE + 21)
#define NELOG_Access_File_Bad (ERRLOG_BASE + 22)
#define NELOG_Srvnet_Not_Started (ERRLOG_BASE + 23)
#define NELOG_Init_Chardev_Err (ERRLOG_BASE + 24)
#define NELOG_Remote_API (ERRLOG_BASE + 25)
#define NELOG_Ncb_TooManyErr (ERRLOG_BASE + 26)
#define NELOG_Mailslot_err (ERRLOG_BASE + 27)
#define NELOG_ReleaseMem_Alert (ERRLOG_BASE + 28)
#define NELOG_AT_cannot_write (ERRLOG_BASE + 29)
#define NELOG_Cant_Make_Msg_File (ERRLOG_BASE + 30)
#define NELOG_Exec_Netservr_NoMem (ERRLOG_BASE + 31)
#define NELOG_Server_Lock_Failure (ERRLOG_BASE + 32)
#define NELOG_Msg_Shutdown (ERRLOG_BASE + 40)
#define NELOG_Msg_Sem_Shutdown (ERRLOG_BASE + 41)
#define NELOG_Msg_Log_Err (ERRLOG_BASE + 50)
#define NELOG_VIO_POPUP_ERR (ERRLOG_BASE + 51)
#define NELOG_Msg_Unexpected_SMB_Type (ERRLOG_BASE + 52)
#define NELOG_Wksta_Infoseg (ERRLOG_BASE + 60)
#define NELOG_Wksta_Compname (ERRLOG_BASE + 61)
#define NELOG_Wksta_BiosThreadFailure (ERRLOG_BASE + 62)
#define NELOG_Wksta_IniSeg (ERRLOG_BASE + 63)
#define NELOG_Wksta_HostTab_Full (ERRLOG_BASE + 64)
#define NELOG_Wksta_Bad_Mailslot_SMB (ERRLOG_BASE + 65)
#define NELOG_Wksta_UASInit (ERRLOG_BASE + 66)
#define NELOG_Wksta_SSIRelogon (ERRLOG_BASE + 67)
#define NELOG_Build_Name (ERRLOG_BASE + 70)
#define NELOG_Name_Expansion (ERRLOG_BASE + 71)
#define NELOG_Message_Send (ERRLOG_BASE + 72)
#define NELOG_Mail_Slt_Err (ERRLOG_BASE + 73)
#define NELOG_AT_cannot_read (ERRLOG_BASE + 74)
#define NELOG_AT_sched_err (ERRLOG_BASE + 75)
#define NELOG_AT_schedule_file_created (ERRLOG_BASE + 76)
#define NELOG_Srvnet_NB_Open (ERRLOG_BASE + 77)
#define NELOG_AT_Exec_Err (ERRLOG_BASE + 78)
#define NELOG_Lazy_Write_Err (ERRLOG_BASE + 80)
#define NELOG_HotFix (ERRLOG_BASE + 81)
#define NELOG_HardErr_From_Server (ERRLOG_BASE + 82)
#define NELOG_LocalSecFail1 (ERRLOG_BASE + 83)
#define NELOG_LocalSecFail2 (ERRLOG_BASE + 84)
#define NELOG_LocalSecFail3 (ERRLOG_BASE + 85)
#define NELOG_LocalSecGeneralFail (ERRLOG_BASE + 86)
#define NELOG_NetWkSta_Internal_Error (ERRLOG_BASE + 90)
#define NELOG_NetWkSta_No_Resource (ERRLOG_BASE + 91)
#define NELOG_NetWkSta_SMB_Err (ERRLOG_BASE + 92)
#define NELOG_NetWkSta_VC_Err (ERRLOG_BASE + 93)
#define NELOG_NetWkSta_Stuck_VC_Err (ERRLOG_BASE + 94)
#define NELOG_NetWkSta_NCB_Err (ERRLOG_BASE + 95)
#define NELOG_NetWkSta_Write_Behind_Err (ERRLOG_BASE + 96)
#define NELOG_NetWkSta_Reset_Err (ERRLOG_BASE + 97)
#define NELOG_NetWkSta_Too_Many (ERRLOG_BASE + 98)
#define NELOG_Srv_Thread_Failure (ERRLOG_BASE + 104)
#define NELOG_Srv_Close_Failure (ERRLOG_BASE + 105)
#define NELOG_ReplUserCurDir (ERRLOG_BASE + 106)
#define NELOG_ReplCannotMasterDir (ERRLOG_BASE + 107)
#define NELOG_ReplUpdateError (ERRLOG_BASE + 108)
#define NELOG_ReplLostMaster (ERRLOG_BASE + 109)
#define NELOG_NetlogonAuthDCFail (ERRLOG_BASE + 110)
#define NELOG_ReplLogonFailed (ERRLOG_BASE + 111)
#define NELOG_ReplNetErr (ERRLOG_BASE + 112)
#define NELOG_ReplMaxFiles (ERRLOG_BASE + 113)
#define NELOG_ReplMaxTreeDepth (ERRLOG_BASE + 114)
#define NELOG_ReplBadMsg (ERRLOG_BASE + 115)
#define NELOG_ReplSysErr (ERRLOG_BASE + 116)
#define NELOG_ReplUserLoged (ERRLOG_BASE + 117)
#define NELOG_ReplBadImport (ERRLOG_BASE + 118)
#define NELOG_ReplBadExport (ERRLOG_BASE + 119)
#define NELOG_ReplSignalFileErr (ERRLOG_BASE + 120)
#define NELOG_DiskFT (ERRLOG_BASE+121)
#define NELOG_ReplAccessDenied (ERRLOG_BASE + 122)
#define NELOG_NetlogonFailedPrimary (ERRLOG_BASE + 123)
#define NELOG_NetlogonPasswdSetFailed (ERRLOG_BASE + 124)
#define NELOG_NetlogonTrackingError (ERRLOG_BASE + 125)
#define NELOG_NetlogonSyncError (ERRLOG_BASE + 126)
#define NELOG_NetlogonRequireSignOrSealError (ERRLOG_BASE + 127)
#define NELOG_UPS_PowerOut (ERRLOG_BASE + 130)
#define NELOG_UPS_Shutdown (ERRLOG_BASE + 131)
#define NELOG_UPS_CmdFileError (ERRLOG_BASE + 132)
#define NELOG_UPS_CannotOpenDriver (ERRLOG_BASE+133)
#define NELOG_UPS_PowerBack (ERRLOG_BASE + 134)
#define NELOG_UPS_CmdFileConfig (ERRLOG_BASE + 135)
#define NELOG_UPS_CmdFileExec (ERRLOG_BASE + 136)
#define NELOG_Missing_Parameter (ERRLOG_BASE + 150)
#define NELOG_Invalid_Config_Line (ERRLOG_BASE + 151)
#define NELOG_Invalid_Config_File (ERRLOG_BASE + 152)
#define NELOG_File_Changed (ERRLOG_BASE + 153)
#define NELOG_Files_Dont_Fit (ERRLOG_BASE + 154)
#define NELOG_Wrong_DLL_Version (ERRLOG_BASE + 155)
#define NELOG_Error_in_DLL (ERRLOG_BASE + 156)
#define NELOG_System_Error (ERRLOG_BASE + 157)
#define NELOG_FT_ErrLog_Too_Large (ERRLOG_BASE + 158)
#define NELOG_FT_Update_In_Progress (ERRLOG_BASE + 159)
#define NELOG_Joined_Domain (ERRLOG_BASE + 160)
#define NELOG_Joined_Workgroup (ERRLOG_BASE + 161)
#define NELOG_OEM_Code (ERRLOG_BASE + 199)
#define ERRLOG2_BASE 5700
#define NELOG_NetlogonSSIInitError (ERRLOG2_BASE + 0)
#define NELOG_NetlogonFailedToUpdateTrustList (ERRLOG2_BASE + 1)
#define NELOG_NetlogonFailedToAddRpcInterface (ERRLOG2_BASE + 2)
#define NELOG_NetlogonFailedToReadMailslot (ERRLOG2_BASE + 3)
#define NELOG_NetlogonFailedToRegisterSC (ERRLOG2_BASE + 4)
#define NELOG_NetlogonChangeLogCorrupt (ERRLOG2_BASE + 5)
#define NELOG_NetlogonFailedToCreateShare (ERRLOG2_BASE + 6)
#define NELOG_NetlogonDownLevelLogonFailed (ERRLOG2_BASE + 7)
#define NELOG_NetlogonDownLevelLogoffFailed (ERRLOG2_BASE + 8)
#define NELOG_NetlogonNTLogonFailed (ERRLOG2_BASE + 9)
#define NELOG_NetlogonNTLogoffFailed (ERRLOG2_BASE + 10)
#define NELOG_NetlogonPartialSyncCallSuccess (ERRLOG2_BASE + 11)
#define NELOG_NetlogonPartialSyncCallFailed (ERRLOG2_BASE + 12)
#define NELOG_NetlogonFullSyncCallSuccess (ERRLOG2_BASE + 13)
#define NELOG_NetlogonFullSyncCallFailed (ERRLOG2_BASE + 14)
#define NELOG_NetlogonPartialSyncSuccess (ERRLOG2_BASE + 15)
#define NELOG_NetlogonPartialSyncFailed (ERRLOG2_BASE + 16)
#define NELOG_NetlogonFullSyncSuccess (ERRLOG2_BASE + 17)
#define NELOG_NetlogonFullSyncFailed (ERRLOG2_BASE + 18)
#define NELOG_NetlogonAuthNoDomainController (ERRLOG2_BASE + 19)
#define NELOG_NetlogonAuthNoTrustLsaSecret (ERRLOG2_BASE + 20)
#define NELOG_NetlogonAuthNoTrustSamAccount (ERRLOG2_BASE + 21)
#define NELOG_NetlogonServerAuthFailed (ERRLOG2_BASE + 22)
#define NELOG_NetlogonServerAuthNoTrustSamAccount (ERRLOG2_BASE + 23)
#define NELOG_FailedToRegisterSC (ERRLOG2_BASE + 24)
#define NELOG_FailedToSetServiceStatus (ERRLOG2_BASE + 25)
#define NELOG_FailedToGetComputerName (ERRLOG2_BASE + 26)
#define NELOG_DriverNotLoaded (ERRLOG2_BASE + 27)
#define NELOG_NoTranportLoaded (ERRLOG2_BASE + 28)
#define NELOG_NetlogonFailedDomainDelta (ERRLOG2_BASE + 29)
#define NELOG_NetlogonFailedGlobalGroupDelta (ERRLOG2_BASE + 30)
#define NELOG_NetlogonFailedLocalGroupDelta (ERRLOG2_BASE + 31)
#define NELOG_NetlogonFailedUserDelta (ERRLOG2_BASE + 32)
#define NELOG_NetlogonFailedPolicyDelta (ERRLOG2_BASE + 33)
#define NELOG_NetlogonFailedTrustedDomainDelta (ERRLOG2_BASE + 34)
#define NELOG_NetlogonFailedAccountDelta (ERRLOG2_BASE + 35)
#define NELOG_NetlogonFailedSecretDelta (ERRLOG2_BASE + 36)
#define NELOG_NetlogonSystemError (ERRLOG2_BASE + 37)
#define NELOG_NetlogonDuplicateMachineAccounts (ERRLOG2_BASE + 38)
#define NELOG_NetlogonTooManyGlobalGroups (ERRLOG2_BASE + 39)
#define NELOG_NetlogonBrowserDriver (ERRLOG2_BASE + 40)
#define NELOG_NetlogonAddNameFailure (ERRLOG2_BASE + 41)
#define NELOG_RplMessages (ERRLOG2_BASE + 42)
#define NELOG_RplXnsBoot (ERRLOG2_BASE + 43)
#define NELOG_RplSystem (ERRLOG2_BASE + 44)
#define NELOG_RplWkstaTimeout (ERRLOG2_BASE + 45)
#define NELOG_RplWkstaFileOpen (ERRLOG2_BASE + 46)
#define NELOG_RplWkstaFileRead (ERRLOG2_BASE + 47)
#define NELOG_RplWkstaMemory (ERRLOG2_BASE + 48)
#define NELOG_RplWkstaFileChecksum (ERRLOG2_BASE + 49)
#define NELOG_RplWkstaFileLineCount (ERRLOG2_BASE + 50)
#define NELOG_RplWkstaBbcFile (ERRLOG2_BASE + 51)
#define NELOG_RplWkstaFileSize (ERRLOG2_BASE + 52)
#define NELOG_RplWkstaInternal (ERRLOG2_BASE + 53)
#define NELOG_RplWkstaWrongVersion (ERRLOG2_BASE + 54)
#define NELOG_RplWkstaNetwork (ERRLOG2_BASE + 55)
#define NELOG_RplAdapterResource (ERRLOG2_BASE + 56)
#define NELOG_RplFileCopy (ERRLOG2_BASE + 57)
#define NELOG_RplFileDelete (ERRLOG2_BASE + 58)
#define NELOG_RplFilePerms (ERRLOG2_BASE + 59)
#define NELOG_RplCheckConfigs (ERRLOG2_BASE + 60)
#define NELOG_RplCreateProfiles (ERRLOG2_BASE + 61)
#define NELOG_RplRegistry (ERRLOG2_BASE + 62)
#define NELOG_RplReplaceRPLDISK (ERRLOG2_BASE + 63)
#define NELOG_RplCheckSecurity (ERRLOG2_BASE + 64)
#define NELOG_RplBackupDatabase (ERRLOG2_BASE + 65)
#define NELOG_RplInitDatabase (ERRLOG2_BASE + 66)
#define NELOG_RplRestoreDatabaseFailure (ERRLOG2_BASE + 67)
#define NELOG_RplRestoreDatabaseSuccess (ERRLOG2_BASE + 68)
#define NELOG_RplInitRestoredDatabase (ERRLOG2_BASE + 69)
#define NELOG_NetlogonSessionTypeWrong (ERRLOG2_BASE + 70)
#define NELOG_RplUpgradeDBTo40 (ERRLOG2_BASE + 71)
#define NELOG_NetlogonLanmanBdcsNotAllowed (ERRLOG2_BASE + 72)
#define NELOG_NetlogonNoDynamicDns (ERRLOG2_BASE + 73)
#define NELOG_NetlogonDynamicDnsRegisterFailure (ERRLOG2_BASE + 74)
#define NELOG_NetlogonDynamicDnsDeregisterFailure (ERRLOG2_BASE + 75)
#define NELOG_NetlogonFailedFileCreate (ERRLOG2_BASE + 76)
#define NELOG_NetlogonGetSubnetToSite (ERRLOG2_BASE + 77)
#define NELOG_NetlogonNoSiteForClient (ERRLOG2_BASE + 78)
#define NELOG_NetlogonBadSiteName (ERRLOG2_BASE + 79)
#define NELOG_NetlogonBadSubnetName (ERRLOG2_BASE + 80)
#define NELOG_NetlogonDynamicDnsServerFailure (ERRLOG2_BASE + 81)
#define NELOG_NetlogonDynamicDnsFailure (ERRLOG2_BASE + 82)
#define NELOG_NetlogonRpcCallCancelled (ERRLOG2_BASE + 83)
#define NELOG_NetlogonDcSiteCovered (ERRLOG2_BASE + 84)
#define NELOG_NetlogonDcSiteNotCovered (ERRLOG2_BASE + 85)
#define NELOG_NetlogonGcSiteCovered (ERRLOG2_BASE + 86)
#define NELOG_NetlogonGcSiteNotCovered (ERRLOG2_BASE + 87)
#define NELOG_NetlogonFailedSpnUpdate (ERRLOG2_BASE + 88)
#define NELOG_NetlogonFailedDnsHostNameUpdate (ERRLOG2_BASE + 89)
#define NELOG_NetlogonAuthNoUplevelDomainController (ERRLOG2_BASE + 90)
#define NELOG_NetlogonAuthDomainDowngraded (ERRLOG2_BASE + 91)
#define NELOG_NetlogonNdncSiteCovered (ERRLOG2_BASE + 92)
#define NELOG_NetlogonNdncSiteNotCovered (ERRLOG2_BASE + 93)
#define NELOG_NetlogonDcOldSiteCovered (ERRLOG2_BASE + 94)
#define NELOG_NetlogonDcSiteNotCoveredAuto (ERRLOG2_BASE + 95)
#define NELOG_NetlogonGcOldSiteCovered (ERRLOG2_BASE + 96)
#define NELOG_NetlogonGcSiteNotCoveredAuto (ERRLOG2_BASE + 97)
#define NELOG_NetlogonNdncOldSiteCovered (ERRLOG2_BASE + 98)
#define NELOG_NetlogonNdncSiteNotCoveredAuto (ERRLOG2_BASE + 99)
#define NELOG_NetlogonSpnMultipleSamAccountNames (ERRLOG2_BASE + 100)
#define NELOG_NetlogonSpnCrackNamesFailure (ERRLOG2_BASE + 101)
#define NELOG_NetlogonNoAddressToSiteMapping (ERRLOG2_BASE + 102)
#define NELOG_NetlogonInvalidGenericParameterValue (ERRLOG2_BASE + 103)
#define NELOG_NetlogonInvalidDwordParameterValue (ERRLOG2_BASE + 104)
#define NELOG_NetlogonServerAuthFailedNoAccount (ERRLOG2_BASE + 105)
#define NELOG_NetlogonNoDynamicDnsManual (ERRLOG2_BASE + 106)
#define NELOG_NetlogonNoSiteForClients (ERRLOG2_BASE + 107)
#define NELOG_NetlogonDnsDeregAborted (ERRLOG2_BASE + 108)
#define NELOG_NetlogonRpcPortRequestFailure (ERRLOG2_BASE + 109)

#ifdef __cplusplus
}
#endif
#endif
