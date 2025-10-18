.data
	float1: .float 14.69 
	float2: .float 16.48 
	
	float3: .float 19.23 
	float4: .float 11.95
	
	zeroFloat: .float 0.00
	newLine: .asciiz "\n"
.text

main:
	lwc1 $f0, zeroFloat
	lwc1 $f2, float1
	lwc1 $f4, float2
	
	add.s $f8, $f4, $f2
	
	lwc1 $f6, float3
	lwc1 $f10, float4
	
	add.s $f24, $f10, $f6
	
	c.le.s $f8, $f24
	
	bc1t less
	
	add.s $f12, $f24, $f0
	li $v0, 2
	syscall
	
	lwc1 $f12, zeroFloat
	
	li $v0,4
	la $a0, newLine
	syscall
	
	add.s $f12, $f8, $f0
	li $v0, 2
	syscall
	
li $v0, 10
syscall

	less:
		add.s $f12, $f8, $f0
		li $v0, 2
		syscall
	
		lwc1 $f12, zeroFloat
		
		li $v0,4
		la $a0, newLine
		syscall
	
		add.s $f12, $f24, $f0
		li $v0, 2
		syscall