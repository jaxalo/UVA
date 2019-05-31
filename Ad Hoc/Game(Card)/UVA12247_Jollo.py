import sys
import itertools


def rl():
    return sys.stdin.readline().rstrip('\n')


def rn():
    return list(map(int, sys.stdin.readline().split()))


def solve(hand):
    # Test all value of cards in order
    poss_card = [i for i in range(1, 53)]
    for card in hand:
        poss_card.remove(card)

    # for each hand run simulations until you found one where the prince always win
    for poss in poss_card:
        res = simulate(poss, hand)
        if res:
            print(poss)
            return
    print(-1)


def simulate(poss, hand):
    princess = hand[0:3:1]
    prince = hand[3::1]
    prince.append(poss)
    count = 0
    for hand1 in itertools.permutations(princess):
        for hand2 in itertools.permutations(prince):
            count += matchk(hand1, hand2)
            if count <= 1:
                return False
            else:
                 count = 0
    return True


def matchk(hand1, hand2):
    count = 0
    for i in range(3):
        count += 1 if hand2[i] > hand1[i] else 0
    return count


if __name__ == '__main__':
    for line in sys.stdin:
        if line[0] == '0':
            break
        hand = [int(e) for e in line.split()]
        solve(hand)

