import os
import sys

available = ['segtree.cpp', 'lazysegtree.cpp', 'sparsetable.cpp', 'stringhash.cpp']
filename = (sys.argv[1])

os.system("touch " + filename)
os.system("less base.cpp > " + filename)

while (True):
	for i, name in enumerate(available):
		print (str(i)+": "+name)

	choice = raw_input()
	choice = int(choice)
	if (choice < 0):
		break
	os.system("less " + available[choice] + " >> " + filename)

os.system("less main.cpp >> " + filename)