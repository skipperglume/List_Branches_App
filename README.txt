Compile the cpp code with root libs via line:
g++ -o ListB Response_Control.cxx `root-config --cflags --glibs`

Run the code with:
./ListB PATH_TO_ROOT_FILE

Code to install in .bashrc (or other shell profile)
PATH_TO_LISTB_CODE - is directory where you cloned code from git
If some errors concerning libraries or dependencies, uncomment in first half of function
function ListT(){
	PATH_TO_LISTB_CODE="/afs/cern.ch/work/d/dtimoshy/List_Branches_App/"
    
    # if [ "$(which root)" != "/cvmfs/sft.cern.ch/lcg/releases/LCG_102/ROOT/6.26.04/x86_64-centos7-gcc11-opt/bin/root" ]; then
    #     # echo "Dependencies are UNFIT"
    #     setupATLAS
    #     lsetup "root 6.26.04-x86_64-centos7-gcc11-opt"
    # # else 
    #     # echo "Dependencies are Ok"
    # fi
    
    
    if [[ -f "${PATH_TO_LISTB_CODE}ListB" ]]; then
        
        ${PATH_TO_LISTB_CODE}ListB $1
        # echo "g++ is NOT NEEDED"
    else 
        cd $PATH_TO_LISTB_CODE
        g++ -o ListB Response_Control.cxx `root-config --cflags --glibs`
        cd -
        ${PATH_TO_LISTB_CODE}ListB $1
        # echo "g++ is NEEDED"
    fi
	# echo "${PATH_TO_LISTB_CODE}ListB"

}