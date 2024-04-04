# 1) $s1 -> g, $s2 -> h, $s3 -> A array's starting point
#     g = h + A[8]
	lw $t0, 32($s3) # t0=A[8] 8x4 = 32
	add $t1, $t0, $s2 # g = h + A[8]

# 2) $s2 -> h, $s3 -> A's base
#    A[12] = h + A[8]
	lw $t0, 32($s3) 
	add $t0, $t0, $s2 # $t0 = A[8] + h
	sw $t0, 48($s3) # A[12] = A[8] + h
			# "store word" // sw $s1, 20($s2) -> $s1=memory($s2+20)

	sll $s1, $s1, 10 # $s1=$s2<<10
			 # shift left logical
			 # srr "shift right logical"
	and $s1, $s2, $s3 # $s1 = $s2 & $s3
	andi $s1, $s2, 10 # $s1 = $s2 & 10
	or $s1, $s2, $s2 # $s1 = $s2 | $s3
	nor $s1, $s2, $s3 # $s1 = -($s2 | $s3)
			  # not
	
	beq $s1, $s2, L # if ( $s1 == $s2 go L )
			# branch on equal
	bne $s1, $s2, L #if ( $s1 /= $s2 go L )
			# branch on NO equal
			
# 3) Loops 
# $s3 -> i, $s5 -> k, $s6 -> save[i]
# while (save[i] == k)
#	i+=i	
	Loop: sll $t1, $s3, 2 # $t1=i*4 -- sll multiplies by 2, so 4 bits/next value in array
	      add $t1, $t1, $s6 # $t1=save[i] adress
	      lw $t0, 0($t1) # $t0 = save[i], load save[i]
	      bne $t0, $s5, exit # save[i] /= k, go exit 
	      addi $s3,$s3,1 #i=i+1
	      j loop
	      exit:
	  
# Looking for index variable less then 0   
	slt $t0, $s3, $s4 # if($s3<$s4) $t0=1 else $t0=0
			  # set on less than (signed)
			  # sltu (unsigned), also checks if $s3 negative as well as if $s3 < $s4
	slti $t0, $s2, 10 # $t0 = 1 if $s2 < 10
	
# registers
	$a0-$a3 -> for pass parameters
	$v0-$v1 -> return values
	$ra -> return to the point of origin 
		# (return adress)
	
	jal proceduresofaddress # jal jumps to an address and saves the adress of the following instruction in reg $ra
	jr $ra # go to $ra
	
# 4) Stacks
	$sp -> stack pointer
	#pushing
	addi $sp, $sp, -12 # stack has room for 3 items (4*3=12)
	sw $t1, 8($sp) #save $t1
	sw $t0, 4($sp) #save $t0
	sw $s0, 0($sp) #save $s0
	
	#return to return valur, copy it into a return register
	add $v0, $s0, $zero
	
	#popping
	lw $s0, 0($sp) #restore $s0
	lw $t0, 4($sp) #restore $t0
	lw $t1, 8($sp) #restore $t1
	addi $sp, $sp, 12 # stack delete 3 items
	
# 5) Recursive
# int fact (int n){ 
#	if (n<1) return 1;
#	else return (n*fac(n-1));
# $a0 -> n

	addi $sp, $sp, 8
	sw $ra, 4($sp) #save the return address
	sw $a0, 0($sp) #save n
	
	slti $t0, $a0, 1 #test for n<1
	beq $t0, $zero, L1 #if n>=1, go to L
		#if n is less than 1, fact returns 1
	
	addi $v0, $zero, 1 #return 1
	$addi $sp, $sp, 8 #pop 2 items
	jr $ra #return caller
	
	L1: addi $a0, $a0, -1 # n>=1, argument gets n-1
	jal fact #call fact with n-1
	
	lw $a0, 0($sp) # return from jal: restore argument n
	lw $ra, 4($sp) # restore the return address
	addi $sp, $sp, 8 # adjust stack pointer to pop 2 items	
	
	mul $v0,$a0,$v0 # return n * fact (n – 1)
	jr $ra # return to the caller
	
# 6) Swap
# temp = v[k]
# v[k] = v[k+1]
# v[k+1] = temp

	sll $t1, $a1,2 # reg $t1 = k * 4
	add $t1, $a0,$t1 # reg $t1 = v + (k * 4)
	# reg $t1 has the address of v[k]
	
	lw $t0, 0($t1) # reg $t0 (temp) = v[k]
	lw $t2, 4($t1) # reg $t2 = v[k + 1]
	# refers to next element of v
	
	sw $t2, 0($t1) # v[k] = reg $t2
	sw $t0, 4($t1) # v[k+1] = reg $t0 (temp)
	
	
# 7) strcmp
	lb $t0,0($sp) # Read byte from source
	sb $t0,0($gp) # Write byte to destination
	
# void strcpy (char x[], char y[]){
# int i=0;
# while ((x[i] = y[i]) != ‘\0’) /* copy & test byte */
# i += 1; }
# $a0 -> x, $a1 -> y, $s0 -> i, strcmp adjust the stack pointer and saves the register $s0 on stack

	strcpy:
	addi $sp,$sp,–4 # adjust stack for 1 more item
	sw $s0, 0($sp) # save $s0

	add $s0,$zero,$zero # i = 0 + 0

	L1: add $t1,$s0,$a1 # address of y[i] in $t1
	lbu $t2, 0($t1) # $t2 = y[i]

	add $t3,$s0,$a0 # address of x[i] in $t3
	sb $t2, 0($t3) # x[i] = y[i]

	beq $t2,$zero,L2 # if y[i] == 0, go to L2

	addi $s0, $s0,1 # i = i + 1
	j L1 

	L2: lw $s0, 0($sp) # y[i] == 0: end of string.
	addi $sp,$sp,4 # pop 1 word off stack
	jr $ra # return
	
# exit
	exit:
	add $a0, $0, $v0
	addi $v0, $0, 1           
	syscall
    
	addi $v0, $0, 10 #exit program
	syscall

# li == addi
	addi $t0, $0, 4 # $t0 => n=4
	addi $t1, $0, 1 # $t1 => temp=1
	addi $t2, $0, 4 # $t3 => i=n

# example 1
# int a[10] = {0};
# main(){ int k=0;
# int i, num;
# for (i=0; i<10;i++)
# { scanf("%d", &num); // get input
# if (num > 0) // if +ve store in a
# { a[k] = num;
# k = k + 1; }} } } // if, for, main closing
# 3, -1, 4, -6, 8, 2, -5, -2, 9, -7 (input)
# arr: .word 3, 4, 8, 2, 9 (output)

.text
	addi $t0, $0, 1 # i
	addi $t1,$0, 11 # upper limit
	la $s0, arr # array address
	loop: beq $t0, $t1, end # loop
	addi $v0, $0, 5 # get input
	syscall
	slt $t2, $0, $v0 # skip if -ve
	beq $t2, $0, skip
	sw $v0, 0($s0) # store input at array
	addi $s0,$s0,4 # increment pointer
	skip: addi $t0, $t0,1 # increment counter
	j loop
	end: li $v0, 10 # terminate program
	syscall
