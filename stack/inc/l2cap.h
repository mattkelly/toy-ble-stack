/**
 * This file defines the Logical Link Control and Adaptation Protocol (L2CAP) layer.
 *
 * In the BLE stack, the L2CAP layer exists directly below ATT and directly above HCI.
 *
 * Responsibilities:
 *  - Multiplexes logical channels (called L2CAP channels) over one or more logical links
 *
 * Services Provided:
 *  - Connection-oriented and connectionless data services
 *  - Protocol multiplexing capability
 *  - Segmentation and reassembly operation
 *
 * References:
 *  - BT Spec: Vol 3, Part A - L2CAP Specification
 */
#pragma once

#include <stddef.h>
#include <stdint.h>

#include "hci_defs.h"

// @TODO should probably be user-configurable
#define L2CAP_ACL_MAX_PAYLOAD_LEN 512

#define L2CAP_ACL_RECEIVE_BUFFER_LEN (sizeof(HciAclDataHdr) + L2CAP_ACL_MAX_PAYLOAD_LEN)

/**
 * State definitions for the ACL Receive State Machine
 */
typedef enum {
    kL2capAclReceiveStateIdle,            // No data expected currently
    kL2capAclReceiveStateReceiving,       // Receiving data
    kL2capAclReceiveStateReceivedAllData, // Received all data
} L2capAclReceiveState;

/**
 * ACL Receive State Machine
 *
 * Handles reassembly of fragmented ACL data received over HCI.
 */
typedef struct {
    L2capAclReceiveState state;
    size_t num_bytes_expected;
    size_t buffer_pos;
    uint8_t buffer[L2CAP_ACL_RECEIVE_BUFFER_LEN];
} L2capAclReceiveStateMachine;

/**
 * @TODO
 */
int L2capHandleAclDataReceived(const void *data, size_t len, HciAclPacketBoundaryFlag pb_flag);
