#include "Response_Control_H.h"
TChain* Response_vs_E_true::Set_Up_TChain(std::string path_to_files,std::string TTree_name){

    
    TChain * ch_p= new TChain(FSTCA(TTree_name));
    std::string str;
    std::ifstream infile ;
    // vector <string> paths_to_ttrees ;
    infile.open(FSTCA(path_to_files));
    while(!infile.eof()){
        getline(infile,str);
        // paths_to_ttrees.push_back(str);
        if(is_file_exist(FSTCA(str))){
            std::cout<<"FILE EXISTS: "<<str<<"\n\n";
            ch_p->Add(FSTCA(str));
        }
        else { std::cout<<"ERROR FILE DOES NOT EXIST: "<<str<<"\n\n"; 
        }
            
    }
    infile.close();
    return ch_p;
}
//  g++ -o ListB Response_Control.cxx `root-config --cflags --glibs`
//  ./ListB group.perf-jets.30761817._000001.tree.root
//  g++ -o ListB Response_Control.cxx `root-config --cflags --glibs`  &&  ./ListB group.perf-jets.30761817._000001.tree.root  
void Response_vs_E_true::Main_Func(std::string name_of_file){

    TFile * file = new TFile(FSTCA(name_of_file), "read");
    TList * f_objects = file->GetListOfKeys();  
    int N_objects = file->GetNkeys();
    
    // Print_Value(N_objects);
    std::vector <TKey*> TTree_vector;
    for(int i = 0 ; i < N_objects;i++){
        TKey* object = (TKey*) f_objects->At(i);
        // Print_Value( object->GetName());
        // Print_Value( object->ReadObj()->ClassName());
        std::string line = std::string(object->ReadObj()->ClassName())  +"  "+std::string(object->GetName());
        if(std::string(object->ReadObj()->ClassName()) == "TTree"){
            TTree_vector.push_back(object);
        }
        Print_Value(line);
        // Print_Value( object->ReadObj()->InheritsFrom("TTree"));
        
    }
    Print_Value("Branches for TTrees: ");
    for(int i = 0 ; i < TTree_vector.size();i++){
        TKey* object = TTree_vector.at(i);
        int N_branches = ((TTree*)object->ReadObj())->GetNbranches() ;
        int N_Entries = ((TTree*)object->ReadObj())->GetEntries() ;
        std::string line = std::to_string(i)+ " "+std::string(object->ReadObj()->GetName())+" Entries: "+std::to_string(N_Entries);
        std::string line2 = std::string(object->GetName());
        Print_Value(line);
        // Print_Value(line2);
        // TObjArray * B_List = ((TTree*)object)->GetListOfBranches();
        // Print_Value(  ((TTree*)object)->ReadObj()->GetNbranches() );
        // Print_Value(  ((TTree*)object->ReadObj())->GetEntries() );
        
        TObjArray * B_List = ((TTree*)object->ReadObj())->GetListOfBranches();
        TObjArray *leaves = ((TTree*)object->ReadObj())->GetListOfLeaves();


        for (int j =0 ; j < N_branches; j++){
            TLeafObject * leaf = (TLeafObject*) (leaves->At(j));
            std::string branch_line = "  "+std::to_string(j)+": "+std::string( B_List->At(j)->GetName())+" : "+ std::string(leaf->GetTypeName());
            Print_Value(branch_line);
            
            // std::cout<< ((TBranch*)(B_List->At(j)))->Class_Name()<<<<std::endl;           
            
            // TLeaf leaf = (TLeaf)(leaves->At(1));
            // TLeafObject leafobj;
            // leafobj = (TLeafObject)leaf;
            // Print_Value(leaf->GetTypeName());
        }
        // Print_Value(  ((TTree*)object->ReadObj())->GetListOfBranches() );
        // Print_Value(  ((TTree*)object)->GetListOfBranches()->GetName() );
        
    }  

    return ;
}

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
    Response_vs_E_true * h = new Response_vs_E_true( );
    h->Main_Func(name_of_file);
    
    delete h;
    /**/
    // std::cout<<__cplusplus<<std::endl;
    return 0;
}