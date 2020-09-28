#!/usr/bin/env python

import sys
import ROOT as rt
import csv

def get_rse(filename,cache=None):
    infile = rt.TFile(filename)
    T = infile.Get("wcpselection/T_PFeval")
    if not T:
        print("Cannot get TTree.")

    # setup toolbar
    toolbar_width = 40
    toolbar_step = T.GetEntries()/toolbar_width
    sys.stdout.write("[%s]" % (" " * toolbar_width))
    sys.stdout.flush()
    sys.stdout.write("\b" * (toolbar_width+1)) # return to start of line, after '['

    rses = []
    rses_dup = []
    for i,e in enumerate(T):
        if i%toolbar_step == 0:
            sys.stdout.write("=")
            sys.stdout.flush()

        rse = (e.run, e.subrun, e.event)
        #rse = (e.run, e.subrun)
        if rses.count(rse)==0:
            rses.append(rse)
        else:
            rses_dup.append(rse)

    sys.stdout.write("]\n") # this ends the progress bar

    print("duplications:")
    for rse in rses_dup:
        print(rse)

    print("unique rse: %d"%len(rses))

    return rses

rse = get_rse(sys.argv[1])

with open("rse.csv", "wb") as f:
    writer = csv.writer(f)
    writer.writerows(rse)
