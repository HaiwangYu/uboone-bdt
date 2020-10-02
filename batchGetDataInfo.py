#!/usr/bin/env python

import sys
import os
import subprocess

input = sys.argv[1]

with open(input, 'r') as infile:
    data = infile.readlines()
    for i,line in enumerate(data):
        rs = line.split()
        if i == 0:
            subprocess.call(["/uboone/app/users/zarko/getDataInfo.py", "-v2", "-r", rs[0], "-s", rs[1]])
        else:
            subprocess.call(["/uboone/app/users/zarko/getDataInfo.py", "--noheader", "-v2", "-r", rs[0], "-s", rs[1]])
