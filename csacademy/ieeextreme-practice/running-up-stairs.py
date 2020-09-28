from typing import List

NMAX : int = 22000 + 11

fib : List[int]  = (NMAX) * [0]
fib[0] = fib[1] = 1

for i in range(2, NMAX):
    fib[i] = fib[i - 1] + fib[i - 2]

t : int = int(input())

while (t):
    t -= 1
    n : int = int(input())
    print (fib[n])
