#!/usr/bin/env python3
import os
from sys import argv
import random

final_tree = ""


def ask_for_champs_dir(main_class):
    while True:
        try:
            answer = input('\033[95m' + "Select a directory path: " + '\033[0m')
            if answer == "":
                continue
            if answer == "exit":
                exit()
            main_class.champ_dir = answer
            break
        except EOFError:
            print()
            continue
        except KeyboardInterrupt:
            print()
            continue


def ask_for_vm_path(main_class):
    while True:
        try:
            answer = input('\033[95m' + "Select a vm path: " + '\033[0m')
            if answer == "":
                continue
            if answer == "exit":
                exit()
            try:
                open(answer)
                main_class.vm_path = answer
                print("\033[92m" + "vm found" + "\033[0m")
                break
            except FileNotFoundError:
                print("\033[91m" + "vm not found" + "\033[0m")
                continue
        except EOFError:
            print()
            continue
        except KeyboardInterrupt:
            print()
            continue


def recup_champions(path, main_class):
    try:
        for file in os.listdir(path):
            if file.endswith(".cor"):
                main_class.champions.append(file)
    except FileNotFoundError:
        print("\033[91m" + "Directory not found" + "\033[0m")
        ask_for_champs_dir(main)
        recup_champions(main.champ_dir, main)


def look_for_winner(nb_phase, chmp_one, chmp_two):
    winner = ""
    index = 1
    nb_chmp = 0
    with open("tmp_tournament/phase" + str(nb_phase) + "/" + chmp_one + "_vs_" + chmp_two) as f:
        for line in f:
            if line.startswith("Le joueur") and line.endswith(" a gagné.\n"):
                while line[index - 1] != "(":
                    index += 1
                while line[index] != ")":
                    winner += line[index]
                    index += 1
                nb_chmp = int(line.split(" ")[2])
                print("\033[92m" + "Winner: " + winner + "\033[0m")
                break
    return nb_chmp


class main(object):
    def __init__(self):
        self.champions = []
        self.next_turn = []
        self.nb_phase = 0
        self.vm_path = ""
        self.champ_dir = ""
        self.phases = {}

    def match_loop(self):
        len_champ = len(self.champions)
        champ_one = ""
        champ_two = ""
        nb_match = 0
        self.phases[self.nb_phase] = []
        print("\033[96m" + "---> Phase " + str(self.nb_phase) + " <---" + "\033[0m")
        os.system("mkdir tmp_tournament/phase" + str(self.nb_phase))
        if self.nb_phase != 0:
            os.system("mv tmp_tournament/phase" + str(self.nb_phase - 1) + " tmp_tournament/phase" + str(self.nb_phase))
        for _ in range(int(len_champ / 2)):
            champ_one = self.champions.pop(0)
            champ_two = self.champions.pop(0)
            self.phases[self.nb_phase].append(champ_one)
            self.phases[self.nb_phase].append(champ_two)
            print("\033[94m" + "Match " + str(_) + ": " + champ_one + " vs " + champ_two + "\033[0m")
            os.system(
                self.vm_path + " " + self.champ_dir + "/" + champ_one + " " + self.champ_dir + "/" + champ_two + " > tmp_tournament/phase" + str(self.nb_phase) + "/" + champ_one + "_vs_" + champ_two)
            if look_for_winner(self.nb_phase, champ_one, champ_two) == 1:
                self.next_turn.append(champ_one)
            else:
                self.next_turn.append(champ_two)
            nb_match = _
        nb_match += 1
        if len(self.champions) > 0:
            champ_one = self.champions.pop(0)
            champ_two = self.next_turn.pop(-1)
            self.phases[self.nb_phase].append(champ_one)
            print("\033[94m" + "Match " + str(nb_match) + ": " + champ_one + " vs " + champ_two + "\033[0m")
            os.system(
                self.vm_path + " " + self.champ_dir + "/" + champ_one + " " + self.champ_dir + "/" + champ_two + " > tmp_tournament/phase" + str(self.nb_phase) + "/" + champ_one + "_vs_" + champ_two)
            if look_for_winner(self.nb_phase, champ_one, champ_two) == 1:
                self.next_turn.append(champ_one)
            else:
                self.next_turn.append(champ_two)
        self.champions = self.next_turn
        self.next_turn = []
        self.nb_phase += 1


if __name__ == "__main__":
    main = main()
    try:
        os.mkdir("tmp_tournament")
    except FileExistsError:
        os.system("rm -rf tmp_tournament")
        os.mkdir("tmp_tournament")
    try:
        recup_champions(argv[1], main)
        main.champ_dir = argv[1]
    except IndexError:
        ask_for_champs_dir(main)
        recup_champions(main.champ_dir, main)
    ask_for_vm_path(main)
    if len(main.champions) < 2:
        print("\033[91m" + "Not enough champions" + "\033[0m")
        exit()
    main.champions.pop(0)
    random.shuffle(main.champions)
    while len(main.champions) > 1:
        main.match_loop()
    print()
    print("\033[92m" + "Tournament Winner: " + main.champions[0] + "\033[0m")
    os.system("tree tmp_tournament")
