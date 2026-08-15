# A. Domino piling - Codeforces 50A

- **Platform:** Codeforces
- **Problem Link:** [50A - Domino piling](https://codeforces.com/problemset/problem/50/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Greedy`, `Math`
- **Language:** C++

---

## 📌 Problem Statement

You are given a rectangular board of $M \times N$ squares and an unlimited number of standard $2 \times 1$ domino pieces.

Dominos can be rotated, must not overlap, and must lie entirely inside the board. Find the **maximum number of dominoes** that can be placed on the board.

---

## 💡 Key Intuition & Approach

### 1. Mathematical Area Division
- Each domino covers exactly $2$ squares of the board.
- The total number of available squares on the board is $M \times N$.
- Since any $2 \times 1$ arrangement can tile an even board completely or leave at most $1$ empty square when the total area is odd, the maximal number of dominoes is simply:
$$\lfloor \frac{M \times N}{2} \rfloor$$

### 2. Implementation
Read integers $m$ and $n$, then directly output `(m * n) / 2`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — Single arithmetic operation.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses constant auxiliary memory.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2 4` | `4` | Total area is $2 \times 4 = 8$. Max dominoes $= 8 / 2 = 4$. |
| `3 3` | `4` | Total area is $3 \times 3 = 9$. Max dominoes $= \lfloor 9 / 2 \rfloor = 4$. |
| `1 5` | `2` | Total area is $1 \times 5 = 5$. Max dominoes $= \lfloor 5 / 2 \rfloor = 2$. |

---

## 💻 Code

```cpp
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    cout << (m * n) / 2;
    
    return 0;
}
```
