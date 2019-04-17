import math
import sys

INF = 999999999999

def rl():
    return sys.stdin.readline().rstrip('\n')

for line in sys.stdin:
    if(len(line.split()) == 1):
        break
    k,m = map(int,line.split())
    mike = set(map(str,rl().split()))
    solve = True
    for _ in range(m):
        temp = list(map(str,rl().split()))
        minToTake = int(temp[1])
        courses = temp[2::]
        count = 0
        for course in courses:
            if(course in mike):
                count +=1
        if(count < minToTake):
            solve = False
    print('yes' if solve else 'no')
