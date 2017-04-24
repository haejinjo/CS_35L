#!/usr/bin/python

import random, sys
from optparse import OptionParser 

class comm: 
	def __init__(self, sys.argv[1]): 
		f1 = open (sys.argv[1], 'r') 
		self.lines = f1.readlines() 
		f1.close () 
	def __init__(self, sys.argv[2]): 
		f2 = open (sys.argv[2], 'r')
		self.lines = f2.readlines()
		f2.close()

