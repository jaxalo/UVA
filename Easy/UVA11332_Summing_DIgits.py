import sys

for line in sys.stdin:
    if(int(line) == 0):
        break
    print(1 + (int(line) - 1)% 9)
