;****************************************************************************
;****************************************************************************
;*********                                                          *********
;*********               Hardware related equates                   *********
;*********         ( for emulator / real-word circuit )             *********
;*********                                                          *********
;****************************************************************************
;****************************************************************************


;***************************************
;********* data section absolute address
;***************************************
.ifc df EMU
DATA            = 200h
.endc
.ifc ndf EMU
DATA            = 0
.endc

;***************************************
;********************* STACK Declaration
;***************************************
.ifc df EMU
SSTACK      := (13 * 16)               ; System stack address group C-D
USTACK      := (11 * 16)               ; User stack address group B
.endc
.ifc ndf EMU
SSTACK      := (13 * 16)               ; System stack address group C-D
USTACK      := (11 * 16)               ; User stack address group B-A
.endc


;***************************************
;********************* I/O ports equates
;***************************************
;** P0X EQUATES ( P4X EMULATED )
RWN             = 00010000b
RS0             = 00100000b
CSN             = 01000000b
O2              = 10000000b

;** P1X EQUATES ( P7X EMULATED / SHIFTED LEFT 2 )
.ifc df EMU
ENABLE          = 00000100b 
PLAYLN          = 00001000b 
RECN            = 00010000b 
RECLEDN         = 00100000b 
PD118           = 01000000b 
PD119           = 10000000b 
.endc
.ifc ndf EMU
ENABLE          = 00000001b
PLAYLN          = 00000010b
RECN            = 00000100b
RECLEDN         = 00001000b
PD118           = 00010000b
PD119           = 00100000b
.endc

;** P2X EQUATES ( P2X EMULATED )
.ifc df EMU
BACKLIGHT       = 00000001b
SDI             = 00000010b
SCK             = 00000100b
SDO             = 00001000b
DTMFCP          = 00010000b
LED1            = 00100000b
LED2            = 01000000b
REMOTE          = 10000000b
.endc
.ifc ndf EMU
BACKLIGHT       = 00000001b
SDO             = 00000010b
SCK             = 00000100b
SDI             = 00001000b
DTMFCP          = 00010000b
LED1            = 00100000b
LED2            = 01000000b
REMOTE          = 10000000b
.endc

;** P3X EQUATES ( P3X EMULATED )
HOOK            = 00000001b
ALARM1          = 00000010b
ALARM2          = 00000100b
ALARM3          = 00001000b
PROG            = 00010000b
RESET           = 00100000b

;** P5X EQUATES ( P5X EMULATED )
MUTE            = 00000001b
REL1            = 00000010b
REL2            = 00000100b
RING            = 00001000b
CUE             = 00010000b
CONT            = 00100000b


;***************************************
;*********** External interrupts equates
;***************************************

.ifc df EMU
ipwd    = ipa0m
iwd     = ia0m
.endc
.ifc ndf EMU
ipwd    = ipa0m
iwd     = ia0m
.endc

.ifc df EMU
iprem   = ipd1m
irem    = id1m
.endc
.ifc ndf EMU
iprem   = ipb1m
irem    = ib1m
.endc

.ifc df EMU
ip8880  = ipa1m
i8880   = ia1m
.endc
.ifc ndf EMU
ip8880  = ipa1m
i8880   = ia1m
.endc

.ifc df EMU
ipspi   = ipb0m
ispi    = ib0m
.endc
.ifc ndf EMU
ipspi   = ipb0m
ispi    = ib0m
.endc


;***************************************
;**************** Emulator needed macros
;***************************************
.macro P1_PAGE
   .ifc df EMU
   spp      #P7D_PG
   .endc
.endm
