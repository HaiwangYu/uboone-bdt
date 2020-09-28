#!/usr/bin/env python

import sys
import ROOT as rt
import csv

def get_rse(filename):
    rses = []
    with open(filename,"rb") as f:
        rses = [list(map(int,rec)) for rec in csv.reader(f, delimiter=',')]
    print("unique rse: %d"%len(rses))
    return rses

rses1 = get_rse(sys.argv[1])
rses2 = get_rse(sys.argv[2])

# setup toolbar
toolbar_width = 40
toolbar_step = max(1,(len(rses2))/toolbar_width)
sys.stdout.write("[%s]" % (" " * toolbar_width))
sys.stdout.flush()
sys.stdout.write("\b" * (toolbar_width+1)) # return to start of line, after '['

duplication = 0
rses_dup = []
for i,rse in enumerate(rses2):
    if i%toolbar_step == 0:
        sys.stdout.write("=")
        sys.stdout.flush()

    if rses1.count(rse) != 0:
        duplication += 1
        rses_dup.append(rse)

print("rse1: %d"%len(rses1))
print("rse2: %d"%len(rses2))
print("duplication: %d"%duplication)
if(duplication>0):
    for rse in rses_dup:
        print(rse)
