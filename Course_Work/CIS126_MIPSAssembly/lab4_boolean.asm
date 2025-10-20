.data

.text
addi $s0, $zero, 60		
addi $s1, $zero, 50

slt $s6, $s1, $s0
	
beq $s6, $zero, Else
    sub $s3, $s0, $s1
    j Exit
Else: 
    sub $s3, $s1, $s0
Exit:
	
li $v0, 1
add $a0, $zero, $s3
syscall
	
