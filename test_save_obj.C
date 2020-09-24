#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TList.h"
#include "TString.h"

#include <vector>
#include <string>

namespace evwgh {
    struct MCEventWeight
    {
        std::map<std::string, std::vector<double> > fWeight;
    };
}

void test_save_obj(
        const char* output = "save_obj.root"
        ) {

    auto *tf_out = TFile::Open(output, "recreate");

    auto *tree = new TTree("save_obj","save_obj");

    evwgh::MCEventWeight EventWeightMar18;
    tree->Branch("EventWeightMar18", &EventWeightMar18);

    //std::map<std::string, std::vector<double>> fmcweight;
    //tree->Branch("mcweight", "std::map<std::string, std::vector<double>>",&fmcweight);

    for(Long64_t ientry=0; ientry<2; ++ientry) {

        EventWeightMar18.fWeight["knob_name"] = {1., 1.};

        //fmcweight["knob_name"] = {1., 1.};

        tree->Fill();
    }

    tree->Write();
    tf_out->Close();
}
