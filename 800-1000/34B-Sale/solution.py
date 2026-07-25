n,m=map(int,input().split())
price=list(map(int,input().split()))
totalEarn=0
totalTv=0
while (totalTv<m):
    minPrice=min(price)
    if(minPrice<0): 
        totalEarn+=minPrice
        totalTv+=1
        price.remove(minPrice)
    else:
        break
print(totalEarn*-1)
    