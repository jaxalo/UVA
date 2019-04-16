t = int(input())
for i in range(t):
    n = int(input())
    tab = list(map(int,input().split()))
    mile,juice = 0,0
    for e in tab:
        mile  += ((e//30) + 1) *10
        juice += ((e//60) + 1) *15
    res = 'Case ' + str(i+1) + ': '
    if(mile == juice):
        res += 'Mile Juice ' + str(mile)
    elif(mile < juice):
        res += 'Mile ' + str(mile)
    elif(mile > juice):
        res += 'Juice ' + str(juice)
    print(res)
