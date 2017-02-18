/**
 * Definitions required by the HCI layer
 */
#pragma once

#include "hci_error.h"

#define HCI_MAX_CMD_SIZE 255

/**
 * HCI group values
 */
typedef enum {
    kHciGroupLinkControl         = 0x01,
    kHciGroupLinkPolicy          = 0x02,
    kHciGroupControllerBaseband  = 0x03,
    kHciGroupInformationalParams = 0x04,
    kHciGroupStatusParams        = 0x05,
    kHciGroupTest                = 0x06,
    kHciGroupLeController        = 0x08,
    kHciGroupVendor              = 0x3f,
} HciOpcodeGroup;
