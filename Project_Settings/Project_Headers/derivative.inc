; Note: This file is recreated by the project wizard whenever the MCU is
;       changed and should not be edited by hand

; include derivative specific macros
            INCLUDE 'MC9S08PT60.inc'


; RAM/ROM definitions


; Watchdog feed macro
feed_watchdog: MACRO
            LDHX #-23038      ;first part of reset sequence (0xA602U)
            STHX WDOG_CNT
            LDHX #-19328      ;second part of reset sequence (0xB480U)
            STHX WDOG_CNT

          ENDM
