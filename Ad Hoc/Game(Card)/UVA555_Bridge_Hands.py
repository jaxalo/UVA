import sys

#Read input
#each card are in an array of 2 cells (suits and height)
#sort them using predicates
#display

def rl():
    return sys.stdin.readline().rstrip('\n')


def getDealer(dealer):
    if(dealer == "S"):
        return 0
    elif(dealer == "W"):
        return 1
    elif(dealer == "N"):
        return 2
    elif(dealer == "E"):
        return 3

def getName(index):
    if(index == 0):
        return "S"
    elif(index == 1):
        return "W"
    elif(index == 2):
        return "N"
    elif(index == 3):
        return "E"

def suit(card):
    if(card[0] == "C"):
        return 0
    elif(card[0] == "D"):
        return 1
    elif(card[0] == "S"):
        return 2
    elif(card[0] == "H"):
        return 3

def height(card):
    if(card[1] == "J"):
        return 11
    elif(card[1] == "Q"):
        return 12
    elif(card[1] == "K"):
        return 13
    if(card[1] == "A"):
        return 14
    if(card[1] == 'T'):
        return 10
    else:
        return int(card[1])


for line in sys.stdin:
    if(line.rstrip('\n') == '#'):
        break
    else:
        dealer = line.rstrip('\n')
        index = getDealer(dealer)
        deck = rl() + rl()
        players = [['' for _ in range(13)] for _ in range(4)]
        dep = dealer
        count = 0
        for i in range(52):
            players[(i + index + 1)%4][i%13] = deck[count:count+2]
            count += 2
        for player in players:
            player.sort(key=lambda x: (suit(x), height(x)))
        for i in range(4):
            res = getName(i)+': ' + ' '.join(players[getDealer(getName(i))])
            print(res)
