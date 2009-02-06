/***************************************************************************
 *            network.h
 *
 *  Fri Sep  1 10:08:50 2006
 *  Copyright  2006  User
 *  Email
 ****************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#ifndef _NETWORK_H
	#define _NETWORK_H

	#include "arp.h"
	#include "ethernet.h"
	#include "ip.h"
	#include "udp.h"

	#define DHCP		0x01
	#define NTP			0x02
	#define IRQMODE     0x04
	#define POLLMODE 	0x00
	
#endif /* _NETWORK_H */
