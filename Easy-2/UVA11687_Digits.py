import sys
import re

INF = 9999999999

#Doesn't pass in python I had to use c++ for this one

def rl():
    return sys.stdin.readline().rstrip('\n')

def nextL(x):
    return len(str(x))

for line in sys.stdin:
    if(line.rstrip('\n') == 'END'):
        print()
        break
    i = 1
    x = int(line)
    while(x != nextL(x)):
        i += 1
        x = nextL(x)
    print(i)
