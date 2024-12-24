ARG=$(shuf -i 1-300 -n 300 | tr '\n' ' ')

time ./push_swap $ARG | ./checker_linux $ARG