lenMusics = 16
musics = [''] * lenMusics

musics[0] = 'Happy'
musics[1] = 'birthday'
musics[2] = 'to'
musics[3] = 'you'

musics[4] = 'Happy'
musics[5] = 'birthday'
musics[6] = 'to'
musics[7] = 'you'

musics[8] = 'Happy'
musics[9] = 'birthday'
musics[10] = 'to'
musics[11] = 'Rujia'


musics[12] = 'Happy'
musics[13] = 'birthday'
musics[14] = 'to'
musics[15] = 'you'


def sing(turn):
    for i in range(lenMusics):
        print(names[turn]+': '+musics[i])
        turn  = (turn  + 1) % n
    return turn

n = int(input())
names = [''] * n
for i in range(n):
    names[i] = input().rstrip('\n')

numberOfRep = (n//lenMusics) + 0 if (n%lenMusics == 0) else 1
dep = 0
for _ in range(numberOfRep+1):
    dep = sing(dep)


    
    
