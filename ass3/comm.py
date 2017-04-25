#!/usr/bin/python

#including the necessary libraries/classes/etc
import sys
from optparse import OptionParser 

# class comm: 
# 	def __init__(self, arg1, arg2, options, parser)
# 		f1 = open (sys.argv[1], 'r') 
# 		self.lines = f1.readlines() #reads file contents, converts to list of strings called lines
# 		f1.close () 

# 	def __init__(self, sys.argv[2]): 
# 		f2 = open (sys.argv[2], 'r')
# 		self.lines = f2.readlines()
# 		f2.close()


def main():
	#creates OptParser instance called parser
	parser = OptionParser() 

	# Since these options are boolean values, the action should simply to turn on 
	# aka store a truth value confirming that a given option has been requested by the user
	# default value for boolean options probably False anyway, but juuuust in case
	parser.add_option("-1", "--suppress1", action="store_true", dest="col1", default=False, help="suppress column of words unique to file1") 
	parser.add_option("-2", "--suppress2", action="store_true", dest="col2", default=False, help="suppress column of words unique to file2") 
	parser.add_option("-3", "--suppress3", action="store_true", dest="col3", default=False, help="suppress column of words unique to file3") 
	parser.add_option("-u", "--unsorted", action="store_true", dest="input_unsorted", default=False, help="allow unsorted input") 

	# parse_args returns 2 values (which we store respectively into my creatively-named options and args variables) 
	# RETURN VALUE 1: options; an object that contains all the options' arguments (in this case, implicit option argument is True or False stored in the destination variable I provided)
	# RETURN VALUE 2: args; a list of the positional arguments aka the arguments directly related to the command itself
	# By default, it does this by parsing sys.argv[1:] which is the whole argument list, starting after the comm scriptname itself 
	options, args = parser.parse_args(sys.argv[1:]) 



########################################### TAKING CARE OF POSITIONAL ARGUMENTS ###########################################################################################

	# Reports error if given the wrong number of input operands, making sure user entered exactly 2 points of comparison
	# Exits with error status 2 
	if len(args) != 2:
		parser.error("wrong number of operands")
    

    # We know that at most one of either two files will take input from STDIN 
	# NOTE: This is index 0 of the positional args list, NOT the original sys.argv list, in which case index 0 would be the script name, comm, itself 
	# NOTE: readlines is a builtin python function that will return list (think of it like an array) of the file's lines 

	# if FILE 1 TAKES STDIN
	if args[0] == '-':
		f1 = sys.stdin.readlines()

		# FILE 2 takes file input 
		f2stream = open(args[1], 'r') 
		f2 = f2stream.readlines()  #now f2 is a list variable with each element being a line from file 2
		f2stream.close()

	# else if FILE 2 TAKES STDIN
	elif (args[1] == '-'):

		
		f2 = sys.stdin.readlines()
		
		#FILE 1 takes FILE INPUT
		f1stream = open(args[0], 'r')
		f1 = f1stream.readlines() #now f1 is a list variable with each element being a line from file 1
		f1stream.close()

	# otherwise, BOTH FILE ARGS TAKE FILE INPUT 
	else:
		f1stream = open(args[0], 'r')
		f1 = f1stream.readlines() #now f1 is a list variable with each element being a line from file 1
		f1stream.close()

		f2stream = open(args[1], 'r') 
		f2 = f2stream.readlines()  #now f2 is a list variable with each element being a line from file 2
		f2stream.close()


