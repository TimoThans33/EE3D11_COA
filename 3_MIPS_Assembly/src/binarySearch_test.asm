		.data
		testArray: .word 1,3,4,2,5	#define an array, only for testing purposes
		.text
		
		j binSearch
		
	
binSearch:	#begin code only used for testing
		la 	$a0, testArray 			# $t3 has the address of testArray
		addi 	$a1, $zero, 5			# let's say for now that length = 5
		addi 	$a2, $zero, 5			# elem, value of a[i] from the main
		#end code only used for testing
		
		addi	$s0, $zero, -1			# low = -1
		move	$s1, $a1			# high, s1 gets value of a1 (length)
		addi 	$s2, $zero, 0			# initialize int mid
		
loop:		#while loop
		addi	$t0, $s1, -1			# t0 stores high-1
		bge	$s0, $t0, exit			# if s0 (low) is greater equal t0 (high-1), exit
		
		#body of loop
		add	$t1, $s0, $s1			# t1 = low + high
		sra 	$s2, $t1, 1			# mid = divide (low + high) by 2, using bitshift
		
		sll	$t2, $s2, 2			# t2 = mid*4
		add 	$t3, $a0, $t2			# t3 = address of array + mid*4, so a[mid], address.. not value!
		
		lw 	$t4, 0($t3)			# load the value of a[mid] into t4
		blt 	$t4, $a2, else			# if t4 (a[mid]) < a2 (elem), goto else 
		move	$s1, $s2			#  s1 (high) gets value of s2 (mid)
		j 	loop				# back to while loop
		
	else:	move 	$s0, $s2			# s0 (low) gets the value of s2 (mid)
		j 	loop				# jump back to loop
		#end body of loop
		
		
exit:		#exit of while loop
		move	$v0, $s1			#return high
		#jr	$ra				#jump back to calller, uncomment in main
		
		#begin code only used for testing
		#move	$a0, $s1 			# move to a0 to be printed
		#li	$v0, 1				# print of the element a[i]
		#syscall					# 
		#end code only used for testing