/**
 * HCI error codes
 *
 * BT Spec: Vol 2, Part D, Section 1.3
 */

typedef enum {
    kHciErrorCodeSuccess                       = 0x00, // Success
    kHciErrorCodeUnknownCmd                    = 0x01, // Unknown HCI Command
    kHciErrorCodeUnknownConn                   = 0x02, // Unknown Connection Identifier
    kHciErrorCodeHardwareFailure               = 0x03, // Hardware Failure
    kHciErrorCodePageTimeout                   = 0x04, // Page Timeout
    kHciErrorCodeAuthFailure                   = 0x05, // Authentication Failure
    kHciErrorCodeKeyMissing                    = 0x06, // PIN or Key Missing
    kHciErrorCodeMemCapacityExceeded           = 0x07, // Memory Capacity Exceeded
    kHciErrorCodeConnTimeout                   = 0x08, // Connection Timeout
    kHciErrorCodeConnLimitExceeded             = 0x09, // Connection Limit Exceeded
    kHciErrorCodeSyncConnLimitExceeded         = 0x0A, // Synchronous Connection Limit To A Device Exceeded
    kHciErrorCodeACLConnectionExists           = 0x0B, // ACL Connection Already Exists
    kHciErrorCodeCmdDisallowed                 = 0x0C, // Command Disallowed
    kHciErrorCodeConnRejectedLimitedResources  = 0x0D, // Connection Rejected due to Limited Resources
    kHciErrorCodeConnRejectedSecurityReason    = 0x0E, // Connection Rejected Due To Security Reasons
    kHciErrorCodeConnRejectedBadAddr           = 0x0F, // Connection Rejected due to Unacceptable BD_ADDR
    kHciErrorCodeConnAcceptTimeout             = 0x10, // Connection Accept Timeout Exceeded
    kHciErrorCodeUnsupported                   = 0x11, // Unsupported Feature or Parameter Value
    kHciErrorCodeInvalidParam                  = 0x12, // Invalid HCI Command Parameters
    kHciErrorCodeRemoteUserTerminated          = 0x13, // Remote User Terminated Connection
    kHciErrorCodeRemoveDeviceLowResource       = 0x14, // Remote Device Terminated Connection due to Low Resources
    kHciErrorCodeRemoteDevicePowerOff          = 0x15, // Remote Device Terminated Connection due to Power Off
    kHciErrorCodeLocalHostTerminated           = 0x16, // Connection Terminated By Local Host
    kHciErrorCodeRepeatedAttempts              = 0x17, // Repeated Attempts
    kHciErrorCodePairingDisallowed             = 0x18, // Pairing Not Allowed
    kHciErrorCodeUnknownPDU                    = 0x19, // Unknown LMP PDU
    kHciErrorCodeUnsupportedRemoteFeature      = 0x1A, // Unsupported Remote Feature / Unsupported LMP Feature
    kHciErrorCodeSCOOffsetRejected             = 0x1B, // SCO Offset Rejected
    kHciErrorCodeSCOIntervalRejected           = 0x1C, // SCO Interval Rejected
    kHciErrorCodeSCOAirModeRejected            = 0x1D, // SCO Air Mode Rejected
    kHciErrorCodeInvalidLMP_LLParams           = 0x1E, // Invalid LMP Parameters / Invalid LL Parameters
    kHciErrorCodeUnspecified                   = 0x1F, // Unspecified Error
    kHciErrorCodeUnspecifiedLMP_LLParam        = 0x20, // Unsupported LMP Parameter Value / Unsupported LL Parameter Value
    kHciErrorCodeRoleChangeDisallowed          = 0x21, // Role Change Not Allowed
    kHciErrorCodeLMPResponseTimeout            = 0x22, // LMP Response Timeout / LL Response Timeout
    kHciErrorCodeLMPCollision                  = 0x23, // LMP Error Transaction Collision
    kHciErrorCodeLMP_PDUDisallowed             = 0x24, // LMP PDU Not Allowed
    kHciErrorCodeEncryptionMode                = 0x25, // Encryption Mode Not Acceptable
    kHciErrorCodeLinkKey                       = 0x26, // Link Key cannot be Changed
    kHciErrorCodeQoSUnsupported                = 0x27, // Requested QoS Not Supported
    kHciErrorCodeInstantPassed                 = 0x28, // Instant Passed
    kHciErrorCodeUnitKeyUnsupported            = 0x29, // Pairing With Unit Key Not Supported
    kHciErrorCodeDifferentTransactionCollision = 0x2A, // Different Transaction Collision
    kHciErrorCodeReserved2B                    = 0x2B, // Reserved
    kHciErrorCodeQoSBadParam                   = 0x2C, // QoS Unacceptable Parameter
    kHciErrorCodeQoSRejected                   = 0x2D, // QoS Rejected
    kHciErrorCodeChannelClassUnsupported       = 0x2E, // Channel Classification Not Supported
    kHciErrorCodeInsufficientSecurity          = 0x2F, // Insufficient Security
    kHciErrorCodeParamaterOutOfRange           = 0x30, // Parameter Out Of Mandatory Range
    kHciErrorCodeReserved31                    = 0x31, // Reserved
    kHciErrorCodeRoleSwitchPending             = 0x32, // Role Switch Pending
    kHciErrorCodeReserved33                    = 0x33, // Reserved
    kHciErrorCodeReservedSlotViolation         = 0x34, // Reserved Slot Violation
    kHciErrorCodeRoleSwitchFailed              = 0x35, // Role Switch Failed
    kHciErrorCodeEIRTooLarge                   = 0x36, // Extended Inquiry Response Too Large
    kHciErrorCodeSSPUnsupported                = 0x37, // Secure Simple Pairing Not Supported By Host
    kHciErrorCodeHostBusyPairing               = 0x38, // Host Busy - Pairing
    kHciErrorCodeNoSuitableChannel             = 0x39, // Connection Rejected due to No Suitable Channel Found
    kHciErrorCodeControllerBusy                = 0x3A, // Controller Busy
    kHciErrorCodeBadConnectionParams           = 0x3B, // Unacceptable Connection Parameters
    kHciErrorCodeDirectedAdvTimeout            = 0x3C, // Directed Advertising Timeout
    kHciErrorCodeMICFailure                    = 0x3D, // Connection Terminated due to MIC Failure
    kHciErrorCodeConnectionFailed              = 0x3E, // Connection Failed to be Established
    kHciErrorCodeMACConnectionFailed           = 0x3F, // MAC Connection Failed
    kHciErrorCodeCourseClockAdjustRejected     = 0x40, // Coarse Clock Adjustment Rejected but Will Try to Adjust Using Clock Dragging
} HciErrorCode;
