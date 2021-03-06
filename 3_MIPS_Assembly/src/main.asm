		.text
		j	main			# Jump to main-routine

		.data
str1:		.asciiz "Insert the array size \n"
str2:		.asciiz "Insert the array elements,one per line  \n"
str3:		.asciiz "The sorted array is : \n"
str5:		.asciiz "\n"

		.text
		.globl	main
main: 
		la	$a0, str1		# load text string str1 from RAM into $a0
		li	$v0, 4			# print instruction, 4 is instruction for print string
		syscall				# execute

		li	$v0, 5			# Get the array size(n), 5 is instruction for read int and put it in $v0
		syscall				# print $v0
		
		move	$s2, $v0		# $s2=n, $s2 = length
		sll	$s0, $v0, 2		# $s0=n*4
		sub	$sp, $sp, $s0		# This instruction creates a stack frame large enough to contain the array
						# subtracting by s0 makes space for n (=s2) words
						
		la	$a0, str2		#
		li	$v0, 4			# Print of str2
		syscall				#
            
		move	$s1, $zero		# i=0
for_get:	bge	$s1, $s2, exit_get	# if i>=n go to exit_for_get
		sll	$t0, $s1, 2		# $t0=i*4
		add	$t1, $t0, $sp		# $t1=$sp+i*4
		li	$v0, 5			# Get one element of the array, 5 is instruction for read int
		syscall				# execute
		sw	$v0, 0($t1)		# The element is stored at the address $t1
						
		la	$a0, str5
		li	$v0, 4			# print string
		syscall
		addi	$s1, $s1, 1		# i=i+1
		j	for_get			#jump back to start of for loop
		
exit_get:	move	$a0, $sp		# $a0=base address af the array
		move	$a1, $s2		# $a1=size of the array
		jal	insertSort		# isort(a,n), $a0 and $a1 are input arguments 
						# In this moment the array has been 
						# sorted and is in the stack frame 
		la	$a0, str3		# Print of str3
		li	$v0, 4
		syscall

		move	$s1, $zero		# i=0
for_print:	bge	$s1, $s2, exit_print	# if i>=n go to exit_print
		sll	$t0, $s1, 2		# $t0=i*4
		add	$t1, $sp, $t0		# $t1=address of a[i]
		lw	$a0, 0($t1)		#
		li	$v0, 1			# print of the element a[i]
		syscall				#

		la	$a0, str5
		li	$v0, 4
		syscall
		addi	$s1, $s1, 1		# i=i+1
		j	for_print
exit_print:	add	$sp, $sp, $s0		# elimination of the stack frame 
              
		li	$v0, 10			# EXIT, 10 is unstruction for end of program
	   	syscall				#
	   	

################################################################# end of main
   	   	   	
################################################################# begin code for insertionSort  
		j insertSort
insertSort:	
		
		
		# first, lets save the to be used s registers and the return address to the stack
		addi	$sp, $sp, -20				# make room for 5 registers
		sw	$ra, 16($sp)				
		sw	$s3, 12($sp)
		sw	$s2, 8($sp)
		sw 	$s1, 4($sp)
		sw 	$s0, 0($sp)
		# now we can safely use these registers in this procedure. 
		
		
		move 	$s0, $a0				# save a0 (address of a[]) into s0
		move 	$s1, $a1 				# save a1 (length) into s1
		
		# allocate memory for b on the stack?
		sll	$s2, $a1, 2				# s2 = length * 4
		sub 	$sp, $sp, $s2				# ajust the stack for 'length' number of items
		# sp now holds adress of b[0]? i think so, check this!!!

		
		move	$s3, $zero				# i=0
for_func:	bge	$s3, $s1, exit_func			# branch to exit if i >= length
		
		sll	$t0, $s3, 2				# $t0=i*4
		add	$t4, $t0, $s0				# t4 now holds the address of a[i] 
		
		# prepare for binarySearch procedure call
		move 	$a0, $sp				# set address of b from sp into a0, check this!!!
		move	$a1, $s3				# set i as the second input argument
		lw	$a2, 0($t4)				# load the value of a[i] into a2
		
		# we don't need to save t0 etc before calling binSearch 
		# because we don't use their old values after calling binSearch 
		
		jal 	binSearch				# goto function binSearch
		
		# prepare for insert procedure call
		move	$a3, $v0				# put the return of binSearch as the 3rd input of insert function
			 
		# insert
		jal	insert					# goto function insert 
		
		addi 	$s3, $s3, 1				# i++	
		j	for_func				#back to start of loop

