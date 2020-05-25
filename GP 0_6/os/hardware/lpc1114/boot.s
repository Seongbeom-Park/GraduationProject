	AREA    RESET, DATA, READONLY
	EXPORT  __Vectors

__Vectors
	DCD     0x10001000					; Top of Stack
	DCD     Reset_Handler				; Reset Handler
	DCD     0							; NMI_Handler
	DCD     0							; HardFault_Handler
	DCD     0							; Reserved
	DCD     0							; Reserved
	DCD     0							; Reserved
	DCD     0							; Reserved
	DCD     0							; Reserved
	DCD     0							; Reserved
	DCD     0							; Reserved
	DCD     0							; SVC_Handler
	DCD     0							; Reserved
	DCD     0							; Reserved
	DCD     0							; PendSV_Handler
	DCD     0							; SysTick_Handler

	; External Interrupts
	DCD     0;WAKEUP_IRQHandler			; 16+ 0: Wakeup PIO0.0
	DCD     0;WAKEUP_IRQHandler			; 16+ 1: Wakeup PIO0.1
	DCD     0;WAKEUP_IRQHandler			; 16+ 2: Wakeup PIO0.2
	DCD     0;WAKEUP_IRQHandler			; 16+ 3: Wakeup PIO0.3
	DCD     0;WAKEUP_IRQHandler			; 16+ 4: Wakeup PIO0.4
	DCD     0;WAKEUP_IRQHandler			; 16+ 5: Wakeup PIO0.5
	DCD     0;WAKEUP_IRQHandler			; 16+ 6: Wakeup PIO0.6
	DCD     0;WAKEUP_IRQHandler			; 16+ 7: Wakeup PIO0.7
	DCD     0;WAKEUP_IRQHandler			; 16+ 8: Wakeup PIO0.8
	DCD     0;WAKEUP_IRQHandler			; 16+ 9: Wakeup PIO0.9
	DCD     0;WAKEUP_IRQHandler			; 16+10: Wakeup PIO0.10
	DCD     0;WAKEUP_IRQHandler			; 16+11: Wakeup PIO0.11
	DCD     0;WAKEUP_IRQHandler			; 16+12: Wakeup PIO1.0
	DCD     0;CAN_IRQHandler			; 16+13: CAN
	DCD     0;SSP1_IRQHandler			; 16+14: SSP1
	DCD     0;I2C_IRQHandler			; 16+15: I2C
	DCD     0;TIMER16_0_IRQHandler		; 16+16: 16-bit Counter-Timer 0
	DCD     0;TIMER16_1_IRQHandler		; 16+17: 16-bit Counter-Timer 1
	DCD     0;TIMER32_0_IRQHandler		; 16+18: 32-bit Counter-Timer 0
	DCD     0;TIMER32_1_IRQHandler		; 16+19: 32-bit Counter-Timer 1
	DCD     0;SSP0_IRQHandler			; 16+20: SSP0
	DCD     0;UART_IRQHandler			; 16+21: UART
	DCD     0;USB_IRQHandler			; 16+22: USB IRQ
	DCD     0;USB_FIQHandler			; 16+24: USB FIQ
	DCD     0;ADC_IRQHandler			; 16+24: A/D Converter
	DCD     0;WDT_IRQHandler			; 16+25: Watchdog Timer
	DCD     0;BOD_IRQHandler			; 16+26: Brown Out Detect
	DCD     0;FMC_IRQHandler			; 16+27: IP2111 Flash Memory Controller
	DCD     0;PIOINT3_IRQHandler		; 16+28: PIO INT3
	DCD     0;PIOINT2_IRQHandler		; 16+29: PIO INT2
	DCD     0;PIOINT1_IRQHandler		; 16+30: PIO INT1
	DCD     0;PIOINT0_IRQHandler		; 16+31: PIO INT0

	AREA    |.text|, CODE, READONLY
		
Reset_Handler PROC
	EXPORT	Reset_Handler
	IMPORT	boot
	LDR		R0, =boot
	BLX		R0
	b .
	ENDP
	
	ALIGN
		
func2int PROC
	EXPORT	func2int
	BX		LR
	ENDP
		
	ALIGN
		
execute PROC
	EXPORT	execute
	BX 		R1
	ENDP
		
	ALIGN
		
	END