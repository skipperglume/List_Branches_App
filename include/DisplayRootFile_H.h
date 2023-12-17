#ifndef  DisplayRootFile_H
#define  DisplayRootFile_H 

#include <iostream>
#include <vector>
#include <fstream>

#include <iostream>
#include <algorithm>
#include <numeric>
#include <assert.h>
#include <unordered_map>
#include <cmath>
#include <math.h> 
#include <unordered_set>
#include <filesystem>

#include <string>
#include <set>
#include <utility>
#include <iterator>

#include "TLeafObject.h"
#include "TTree.h"
#include "TH1F.h"
#include "TProfile.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TList.h"
#include "TROOT.h"
#include "TKey.h"
#include "TFile.h"
#include "TChain.h"
#include "TF2.h"
#include "TH3F.h"
#include "TEnv.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TString.h"

class DisplayRootFile {
public:
    
    TChain* ch ;
    

    std::vector<TString> availableKeys;
    TString compareToConst;
    
    DisplayRootFile();
    void Main_Func(std::string name_of_file);
    void fillInfo(const TString & fileName);
    char * FSTCA(std::string & name);
    char * From_String_To_Char_Array( std::string & name);
    bool is_file_exist(const char *fileName);
    void recursiveDisplayDirectoryFile(const TDirectoryFile & tdirfile, const Int_t layerDepth);
    // template <typename T> void Print_Value(T a);
    template <typename T> void Print_Value(T a, int new_lines = 1 );
};

#endif
