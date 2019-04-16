t = int(input())
for _ in range(t):
    n = int(input())
    moves = [0] * n
    for i in range(n):
        move = input()
        if(move == 'LEFT'):
            moves[i] = -1
        elif(move == 'RIGHT'):
            moves[i] = 1
        else:
            words = move.split()
            moves[i] = moves[int(words[-1]) - 1]
    print(sum(moves))
