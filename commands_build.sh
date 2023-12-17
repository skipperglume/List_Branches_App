# setupATLAS
# lsetup "root 6.26.04-x86_64-centos7-gcc11-opt"
# echo $ROOTSYS

ROOT_FILE_TEST='/eos/user/d/dtimoshy/MC23_CSSKUFO/MC23c/MC23c_801165/__reweighted__user.dtimoshy.35492237._000009.tree.root'
ROOT_FILE_TEST='/eos/atlas/atlascerngroupdisk/perf-jets/JETDEF/MC23_SmallR_UFO_7GeV/user.dtimoshy.801165.MC23aIJTR30v01_CSSKUFO_121223_tree.root/user.dtimoshy.35989255._000009.tree.root'
ROOT_FILE_TEST='../plots.root'
rm -rf ./* && cmake ../ && make && ./Dsply ${ROOT_FILE_TEST}
