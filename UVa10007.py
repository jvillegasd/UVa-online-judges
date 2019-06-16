"""
Todos los BST posibles con n nodos = Catalan(n) = C(2n, n)/(n + 1)
Todos los arboles binarios con n nodos = Catalan(n)*n!
"""
from sys import stdin
from sys import stdout

def c(n, k):
    ans = 1;
    if k>n-k: k=n-k;
    for i in range(k): 
        ans*=(n-i)
        ans//=(i+1)
    return ans

fact=[1]
for i in range(1, 310*3): fact.append(i*fact[-1])

while True:
    n = int(stdin.readline())
    if not n:
        break
    stdout.write("%d\n" % (c(2*n, n)//(n+1)*fact[n]))
