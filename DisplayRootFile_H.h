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

class DisplayRootFile {
public:
    
    TChain* ch ;
    


    
    DisplayRootFile();
    void Main_Func(std::string name_of_file);
    char * FSTCA(std::string & name);
    char * From_String_To_Char_Array( std::string & name);
    bool is_file_exist(const char *fileName);
    // template <typename T> void Print_Value(T a);
    template <typename T> void Print_Value(T a, int new_lines = 1 );
};
DisplayRootFile::DisplayRootFile(){

}
char * DisplayRootFile::From_String_To_Char_Array( std::string & name){
    char * char_name[500];
    for (int i =0; i < name.size();i++){
        //cout<<name.at(i);
        char_name[i] = & name.at(i);
    }
    
    return (*char_name);
}
char * DisplayRootFile::FSTCA(std::string & name){
    return From_String_To_Char_Array(  name);
}
bool DisplayRootFile::is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    // if (std::filesystem::exists(reweightHistFile.Data())){

    bool exists = infile.good();
    return exists;
}
// template <typename T>  void  DisplayRootFile::Print_Value(T a){
//     std::cout<<a<<'\n';
//     return;
// }
template <typename T>  void  DisplayRootFile::Print_Value(T a, int new_lines ){
    
    std::string n_l = "";
    for(int i =0 ; i< new_lines ; i ++)
        n_l+='\n';
    
    std::cout<<a<<n_l;
    return;
}
#endif
