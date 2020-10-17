#!/usr/bin/env python

from __future__ import print_function
import sys
import os
import subprocess
import json


'''
usage: ./samweb-files-rs-filter.py file_list bad_rs_list
'''

file_list = sys.argv[1]
bad_rs_list = sys.argv[2]
outname = '{}_filter.txt'.format(file_list)

files = []
with open(file_list, 'r') as infile:
    files = infile.read().splitlines()

print('input files: %d'%(len(files)))

bad_rs = []
with open(bad_rs_list, 'r') as f:
    for line in f:
        data = line.split()
        r = int(data[0])
        s = int(data[1])
        if bad_rs.count((r,s)) == 0:
            bad_rs.append((r,s))
print('bad rs: %d'%(len(bad_rs)))

outfile = open(outname,'w')
for i,file_path in enumerate(files):
    file = os.path.basename(file_path)
    meta = subprocess.check_output(["samweb", "get-metadata", "--json", file])
    meta = json.loads(meta)
    print(i, file, meta["runs"])
    is_bad_rs = False
    for rs in meta["runs"]:
        if bad_rs.count((rs[0],rs[1])) > 0:
            is_bad_rs = True
            break
    if is_bad_rs:
        print(file_path, file=outfile)

outfile.close()
