#!/bin/bash

GREEN="\033[32m"
RED="\033[0;31m"
BOLD="\033[1m"
LINED_BLUE="\e[4;96m"
RESET="\033[0m"

# input: number of tests
tests=$1

# input: number of random numbers in each combination
nbrs=$2

# Range of random numbers
min=-2147483648
max=2147483647
range=$((max - min + 1))

# Variable to count successful sorts
total_sorted=0
total_operations=0

printf "\n${BOLD}--------------------------------------------------${RESET}"
printf "\n${BOLD}      PUSH SWAP TESTER: Sorting ${LINED_BLUE}$nbrs${RESET} ${BOLD}numbers${RESET}"
printf "\n${BOLD}--------------------------------------------------\n\n${RESET}"

for ((i=1; i<=tests; i++))
do

    combination=""
    random_numbers=$(shuf -i 0-$range -n $nbrs)
    for number in $random_numbers
    do
        actual_number=$((number + min))
        combination="$combination $actual_number"
    done

    result=$(./push_swap $combination | ./checker_linux $combination)
    operations=$(./push_swap $combination | wc -l)
    printf "${BOLD}Test $i.${RESET}"
    leak_result=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes ./push_swap $combination 2>&1 | grep "All heap blocks were freed -- no leaks are possible")

    if [ "$result" = "OK" ] && [ -n "$leak_result" ]
    then
        printf "${GREEN} [$result]${RESET} ($operations moves) "
        printf "${GREEN} [No leaks detected]${RESET}\n"
        total_sorted=$((total_sorted + 1))
    else
        printf "${RED} [$result]${RESET} ($operations moves) "
        printf "${RED} [Leaks detected]${RESET}\n"
    fi

    total_operations=$((total_operations + operations))

done

printf "\n${BOLD}----Results----\n"
if [ $total_sorted -eq $tests ]
then
    printf "OK: ${GREEN}[$total_sorted/$tests]${RESET}\n"
else
    printf "KO: ${RED}[$total_sorted/$tests]${RESET}\n"
fi

# Calculate the average number of operations
average_operations=$((total_operations / tests))
printf "Avg moves: $average_operations\n"