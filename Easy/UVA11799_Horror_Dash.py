

n = int(input())
for i in range(n):
    line = input()
    print('Case',str(i+1)+':',max(map(int,line.split())))
