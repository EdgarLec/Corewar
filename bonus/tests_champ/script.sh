#!/bin/bash

repo=/home/pleclercq/Projects/CPE-201/B-CPE-201-LIL-2-1-corewar-paulin.leclercq
test_path=$repo/bonus/tests_champ
champs=$repo/bonus/tests_champ/champs
champs_err=$repo/bonus/tests_champ/champs_err
asm_path=$repo/asm/asm
decomp_path=$repo/bonus/decompiler/decompiler

cd $test_path/results && find $champs -type f -name '*.s' -exec ./asm {} \;
cd $test_path/my_results && find $champs -type f -name '*.s' -exec $asm_path 2> $repo/out {} \;
cd $repo && printf '\033[0;31m' && diff --from-file=$test_path/results $test_path/my_results | grep differ
pygmentize -g out && rm out

cd $test_path/my_results_err && rm -f '*.cor' && find $champs_err -type f -name '*.s' -exec $asm_path 2> $repo/out {} \;
find -type f -name '*.cor' -exec echo {}: Failed \;
cd $repo && rm out

cd $test_path/decomp_test && find $test_path/results -type f -name '*.cor' -exec $decomp_path {} \;
cd $test_path/decomp_test && find -type f -name '*.s' -exec $asm_path {} \;
cd $repo && printf '\033[0;31m' && diff --from-file=$test_path/results $test_path/decomp_test | grep differ