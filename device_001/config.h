#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdio.h>
#include <avr/eeprom.h>
#include <avr/boot.h>

#ifndef MAC_LAST_BYTE
    #error Please set -DMAC_LAST_BYTE=0x__
#endif

#define	MYMAC1 0xAA
#define	MYMAC2 0x00
#define	MYMAC3 0x00
#define	MYMAC4 0x00
#define	MYMAC5 0x01
#define	MYMAC6 MAC_LAST_BYTE
	

// BOOTLOADER_FLAVOR selects the version to build (see docs)
// allowed values are:  SMALL, MEDIUM, LARGE

#define BL_VERSION_SMALL  1
#define BL_VERSION_MEDIUM 2
#define BL_VERSION_LARGE  3

// makefile will pass the definition thru the compiler
// #define BOOTLOADER_FLAVOR BL_VERSION_SMALL

#if BOOTLOADER_FLAVOR >= BL_VERSION_MEDIUM
  #define USE_DHCP
  #define DHCP_PARSE_TFTP_PARAMS
#else
  #define FIXED_TFTP_SRV
#endif


#define DEBUG_AV				0
#define DEBUG_ENC_BUFFER_DATA	0
#define DEBUG_FLASH_PROG		0
#define DEBUG_TFTP				0
#define DEBUG_ARP				0


//-> enc28j60
#define USE_ENC28J60	1

// set these so that it reflects your hardware
// Net-IO board from Pollin
#define ENC28J60_CONTROL_DDR	DDRB
#define ENC28J60_CONTROL_PORT	PORTB
// other boards are wired this way
//#define ENC28J60_CONTROL_DDR	DDRD
//#define ENC28J60_CONTROL_PORT	PORTD

#define ENC28J60_PIN_SCK	1
#define ENC28J60_PIN_MISO   3
#define ENC28J60_PIN_MOSI	2

// Net-IO board from Pollin
#define ENC28J60_PIN_SS		0
#define ENC28J60_PIN_CS		0
// other boards are wired this way
//#define ENC28J60_PIN_SS		4
//#define ENC28J60_PIN_CS		3


// -> SPI
#define SPI_PORT	ENC28J60_CONTROL_PORT
#define SPI_DDR		ENC28J60_CONTROL_DDR
#define SS			ENC28J60_PIN_SS
#define MISO		ENC28J60_PIN_MISO
#define MOSI		ENC28J60_PIN_MOSI
#define SCK			ENC28J60_PIN_SCK


#if defined (__AVR_ATmega64__) || defined (__AVR_ATmega644__) || defined (__AVR_ATmega644P__) || defined (__AVR_ATmega128__)
	#define MTU_SIZE 1200
#else
	#define MTU_SIZE 600
#endif



/////////////////////////////// HELPERS ////////////////////////////////////////////
//DO NOT CHANGE ANYTHING BELOW!

//convert config ip to long:
#define IP(a0,a1,a2,a3) ((((unsigned long)(a3))<<24)|(((unsigned long)(a2))<<16)|(((unsigned long)(a1))<<8)|(unsigned long)(a0))

/*#define NIC_IP_ADDRESS \
				(((uint32_t)NIC_IP_ADDRESS_0)<<24 | \
				((uint32_t)NIC_IP_ADDRESS_1)<<16 | \
				((uint32_t)NIC_IP_ADDRESS_2)<< 8 | \
				((uint32_t)NIC_IP_ADDRESS_3))

#define NIC_IP_NETMASK \
				(((uint32_t)NIC_IP_NETMASK_0)<<24 | \
				((uint32_t)NIC_IP_NETMASK_1)<<16 | \
				((uint32_t)NIC_IP_NETMASK_2)<< 8 | \
				((uint32_t)NIC_IP_NETMASK_3))


#define NIC_GATEWAY_IP_ADDRESS \
				(((uint32_t)NIC_GATEWAY_IP_ADDRESS_0)<<24 | \
				((uint32_t)NIC_GATEWAY_IP_ADDRESS_1)<<16 | \
				((uint32_t)NIC_GATEWAY_IP_ADDRESS_2)<< 8 | \
				((uint32_t)NIC_GATEWAY_IP_ADDRESS_3))

#define NTP_SERVER_IP_ADDRESS \
				(((uint32_t)NTP_SERVER_IP_ADDRESS_0)<<24 | \
				((uint32_t)NTP_SERVER_IP_ADDRESS_1)<<16 | \
				((uint32_t)NTP_SERVER_IP_ADDRESS_2)<< 8 | \
				((uint32_t)NTP_SERVER_IP_ADDRESS_3))
*/


#define lo8(x) ((x   )&0xFF)
#define hi8(x) (((x)>>8)&0xFF)


// Debugging
#if DEBUG_AV

	#include <avr/pgmspace.h>

	void sendchar (unsigned char Zeichen) BOOTLOADER_SECTION;
	void puthexbyte(uint8_t bt) BOOTLOADER_SECTION;
	void putstring (unsigned char *string) BOOTLOADER_SECTION;
	void putPGMstring(const char *progmem_s) BOOTLOADER_SECTION;
	#define putpgmstring(__s) putPGMstring(PSTR(__s))

#endif

#endif


