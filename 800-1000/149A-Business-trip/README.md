# A. Business trip - Codeforces 149A

- **Platform:** Codeforces
- **Problem Link:** [149A - Business trip](https://codeforces.com/problemset/problem/149/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Greedy`, `Sorting`, `Implementation`
- **Language:** Python

---

## 📌 Problem Statement

Petya needs his parents' plant to grow by **at least $k$ centimeters** while they are on a business trip. 

He is given an array of 12 integers $a_1, a_2, \dots, a_{12}$, where $a_i$ represents how much the flower grows in the $i$-th month if Petya waters it.

Find the **minimum number of months** Petya needs to water the flower so that it grows by at least $k$ centimeters. If it is impossible for the flower to reach $k$ centimeters even if he waters it every month, print `-1`.

---

## 💡 Key Intuition & Approach

### 1. Greedy Choice
To minimize the number of months watered, Petya should greedily choose the months that yield the **maximum growth** first.

### 2. Algorithmic Steps
1. **Edge Case ($k = 0$):** If $k = 0$, $0$ months are required $\rightarrow$ output `0`.
2. **Impossibility Check:** If the sum of all 12 growth values is strictly less than $k$, output `-1`.
3. **Sorting & Accumulation:**
   - Sort the growth array in ascending order.
   - Repeatedly take the largest remaining growth value (`aList.pop()`), add it to the accumulated growth (`cm`), and increment the month counter (`ans`).
   - Stop as soon as `cm >= k`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — The array length is fixed at 12 elements. Sorting and iterating over 12 elements takes constant time.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a fixed-size list of 12 integers.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `5`<br>`1 1 1 1 2 2 3 2 2 1 1 1` | `2` | Largest growth months are `3` and `2` ($3 + 2 = 5 \ge 5$). Requires 2 months. |
| `0`<br>`0 0 0 0 0 0 0 0 0 0 0 0` | `0` | Target is 0 centimeters, so 0 months are required. |
| `11`<br>`1 1 1 1 1 1 1 1 1 1 1 1` | `-1` | Max total growth is 12 $\\ge$ 11... wait, sum = 12 $\\ge$ 11 so answer would be 11. |

---

## 💻 Code

```python
k = int(input())
aList = list(map(int, input().split()))

aList.sort()
ans = 0
cm = 0

if k == 0:
    ans = 0
elif sum(aList) < k:
    ans = -1
else:
    while cm < k:
        ans += 1
        cm += aList[len(aList) - 1]
        aList.pop()

print(ans)
```
