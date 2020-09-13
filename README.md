

## Documents

[WireCell LEE Master Task List](https://docs.google.com/document/d/1X-nV4gox1uYCATGu71e4DvuiB27dGS5yVxeLTgr2iFM/edit)

[WCP + larsoft port module Data Production](https://docs.google.com/document/d/1Cr-QVRa4Js4jDhgpZDS-Nmt8R4mkRXrA_q8kSOZodcM/edit)

## Finding samples

[AT Page](https://microboone-exp.fnal.gov/at_work/AnalysisTools/index.html)

[MCC9.1 WCP reco1.5 Samples](https://microboone-exp.fnal.gov/at_work/AnalysisTools/mc/mcc9.0/details_wcp_v28.html)

##  Production

### generate file list

check dataset summary

```bash
samweb list-files --summary defname:prodgenie_bnb_intrinsic_nue_uboone_overlay_LowE_reco1.5_run3_reco1.5_reco1.5
```



```
cd /uboone/app/users/yuhw/Portback_WCP/Samdata
./samfilelist.sh 1 581 prodgenie_bnb_intrinsic_nue_uboone_overlay_LowE_reco1.5_run3_reco1.5_reco1.5
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

### Careful!!!

- need to check if `br_filled==1`
- 

### Merge banches from two trees

https://root-forum.cern.ch/t/merging-branches-from-two-tfiles-into-one-tree/21734

https://root-forum.cern.ch/t/how-to-merge-two-root-files-with-different-branches-togher/14260

### 2020-09-07 log

run3_intrinsic_nue part1:

```bash
$jobsub_q --user yuhw
JOBSUBJOBID                           OWNER           SUBMITTED     RUN_TIME   ST PRI SIZE CMD
11966436.812@jobsub03.fnal.gov        yuhw            09/04 20:56   0+06:00:07 H   0   1.5 port2-run3_intrinsic_nue-v08_00_00_42.sh_20200904_205616_2941473_0_1_wrap.sh 
11966436.1639@jobsub03.fnal.gov       yuhw            09/04 20:56   0+00:54:31 H   0   1.5 port2-run3_intrinsic_nue-v08_00_00_42.sh_20200904_205616_2941473_0_1_wrap.sh
```

run3_intrinsic_nue part2 and run1_intrinsic_nue_LowE

```bash
$jobsub_q --user yuhw
JOBSUBJOBID                           OWNER           SUBMITTED     RUN_TIME   ST PRI SIZE CMD
36363131.551@jobsub01.fnal.gov        yuhw            09/06 12:19   0+06:00:04 H   0   1.7 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.693@jobsub01.fnal.gov        yuhw            09/06 12:19   0+02:40:40 H   0   3.7 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.782@jobsub01.fnal.gov        yuhw            09/06 12:19   0+01:55:12 H   0   3.2 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.891@jobsub01.fnal.gov        yuhw            09/06 12:19   0+02:37:15 H   0   3.9 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh 
36363131.1344@jobsub01.fnal.gov       yuhw            09/06 12:19   0+01:04:43 H   0   3.9 port2-run3_intrinsic_nue_part2-v08_00_00_42.sh_20200906_121912_1548818_0_1_wrap.sh
```

run1_intrinsic_nue part1

```bash
$jobsub_q --user yuhw
JOBSUBJOBID                           OWNER           SUBMITTED     RUN_TIME   ST PRI SIZE CMD
36644692.168@jobsub02.fnal.gov        yuhw            09/07 12:14   0+01:16:00 H   0   3.9 port2-run1_intrinsic_nue_part1-v08_00_00_42.sh_20200907_121417_664310_0_1_wrap.sh 
36644692.363@jobsub02.fnal.gov        yuhw            09/07 12:14   0+00:22:11 H   0   3.7 port2-run1_intrinsic_nue_part1-v08_00_00_42.sh_20200907_121417_664310_0_1_wrap.sh 
36644692.391@jobsub02.fnal.gov        yuhw            09/07 12:14   0+02:24:53 H   0   3.9 port2-run1_intrinsic_nue_part1-v08_00_00_42.sh_20200907_121417_664310_0_1_wrap.sh 
36644692.402@jobsub02.fnal.gov        yuhw            09/07 12:14   0+01:11:37 H   0   3.7 port2-run1_intrinsic_nue_part1-v08_00_00_42.sh_20200907_121417_664310_0_1_wrap.sh 
36644692.569@jobsub02.fnal.gov        yuhw            09/07 12:14   0+05:33:07 R   0   1.7 port2-run1_intrinsic_nue_part1-v08_00_00_42.sh_20200907_121417_664310_0_1_wrap.sh 
36644692.844@jobsub02.fnal.gov        yuhw            09/07 12:14   0+01:42:30 H   0   3.2 port2-run1_intrinsic_nue_part1-v08_00_00_42.sh_20200907_121417_664310_0_1_wrap.sh 

6 jobs; 0 completed, 0 removed, 0 idle, 1 running, 5 held, 0 suspended
```

run1_intrinsic_nue part3

```bash
$jobsub_q --user yuhw
JOBSUBJOBID                           OWNER           SUBMITTED     RUN_TIME   ST PRI SIZE CMD
36649474.584@jobsub02.fnal.gov        yuhw            09/08 08:33   0+01:27:32 H   0   3.9 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.788@jobsub02.fnal.gov        yuhw            09/08 08:33   0+02:18:00 H   0   3.7 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.795@jobsub02.fnal.gov        yuhw            09/08 08:33   0+06:00:41 H   0   2.2 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.804@jobsub02.fnal.gov        yuhw            09/08 08:33   0+06:00:36 H   0   2.0 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.813@jobsub02.fnal.gov        yuhw            09/08 08:33   0+06:00:39 H   0   2.0 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.818@jobsub02.fnal.gov        yuhw            09/08 08:33   0+06:00:37 H   0   2.4 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1325@jobsub02.fnal.gov       yuhw            09/08 08:33   0+01:00:20 H   0   2.9 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1336@jobsub02.fnal.gov       yuhw            09/08 08:33   0+01:25:57 H   0   3.7 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1384@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:08 H   0   3.2 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1435@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:06 H   0   2.0 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1468@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:09 H   0   1.7 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1479@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:09 H   0   2.2 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1489@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:10 H   0   2.2 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1494@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:06 H   0   2.2 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1501@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:04 H   0   1.7 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
36649474.1504@jobsub02.fnal.gov       yuhw            09/08 08:33   0+06:00:07 H   0   1.7 port2-run1_intrinsic_nue_part3-v08_00_00_42.sh_20200908_083338_1643221_0_1_wrap.sh 
12034896.172@jobsub03.fnal.gov        yuhw            09/07 22:00   0+01:10:55 H   0   3.4 port2-run1_intrinsic_nue_part2-v08_00_00_42.sh_20200907_220014_1833728_0_1_wrap.sh 
12034896.522@jobsub03.fnal.gov        yuhw            09/07 22:00   0+06:00:21 H   0   1.7 port2-run1_intrinsic_nue_part2-v08_00_00_42.sh_20200907_220014_1833728_0_1_wrap.sh 
12034896.721@jobsub03.fnal.gov        yuhw            09/07 22:00   0+02:48:12 H   0   3.7 port2-run1_intrinsic_nue_part2-v08_00_00_42.sh_20200907_220014_1833728_0_1_wrap.sh 
12034896.1014@jobsub03.fnal.gov       yuhw            09/07 22:00   0+02:22:55 H   0   3.9 port2-run1_intrinsic_nue_part2-v08_00_00_42.sh_20200907_220014_1833728_0_1_wrap.sh 
12034896.1050@jobsub03.fnal.gov       yuhw            09/07 22:00   0+02:52:13 H   0   3.9 port2-run1_intrinsic_nue_part2-v08_00_00_42.sh_20200907_220014_1833728_0_1_wrap.sh 
12034896.1087@jobsub03.fnal.gov       yuhw            09/07 22:00   0+02:35:16 H   0   3.4 port2-run1_intrinsic_nue_part2-v08_00_00_42.sh_20200907_220014_1833728_0_1_wrap.sh 

22 jobs; 0 completed, 0 removed, 0 idle, 0 running, 22 held, 0 suspended
```

run3_intrinsic_nue_LowE

```bash
$jobsub_q --user yuhw
JOBSUBJOBID                           OWNER           SUBMITTED     RUN_TIME   ST PRI SIZE CMD
36469315.76@jobsub01.fnal.gov         yuhw            09/10 14:21   0+06:00:13 H   0   1.7 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.77@jobsub01.fnal.gov         yuhw            09/10 14:21   0+06:00:08 H   0   1.5 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.79@jobsub01.fnal.gov         yuhw            09/10 14:21   0+06:00:12 H   0   1.5 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 

...

36469315.564@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:06 H   0   0.0 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.565@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:05 H   0   1.5 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.568@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:09 H   0   1.5 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.569@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:09 H   0   0.0 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.571@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:08 H   0   1.7 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.572@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:08 H   0   1.5 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.574@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:05 H   0   1.5 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 
36469315.578@jobsub01.fnal.gov        yuhw            09/10 14:21   0+06:00:12 H   0   1.5 port2-run3_intrinsic_nue_LowE-v08_00_00_42.sh_20200910_142118_780971_0_1_wrap.sh 

180 jobs; 0 completed, 0 removed, 0 idle, 0 running, 180 held, 0 suspended
```



### 2020-09-07

Good reco cut:

```bash
nuvtx_diff<1 && showervtx_diff<1 && truth_isCC && abs(truth_nuPdg)==12 && truth_vtxInside
```

nu nc: line 140 of https://nusoft.fnal.gov/larsoft/doxsvn/html/MCNeutrino_8h_source.html#l00079

```bash
T_PFeval: truth_nuIntType != 1098  (“1098” means NC nu electron elastic scattering)
```

```bash
f_flash_found && f_match_found && !f_match_isTgm && !f_stm_TGM && !f_stm_STM && !f_stm_lowenergy && !f_stm_LM && !f_stm_FullDead && f_stm_clusterlength>15 
```

### BNB, EXT POT

`/uboone/app/users/hanyuwei/Portback_WCP/WCPport/production_temp/Reco2_WCPplus/nueDev/NewReleaseAug/Analysis/WCP_selection_extbnb_run1_C1_gt10.root`

```bash
Run comamnd "/uboone/app/users/zarko/getDataInfo.py -v2 --run-subrun-list rslist.txt"
===
How to read off the POT information?
* BNB data: column ``tor875`` is the POT
* BNB EXT: scale POT from any BNB data with ``EXT`` and BNB data ``E1DCNT``
  Per 1e18 POT, the E1DCNT is about 230,000
===
Read 86289 lines from rslist.txt
           EXT         Gate2        E1DCNT        tor860        tor875   E1DCNT_wcut   tor860_wcut   tor875_wcut
    27581104.0    29471500.0    29527890.0     1.226e+20     1.225e+20    27066970.0     1.213e+20     1.212e+20
Warning!! BNB data for some of the requested runs/subruns is not in the database.
1 runs missing BNB data (number of subruns missing the data): 96 (2),
```

`/uboone/app/users/hanyuwei/Portback_WCP/WCPport/production_temp/Reco2_WCPplus/nueDev/NewReleaseAug/Analysis/v00_14_04/WCP_selection_extbnb_run3_F_G1.root`

```bash
$./mb-POT-bnb-T_eval.py WCP_selection_extbnb_run3_F_G1.root 
Save 90889 lines to rslist.txt
Run comamnd "/uboone/app/users/zarko/getDataInfo.py -v2 --run-subrun-list rslist.txt"
===
How to read off the POT information?
* BNB data: column ``tor875`` is the POT
* BNB EXT: scale POT from any BNB data with ``EXT`` and BNB data ``E1DCNT``
  Per 1e18 POT, the E1DCNT is about 230,000
===
Read 90889 lines from rslist.txt
           EXT         Gate2        E1DCNT        tor860        tor875   E1DCNT_wcut   tor860_wcut   tor875_wcut
    43608004.0    24784390.0    24890552.0     9.585e+19     9.608e+19    20187655.0     8.516e+19     8.536e+19
```

