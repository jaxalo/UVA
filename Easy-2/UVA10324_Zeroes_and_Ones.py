import sys

INF = 999999999999

def rl():
    return sys.stdin.readline().rstrip('\n')
    
case = 0
for line in sys.stdin:
    case += 1
    if(not(line.rstrip('\n'))):
        break

    inp = list(line.rstrip('\n')) + [-1]
    n = int(rl())
    
    depChar = inp[0]
    depIndex = 0
    endIndex = 0
    maxBound = [0]*len(inp)
    
    for i in range(1,len(inp)):
        endIndex = i
        if(depChar != inp[i]):
            for k in range(depIndex,endIndex):
                maxBound[k] = endIndex - 1
            depIndex = endIndex
            depChar = inp[i]
    
    #print(inp)
    #print(maxBound)
            
            
            
    print('Case '+str(case)+':')
    for _ in range(n):
        i,j = map(int,input().split())
        mini = min(i,j)
        maxi = max(i,j)
        if(mini == maxi or mini >= len(inp)-2):
            print('Yes')
        else:
           if(maxBound[mini] >= maxi):
               print('Yes')
           else:
               print('No')
