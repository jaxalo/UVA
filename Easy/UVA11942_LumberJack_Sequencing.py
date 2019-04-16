n = int(input())
print('Lumberjacks:')
for i in range(n):
    tab = list(map(int,input().split()))
    print('Ordered' if tab == sorted(tab) or tab == sorted(tab,reverse = True) else 'Unordered')
