<div align="center">
  <a href="https://github.com/Gbriel70/born2beroot" target="_blank"><img height=100 src="https://github.com/byaliego/42-project-badges/raw/main/badges/push_swap.png"></a>
</div>

# push_swap

This project is a solution to a challenge from the 42 School. The goal is to develop a program that receives x numbers and returns the minimum number of moves required to sort them. The solution must use only one auxiliary stack and a specific set of allowed operations.

## moves

| Code  | Operation                           | Action                                                  |
| ----- | ----------------------------------- | ------------------------------------------------------- |
| `sa`  | swap a                              | swaps the first 2 elements at the top of stack a        |
| `sb`  | swap b                              | swaps the first 2 elements at the top of stack b        |
| `ss`  | swap a + swap b                     | `sa` and `sb` at the same time                          |
| `pa`  | push a                              | puts the first element of stack b at the top of stack a |
| `pb`  | push b                              | puts the first element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts up all elements of stack a by 1                  |
| `rb`  | rotate b                            | shifts up all elements of stack b by 1                  |
| `rr`  | rotate a + rotate b                 | `ra` and `rb` at the same time                          |
| `rra` | reverse rotate a                    | shifts down all elements of stack a by 1                |
| `rrb` | reverse rotate b                    | shifts down all elements of stack b by 1                |
| `rrr` | reverse rotate a + reverse rotate b | `rra` and `rrb` at the same time                        |

# How did I solve

I spent a considerable amount of time researching algorithms to solve this problem, which took several days. During this process, I came across various solutions, such as Radix Sort, Quicksort, Merge Sort, and even implementations combining multiple algorithms. However, my goal was to achieve the maximum score for the project.

After extensive research, I found an article about an algorithm called Turk Sort, which is not exactly a conventional algorithm, as it was specifically designed to address this type of problem. I recommend reading the article [Turk_sort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) to better understand what I am referring to.

# How I implemented

My implementation works as follows:  

1. **Process the arguments**  
   After processing all the received arguments, the first step is to transfer all the elements from **stack A** to **stack B**, except for the last three items.  

2. **Sort the last three numbers in stack A**  
   The remaining three numbers in **stack A** are sorted. This is important because when moving the numbers from **stack B** back to **stack A**, these three elements will serve as a reference.  

3. **Identify the cheapest number in stack B**  
   The next step is to analyze which number in **stack B** is the "cheapest" to move to **stack A**, meaning the one that requires the least number of moves.  

4. **Move the identified number to stack A**  
   The "cheapest" number is moved to **stack A**.  

5. **Repeat until stack B is empty**  
   The process of analysis and movement is repeated until there are no more items left in **stack B**.  

---

# Flow visualization

I used it to visualize the execution of the program [visualizer](https://github.com/o-reo/push_swap_visualizer)

# How use

```sh
    git clone https://github.com/Gbriel70/push_swap.git
```

```sh
    make
```
```
$>./push_swap <random numbers that will be the input>

    show operations here
```
```
$>./push_swap <random numbers that will be the input> | wc -l
    
    shows quantity of movements
```

# My tester

**basically my tester runs the program the amount entered by the user and checks if during execution there is a memory leak with valgrind**

1. Copy or clone the script in [My Tester](https://github.com/Gbriel70/push_swap/blob/main/try_do_my_tests/test.sh)

2. execute permission with the command chmod +x **program**

# Use exemple

```
gbiel@clovis:~/projeto_push_swap/push_swap$ ./try_do_my_tests/test.sh 10 200

--------------------------------------------------
      PUSH SWAP TESTER: Sorting 200 numbers
--------------------------------------------------

Test 1. [OK] (1478 moves)  [No Leaks detected]
Test 2. [OK] (1424 moves)  [No Leaks detected]
Test 3. [OK] (1448 moves)  [No Leaks detected]
Test 4. [OK] (1461 moves)  [No Leaks detected]
Test 5. [OK] (1598 moves)  [No Leaks detected]
Test 6. [OK] (1543 moves)  [No Leaks detected]
Test 7. [OK] (1463 moves)  [No Leaks detected]
Test 8. [OK] (1452 moves)  [No Leaks detected]
Test 9. [OK] (1413 moves)  [No Leaks detected]
Test 10. [OK] (1475 moves)  [No Leaks detected]

----Results----
OK: [10/10]
Avg moves: 1475

```

# Bonus Part

The bonus part basically requires you to create your own program checker.

```sh
    make bonus
```
```
    ./push_swap <numbers> | ./checker <same numbers>
```
