lis = [3,5,8,15,19,25]
target = 5

print(lis)


low = 0
high = len(lis)

while low <= high:
    mid = (low+high)//2

    if(lis[mid] >= target):
        ans = mid
        high = mid - 1
    else:
        low = mid +1 

lis.insert(ans,target)

def ar(l,t,p):
    x = l[p]
    for i in range(p , len(l)-1):
        l[p]
    temp = []
    for i in 

print(lis)
