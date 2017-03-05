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
#include <stdint.h>

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
        uint8_t peer_addr[6],
        uint8_t adv_chan_map,
        uint8_t adv_filter_policy);
/**
 * Send an HCI Advertise Enable command to the Controller.
 */
int HciSendAdvertiseEnable(bool enable);