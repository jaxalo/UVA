import sys

case = 0

for line in sys.stdin:
    case += 1
    n,m,c = map(int,line.split())
    if(n == 0 and m == 0 and  c == 0):
        break
    
    
    
    capa = [0] * n
    opened = [0] * n
    
    for i in range(n):
        capa[i] = int(sys.stdin.readline().rstrip('\n'))
    curPow = 0
    maxPow = -1
    solved = False
    
    for _ in range(m):
        power =  int(sys.stdin.readline().rstrip('\n'))
        if(opened[power - 1] == 1):
            curPow -= capa[power - 1]
            opened[power - 1] = 1 - opened[power - 1]
        else:
            curPow += capa[power - 1]
            maxPow = max(maxPow,curPow)
            opened[power - 1] = 1 - opened[power - 1]
            
        if(curPow > c):
            solved = True
        

    if(not(solved)):
        print('Sequence',case)
        print('Fuse was not blown.')
        print('Maximal power consumption was',maxPow,'amperes.')
        print()
    else:
        print('Sequence',case)
        print('Fuse was blown.')
        print()
