/**
 * Definitions required by the HCI layer
 */
#pragma once

#include "hci_error.h"

#define HCI_MAX_CMD_SIZE 255

/**
 * HCI Group Types (OGFs)
 */
typedef enum {
    kHciGroupLinkControl         = 0x01,
    kHciGroupLinkPolicy          = 0x02,
    kHciGroupControllerBaseband  = 0x03,
    kHciGroupInformationalParams = 0x04,
    kHciGroupStatusParams        = 0x05,
    kHciGroupTest                = 0x06,
    kHciGroupLeController        = 0x08,
    kHciGroupVendorSpecific      = 0x3F,
} eHciGroup;

/**
 * Link Control Commands (OGF 0x01)
 * BT Spec: Vol 2, Part E, Section 7.1
 */
typedef enum {
    kHciCmdLinkControlInquiry                     = 0x01,
    kHciCmdLinkControlInquiryCancel               = 0x02,
    kHciCmdLinkControlPeriodicInquiryMode         = 0x03,
    kHciCmdLinkControlExitPeriodicInquiryMode     = 0x04,
    kHciCmdLinkControlCreateConnection            = 0x05,
    kHciCmdLinkControlDisconnect                  = 0x06,
    kHciCmdLinkControlAddSCOConnection            = 0x07,
    kHciCmdLinkControlAcceptConnectionRequest     = 0x09,
    kHciCmdLinkControlRejectConnectionRequest     = 0x0A,
    kHciCmdLinkControlLinkKeyRequestReply         = 0x0B,
    kHciCmdLinkControlLinkKeyRequestNegativeReply = 0x0C,
    kHciCmdLinkControlPINRequestReply             = 0x0D,
    kHciCmdLinkControlPINRequestNegativeReply     = 0x0E,
    kHciCmdLinkControlChangeConnectionPacketType  = 0x0F,
    kHciCmdLinkControlAuthenticationRequested     = 0x11,
    kHciCmdLinkControlSetConnectionEncryption     = 0x13,
    kHciCmdLinkControlChangeConnectionLinkKey     = 0x15,
    kHciCmdLinkControlMasterLinkKey               = 0x17,
    kHciCmdLinkControlRemoteNameRequest           = 0x19,
    kHciCmdLinkControlReadRemoteSupportedFeatures = 0x1B,
    kHciCmdLinkControlReadRemoteVersionInfo       = 0x1D,
    kHciCmdLinkControlReadClockOffset             = 0x1F,
} eHciCmdLinkControl;

/**
 * Link Policy Commands (OGF 0x02)
 * BT Spec: Vol 2, Part E, Section 7.2
 */
typedef enum {
    kHciCmdLinkPolicyHoldMode      = 0x01,
    kHciCmdLinkPolicySniffMode     = 0x03,
    kHciCmdLinkPolicyExitSniffMode = 0x04,
    kHciCmdLinkPolicyParkMode      = 0x05,
    kHciCmdLinkPolicyExitParkMode  = 0x06,
    kHciCmdLinkPolicyQoSSetup      = 0x07,
    kHciCmdLinkPolicyRoleDiscovery = 0x09,
    kHciCmdLinkPolicySwitchRole    = 0x0B,
    kHciCmdLinkPolicyReadSettings  = 0x0C,
    kHciCmdLinkPolicyWriteSettings = 0x0D,
} eHciCmdLinkPolicy;

/**
 * Controller and Baseband Commands (OGF 0x03)
 * BT Spec: Vol 2, Part E, Section 7.1
 */
typedef enum {
    kHciCmdControllerSetEventMask                   = 0x01,
    kHciCmdControllerReset                          = 0x03,
    kHciCmdControllerSetEventFilter                 = 0x05,
    kHciCmdControllerFlush                          = 0x08,
    kHciCmdControllerReadPINType                    = 0x09,
    kHciCmdControllerWritePINType                   = 0x0A,
    kHciCmdControllerCreateNewUnitKey               = 0x0B,
    kHciCmdControllerReadStoredLinkKey              = 0x0D,
    kHciCmdControllerWriteStoredLinkKey             = 0x11,
    kHciCmdControllerDeleteStoredLinkKey            = 0x12,
    kHciCmdControllerChangeLocalName                = 0x13,
    kHciCmdControllerReadLocalName                  = 0x14,
    kHciCmdControllerReadConnectionAcceptTimeout    = 0x15,
    kHciCmdControllerWriteConnectionAcceptTimeout   = 0x16,
    kHciCmdControllerReadPageTimeout                = 0x17,
    kHciCmdControllerWritePageTimeout               = 0x18,
    kHciCmdControllerReadScanEnable                 = 0x19,
    kHciCmdControllerWriteScanEnable                = 0x1A,
    kHciCmdControllerReadPageScanActivity           = 0x1B,
    kHciCmdControllerWritePageScanActivity          = 0x1C,
    kHciCmdControllerReadInquiryScanActivity        = 0x1D,
    kHciCmdControllerWriteInquiryScanActivity       = 0x1E,
    kHciCmdControllerReadAuthEnable                 = 0x1F,
    kHciCmdControllerWriteAuthEnable                = 0x20,
    kHciCmdControllerReadEncryptionMode             = 0x21,
    kHciCmdControllerWriteEncryptionMode            = 0x22,
    kHciCmdControllerReadClassOfDevice              = 0x23,
    kHciCmdControllerWriteClassOfDevice             = 0x24,
    kHciCmdControllerReadVoiceSetting               = 0x25,
    kHciCmdControllerWriteVoiceSetting              = 0x26,
    kHciCmdControllerReadAutoFlushTimeout           = 0x27,
    kHciCmdControllerWriteAutoFlushTimeout          = 0x28,
    kHciCmdControllerReadNumBroadcastRetrans        = 0x29,
    kHciCmdControllerWriteNumBroadcastRetrans       = 0x2A,
    kHciCmdControllerReadHoldModeActivity           = 0x2B,
    kHciCmdControllerWriteHoldModeActivity          = 0x2C,
    kHciCmdControllerReadTransmitPowerLevel         = 0x2D,
    kHciCmdControllerReadSCOFlowControlEnable       = 0x2E,
    kHciCmdControllerWriteSCOFlowControlEnable      = 0x2F,
    kHciCmdControllerSetControllerToHostFlowControl = 0x31,
    kHciCmdControllerHostBufferSize                 = 0x33,
    kHciCmdControllerHostNumCompletedPackets        = 0x35,
    kHciCmdControllerReadLinkSupervisionTimeout     = 0x36,
    kHciCmdControllerWriteLinkSupervisionTimeout    = 0x37,
    kHciCmdControllerReadNumSupportedIAC            = 0x38,
    kHciCmdControllerReadCurrentIAC_LAP             = 0x39,
    kHciCmdControllerWriteCurrentIAC_LAP            = 0x3A,
    kHciCmdControllerReadPageScanPeriodMode         = 0x3B,
    kHciCmdControllerWritePageScanPeriodMode        = 0x3C,
    kHciCmdControllerReadPageScanMode               = 0x3D,
    kHciCmdControllerWritePageScanMode              = 0x3E,
} eHciCmdControllerBaseband;
