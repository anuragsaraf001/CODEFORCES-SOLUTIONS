n,m=map(int,input().split())
ticket=list(map(int,input().split()))
maxAmt,minAmt=0,0
ticket_copy=ticket.copy()
for i in range(n):
    if 0 in ticket_copy: ticket_copy.remove(0)
    
    maxi=max(ticket_copy)
    maxiInd=ticket_copy.index(maxi)
    maxAmt+=maxi
    ticket_copy[maxiInd]-=1
    
for i in range(n):
    if 0 in ticket: ticket.remove(0)
    
    mini=min(ticket)
    miniInd=ticket.index(mini)
    minAmt+=mini
    ticket[miniInd]-=1
    
print(maxAmt,minAmt,end=" ")