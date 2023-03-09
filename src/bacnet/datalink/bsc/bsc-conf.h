/**
 * @file
 * @brief Configuration file of BACNet/SC datalink.
 * @author Kirill Neznamov
 * @date August 2022
 * @section LICENSE
 *
 * Copyright (C) 2022 Legrand North America, LLC
 * as an unpublished work.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __BSC__CONF__INCLUDED__
#define __BSC__CONF__INCLUDED__

#include "bacnet/bacdef.h"

#ifndef BSC_CONF_HUB_CONNECTORS_NUM
#define BSC_CONF_HUB_CONNECTORS_NUM 1
#endif

#ifndef BSC_CONF_HUB_FUNCTIONS_NUM
#define BSC_CONF_HUB_FUNCTIONS_NUM 1
#endif

#ifndef BSC_CONF_NODE_SWITCHES_NUM
#define BSC_CONF_NODE_SWITCHES_NUM 1
#endif

#ifndef BSC_CONF_NODES_NUM
#define BSC_CONF_NODES_NUM 1
#endif

#ifndef BVLC_SC_NPDU_SIZE_CONF
/* 16 bytes is sum of all sizes of all static (non variable)
   fields of BVLC message */
#define BVLC_SC_NPDU_SIZE_CONF ((MAX_PDU) + 16)
#endif

#ifndef BSC_CONF_WEBSOCKET_INITIAL_RECV_BUFFER_LEN
#define BSC_CONF_WEBSOCKET_INITIAL_RECV_BUFFER_LEN BVLC_SC_NPDU_SIZE_CONF
#endif

/* THIS should not be changed, most of BACNet/SC devices must have */
/* hub connector, it uses 2 connections */
#ifndef BSC_CONF_HUB_CONNECTOR_CONNECTIONS_NUM
#define BSC_CONF_HUB_CONNECTOR_CONNECTIONS_NUM (BSC_CONF_HUB_CONNECTORS_NUM*2)
#endif

#ifndef BSC_CONF_HUB_FUNCTION_CONNECTIONS_NUM
#define BSC_CONF_HUB_FUNCTION_CONNECTIONS_NUM (BSC_CONF_HUB_FUNCTIONS_NUM*10)
#endif

#ifndef BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM
#define BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM 10
#endif

/* Total amount of client(initiator) webosocket connections */
#ifndef BSC_CONF_CLIENT_CONNECTIONS_NUM
#define BSC_CONF_CLIENT_CONNECTIONS_NUM (BSC_CONF_HUB_CONNECTOR_CONNECTIONS_NUM + BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM*BSC_CONF_NODE_SWITCHES_NUM)
#endif

#ifndef BSC_CONF_SERVER_HUB_CONNECTIONS_MAX_NUM
#define BSC_CONF_SERVER_HUB_CONNECTIONS_MAX_NUM (BSC_CONF_HUB_FUNCTION_CONNECTIONS_NUM)
#endif

#ifndef BSC_CONF_SERVER_DIRECT_CONNECTIONS_MAX_NUM
#define BSC_CONF_SERVER_DIRECT_CONNECTIONS_MAX_NUM  (BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM*BSC_CONF_NODE_SWITCHES_NUM)
#endif

#define BSC_CONF_RX_BUFFER_SIZE 4096
#define BSC_CONF_TX_BUFFER_SIZE 4096

#ifndef BSC_CONF_WSURL_MAX_LEN
#define BSC_CONF_WSURL_MAX_LEN 128
#endif

#ifndef BSC_CONF_WEBSOCKET_ERR_DESC_STR_MAX_LEN
#define BSC_CONF_WEBSOCKET_ERR_DESC_STR_MAX_LEN 128
#endif

#ifndef BSC_CONF_NODE_MAX_URI_SIZE_IN_ADDRESS_RESOLUTION_ACK
#define BSC_CONF_NODE_MAX_URI_SIZE_IN_ADDRESS_RESOLUTION_ACK BSC_CONF_WSURL_MAX_LEN
#endif

#ifndef BSC_CONF_NODE_MAX_URIS_NUM_IN_ADDRESS_RESOLUTION_ACK
#define BSC_CONF_NODE_MAX_URIS_NUM_IN_ADDRESS_RESOLUTION_ACK \
        (BSC_CONF_RX_BUFFER_SIZE/BSC_CONF_NODE_MAX_URI_SIZE_IN_ADDRESS_RESOLUTION_ACK - 1)
#endif

#ifndef BSC_CONF_OPERATIONAL_CERTIFICATE_FILE_INSTANCE
#define BSC_CONF_OPERATIONAL_CERTIFICATE_FILE_INSTANCE 5
#endif

#ifndef BSC_CONF_CERTIFICATE_SIGNING_REQUEST_FILE_INSTANCE
#define BSC_CONF_CERTIFICATE_SIGNING_REQUEST_FILE_INSTANCE 6
#endif

#ifndef BSC_CONF_ISSUER_CERTIFICATE_FILE_1_INSTANCE
#define BSC_CONF_ISSUER_CERTIFICATE_FILE_1_INSTANCE 7
#endif

#ifndef BSC_CONF_ISSUER_CERTIFICATE_FILE_2_INSTANCE
#define BSC_CONF_ISSUER_CERTIFICATE_FILE_2_INSTANCE 8
#endif

#ifndef BSC_CONF_ISSUER_CERTIFICATE_FILE_3_INSTANCE
#define BSC_CONF_ISSUER_CERTIFICATE_FILE_3_INSTANCE 9
#endif

#ifndef BSC_CONF_HUB_FUNCTION_CONNECTION_STATUS_MAX_NUM
#define BSC_CONF_HUB_FUNCTION_CONNECTION_STATUS_MAX_NUM BSC_CONF_HUB_FUNCTION_CONNECTIONS_NUM
#endif

#ifndef BSC_CONF_NODE_SWITCH_CONNECTION_STATUS_MAX_NUM
#define BSC_CONF_NODE_SWITCH_CONNECTION_STATUS_MAX_NUM BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM
#endif

#ifndef BSC_CONF_FAILED_CONNECTION_STATUS_MAX_NUM
#define BSC_CONF_FAILED_CONNECTION_STATUS_MAX_NUM 8
#endif

#endif
