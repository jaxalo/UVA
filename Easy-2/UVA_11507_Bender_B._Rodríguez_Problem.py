# I used this site https://pastebin.com/Dsjzc6CR

n = 0
yp =  [1, 2, 3, 0, 4, 5]
ym =  [3, 0, 1, 2, 4, 5]
zp =  [5, 1, 4, 3, 0, 2]
zm =  [4, 1, 5, 3, 2, 0]
pos = ["+x","+y","-x","-y","-z","+z"]

while (True):
    line = input().rstrip('\n')
    if(not(line) or int(line) == 0):
        break
    n = int(line)
    s = ''
    p = 0;
    ss = input().split()
    
    for s in ss:
        if (s == "+y"):
            p = yp[p]
        elif (s == "-y"): 
            p = ym[p]
        elif (s == "+z"): 
            p = zp[p]
        elif (s == "-z"): 
            p = zm[p]
    print(pos[p])


