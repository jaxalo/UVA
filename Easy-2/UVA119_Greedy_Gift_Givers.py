import sys
import math

entered = False

for line in sys.stdin:
    n = int(line)
    line = sys.stdin.readline().rstrip('\n')
    names = list(map(str,line.split()))
    #Init scores
    scores = [0] * n 
    #Fill names <-> index
    dic = dict()
    for i in range(n):
        dic[names[i]] = i
    #Give and send gift
    for i in range(n):
        line = sys.stdin.readline().rstrip('\n')
        temp = list(map(str,line.split()))
        name = temp[0]
        give = int(temp[1])
        nbReceivers = int(temp[2])
        if(nbReceivers > 0):
            per = int(give/nbReceivers) 
            scores[dic[name]] -= int(per * nbReceivers) 
            receivers = temp[3::]
            for receiver in receivers:
                scores[dic[receiver]] += int(give/nbReceivers)
    #Answer
    #Presentation
    if(entered):
        print()
    #The real answer
    for i in range(n):
        print(names[i],scores[i])
    entered = True
    
