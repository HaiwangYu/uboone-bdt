## wcp_v00_14_04
### bdt-0912

location: `/uboone/app/users/yuhw/Portback_WCP/wcp_v00_14_04/bdt-0912`

All samples were processed using `wcp_v00_14_04` except the `run1_ext_bnb_C1_gt10_wcp_v00_14_00_POT1.2E20.root`, which was processed using ``wcp_v00_14_00`

**Use the `bdt` `TTree` only**. The `T_BDTvars` tree is a by-product producing this file and should NOT be used.

A rough POT number was given for each root file in the name.

Use **only even `run`** for training: `(run%2)==0` (TODO: use `run` or `subrun`?)

`event_type` indicates sample category

- 0: intrinsic nue
- 1: intrinsic nue LowE
- 2: bnb nu
- 3: bnb nu LowE
- 4: ext bnb

**note**: `truth_*` and `weight_*` variables should not be used for the 'ext bnb' sample as it is real data



**for nue bdt training:**

signal selection

- intrinsic_nue sample + truth nueCC + truth vtx inside FC + good reco:

```bash
( (event_type%10)==0 || (event_type%10)==1 ) &&
( nuvtx_diff<1 && showervtx_diff<1 && truth_isCC && abs(truth_nuPdg)==12 && truth_vtxInside )
```

background selection:

- bnb_nu_overlay + veto truth nueCC:

```
( (event_type%10)==2 or (event_type%10)==3 ) &&
( !(truth_isCC==1 && abs(truth_nuPdg)==12) )
```

- ext_bnb:

```
(event_type%10)==4
```



