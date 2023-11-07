#!/usr/bin/env python3
import os
from sys import argv
from os import system

vm_path = "../corewar/corewar"
ref_path = "../B-CPE-200_corewar_binaries/corewar_binaries/corewar/corewar"
chmp_dir_path = "../B-CPE-200_corewar_binaries/corewar_binaries/corewar/assets/champions"
error = 0
error_out = 0
answer = ""
begin_dump = 0
nb_dump = 0
champions = []

if len(argv) != 1:
    champions = [i for i in argv[1:]]

while True:
    try:
        answer = input('\033[95m' + "Do you want to clean the diff_logs directory? (y/n): " + '\033[0m')
    except EOFError:
        print()
        continue
    except KeyboardInterrupt:
        print()
        continue
    if answer == "y" or answer == "yes":
        os.system("rm diff_logs/diff_check*")
        break
    elif answer == "n" or answer == "no":
        break

if len(champions) == 0:
    while True:
        try:
            answer = input('\033[95m' + "Name the champions you want (end to finish): " + '\033[0m')
        except EOFError:
            print()
            continue
        except KeyboardInterrupt:
            print()
            continue
        if answer == "end":
            break
        champions.append(answer)

while True:
    try:
        begin_dump = input('\033[95m' + "Select a start dump number (enter for begin): " + '\033[0m')
    except EOFError:
        print()
        continue
    except KeyboardInterrupt:
        print()
        continue
    if begin_dump == "\n":
        break
    try:
        begin_dump = int(begin_dump)
        if begin_dump < 0:
            print("\033[91m" + "Please enter a valid number" + '\033[0m')
            continue
        break
    except ValueError:
        print("\033[91m" + "Please enter a valid number" + '\033[0m')

while True:
    try:
        nb_dump = input('\033[95m' + "How many dumps do you want to test? (0 to exit): " + '\033[0m')
    except EOFError:
        print()
        continue
    except KeyboardInterrupt:
        print()
        continue
    if nb_dump == "0":
        exit(0)
    try:
        nb_dump = int(nb_dump)
        if nb_dump < 0:
            print("\033[91m" + "Please enter a valid number" + '\033[0m')
            continue
        break
    except ValueError:
        print("\033[91m" + "Please enter a valid number" + '\033[0m')


for i in range(begin_dump, nb_dump):
    if len(argv) == 1:
        command_vm = vm_path + " "
        for j in range(len(champions)):
            command_vm += chmp_dir_path + "/" + champions[j] + ".cor "
        command_vm += "-dump " + str(i) + " 1>tmp_vm 2>tmp_vm_err"
        command_ref = ref_path + " "
        for j in range(len(champions)):
            command_ref += chmp_dir_path + "/" + champions[j] + ".cor "
        command_ref += "-dump " + str(i) + " 1>tmp_ref 2>tmp_ref_err"
        os.system(command_vm)
        os.system(command_ref)
    else:
        command_vm = vm_path + " "
        for j in range(len(champions)):
            command_vm += champions[j] + " "
        command_vm += "-dump " + str(i) + " 1>tmp_vm 2>tmp_vm_err"
        command_ref = ref_path + " "
        for j in range(len(champions)):
            command_ref += champions[j] + " "
        command_ref += "-dump " + str(i) + " 1>tmp_ref 2>tmp_ref_err"
        os.system(command_vm)
        os.system(command_ref)
    os.system("diff tmp_vm tmp_ref > diff_logs/diff_check" + str(i))
    os.system("diff tmp_vm_err tmp_ref_err > diff_logs/diff_check_err" + str(i))
    if open("diff_logs/diff_check" + str(i), "r").read() != "":
        print('\033[93m' + "diff detected on dump" + str(i) + '\033[0m')
        error = 1
    else:
        print('\033[96m' + "dump" + str(i) + " ok" + '\033[0m')
        os.system("rm diff_logs/diff_check" + str(i))

    if open("diff_logs/diff_check_err" + str(i), "r").read() != "":
        print('\033[93m' + "diff detected on dump error output" + str(i) + '\033[0m')
        error_out = 1
    else:
        os.system("rm diff_logs/diff_check_err" + str(i))

if error == 0:
    print('\033[92m' + "No diff detected")
    print("All tests passed!!" + '\033[0m')
if error_out == 1:
    print('\033[91m' + "Diff error output detected" + '\033[0m')
if error == 1:
    print('\033[91m' + "Diff detected")
    print("Diff logs are in diff_logs directory" + '\033[0m')


os.system("rm tmp_vm")
os.system("rm tmp_ref")
os.system("rm tmp_vm_err")
os.system("rm tmp_ref_err")
