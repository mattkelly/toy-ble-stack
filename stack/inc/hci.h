/**
 * This file defines the Host Controller Interface (HCI) layer.
 *
 * In the BLE stack, the HCI layer exists directly below L2CAP and directly
 * above the physical bus driver to the Controller (e.g. UART or USB).
 *
 * If the Host and Controller are integrated, then the HCI layer is not required.
 * In this case, L2CAP would exist directly above the LMP layer of the Controller
 * stack.
 *
 * Responsibilities:
 *  - Standardizes interface between (and decouples) Host and Controller
 *  - Manages flow control between Host and Controller
 *
 * Services Provided:
 *  - Exposes functionality to allow Host to:
 *   - Discover, add, and manage devices on the piconet
 *   - Configure Controller properties
 *   - Set up, manage, and release logical transports and links
 *   - Write directly to the baseband's buffer for SCO and eSCO streaming
 *
 * References:
 *  - BT Spec: Vol 2, Part E - HCI Functional Specification
 *  - BT Spec: Vol 2, Part E, Section 3.19 - HCI Requirements for LE Controller
 */
#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "toy_ble.h"

/**
 * Send an HCI Reset command to the Controller.
 */
int HciSendReset(void);

/**
 * Send an HCI Set Advertising Parameters command to the Controller.
 */
// @TODO enums etc.
int HciSendSetAdvertisingParams(uint16_t adv_interval_min,
        uint16_t adv_interval_max,
        uint8_t adv_type,
        uint8_t own_addr_type,
        uint8_t peer_addr_type,
        BdAddr peer_addr,
        uint8_t adv_chan_map,
        uint8_t adv_filter_policy);

/**
 * Send an HCI Advertise Enable command to the Controller.
 */
int HciSendSetAdvertiseEnable(bool enable);

/**
 * Send an HCI Set Advertising Data command to the Controller.
 */
int HciSendSetAdvertisingData(uint8_t adv_data_len, const uint8_t *adv_data);

/**
 * Send an HCI Set Scan Parameters command to the Controller.
 */
// @TODO enums etc.
int HciSendSetScanParams(uint8_t le_scan_type,
        uint16_t le_scan_interval,
        uint16_t le_scan_window,
        uint8_t own_address_type,
        uint8_t scanning_filter_policy);

/**
 * Send an HCI Set Scan Enable command to the Controller.
 */
int HciSendSetScanEnable(bool enable, bool filter_duplicates);

/**
 * Handle generic data received by the HCI Transport.
 */
int HciHandleDataReceived(void *data, size_t len);
