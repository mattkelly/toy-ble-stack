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

/**
 * Send an HCI Reset command to the Controller.
 */
int HciSendReset(void);
