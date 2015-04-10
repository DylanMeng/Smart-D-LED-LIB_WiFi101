/**
 *
 * \file
 *
 * \brief BSD compatible socket interface.
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef __SOCKET_BUFFER_H__
#define __SOCKET_BUFFER_H__

#include "socket/include/socket.h"

#ifdef  __cplusplus
extern "C" {
#endif

#define SOCKET_BUFFER_TCP_SIZE				(SOCKET_BUFFER_MTU * 3)
#define SOCKET_BUFFER_UDP_SIZE				((SOCKET_BUFFER_MTU + SOCKET_BUFFER_UDP_HEADER_SIZE) * 3)
#define SOCKET_BUFFER_UDP_HEADER_SIZE		8
#define SOCKET_BUFFER_MTU					1400

#define SOCKET_BUFFER_FLAG_CONNECTED		1
#define SOCKET_BUFFER_FLAG_FULL				2
#define SOCKET_BUFFER_FLAG_BIND				256
#define SOCKET_BUFFER_FLAG_SPAWN			512
#define SOCKET_BUFFER_SERVER_SOCKET_MSK		0xFF

typedef struct{
	uint8		*buffer;
	uint32		*flag;
	uint32		*head;
	uint32		*tail;
}tstrSocketBuffer;

void socketBufferInit(void);
void socketBufferRegister(SOCKET socket, uint32 *flag, uint32 *head, uint32 *tail, uint8 *buffer);
void socketBufferUnregister(SOCKET socket);
void socketBufferCb(SOCKET sock, uint8 u8Msg, void *pvMsg);

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __SOCKET_BUFFER_H__ */