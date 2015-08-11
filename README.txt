AVR-Etherboot for Arduino Mega 2560.

This is a bootloader source code. When uploaded to your Mega, it will be able to flash the chip over Ethernet. On every boot it downloads the hex-file and writes it.

How to use:

Do parts 1-7 once for every Arduino Mega
Do parts 8 once.
Do part 9 every time you need to re-load your firmware

1. Choose last byte of mac address and last byte for IP-address for your target device. First bytes are
AA:00:00:00:01 (see device_001/config.h)
192.168.100 (see device_001/eemem.c)
(hardcoded)

2. Choose filename which target device will ask server for. "d01" for example.

3. Run

make -C device_001 MAC_BYTE_6=0x01 IP_ADDRESS_4=31 REQ_FILENAME_3SYM=d01 all

with desired parameters (0x01, 31, d01 for example)

This command will build your bootloader

4. Run
make -C device_001 fuse

This command will set MC's fuses (note: usbasp programmer hardcoded. See device_001/makefile)

5. Run
make -C device_001 program

This command will flash the bootloader (note: usbasp programmer hardcoded)

6. Connect ENC28J60 to your Mega. Use pins 50, 51, 52, 53

7. Connect ENC28J60 to your network. Network should be 192.168.100.0/24

8. Set up a TFTP server on 192.168.100.1. Place your app's hex file to /var/tftp/d01.hex.

9. Reboot your arduino (reset button). Firmware should load.

Troublesooting
1. See TFTP server logs
2. Check out dumps with Wireshark
3. Check out your enc28j60-mega connection again
