#!/bin/bash
# filepath: /home/gbriel/push_augusto/test.sh

# Colors and formatting
BOLD='\033[1m'
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
LINED_BLUE='\033[4;34m'
RESET='\033[0m'

# Default values
tests=10
nbrs=100
min=-50
range=100
total_sorted=0
total_operations=0

# Handle command line arguments
if [ $# -ge 1 ]; then
    tests=$1
fi

if [ $# -ge 2 ]; then
    nbrs=$2
    range=$nbrs
    min=$((-range / 2))
fi

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
    
    valgrind_output=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes ./push_swap $combination 2>&1)
    leak_result=$(echo "$valgrind_output" | grep "All heap blocks were freed -- no leaks are possible")
    has_leaks=$(echo "$valgrind_output" | grep "definitely lost\|indirectly lost\|possibly lost\|still reachable" | grep -v "0 bytes")

    if [ "$result" = "OK" ] && [ -n "$leak_result" ] && [ -z "$has_leaks" ]
    then
        printf "${GREEN} [$result]${RESET} ($operations moves) "
        printf "${GREEN} [No leaks detected]${RESET}\n"
        total_sorted=$((total_sorted + 1))
    else
        printf "${RED} [$result]${RESET} ($operations moves) "
        if [ "$result" != "OK" ]; then
            printf "${RED}[Ordenação falhou]${RESET} "
        fi
        if [ -z "$leak_result" ] || [ -n "$has_leaks" ]; then
            printf "${RED}[Vazamentos detectados]${RESET}\n"
            
            leak_details=$(echo "$valgrind_output" | grep -A 2 "definitely lost\|indirectly lost\|possibly lost\|still reachable" | grep -v "0 bytes")
            if [ -n "$leak_details" ]; then
                printf "${RED}Detalhes do vazamento:${RESET}\n"
                echo "$leak_details"
                
                printf "${RED}Origem do vazamento:${RESET}\n"
                echo "$valgrind_output" | grep -A 3 "by 0x" | head -10
            fi
        else
            printf "\n"
        fi
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