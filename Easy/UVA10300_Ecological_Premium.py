import sys

n = int(input())
for _ in range(n):
    nf = int(input())
    total = 0
    for i in range(nf):
        szFarm,nbAnimals,friend = map(int,input().split())
        total += (friend*szFarm) 
    print(total)
    
