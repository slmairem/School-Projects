.data
	array:   .word 7, -4, 5, -5, 8, -2, 1, -3 

.text
	main:
	la $t0, array # $t0 = array
	li $t1, 0 # $t1 = (i)
	li $t2, 8 # $t2 = element number
	li $t3, 0 # $t3=sum
	
	loop:
	lw $t4, 0($t0) # $t4 = current array element
	bge $t4, 0, greater #if $t4 >= 0 go greater
	addi $t0, $t0, 4 #next element in array
	addi $t1, $t1, 1 # i+1
	bne $t1, $t2, loop
	j done

	greater:
	add $t3, $t3, $t4 # $t3 = sum+=array[i] 
	addi $t0, $t0, 4 #next element in array
	addi $t1, $t1, 1 # i+1
	bne $t1, $t2, loop # $t1 /= $t2 continue the loop
	
	done:
	move $a0, $t3 #printing
	li $v0, 1             
	syscall
    
	li $v0, 10 #exit program
	syscall
	
#Selma Irem Ozdemir 21070001028
	
	