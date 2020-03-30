import os
import sys

base_folder = "/Users/macbookpro/Documents/C++/Template/"

available = ['segtree.cpp', 'lazysegtree.cpp', 'sparsetable.cpp', 'stringhash.cpp', 'zfunction.cpp']
filename = (sys.argv[1])

os.system("touch " + filename)
os.system("less " + base_folder + "base.cpp > " + filename)

while (True):
	for i, name in enumerate(available):
		print (str(i)+": "+name)

	choice = raw_input()
	choice = int(choice)
	if (choice < 0):
		break
	os.system("less " + base_folder + available[choice] + " >> " + filename)

os.system("less " + base_folder + "main.cpp >> " + filename)