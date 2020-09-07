

## Documents

[WireCell LEE Master Task List](https://docs.google.com/document/d/1X-nV4gox1uYCATGu71e4DvuiB27dGS5yVxeLTgr2iFM/edit)

[WCP + larsoft port module Data Production](https://docs.google.com/document/d/1Cr-QVRa4Js4jDhgpZDS-Nmt8R4mkRXrA_q8kSOZodcM/edit)





## Finding samples

[MCC9.1 WCP reco1.5 Samples](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/details_wcp_v28.html)

data

- [data_bnb_run1_5e19](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/xml/data,)
- [data_extbnb_run1_C1](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/xml/data,)

MC

- [prodgenie_bnb_nu_overlay_run1](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/xml/data,) 1 neutrino in cryo + cosmic, neutrino corresponding to bean (bnb)
  - nue 0.5%
- [prodgenie_bnb_intrinsic_nue_overlay_run1](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/xml/data,) 



LowE:

[prodgenie_bnb_nu_overlay_LowE_run1](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/xml/data,)

[prodgenie_bnb_intrinsic_nue_overlay_LowE_run1](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/xml/data,)



##  Production

### generate file list

check dataset summary

```bash
samweb list-files --summary defname:prodgenie_bnb_intrinsic_nue_uboone_overlay_mcc9.0_run1_wcp_reco1.5_v08_00_00_29_reco1.5_reco1.5
```



```
cd /uboone/app/users/yuhw/Portback_WCP/Samdata
./samfilelist.sh 1 4720 prodgenie_bnb_intrinsic_nue_uboone_overlay_mcc9.0_run1_wcp_reco1.5_v08_00_00_29_reco1.5_reco1.5
```

### project.py

```
project.py --xml project_wcpplus.xml --stage port2 --submit
```



### job monitor

```
jobsub_q --user yuhw
jobsub_rm --user yuhw
jobsub_fetchlog --jobid
```



### FIFE

[FIFEMon](https://fifemon.fnal.gov/monitor/d/000000116/user-batch-details?orgId=1&var-cluster=fifebatch&var-user=yuhw)

### Analysis

run_WCPcheckout.fcl

```bash
SaveLeeWieghts: false
```



### Merge banches from two trees

https://root-forum.cern.ch/t/merging-branches-from-two-tfiles-into-one-tree/21734

https://root-forum.cern.ch/t/how-to-merge-two-root-files-with-different-branches-togher/14260

### run3_intrinsic_nue

part1: 1-1700

```bash
$jobsub_q --user yuhw
JOBSUBJOBID                           OWNER           SUBMITTED     RUN_TIME   ST PRI SIZE CMD
11966436.812@jobsub03.fnal.gov        yuhw            09/04 20:56   0+06:00:07 H   0   1.5 port2-run3_intrinsic_nue-v08_00_00_42.sh_20200904_205616_2941473_0_1_wrap.sh 
11966436.1639@jobsub03.fnal.gov       yuhw            09/04 20:56   0+00:54:31 H   0   1.5 port2-run3_intrinsic_nue-v08_00_00_42.sh_20200904_205616_2941473_0_1_wrap.sh
```



part2 and run1_intrinsic_nue_LowE

```bash
$jobsub_q --user yuhw
JOBSUBJOBID                           OWNER           SUBMITTED     RUN_TIME   ST PRI SIZE CMD
36363131.551@jobsub01.fnal.gov        yuhw            09/06 12:19   0+06:00:04 H   0   1.7 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.693@jobsub01.fnal.gov        yuhw            09/06 12:19   0+02:40:40 H   0   3.7 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.782@jobsub01.fnal.gov        yuhw            09/06 12:19   0+01:55:12 H   0   3.2 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.891@jobsub01.fnal.gov        yuhw            09/06 12:19   0+02:37:15 H   0   3.9 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.1344@jobsub01.fnal.gov       yuhw            09/06 12:19   0+01:04:43 H   0   3.9 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh
```