########################################## TAKING CARE OF OPTIONS ########################################################################################################

	# If user applies -123, then just output single newline and exit 
	if options.col1 and options.col2 and options.col3:
		print "\n"
		exit()

	# # If user does NOT enter any options  
	# elif not(options.no_col1 or options.no_col2 or options.no_col3):
	# 	for i in len(bigger_file):
	# 		for j in len
	# 			if f1[i] < f2[i]:
	# 				print f


	suppress_1 = suppress_2 = suppress_shared = False
	f1_smaller = f1_bigger = False

	# Turn on boolean values according to those stored in col1/col2/col3 when the user types the options 
	if options.col1:
		suppress_1 = True
	if options.col2:
		suppress_2 = True
	if options.col3: 
		suppress_shared = True

	# if len(f1) < len(f2):
	# 	bigger_file = f2
	# 	smaller_file = f1
	# else:
	# 	bigger_file = f1  # also encapsulates the case they are equal length files 
	# 	smaller_file = f2

	bigger_file = []
	file_sizes_same = False
	num_lines = 0

	if len(f1) < len(f2):
		f1_smaller = True
		bigger_file = f2
		smaller_file=f1
	elif len(f1) > len(f2):
		f1_bigger = True
		bigger_file = f1
		smaller_file = f2
	else:
		file_sizes_same = True
		num_lines = len(f1)

	output=""


	# NO -u OPTION REQUESTED, just -1 -2 and/or -3
	if not options.input_unsorted:

	# 	if file_sizes_same:
	# 		for i in range(num_lines):
	# 			print i
	# 			for j in range(num_lines):

	# 				# TAKE CARE OF -1 
	# 				if f2[i] > f1[j]: 		# if f1 line ASCII-precedes f2 line,  store in col1
	# 					if not suppress_1: 
	# 						output += f1[j] # column 1 data is leftmost when it is expressed 
	# 					j=j+1

	# 				#TAKE CARE OF -2 
	# 				elif f2[i] < f1[j]: 		# else if f2's line precedes f1's line in ASCII, store in col2
	# 					if not suppress_2:
	# 						if suppress_1:		 # option -1 implies...
	# 							output += f2[i]  # column 2 data will be situated leftmost

	# 						else: 				# option -2 implies...
	# 							print "print " + f2[i] +" to col2 b/c its < than f1[" + str(j) + "]"
	# 							output += '\t'+f2[i] # column 2 is one tab to the right 
	# 					i=i+1


		
	# 				# TAKE CARE OF -3
	# 				else: #all remaining cases: if the compared lines in f1 and f2 are exact same
	# 					if not suppress_shared:

	# 						if (suppress_1 and suppress_2): #option -12
	# 							output += f1[j] #col3 becomes leftmost

	# 						elif suppress_1 or suppress_2: #option -1 or -2
	# 							output += '\t'+f1[j] #col3 becomes one tab to the right 

	# 						# else:  #no options 
	# 						# 	print "this is" + f1[j] +"and"+ f2[i]
	# 							output += '\t\t'+f1[j] #col3 is in its usual place
	# 					i=i+1
	# 					j=j+1
							
	 
	# #loop through f2 list, checking against every element in f1 list 
	# # (inner/outer loops arbitrary since I'll check for leftovers later if files are different sizes)
	# 	else:
	# 		for i in range(len(f2)):
	# 			for j in range(len(f1)):

	# 				# TAKE CARE OF -1 
	# 				if f2[i] > f1[j]: 		# if f1 line ASCII-precedes f2 line,  store in col1
	# 					if not suppress_1: 
	# 						output += f1[j] # column 1 data is leftmost when it is expressed 
	# 					j=j+1
	# 				#TAKE CARE OF -2 
	# 				elif f2[i] < f1[j]: 		# else if f2's line precedes f1's line in ASCII, store in col2
	# 					if not suppress_2:
	# 						if suppress_1:		 # option -1 implies...
	# 							output += f2[i]  # column 2 data will be situated leftmost

	# 						else: 				# option -2 implies...
	# 							output += '\t'+f2[i] # column 2 is one tab to the right 
	# 					i=i+1
		
	# 				# TAKE CARE OF -3
	# 				else: #all remaining cases: if the compared lines in f1 and f2 are exact same
	# 					if not suppress_shared:

	# 						if (suppress_1 and suppress_2): #option -12
	# 							output += f1[j] #col3 becomes leftmost

	# 						elif suppress_1 or suppress_2: #option -1 or -2
	# 							output += '\t'+f1[j] #col3 becomes one tab to the right 

	# 						else:  #no options 
	# 							output += '\t\t'+f1[j] #col3 is in its usual place
	# 							i=i+1
	# 					i=i+1
	# 					j=j+1
	# 				#if unlucky and we're iterating through the smaller list with the bigger one,
	# 				# exit nested loop once inner loop through smaller list is about to finish
	# 				if f1_smaller and j == (len(f1)-1):
	# 					break
	# 			else:
	# 				continue #executed if inner loop ended normally without a break
	# 			break # executed if 'continue' was skipped




	# 	# print the leftovers in the larger file's list in its respective column 
	# 	if f1_bigger and (j < len(f1)) and (not suppress_2): 
	# 		remaining_f1 = f1[j:]

	# 		for k in range(len(remaining_f1)):
	# 			output += remaining_f1[k]

	# 	elif f1_smaller and (i < len(f2)) and (not suppress_2): 
	# 		remaining_f2 = f2[i:]

	# 		for m in range(len(remaining_f2)):
	# 			output += '\t' + remaining_f2[m]


	# # -u OPTION REQUESTED, pepper urself for unsorted input
	# #else: 

		
	# print output

		i=0
		j=0

		while i < len(f2) and j < len(f1):
			#print "i: " + str(i) + " j: " + str(j) + "\n"

			# TAKE CARE OF -1 
			if f2[i] > f1[j]: 		# if f1 line ASCII-precedes f2 line,  store in col1
				if not suppress_1: 
					output += f1[j] # column 1 data is leftmost when it is expressed 
				j=j+1

			#TAKE CARE OF -2 
			elif f2[i] < f1[j]: 		# else if f2's line precedes f1's line in ASCII, store in col2
				if not suppress_2 and suppress_1:  # option -1 implies...
					output += f2[i]  # column 2 data will be situated leftmost

				else: 				# option -2 implies...
					output += '\t'+f2[i] # column 2 is one tab to the right 
				i=i+1
		
			# TAKE CARE OF -3
			else: #all remaining cases: if the compared lines in f1 and f2 are exact same
				if not suppress_shared:

					if (suppress_1 and suppress_2): #option -12
						output += f1[j] #col3 becomes leftmost

					elif suppress_1 or suppress_2: #option -1 or -2
						output += '\t'+f1[j] #col3 becomes one tab to the right 

					else:  #no options 
						output += '\t\t'+f1[j] #col3 is in its usual place
				i=i+1
				j=j+1
					#if unlucky and we're iterating through the smaller list with the bigger one,
					# exit nested loop once inner loop through smaller list is about to finish
				# 	if f1_smaller and j == (len(f1)-1):
				# 		break
				# else:
				# 	continue #executed if inner loop ended normally without a break
				# break # executed if 'continue' was skipped




		# print the leftovers in the larger file's list in its respective column 
		if f1_bigger and (j < len(f1)) and (not suppress_2): 
			remaining_f1 = f1[j:]

			for k in range(len(remaining_f1)):
				output += remaining_f1[k]

		elif f1_smaller and (i < len(f2)) and (not suppress_2): 
			remaining_f2 = f2[i:]

			for m in range(len(remaining_f2)):
				output += '\t' + remaining_f2[m]


	# -u OPTION REQUESTED, pepper urself for unsorted input
	else: 
		
		# Create list for storing col3 values to compare
		column3 = []

		# i = 0
		# j = 0
		# while i < len(f1) and j < len(f2):
		# 	if f1[i] == f2[j]:
		# 		output += '\t\t'+ f1[i]
		# 		column3.append(f1[i])
		# 		i=i+1
		# 		j=j+1


		# 	else: #if unique to file 1, 
		# 		output += f1[i]
		# 		i = i + 1 # compare with next f1 line 
		


		next = False
		next_i = 0
		next_j = 0
		#populate array of COL3 lines 
		for i in range(len(f1)):
			for j in range(len(f2)):
				if next:
					j = next_j
				next = False
				if f1[i] == f2[j]:
					column3.append(f1[i])
					next = True
					next_j = j+1


		#output file 1 stuff (unique lines in col1, shared w/ file2 in col3)
		i = 0
		j = 0
		while i < len(f1) and j < len(column3):

			# if MISMATCH... 
			if f1[i] != column3[j]:
				# but we're not done iterating through col3
				if j < len(column3)-1:
					j = j+1
					continue

				else: # and we've checked it against all the col3 lines
					if i != len(f1):
						output += f1[i]
					i = i+1


			# if MATCH, keep it in col3 output
			else:
				output += '\t\t' + f1[i]
				i = i+1

			

			#If we've reached last line in file1
			if i == len(f1)-1:
				j =0 

			# Reiterate through col3 list of lines
			if j == len(column3) -1:
				j = 0
		
		i = 0
		j = 0

		# output leftover file2 stuff in col2 
		while i < len(f2) and j < len(column3):
			# if MISMATCH... 
			if f2[i] != column3[j]:
				# but we're not done iterating through col3
				if j < len(column3)-1:
					j = j+1
					

				else: # and we've checked it against all the col3 lines
					if i != len(f2):
						output += '\t' + f2[i]
					i = i+1
			else:
				i = i+1
				print "got here"

