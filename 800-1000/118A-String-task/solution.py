s=input()
s=s.lower()
vowels={"a","o","y","e","u","i"}
res=[]
for i in s:
    if i not in vowels:
        res.append("." + i)
print("".join(res))