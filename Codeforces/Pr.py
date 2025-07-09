import math

def runCase():
    n = int(input())
    s = input()
    cost = 0
    c = '0'
    for i in s:
        if(c==i):
            cost+=1
        else:
            c = i
            cost+=2
    flag = 0
    for i in range(n):
        if i>0 and s[i]=='1' and s[i-1]=='0' :
            flag=0
            cnt-=1
    print(cost)

t = int(input())
for i in range(t):
    print("Case #{}".format(i+1))
    runCase()