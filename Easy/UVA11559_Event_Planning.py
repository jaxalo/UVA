import sys

INF = 99999999

for line in sys.stdin:
    n,b,h,w = map(int,line.split())
    #print("line ",line)
    minTotalCost = INF
    for i_h in range(h):
        line = sys.stdin.readline().rstrip('\n')
        #print("line 2 : ",line)
        person = int(line)
        line = sys.stdin.readline().rstrip('\n')
        #print("line 3 : ",line)
        ws = list(map(int,line.split()))
        
        #Enough place in hotel
        moreThanN = False
        for e in ws:
            if(e >= n):
                moreThanN = True
                break
        
        #If it is the case
        if(moreThanN):
            totalCost = n * person
            if(totalCost <= b and totalCost < minTotalCost):
                minTotalCost = totalCost
        
    #Answer
    print(minTotalCost if minTotalCost != INF else 'stay home')
        
        
    