####### ####### ####### THIS IS ATTEMP 2####### ####### ####### ####### 
		# next = False
		# next_i = 0
		# next_j = 0



		# #populate array of COL3 lines 
		# for i in range(len(f1)):
		# 	for j in range(len(f2)):
		# 		if next:
		# 			j = next_j
		# 		next = False
		# 		if f1[i] == f2[j]:
		# 			column3.append(f1[i])
		# 			next = True
		# 			next_j = j+1
				

		# next = False
		# next_i = 0
		# next_j = 0
		# # for i in range(len(column3)):
		# # 	print column3[i]

		# # Loop through file 1
		# for i in range(len(f1)):
		# 	if next:
		# 		i = next_i
		# 	next = False

		# 	#Loop through files existing in file 1 AND file 2
		# 	for j in range(len(column3)):
		# 		if next:
		# 			j = next_j
		# 		next = False

		# 		if f1[i] != column3[j]:
		# 			output += f1[i]
		# 			next = True
		# 			next_i = i+1
		# 			i = i+1

		# 		else:
		# 			output += '\t\t' + f1[i]
		# 			next = True
		# 			next_j = j+1
		# 			j = j+1

		# for i in range(len(f2)):
		# 	for j in range(len(column3)):
		# 		if f2[i] != column3[j]:
		# 			output += '\t' + f2[i]


