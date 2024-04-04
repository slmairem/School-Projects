.data 
	array: .word 8,1,4,5,6,3,2,9,7,0
.text
	main:
	la $t0, array 
	addi $t1, $0, 0 # i=0
	addi $t2, $0, 1 # j=i+1 (1)
	addi $t3, $0, 10 # $t3=10
	addi $t4, $0, 9 # $t4=9
	addi $t8, $0, 10
	
	lw $t5, ($t0) # $t5=arr[i]
	addi $t0, $t0, 4 
	lw $t6, ($t0) # $t6=arr[j]
	
	loopi:
	addi $t1, $t1,1 # i = i+1
	
	loopj:
	slt $t7, $t5, $t6 # $t7=0 if a[i]<a[j], else $t7=1
	beq $t7, $0, no_swap # if a[i]=a[j] no swap
	sw $t5, 0($t0)  # store arr[j] in arr[i]
	sw $t6, 4($t0) # store arr[i] in arr[j]
	
	no_swap:
	addi $t2,$t2,1 # j=j+1
	beq $t2, $t3, loopiend # if j=10 loopiend 
	j loopj # continue loopj
	
	loopiend:
	beq $t1, $t4, doneloop # if i=9 doneloop
	j loopi # continue loopj
	
	doneloop:
	bge $t8, 10, exit
	
	addi $v0, $0, 1
	#move    $a0, $t2 -> how should I write it??
	syscall
	
	addi $8,$8, 1
	j doneloop
	
	exit:
	addi $v0, $0, 1
	syscall
	
	
#Selma Irem Ozdemir 21070001028
	
	
	

	