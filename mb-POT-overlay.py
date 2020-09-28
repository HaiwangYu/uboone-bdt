#!/usr/bin/env python

import sys
import ROOT as rt
import csv

def get_rse(filename):
    rses = []
    with open(filename,"rb") as f:
        rses = [list(map(int,rec)) for rec in csv.reader(f, delimiter=',')]
    print("exclude rs: %d"%len(rses))
    return rses

rs_excl = []
if len(sys.argv) >1 :
    rs_excl = get_rse(sys.argv[2])
    print(rs_excl)

filename = sys.argv[1]

infile = rt.TFile(filename)
T_pot = infile.Get("wcpselection/T_pot")

if not T_pot:
    print("Cannot get TTree with name T_pot.")

RSPv = []
for e in T_pot:
    rsp = (e.runNo, e.subRunNo, e.pot_tor875)
    if rs_excl.count([e.runNo, e.subRunNo]) > 0:
        print("do not count run %d, subrun %d" %(rsp[0], rsp[1]))
        continue
    if RSPv.count(rsp)==0:
        RSPv.append(rsp)
    else:
        print("Duplicated entry for run %d, subrun %d" %(rsp[0], rsp[1]))


total_pot = 0
for run, subrun, pot in RSPv:
    total_pot += pot

print("Total POT: %E" %total_pot)
