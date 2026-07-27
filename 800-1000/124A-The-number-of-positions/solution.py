n,a,b=map(int,input().split())
noOfPositions=0
currPos=-1
front=-1
for i in range(b+1):
    currPos=n-i
    front=n-i-1
    if(front>=a): noOfPositions+=1
print(noOfPositions)   
    