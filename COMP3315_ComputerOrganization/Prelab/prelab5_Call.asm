.data	
	arr1:   .word 5, -1, 4, -3
	arr2:   .space 16  # 4*4 = 16 space for integers
	space: .asciiz " "

.text
.globl main
	main:
	li $t0, 0 #loop counter
	la $t1, arr1 #load arr1 
	la $t2, arr2 #load arr2
	li $t5, 4 # max value	
	
	negate_loop:
	lw $t3, 0($t1) # $t3 = arr1 current element
	li $t4, -1 # $t4 = -1
	mul $t3, $t3, $t4 # arr1[i] * -1
	sw $t3, 0($t2) # arr2[i] = arr1[i]
	
	addi $t0, $t0, 1 # i = i+1
	addi $t1, $t1, 4 # $t1 = arr1[i+1]
	addi $t2, $t2, 4 # $t2= arr2[i+1]
	
	bne $t0, $t5, negate_loop # i /= 4 loop 
	
	li $t0, 0 # i=0
	la $t2, arr2 #load arr2
	
	print_loop:
	lw $a0, 0($t2) # arr2 curr element
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	addi $t0, $t0, 1 # i = i+1
	addi $t2, $t2, 4 # arr2[i+1]
	
	bne $t0, $t5, print_loop
	 
	li $v0, 10
	syscall
