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

// THIS should not be changed, most of BACNet/SC devices must have
// hub connector, it uses 2 connections
#ifndef BSC_CONF_HUB_CONNECTOR_CONNECTIONS_NUM
#define BSC_CONF_HUB_CONNECTOR_CONNECTIONS_NUM (BSC_CONF_HUB_CONNECTORS_NUM*2)
#endif

#ifndef BSC_CONF_HUB_FUNCTION_CONNECTIONS_NUM
#define BSC_CONF_HUB_FUNCTION_CONNECTIONS_NUM (BSC_CONF_HUB_FUNCTIONS_NUM*10)
#endif

#ifndef BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM
#define BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM (BSC_CONF_NODE_SWITCHES_NUM*10)
#endif

// Total amount of client(initiator) webosocket connections
#define BSC_CONF_CLIENT_CONNECTIONS_NUM (BSC_CONF_HUB_CONNECTOR_CONNECTIONS_NUM + BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM)
#define BSC_CONF_SERVER_HUB_CONNECTIONS_MAX_NUM (BSC_CONF_HUB_FUNCTION_CONNECTIONS_NUM)
#define BSC_CONF_SERVER_DIRECT_CONNECTIONS_MAX_NUM  (BSC_CONF_NODE_SWITCH_CONNECTIONS_NUM)
#define BSC_CONF_RX_BUFFER_SIZE 4096
#define BSC_CONF_TX_BUFFER_SIZE 4096

#ifndef BSC_CONF_WSURL_MAX_LEN
#define BSC_CONF_WSURL_MAX_LEN 127
#endif

#ifndef BSC_CONF_NODE_MAX_URI_SIZE_IN_ADDRESS_RESOLUTION_ACK
#define BSC_CONF_NODE_MAX_URI_SIZE_IN_ADDRESS_RESOLUTION_ACK BSC_CONF_WSURL_MAX_LEN
#endif

#ifndef BSC_CONF_NODE_MAX_URIS_NUM_IN_ADDRESS_RESOLUTION_ACK 
#define BSC_CONF_NODE_MAX_URIS_NUM_IN_ADDRESS_RESOLUTION_ACK \
        (BSC_CONF_RX_BUFFER_SIZE/BSC_CONF_NODE_MAX_URI_SIZE_IN_ADDRESS_RESOLUTION_ACK - 1)

#endif

#endif