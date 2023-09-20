# Waiter

## Description

You are a waiter at a party. There is a pile of numbered plates. Create an empty _answers_ array. At each iteration, _i_, remove each plate from the top of the stack in order. Determine if the number on the plate is evenly divisible by the $i^th$ prime number. If it is, stack it in pile $B_i$. Otherwise, stack it in stack $A_i$. Store the values in $B_i$ from top to bottom in _answers_. In the next iteration, do the same with the values in stack $A_i$. Once the required number of iterations is complete, store the remaining values in $A_i$ in _answers_, again from top to bottom. Return the _answers_ array. 

## Returns

- int[n]: the numbers on the plates after processing

## Input

- The first line contains two space-separated integers, _n_ and _q_.
- The next line contains _n_ space-separated integers representing the initial pile of plates, i.e., _A_. 
