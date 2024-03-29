#include "DisplayRootFile_H.h"
//  g++ -o ListB Response_Control.cxx `root-config --cflags --glibs`
//  ./ListB group.perf-jets.30761817._000001.tree.root
//  g++ -o ListB Response_Control.cxx `root-config --cflags --glibs`  &&  ./ListB group.perf-jets.30761817._000001.tree.root  

void DisplayRootFile::recursiveDisplayDirectoryFile(const TDirectoryFile & tdirfile, const Int_t layerDepth = 1){
    return;
    std::cout<<"Sub directory: "<<tdirfile.GetName()<<'\n';
    TList * f_objects = tdirfile.GetListOfKeys();
    TObject * content= tdirfile.GetListOfKeys()->First();
    TObject * foundObject;
    tdirfile.Print();
    tdirfile.Print();
    tdirfile.Print();
    tdirfile.Print();
    while (content != f_objects->Last()){
        std::cout<<" "<<content->GetName()<<' '<<content->ClassName()<<' '<<"\n";
        // std::cout<<" "<<content->GetName()<<' '<<content->Class_Name()<<' '<<"\n";
        // content->Print();
        compareToConst = content->GetName();
        foundObject = tdirfile.FindObject(compareToConst.Data());
        if (foundObject)
            std::cout<<" "<<foundObject->GetName()<<' '<<foundObject->ClassName()<<' '<<"\n";
        else
            std::cout<<"Not found: "<<compareToConst.Data()<<"\n";
        // recursiveDisplayDirectoryFile(*(TDirectoryFile*)content, layerDepth+1);
        // TString objectNameTString(content->GetName());
        // availableKeys.push_back(objectNameTString);
        content = f_objects->After(content);
        std::cout<< (long long uint )content<<' '<< (long long uint )f_objects->Last()<<'\n';
    }

    return;
}

void DisplayRootFile::fillInfo(const TString & fileName){
    availableKeys.clear();

    std::unique_ptr<TFile> filePtr = std::make_unique<TFile>(fileName.Data(), "read");
    TList * objectsList = filePtr->GetListOfKeys();
    

    const TObject * objIter = nullptr;
    for(objIter= (TObject *)objectsList->First(); objIter != objectsList->Last(); objIter=objIter){
        compareToConst = objIter->GetName();
        availableKeys.push_back(compareToConst);
        std::cout<<" "<<objIter->GetName()<<" "<<objIter->ClassName()<< " "<<filePtr->Get(objIter->GetName())->ClassName() <<"\n";
        objIter = objectsList->After(objIter);

    }
    if (objIter){
        std::cout<<" "<<objIter->GetName()<<" "<<objIter->ClassName()<< " "<<filePtr->Get(objIter->GetName())->ClassName() <<"\n";
        compareToConst = objIter->GetName();
        availableKeys.push_back(compareToConst);
        std::cout<< filePtr->Get(objIter->GetName())->ClassName()<<'\n';
    }
    if( !(objectsList->First())->IsEqual((objectsList->Last())) ){
        std::cout<<"kek"<<'\n';
    }
    // do{

    // }
    // std::cout<< sizeof(*objectsList) / sizeof(*(objectsList->First()))<<'\n';

    std::cout<<"Total size is: "<< availableKeys.size()<<'\n';
    uint countObjects = 0;
    std::for_each(availableKeys.begin(), availableKeys.end(),
    [&countObjects](const TString & strIter){std::cout<<"  "<<++countObjects<<' '<< strIter.Data()<<'\n';});

    // void* objPtr = filePtr->Get(availableKeys[0]);
    // std::cout<< ((TObject*)objPtr)->ClassName()<<'\n';
    // compareToConst = (((TObject*)objPtr)->ClassName());
    // if ( !compareToConst.CompareTo("TDirectoryFile")){
    //     std::cout<<"found a dir\n";
    //     recursiveDisplayDirectoryFile(*(TDirectoryFile*) objPtr);
    // }
    return;
}
void DisplayRootFile::Main_Func(std::string name_of_file){

    TFile * file = new TFile(FSTCA(name_of_file), "read");
    TList * f_objects = file->GetListOfKeys();
    int N_objects = file->GetNkeys();

    // std::cout<<"List all file contents:"<<"\n";


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

DisplayRootFile::DisplayRootFile(){

}
// DisplayRootFile::~DisplayRootFile() {
//     std::coud<<"End of display.\n";
// }
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
