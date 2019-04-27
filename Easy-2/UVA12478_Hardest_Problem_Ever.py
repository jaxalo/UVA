import itertools

names = ['RAKIBUL', 'ANINDYA', 'MOSHIUR','SHIPLU' ,'KABIR' ,'SUNNY' ,'OBAIDA' ,'WASI']
grid = ['OBIDAIBKR','RKAULHISP','SADIYANNO','HEISAWHIA','IRAKIBULS','MFBINTRNO','UTOYZIFAH','LEBSYNUNE','EMOTIONAL']

search = ''
for vert in grid:
    search += vert

rev = [['' for _ in range(9)] for _ in range(9)]

for i in range(9):
    for j in range(9):
        rev[i][j] = grid[j][i]
        
for hor in rev:
    search += ''.join(hor)
    

for name in names:
    c = 0
    for perm in itertools.permutations(list(name)):
        c += search.count(''.join(perm))
    if(c == 2):
        print(name)
        break


