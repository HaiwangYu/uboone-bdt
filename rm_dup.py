#!/usr/bin/env python

from __future__ import print_function
import sys
import os
import subprocess
import json


'''
usage: ./rm_dup.py file_list
'''

file_list = sys.argv[1]
outname = '{}_no_dup.txt'.format(file_list)

files = []

outfile = open(outname,'w')
with open(file_list, 'r') as f:
    for line in f:
        print(line,end='')
        if files.count(line) == 0:
            files.append(line)
            print(line,end='',file=outfile)
print('out: %d'%(len(files)))

outfile.close()
