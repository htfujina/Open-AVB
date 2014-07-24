/******************************************************************************

  Copyright (c) 2009-2012, Intel Corporation 
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:
  
   1. Redistributions of source code must retain the above copyright notice, 
      this list of conditions and the following disclaimer.
  
   2. Redistributions in binary form must reproduce the above copyright 
      notice, this list of conditions and the following disclaimer in the 
      documentation and/or other materials provided with the distribution.
  
   3. Neither the name of the Intel Corporation nor the names of its 
      contributors may be used to endorse or promote products derived from 
      this software without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#ifndef DEBUGOUT_HPP
#define DEBUGOUT_HPP

#include <stdio.h>

#define BMCA_DEBUG 0x1
#define MESSAGE_DUMP 0x2
#define ANNOUNCE_DEBUG 0x4
#define OSNET_DEBUG 0x8
#define PDELAY_DEBUG 0x10
#define SYNC_DEBUG 0x20
#define TIMESTAMP_DEBUG 0x30

#define XPTPD_ERROR(fmt,...) fprintf( stderr, "ERROR at %u in %s: " fmt "\n", __LINE__, __FILE__ ,## __VA_ARGS__)
#ifdef PTP_DEBUG
#define XPTPD_INFO(fmt,...) XPTPD_INFOL(0,fmt,## __VA_ARGS__)
#define XPTPD_INFOL(level,fmt,...)										\
	if( level & PTP_DEBUG )												\
		fprintf( stderr, "DEBUG at %u in %s: " fmt "\n", __LINE__, __FILE__ ,## __VA_ARGS__)
#else
#define XPTPD_INFO(fmt,...)
#define XPTPD_INFOL(level,fmt,...)
#endif

#endif/*DEBUGOUT_HPP*/
