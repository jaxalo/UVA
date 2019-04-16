import sys

ts = int(sys.stdin.readline().rstrip('\n'))
for t in range(ts):
    n = int(sys.stdin.readline().rstrip('\n'))
    line = sys.stdin.readline().rstrip('\n')
    js = list(map(int,line.split()))
    h,s = 0,0
    for i in range(1,n):
        if(js[i] > js[i-1]):
            h += 1
        elif(js[i] < js[i-1]):
            s += 1
    print('Case',str(t+1)+':',h,s)
