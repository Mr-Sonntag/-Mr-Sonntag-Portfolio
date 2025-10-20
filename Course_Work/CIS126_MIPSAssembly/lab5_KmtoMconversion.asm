.data
	
	messageConversion: .asciiz " KM are equal to "
	messageMiles: .asciiz " M\n"
	
	zeroDouble: .double 0.0
	conversion: .double 1.609344
	increment: .double 1.0
.text
	addi $s1, $zero, 21
	
	ldc1 $f6, conversion
	ldc1 $f0, zeroDouble
	ldc1 $f8, increment
	
LOOP:	slt $s3, $s0, $s1
	beq $s3, $zero, DONE
	
	li $v0, 1
	add $a0, $zero, $s0
	syscall
	
	li $v0, 4
	la $a0, messageConversion
	syscall
	
	div.d $f2, $f4, $f6
	
	li $v0, 3
	add.d $f12, $f0, $f2
	syscall
	
	li $v0, 4
	la, $a0, messageMiles
	syscall
	
	add.d $f4, $f4, $f8
	addi $s0, $s0, 1
	j LOOP
DONE: