.data 

.text
.globl main
	main:
	li $s0, 0 # $s0 = sum = 0
	li $s1, 7 # $s1 = a = 7
	li $s2, 15 # $s2 = b = 15
	
	addfunc_loop:
	bgt $s1, $s2, addfunc_exit # a>b, exit
	add $s0, $s0, $s1 #  sum+=a
	addi $s1, $s1, 1 # a++
	j addfunc_loop
	
	addfunc_exit:
	move $a0, $s0 #printing
	li $v0, 1             
	syscall
    
	li $v0, 10 #exit program
	syscall
	

