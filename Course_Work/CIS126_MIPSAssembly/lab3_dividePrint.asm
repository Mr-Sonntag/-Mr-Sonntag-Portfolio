.data
	theQuotient: .asciiz "The Quotient is: "		#Text for the quotient stored
	theRemainder: .asciiz " and the Remainder is: "		#Text for the remainder stored
.text
	addi $t0, $zero, 716					#Moves the value 716 into register $t0
	addi $t1, $zero, 19					#Moves the value 19 into register $t1
	
	div  $t0, $t1						#Divides the value in $t1 from $t0 and stores quotient in the LO register and the remainder in the HI register
	
	mflo $s0						#The Quotient moved from the LO register into register $s0
	mfhi $s1						#The Remainder moved from the HI register into register $s1
	
	li $v0, 4						#Loads the 'Print String' command into $v0
	la $a0, theQuotient					#Loads the theQuotient string into $a0 to prepare to print
	syscall							#Executes command
	
	li $v0, 1						#Loads the 'Print integer' command into $v0
	add $a0, $zero, $s0					#Loads the value from $s0 into $a0 to prepare to print
	syscall							#Executes command
	
	li $v0, 4						#Loads the 'Print String' command into $v0
	la $a0, theRemainder					#Loads the theRemainder string into $a0 to prepare to print
	syscall							#Executes command
	
	li $v0, 1						#Loads the 'Print integer' command into $v0
	add $a0, $zero, $s1					#Loads the value from $s1 into $a0 to prepare to print
	syscall							#Executes command
	
								#Complete