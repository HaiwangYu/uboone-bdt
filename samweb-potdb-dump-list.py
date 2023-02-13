#!/usr/bin/env python

from __future__ import print_function
import sys
import os
import subprocess
import json


'''
usage: ./batchGetDataInfo.py file_list
'''

file_list = sys.argv[1]
outname = '{}_potdb.txt'.format(file_list)

potdb = open(outname,'w')
header = "           run        subrun           EXT         Gate2        E1DCNT        tor860        tor875   E1DCNT_wcut   tor860_wcut   tor875_wcut"
print(header, file=potdb)
with open(file_list, 'r') as infile:
    data = infile.readlines()
    nlines = len(data)
    for i,line in enumerate(data):
        if i%100 == 0 :
            print('processing {}%'.format(100.*i/nlines))
        rs = line.split()
        potinfo = subprocess.check_output(["/uboone/app/users/zarko/getDataInfo.py", "--noheader", "-v2", "-r", str(rs[0]), "-s", str(rs[1])])
        print(potinfo, end='', file=potdb)
potdb.close()
