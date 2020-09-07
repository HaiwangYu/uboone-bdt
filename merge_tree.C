#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TList.h"

#include <vector>

void merge_tree(
        const char* input = "WCP_selection.root",
        const char* output = "bdt.root"
        ) {
    auto *tf = TFile::Open(input, "read");
    auto *dir = (TDirectoryFile*) tf->Get("wcpselection");
    auto *T_BDTvars = (TTree*) dir->Get("T_BDTvars");
    auto *T_eval = (TTree*) dir->Get("T_eval");
    auto *T_KINEvars = (TTree*) dir->Get("T_KINEvars");

    auto *tf_out = TFile::Open(output, "recreate");

    auto *bdt = T_BDTvars->CloneTree();
    bdt->SetName("bdt");
    bdt->SetTitle("bdt");

    // seems merging branches from different TTree's are not supported in ROOT
    // https://root-forum.cern.ch/t/how-to-merge-two-root-files-with-different-branches-togher/14260

    // T_eval
    Bool_t match_isFC;
    Bool_t truth_isCC;
    Bool_t truth_vtxInside;
    Int_t truth_nuPdg;
    Float_t truth_nuEnergy;
    Float_t truth_energyInside;
    Float_t weight_spline;
    Float_t weight_cv;
    Float_t weight_lee;
    T_eval->SetBranchAddress("match_isFC",&match_isFC);
    T_eval->SetBranchAddress("truth_isCC",&truth_isCC);
    T_eval->SetBranchAddress("truth_nuPdg",&truth_nuPdg);
    T_eval->SetBranchAddress("truth_nuEnergy",&truth_nuEnergy);
    T_eval->SetBranchAddress("truth_energyInside",&truth_energyInside);
    T_eval->SetBranchAddress("truth_vtxInside",&truth_vtxInside);
    T_eval->SetBranchAddress("weight_spline",&weight_spline);
    T_eval->SetBranchAddress("weight_cv",&weight_cv);
    T_eval->SetBranchAddress("weight_lee",&weight_lee);

    // T_KINEvars
    Float_t kine_reco_Enu;
    T_KINEvars->SetBranchAddress("kine_reco_Enu",&kine_reco_Enu);

    std::vector<TBranch*> brs;
    Float_t match_isFC_f, truth_isCC_f, truth_vtxInside_f, truth_nuPdg_f;
    brs.push_back(bdt->Branch("match_isFC", &match_isFC_f, "match_isFC/F"));
    brs.push_back(bdt->Branch("truth_isCC", &truth_isCC_f, "truth_isCC/F"));
    brs.push_back(bdt->Branch("truth_vtxInside", &truth_vtxInside_f, "truth_vtxInside/F"));
    brs.push_back(bdt->Branch("truth_nuPdg", &truth_nuPdg_f, "truth_nuPdg/F"));
    brs.push_back(bdt->Branch("truth_nuEnergy", &truth_nuEnergy, "truth_nuEnergy/F"));
    brs.push_back(bdt->Branch("truth_energyInside", &truth_energyInside, "truth_energyInside/F"));
    brs.push_back(bdt->Branch("weight_spline", &weight_spline, "weight_spline/F"));
    brs.push_back(bdt->Branch("weight_cv", &weight_cv, "weight_cv/F"));
    brs.push_back(bdt->Branch("weight_lee", &weight_lee, "weight_lee/F"));
    brs.push_back(bdt->Branch("kine_reco_Enu", &kine_reco_Enu, "kine_reco_Enu/F"));

    for(Long64_t ientry=0; ientry<bdt->GetEntries(); ++ientry) {
        T_eval->GetEntry(ientry);
        T_KINEvars->GetEntry(ientry);
        match_isFC_f = match_isFC;
        truth_isCC_f = truth_isCC;
        truth_vtxInside_f = truth_vtxInside;
        truth_nuPdg_f = truth_nuPdg;
        for(auto br : brs) {
            br->Fill();
        }
    }

    bdt->Write();
    tf_out->Close();
}
