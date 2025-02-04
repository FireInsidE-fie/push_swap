#!/bin/sh

echo "[!] - Recompiling..."

make re

echo "[!] - Beginning invalid syntax checks..."

read -r meh

valgrind --leak-check=full ./push_swap
valgrind --leak-check=full ./push_swap 42
valgrind --leak-check=full ./push_swap 42 42
valgrind --leak-check=full ./push_swap 42 43

echo "[!] - Beginning checks for 2 elements..."

read -r meh

valgrind --leak-check=full ./push_swap "42 -42"
valgrind --leak-check=full ./push_swap "-42 42"

echo "[!] - Beginning checks for 3 elements..."

read -r meh

valgrind --leak-check=full ./push_swap "42 -42 66"
valgrind --leak-check=full ./push_swap "-42 66 42"
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 3` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG

echo "[!] - Beginning checks for 5 elements..."

read -r meh

valgrind --leak-check=full ./push_swap "42 -42 66 877 233"
valgrind --leak-check=full ./push_swap "-42 66 42 899 123"
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 5` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG

echo "[!] - Beginning checks for 100 elements..."

read -r meh

ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 100` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG

echo "[!] - Beginning checks for 500 elements..."

read -r meh

ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
ARG=`shuf -i 0-100000 -n 500` && valgrind --leak-check=full ./push_swap $ARG | ./checkers/checker_linux $ARG
