import sys

for line in sys.stdin:
    a,b = map(int,line.rstrip('\n').split())
    if(a < 0 or b < 0):
        break
    if(a > b):
        b,a = a,b
    opt1 = b - a
    opt2 = (100 - b) + (a - 0)
    print(min(opt1,opt2))
