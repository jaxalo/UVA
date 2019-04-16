import sys


for line in sys.stdin:
    h,u,d,f = map(int,line.split())
    if(h == 0):
        break
    
    day = 0
    curh = 0
    curu = u
    degrade = u * (f/100)
    
    while(True):
        day += 1
        curh += curu
        #day
        if(curh > h):
            break
        
        #night
        curh -= d
        if(0 > curh):
            break
        curu -= degrade
        if(curu < 0):
            curu = 0
     

    #Answer
    if(curh > h):
        print('success on day',day)
    else:
        print('failure on day',day)
    

