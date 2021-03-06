/*
 * fdshare.h
 *
 * Copyright (c) 2015-2016, NVIDIA CORPORATION. All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */

#ifndef __FD_SHARE_H__
#define __FD_SHARE_H__

int send_fd(const char *socket_name, int fd_to_send);
int receive_fd(const char *socket_name);

#endif
