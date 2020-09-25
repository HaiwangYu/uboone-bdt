#!/usr/bin/env python

import sys
filename = sys.argv[1]

import ROOT as rt
infile = rt.TFile(filename)
T = infile.Get("wcpselection/T_PFeval")

if not T:
  print("Cannot get TTree.")

rses = []
for e in T:
  rse = (e.run, e.subrun, e.event)
  if rses.count(rse)==0:
    rses.append(rse)
  else:
    print("Duplicated entry for run %d, subrun %d" %(rse[0], rse[1], rse[2]))
