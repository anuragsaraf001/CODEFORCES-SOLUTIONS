# B. Airport - Codeforces 218B

- **Platform:** Codeforces
- **Problem Link:** [218B - Airport](https://codeforces.com/problemset/problem/218/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Greedy`, `Implementation`, `Sorting`
- **Language:** Python

---

## 📌 Problem Statement

There are $n$ passengers in line to buy plane tickets and $m$ planes. The $i$-th plane initially has $a_i$ empty seats. 

When a passenger buys a ticket for a plane with $x$ empty seats ($x > 0$), the ticket costs $x$ zlotys, and the number of empty seats on that plane decreases by $1$.

Calculate the **maximum** and **minimum** total zlotys the airport can earn after selling tickets to all $n$ passengers.

---

## 💡 Key Intuition & Approach

### 1. Maximum Earnings Strategy
To maximize total money earned, passengers should always choose the plane that currently has the **maximum number of empty seats**:
- In each turn, find the plane with the highest seat count, add its seat count to `maxAmt`, and decrement that plane's empty seat count by 1.

### 2. Minimum Earnings Strategy
To minimize total money earned, passengers should always choose the plane with the **fewest non-zero empty seats**:
- In each turn, remove planes with $0$ empty seats, select the plane with the smallest remaining seat count, add it to `minAmt`, and decrement its seat count by 1.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\\mathcal{O}(n \\cdot m)$ — For each of the $n$ passengers, finding the `max()` or `min()` in the array of size $m$ takes $\\mathcal{O}(m)$ time. Given $n, m \\le 1000$, total operations are around $10^6$, running well within the 2-second time limit.
- **Space Complexity:** $\\mathcal{O}(m)$ — To store the list of seat counts for $m$ planes.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `4 3`<br>`2 1 1` | `5 5` | **Max:** $2 + 1 + 1 + 1 = 5$<br>**Min:** $1 + 1 + 2 + 1 = 5$ |
| `4 3`<br>`2 2 2` | `7 6` | **Max:** $2 + 2 + 2 + 1 = 7$<br>**Min:** $2 + 1 + 2 + 1 = 6$ |

---

## 💻 Code

```python
n, m = map(int, input().split())
ticket = list(map(int, input().split()))

maxAmt, minAmt = 0, 0
ticket_copy = ticket.copy()

# Calculate Maximum Earnings
for i in range(n):
    if 0 in ticket_copy: 
        ticket_copy.remove(0)
    
    maxi = max(ticket_copy)
    maxiInd = ticket_copy.index(maxi)
    maxAmt += maxi
    ticket_copy[maxiInd] -= 1

# Calculate Minimum Earnings
for i in range(n):
    if 0 in ticket: 
        ticket.remove(0)
    
    mini = min(ticket)
    miniInd = ticket.index(mini)
    minAmt += mini
    ticket[miniInd] -= 1

print(maxAmt, minAmt, end=" ")
```
