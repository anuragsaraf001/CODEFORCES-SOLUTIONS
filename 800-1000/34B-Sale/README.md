# B. Sale - Codeforces 34B

- **Platform:** Codeforces
- **Problem Link:** [34B - Sale](https://codeforces.com/problemset/problem/34/B)
- **Difficulty:** 800 / Easy
- **Tags:** `Greedy`, `Sorting`, `Implementation`
- **Language:** Python

---

## 📌 Problem Statement

Bob is at a sale of old TV sets where $n$ TV sets are available. The $i$-th TV set costs $a_i$ bellars. Some TV sets have a **negative price**, meaning the owner is willing to pay Bob to take them. 

Bob can carry **at most $m$ TV sets**. Find the maximum amount of money Bob can earn.

---

## 💡 Key Intuition & Approach

### 1. Greedy Selection
To maximize total earnings:
1. Bob should only pick TV sets with **negative prices** ($a_i < 0$), as positive or zero prices do not yield any earnings.
2. Bob wants the **most negative values** first (e.g., $-6$ earns more than $-2$).

### 2. Algorithmic Steps
1. Read $n$, $m$, and the list of prices `price`.
2. Filter or repeatedly pick the minimum element (or sort the array in ascending order).
3. Sum up at most $m$ negative values.
4. Multiply the resulting sum by $-1$ to convert the negative price sum into total positive earnings.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \cdot n)$ for repeated `min()` / `remove()`, or $\mathcal{O}(n \log n)$ if using standard sorting (`price.sort()`). Given $n, m \le 100$, either approach executes almost instantaneously.
- **Space Complexity:** $\mathcal{O}(n)$ — To store the prices of $n$ TV sets.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `5 3`<br>`-6 0 35 -2 4` | `8` | Bob can carry up to 3 TVs. He picks TVs with prices `-6` and `-2`. Total earnings = $6 + 2 = 8$. |
| `4 2`<br>`7 0 0 -7` | `7` | Bob picks the TV with price `-7`. Total earnings = $7$. |

---

## 💻 Code

```python
n, m = map(int, input().split())
price = list(map(int, input().split()))

totalEarn = 0
for i in range(m):
    minPrice = min(price)
    if minPrice < 0:
        totalEarn += minPrice
        price.remove(minPrice)
    else:
        break

print(totalEarn * -1)
```
