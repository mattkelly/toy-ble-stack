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