exit_func:	move	$s3, $zero				# i=0
		
		
for_copy:	bge	$s3, $s1, exit_copy			# if i >= length, exit for_copy loop
		sll	$t0, $s3, 2				# $t0=i*4
		add	$t1, $t0, $s0				# t1 now holds the address of a[i]
		add	$t2, $t0, $sp				# t2 now holds the address of b[i]
		
		lw	$t3, 0($t2)				# load the value of b[i] into t3
		sw	$t3, 0($t1)				# save that value from t3 into a[i]
		
		addi 	$s3, $s3, 1				# i++	
		j for_copy					#back to start of loop
		
exit_copy:
		

		#delete [] b 
		add 	$sp, $sp, $s2				# pop b[] off the stack
		
		# finally, before returing to caller, we restore the stack
		lw	$s0, 0($sp)
		lw	$s1, 4($sp)
		lw	$s2, 8($sp)
		lw	$s3, 12($sp)
		lw	$ra, 16($sp)
		addi 	$sp, $sp, 20				# restore stack pointer
		# now we can return to caller
		
		
		jr	$ra					# jump back to calller, uncomment in main
		
################################################################# end code for insertionSort 		


################################################################# begin code for insert procedure
		j 	insert	
insert:		
		
		# first, lets save the to be used s registers and the return address to the stack
		addi	$sp, $sp, -4				# make room for 5 registers
		sw 	$s0, 0($sp)
		# now we can safely use these registers in this procedure.
		
		addi	$s0, $a1, -1				# j = length - 1
for_insert:	blt 	$s0, $a3, exit_insert			# if j<i go to exit
		
		#body of loop
		
		sll 	$t1, $s0, 2				# t1 = j*4
		add 	$t1, $a0, $t1				# t1 = t1 + address of array, t1 has address a[j]
		
		lw 	$t0, 0($t1)				# t4 has value of a[j]
		sw 	$t0, 4($t1)				# store t4 (a[j]) into a[j+1]
						
		#end body of loop
		
		addi	$s0, $s0, -1				# j = j-1
		j	for_insert				#jump back to start of for loop		

exit_insert:	sll 	$t2, $a3, 2				# t2 = i*4
		add 	$t2, $a0, $t2				# t2 = address of a[i]
		sw	$a2, 0($t2)				# a[i] = elem  
		
		# finally, before returing to caller, we restore the stack
		lw	$s0, 0($sp)
		addi 	$sp, $sp, 4				# restore stack pointer
		# now we can return to caller		
								
		jr	$ra					#jump back to calller, uncomment in main
		
################################################################# end code for insert procedure


################################################################# begin code for binarySerach procedure
		j binSearch	
binSearch:	

		# first, lets save the to be used s registers and the return address to the stack
		addi	$sp, $sp, -12				# make room for 5 registers
		sw	$s2, 8($sp)
		sw 	$s1, 4($sp)
		sw 	$s0, 0($sp)
		# now we can safely use these registers in this procedure. 
		
						
		addi	$s0, $zero, -1				# low = -1
		move	$s1, $a1				# high, s1 gets value of a1 (length)
		addi 	$s2, $zero, 0				# initialize int mid
		
loop:		#while loop
		addi	$t0, $s1, -1				# t0 stores high-1
		bge	$s0, $t0, exit				# if s0 (low) is greater equal t0 (high-1), exit
		
		#body of loop
		add	$t1, $s0, $s1				# t1 = low + high
		sra 	$s2, $t1, 1				# mid = divide (low + high) by 2, using bitshift
		
		sll	$t2, $s2, 2				# t2 = mid*4
		add 	$t3, $a0, $t2				# t3 = address of array + mid*4, so a[mid], address.. not value!
		
		lw 	$t4, 0($t3)				# load the value of a[mid] into t4
		blt 	$t4, $a2, else				# if t4 (a[mid]) < a2 (elem), goto else 
		move	$s1, $s2				#  s1 (high) gets value of s2 (mid)
		j 	loop					# back to while loop
		
	else:	move 	$s0, $s2				# s0 (low) gets the value of s2 (mid)
		j 	loop					# jump back to loop
		#end body of loop
		
		
exit:		#exit of while loop
		move	$v0, $s1				#return high
		
		# finally, before returing to caller, we restore the stack
		lw	$s0, 0($sp)
		lw	$s1, 4($sp)
		lw	$s2, 8($sp)
		addi 	$sp, $sp, 12				# restore stack pointer
		# now we can return to caller
		
		jr	$ra					#jump back to calller, uncomment in main
		
################################################################# end code for binarySerach procedure
