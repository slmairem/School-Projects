.data
	array: .word 3, 7, 4, 5, 6, 8, 2, 9, 1

.text
	main:
	la $t0, array #load the address of array in $t0
	li $t1, 0 #loop counter in $t1 (i)
	li $t2, 9 #element number of array in $t2
	li $t3, 1 #result=1 in $t3

	loop:
	lw $t4, ($t0) #store current array element in $t4
	mul $t3, $t3, $t4 #result*=array[i] in $t3
	addi $t0, $t0, 4 #address+4byte, next element in array
	addi $t1, $t1, 1 #loop counter+1
	bne $t1, $t2, loop #check condition, if $t1 /= $t2, continue loop

	move $a0, $t3 #printing
	li $v0, 1             
	syscall
    
	li $v0, 10 #exit program
	syscall
	
#Selma Irem Ozdemir 21070001028