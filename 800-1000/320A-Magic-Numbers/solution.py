n=int(input())
lst=list(str(n))
i=0
while i<len(lst):
    if lst[i]=='1' and i+2<len(lst) and lst[i+1]=='4' and lst[i+2]=='4':
        lst[i]='144'
        lst[i+1]=''
        lst[i+2]=''
        i=i+3
    elif lst[i]=='1' and i+1<len(lst) and lst[i+1]=='4' :
        lst[i]='14'
        lst[i+1]=''
        i=i+2
    else : i+=1

isMagic=True
for a in lst:
    if a not in ['','1','14','144']:
        isMagic=False
        break
print("YES" if isMagic else "NO")
    