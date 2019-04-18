import sys
import re

INF = 9999999999

def rl():
    return sys.stdin.readline().rstrip('\n')


for line in sys.stdin:
    if(len(line.split()) != 2):
        break
    h,w = map(int,line.split())
    rep = 0
    cur = 0
    tab = list(map(int,rl().split()))
    
    for x in range(len(tab)):
        if(x == 0):
            rep = h - tab[x]
            cur = tab[x]
        else:
            if(tab[x] < cur):
               rep = rep + (cur - tab[x])
        cur = tab[x]
    print(rep)

