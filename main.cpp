#include "DisplayRootFile_H.h"
int main ( int argc ,char* argv[] ){
    // std::cout << "+I+\n";

    // path_to_files TTree_name increment Step eta_min eta_max LegendName
    // std::string input = argv[3];
    // std::string input_1 = argv[1];
    // std::string input_2 = argv[2];
    // int increment = std::stoi(argv[3]);
    // std::string input_3 = argv[4];
    // float upper_limit = std::stof(argv[5]);
    // float lower_limit = std::stof(argv[6]);
    // std::string input_4 = argv[7];

    // std::cout<<argc <<" \n";
    

    std::string name_of_file = argv[1];
    DisplayRootFile * h = new DisplayRootFile( );
    h->Main_Func(name_of_file);
    
    delete h;
    /**/
    // std::cout<<__cplusplus<<std::endl;
    return 0;
}