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
