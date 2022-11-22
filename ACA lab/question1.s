		
		AREA mycode, CODE, READONLY
		ENTRY

Main
		LDR		R0, =0x40000000			;Loading the address of the number
		LDR		R1, [R0]				;R1 = number (dereferencing the address)
		LDR 	R2, =0x40000004			;Loading the address of the result
		MOV		R3, #4					;Counter
		MOV		R4, R1					;Copying R1 into R4
		
UP		AND		R5, R1, #0x0F			;Storing the last digit (LS half-byte) in R5
		AND		R6, R4, #0xF0000000		;Storing the first digit (MS half-byte) in R6
		LSR		R6, R6, #28
		CMP		R6, R5	
		BNE		NOT_PALINDROME			;If not equal, number is not a palindrome
		CMP		R3, #0					;If equal, the number is checked and it is a palindrome
		BEQ		PALINDROME
		SUB		R3, R3, #1				;Decrement counter, if equal
		LSR		R1, R1, #4				;Rotate number right by 1 digit
		LSL		R4, R4, #4				;Rotate number left by 1 digit
		B		UP
		
NOT_PALINDROME	
		MOV 	R7, #1					;R7=1 indicates the number is not a palindrome
		STR		R7,[R2]					;Storing in the memory address
		B		STOP
		
PALINDROME
		MOV		R7, #0					;R7=0 indicates the number is a palindrome
		STR		R7, [R2]				;Storing in the memory address
STOP	B		STOP
		END