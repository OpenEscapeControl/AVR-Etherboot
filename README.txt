�ber die Device_nnn-Unterordner kann man verschiedene Bootloader Versionen kompilieren.
Die Unterordner enthalten die Einstellungen wie IP, MAC und Dateiname f�r den TFTP Transfer:
-In den Makefiles muss Prozessor und Bootloaderadresse angepasst werden.
-In den Config.h Dateien m�ssen die Portpins angepasst werden.
-In den eemem.c Dateien m�ssen die Programmparameter angepasst werden.

Das compile.bat im Hauptordner ruft make in den Ger�teordnern auf.
