.data

.text
.globl main

main:
	addi $v0, $0, 5
	syscall
	
	add $t0,$0,$v0 
	add $t1, $0, -1
	
	xor $t2, $t0, $t1
	addi $t3, $t2, 1
	
	li $v0, 1
	add $a0, $zero, $t3
	syscall