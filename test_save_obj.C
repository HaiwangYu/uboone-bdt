#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TList.h"
#include "TString.h"

#include <vector>
#include <string>

namespace bdt {
    struct MCEventWeight
    {
        //std::map<std::string, std::vector<double> > fWeight;
        std::vector<std::string> fName;
        std::vector<double> fWeight;
    };
}

void test_save_obj(
        const float event_type_in = 30,
        const char* input = "WCP_selection.root",
        const char* output = "bdt.root"
        ) {
    auto *tf = TFile::Open(input, "read");
    auto *dir = (TDirectoryFile*) tf->Get("wcpselection");
    auto *T_BDTvars = (TTree*) dir->Get("T_BDTvars");
    auto *T_eval = (TTree*) dir->Get("T_eval");
    auto *T_KINEvars = (TTree*) dir->Get("T_KINEvars");
    auto *T_PFeval = (TTree*) dir->Get("T_PFeval");

    auto *tf_out = TFile::Open(output, "recreate");

    auto *bdt = T_BDTvars->CloneTree();
    bdt->SetName("bdt");
    bdt->SetTitle("bdt");

    // seems merging branches from different TTree's are not supported in ROOT
    // https://root-forum.cern.ch/t/how-to-merge-two-root-files-with-different-branches-togher/14260

    // T_KINEvars
    Float_t kine_reco_Enu;
    T_KINEvars->SetBranchAddress("kine_reco_Enu",&kine_reco_Enu);

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

    // T_PFeval
    Int_t truth_nuIntType;
    T_PFeval->SetBranchAddress("truth_nuIntType",&truth_nuIntType);

    std::vector<TBranch*> brs;
    brs.push_back(bdt->Branch("kine_reco_Enu", &kine_reco_Enu, "kine_reco_Enu/F"));
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
    Float_t truth_nuIntType_f;
    brs.push_back(bdt->Branch("truth_nuIntType", &truth_nuIntType_f, "truth_nuIntType/F"));

    // 1st digit: run #
    // 2nd digit: 0: intrinsic nue, 1: intrinsic nue lowE, 2: bnb nu, 3: bnb nu lowE, 4: ext bnb, 5 dirt
    // e.g. run3_intrinsic_nue: 30
    Float_t event_type = event_type_in;
    brs.push_back(bdt->Branch("event_type", &event_type, "event_type/F"));

    bdt::MCEventWeight EventWeightMar18;
    brs.push_back(bdt->Branch("EventWeightMar18", &EventWeightMar18));

    for(Long64_t ientry=0; ientry<bdt->GetEntries(); ++ientry) {
        T_eval->GetEntry(ientry);
        T_KINEvars->GetEntry(ientry);
        T_PFeval->GetEntry(ientry);
        match_isFC_f = match_isFC;
        truth_isCC_f = truth_isCC;
        truth_vtxInside_f = truth_vtxInside;
        truth_nuPdg_f = truth_nuPdg;
        truth_nuIntType_f = truth_nuIntType;
        //EventWeightMar18.fWeight["knob_name"] = {1., 1.};
        EventWeightMar18.fName = {"knob0", "knob1"};
        EventWeightMar18.fWeight = {1., 2.};
        for(auto br : brs) {
            br->Fill();
        }
    }

    bdt->Write();
    tf_out->Close();
}
