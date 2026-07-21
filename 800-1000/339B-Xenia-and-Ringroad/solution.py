n,m=map(int,input().split())
a_list=list(map(int,input().split()))
lastVisit=1 #the default house in which last stayed
ans=0
for a in a_list:
    if(a>lastVisit): 
        ans+=(a-lastVisit)
    elif(a<lastVisit): 
        ans+=((n-lastVisit)+a)
    lastVisit=a
print(ans)     