import sys

n = int(input())
for t in range(n):
    blanck = input()
    row = int(input())
    p = [0] * row
    for i in range(row):
        a,b = map(int,input().split())
        p[i] = a - b
    print('yes' if len(set(p)) == 1 else 'no')
    if(t != n-1):
        print()
