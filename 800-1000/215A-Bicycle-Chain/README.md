# A. Bicycle Chain - Codeforces 215A

- **Platform:** Codeforces
- **Problem Link:** [215A - Bicycle Chain](https://codeforces.com/problemset/problem/215/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Brute Force`
- **Language:** Python

---

## 📌 Problem Statement

Vasya's bicycle chain drive consists of $n$ stars on the pedal axle with tooth counts $a_1, a_2, \dots, a_n$ and $m$ stars on the rear wheel axle with tooth counts $b_1, b_2, \dots, b_m$.

A pair $(i, j)$ forms a gear with gear ratio equal to $\frac{b_j}{a_i}$.

Vasya wants to find the number of gears $(i, j)$ such that:
1. The gear ratio $\frac{b_j}{a_i}$ is an **integer** (i.e., $b_j \pmod{a_i} == 0$).
2. The gear ratio is the **maximum** among all valid integer ratios.

---

## 💡 Key Intuition & Approach

### 1. Constraint Analysis
Constraints are small ($n, m \le 50$), so the total number of gear pairs to evaluate is at most $n \times m = 2500$. A complete **brute-force search** over all pairs $(a_i, b_j)$ is optimal and well within limits.

### 2. Hash Map / Frequency Tracking
1. Iterate over each element $i$ in `aList` and $j$ in `bList`.
2. Check if $j$ is divisible by $i$ (`j % i == 0`).
3. If divisible:
   - Calculate the integer ratio `ratio = j // i`.
   - Update `maxGearRatio` with the maximum ratio found so far.
   - Increment the frequency of `ratio` in a hash map (`mydict`).
4. Print the frequency corresponding to `mydict[maxGearRatio]`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \cdot m)$ — Double loop checking every pair of $(a_i, b_j)$. For $n, m \le 50$, this executes in $\approx 2500$ operations.
- **Space Complexity:** $\mathcal{O}(n \cdot m)$ — To store the frequency of gear ratios in a hash map.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2`<br>`4 5`<br>`3`<br>`12 13 15` | `2` | Integer ratios: $\frac{12}{4} = 3$, $\frac{15}{5} = 3$. Max ratio is $3$, occurring $2$ times. |
| `4`<br>`4 3 2 1`<br>`3`<br>`4 8 12` | `1` | Max integer ratio is $\frac{12}{1} = 12$, occurring $1$ time. |

---

## 💻 Code

```python
n = int(input())
aList = list(map(int, input().split()))
m = int(input())
bList = list(map(int, input().split()))

maxGearRatio = -1
mydict = {}

for i in aList:
    for j in bList:
        if j % i == 0:
            ratio = j // i
            maxGearRatio = max(maxGearRatio, ratio)
            if ratio in mydict:
                mydict[ratio] += 1
            else:
                mydict[ratio] = 1

print(mydict[maxGearRatio])
```
