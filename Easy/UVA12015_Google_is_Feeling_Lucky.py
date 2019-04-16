

n = int(input())
for i in range(n):
    l = list()
    maxfreq = -1
    for _ in range(10):
        name,freq = map(str,input().split())
        freq = int(freq)
        l.append((name,freq))
        if(maxfreq < freq):
            maxfreq = freq
    print('Case #'+str(i+1)+':')
    for n,f in l:
        if(f == maxfreq):
            print(n)
