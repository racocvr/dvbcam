#ifndef _CAPMT_H_
#define _CAPMT_H_

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/unistd.h>
#include <arpa/inet.h>
#include <linux/types.h>

typedef enum dmx_ca_type
{
	DMX_CA_BYPASS = 0,
	DMX_CA_DES_ECB,
	DMX_CA_3DES_CBC,
	DMX_CA_3DES_ECB,
	DMX_CA_AES_ECB,
	DMX_CA_AES_CBC,
	DMX_CA_MULTI2,
	DMX_CA_DVB_CSA,
	DMX_CA_AES_CTR,
	DMX_CA_AES_CBC_XOR,
	DMX_CA_AES_CTR_XOR,
} dmx_ca_type_t;

typedef struct ca_config {
	int mode;			// 0: disable, 1: enable.
	int matching_type;	// 0: bank matching, 1: pid matching.
	dmx_ca_type_t ca_type;
	__u16 pid;			// in case of pid matching;
	__u8 keyidx;		// in case of pid matching. (0~31)
	__u8 use_hcas;		// 0: disable, 1: enable.
} ca_config_t;

#define SDP_SET_CA_CTRL         _IOW('o', 102, ca_config_t)		/* set descrambler on/off, ca_type */

#define DVBAPI_FILTER_DATA     0xFFFF0000
#define DVBAPI_CLIENT_INFO     0xFFFF0001
#define DVBAPI_SERVER_INFO     0xFFFF0002
#define DVBAPI_ECM_INFO        0xFFFF0003

#define CAPMT_LIST_MORE            0x00
#define CAPMT_LIST_FIRST           0x01
#define CAPMT_LIST_LAST            0x02
#define CAPMT_LIST_ONLY            0x03
#define CAPMT_LIST_ADD             0x04
#define CAPMT_LIST_UPDATE          0x05

void send_client_info(int socket);
int recv_server_info(int socket);
void send_stop_dmx(int socket, char dmx);
void send_filter_data(int socket, char idx, char flt, unsigned char *data, int len);
void send_pmt(int socket, char lm, unsigned char* buf, int idx);

#endif