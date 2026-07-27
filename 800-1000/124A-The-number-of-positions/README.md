# A. The number of positions - Codeforces 124A

- **Platform:** Codeforces
- **Problem Link:** [124A - The number of positions](https://codeforces.com/problemset/problem/124/A)
- **Difficulty:** 1000 / Easy
- **Tags:** `Math`, `Implementation`
- **Language:** Python

---

## 📌 Problem Statement

Petr stands in a line of $n$ people, but he doesn't know his exact position. He knows two conditions:
1. There are **at least $a$ people** standing in front of him.
2. There are **at most $b$ people** standing behind him.

Find the number of different positions Petr can occupy.

---

## 💡 Key Intuition & Approach

### 1. Mathematical Bounds
Let Petr's position (1-indexed from front to back) be $p$:
- **People in front of Petr:** $p - 1 \ge a \implies p \ge a + 1$.
- **People behind Petr:** $n - p \le b \implies p \ge n - b$.

Thus, Petr's position $p$ must satisfy:
$$p \ge \max(a + 1, n - b)$$

Since Petr can occupy any position up to $n$, the total number of valid positions is:
$$	ext{Total Positions} = n - \max(a, n - b - 1)$$
or equivalently:
$$	ext{Total Positions} = \min(n - a, b + 1)$$

### 2. Iterative Approach
1. Iterate over all possible counts of people behind Petr $i \in [0, b]$ (up to $b$ people behind him).
2. For each state, calculate the number of people in front: $	ext{front} = n - i - 1$.
3. Check if $	ext{front} \ge a$. If valid, increment `noOfPositions`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(b)$ — The loop executes $b + 1$ times ($b < n \le 100$).
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a few primitive variables.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `3 1 1` | `2` | Positions 2 and 3 are valid ($	ext{front} \ge 1$, $	ext{behind} \le 1$). |
| `5 2 3` | `3` | Positions 3, 4, and 5 are valid ($	ext{front} \ge 2$, $	ext{behind} \le 3$). |

---

## 💻 Code

```python
n, a, b = map(int, input().split())
noOfPositions = 0
currPos = -1
front = -1

for i in range(b + 1):
    currPos = n - i
    front = n - i - 1
    if front >= a:
        noOfPositions += 1

print(noOfPositions)
```
