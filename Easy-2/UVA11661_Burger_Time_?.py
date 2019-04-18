import sys
import re

INF = 9999999999

def rl():
    return sys.stdin.readline().rstrip('\n')

def findrightMostSym(dep,sym):
    last = dep
    for i in range(dep+1,len(road)):
        if( (road[i] == 'R' and  sym == 'R') or (road[i] == 'D' and  sym == 'D') ):
            last = i
        if( (road[i] == 'R' and  sym == 'D') or (road[i] == 'D' and  sym == 'R') ):
            break
    return last

def findCompSym(dep,sym):
    for i in range(dep+1,len(road)):
        if( (road[i] == 'R' and  sym == 'D') or (road[i] == 'D' and  sym == 'R') ):
            return i
    return -1

for line in sys.stdin:
    n = int(line)
    if(n == 0):
        break
    road = rl()
    if('Z' in road):
        print(0)
    else:
        minDistance = INF
        i = 0
        while i < n:
            if(road[i] != '.'):
                indexRightMostSym = findrightMostSym(i,road[i])
                indexCompSym = findCompSym(indexRightMostSym,road[i])
                if(indexCompSym == -1):
                    break
                else:
                    minDistance = min(minDistance,indexCompSym - indexRightMostSym)
                    i = indexCompSym
            else:
                i += 1
        print(minDistance)
