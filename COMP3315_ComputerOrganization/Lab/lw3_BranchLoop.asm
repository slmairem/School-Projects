.data
	array: .word 1, 2, 3, 4, 5, 6, 7, 8, 9
.text
	main:
	la $t0, array 
	li $t1, 2 # i=2
	li $t2, 9 #element number

	lw $t3, ($t0) #max1=arr[0]
	addi $t0, $t0, 4 
	lw $t4, ($t0) #max2=arr[1]
	
	bge $t4, $t3, no_swap #if $t4>$t3 swap, if not, continue with "no_swap:"
	move $t5, $t3  # temp = max1
	move $t3, $t4  # max1 = max2
	move $t4, $t5  # max2 = temp
	no_swap:
	
	loop:
	addi $t0, $t0, 4
	addi $t1, $t1, 1 #loop counter+1

	bge $t1, $t2, print_result #if $t1>$t2 (i>element number) go to print_result
	
	lw $t5, ($t0) #current element arr[i]
	bge $t5, $t3, check_second_max # if $t5>$t3 (arr[i]>arr[0]) go to check_second_max
	
	move $t4, $t3 #max2=max1
	move $t3, $t5 #max1=arr[i]
	
	b continue_loop
	
	check_second_max:
	bge $t5, $t4, continue_loop #if $t5>$t4 (arr[i]> max2]
	move $t4, $t5 #max2=arr[i]
		
	continue_loop:
	bne $t1,$t2,loop #go to loop if i and element number doesn't equal
	
	print_result:
	li $v0, 1 #printing
	move $a0, $t4 
	syscall
    
	li $v0, 10 #exit program
	syscall
	
#Doesn't work right and I don't know the issue. Hope you give me feedback about the code, thanks.
	
	
