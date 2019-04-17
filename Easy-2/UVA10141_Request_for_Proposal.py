import sys

INF = 999999999999

def rl():
    return sys.stdin.readline().rstrip('\n')
    
case = 0
for line in sys.stdin:
    case += 1
    n,p  = map(int,line.split())
    if(n == 0 and p == 0):
        break
    for _ in range(n):
        rl()
    
    candidates = [None] * p
    maxCompliance = -1
    
    for i in range(p):
        name = rl()
        price,nbRequirement = map(str,rl().split())
        price = float(price)
        nbRequirement = int(nbRequirement)
        for _ in range(nbRequirement):
            rl()
        candidates[i] = (nbRequirement/p,price,name)
        maxCompliance = max(maxCompliance,nbRequirement/p)

    #MaxCompliance
    selectedCandidates = []
    minPrice = INF 
    for i in range(p):
        if(maxCompliance == candidates[i][0]):
            selectedCandidates.append(candidates[i])
            minPrice = min(minPrice,candidates[i][1])
    
    #MinPrice since it is ordered by input we only need the first
    #one
    for i in range(len(selectedCandidates)):
        if(minPrice ==  selectedCandidates[i][1]):
             #Answer
             if(case != 1):
                 print()
             print('RFP #'+str(case))
             print(selectedCandidates[i][2])
             break