####### ####### ####### #######  ATTEMPT 1 ####### ####### ####### ####### ####### 
		# for i in range(len(f1)):
		# 	if next:
		# 		i = next_i
		# 		print i
				
		# 	next = False

		# 	for j in range(len(f2)):
		# 		if next:
		# 			continue
		# 			next = False

		# 		print "iter j: " + str(j)

		# 		# If both are same
		# 		if f1[i] == f2[j]:

		# 			output += '\t\t' + f1[i]
		# 			column3.append(f1[i])
					
		# 			# If not at end, move onto next file1 line
		# 			if i != len(f1)-1:
		# 				next_i=i+1
		# 				next = True

		# 		# If we've found a unique-to-file1 line, output leftmost
		# 		else:
		# 			output += f1[i]

		# 			if i != len(f1)-1:
		# 				next_i = i+1
		# 				next = True
				


		# for i in range (len(f2)):
		# 	for j in range(len(column3)): 
		# 		if f2[i] != column3[j]:
		# 			output += '\t' + f2[i] # put in col2

		# for i in range(len(unique_to_f1)):
		# 	print unique_to_f1[i]

		
	print output




#Below is needed to prevent executing the entire script just by importing it
#Note: when running script from command line, its name is main,
#but when running script from another script, its name is itself (like b.py)
if __name__ == "__main__":
    main()

