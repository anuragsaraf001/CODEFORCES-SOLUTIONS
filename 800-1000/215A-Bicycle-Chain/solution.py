n=int(input())
aList=list(map(int,input().split()))
m=int(input())
bList=list(map(int,input().split()))
maxGearRatio=-1
mydict={}
for i in aList:
    for j in bList:
        if j%i==0 :
            maxGearRatio=max(maxGearRatio,j//i)
            if j//i in mydict:
                mydict[j//i]+=1
            else:
                mydict[j//i]=1
print(mydict[maxGearRatio])           