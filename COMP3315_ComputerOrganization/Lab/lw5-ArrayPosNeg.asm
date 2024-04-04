.data	
	arr1:   .word 5, -1, 4, -6, 0, 8, -3, 7
	arr2:   .space 32

.text
.globl main
	main: 
	la $t6, arr1 # $a0 = arr1
	la $t7, arr2 # $a1 = arr2
	li $t2, 8 # $t2 = arr2 size
	li $t3, 0 # i=0	
	
	jal test
	
	loop:
	beq $t3,$t2,exit
	lw $t0, 0($t6) # load curr arr1 element
	jal test # call test
	beqz $v0, negative # test return value is 0, "negative"
	
	add $a0,$0,$t0
	addi $v0,$0,1
	syscall
	
	sw $t0, 0($t7) # store positive element in arr2
	addiu $t7, $t7, 4 # increment index for arr2
	
	negative:
	addiu $t6, $t6, 4 # move next eleemnt in arr1
	addiu $t3, $t3, 1 # i++
	j loop
	
	test:
	lw $t0, 0($t6) #32 bit from memory
	srl $t1, $t0, 31 #shift 31 bits for MSB
	beqz $t1, positive # MSB = 0, int positive, go "positive" label
	li $v0, 0 # negative, return 0
	jr $ra
	
	positive:
	li $v0, 1 # positive, return 1
	jr $ra
	
	exit:
	

	
	