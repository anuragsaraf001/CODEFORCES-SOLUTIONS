s=input()
t=input()
ans=True
if len(s)!=len(t):
    ans=False
else:
    i=0
    j=len(t)-1
    while i<len(s):
        if(s[i]!=t[j]):
            ans=False
            break
        else: 
            i+=1
            j-=1
print("YES" if ans else "NO")