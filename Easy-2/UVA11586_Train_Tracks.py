n = int(input())
for _ in range(n):
    tracks = ''.join(list(map(str,input().split())))
    m = tracks.count('M')
    f = tracks.count('F')
    print('LOOP' if (m == f and len(tracks) >= 4) else 'NO LOOP')
    
