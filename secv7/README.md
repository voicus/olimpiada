# secv7
https://www.infoarena.ro/problema/secv7

given n and a sequence of n numbers a1,a2,...,an; we can pick two indexes i,j and calculate X,Y,Z:

X = max { Ak | 1 ≤ k ≤ i },
Y = max { Ak | i+1 ≤ k ≤ j }, 
Z = max { Ak | j+1 ≤ k ≤ N }
and S = X + Y + Z.
Find the indexes i,j for which S is minimal.
Print S on the first line and i,j on the next line.

example:
for input 
7
3 2 1 5 6 3 2
output will be
10
2 3
