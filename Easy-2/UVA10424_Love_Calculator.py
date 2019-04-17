import math
import sys

INF = 999999999999

def rl():
    return sys.stdin.readline().rstrip('\n')

def dr(n):
    return 1 + (n-1)%9 

def sumS(inp):
    res = 0
    for e in inp:
        if( 0 <= ord(e.lower()) - ord('a') <= 25):
           res += ord(e.lower()) - ord('a') + 1  
    return res
    
for line in sys.stdin:
    nextLine = rl()
    sumA = sumS(line)
    sumB = sumS(nextLine)
    res = min(round( (dr(sumB)/dr(sumA)) * 100,2) , round( (dr(sumA)/dr(sumB)) * 100,2))
    res = str(res)
    decimal = res.split('.')[1]
    if(len(decimal) == 1):
        res += '0'
    print(res,'%')
