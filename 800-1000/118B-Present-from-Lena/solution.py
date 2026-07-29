n=int(input())

for i in range(2*n+1):
    k=n-abs(n-i)
    row_nums=list(range(k+1))+list(range(k-1,-1,-1))
    leading_spaces="  "*(n-k)
    digits_str =" ".join(str(x) for x in row_nums)
    if leading_spaces:
        print(leading_spaces+digits_str)
    else:
        print(digits_str)