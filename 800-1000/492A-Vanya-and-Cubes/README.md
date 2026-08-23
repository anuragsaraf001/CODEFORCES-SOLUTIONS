# A. Vanya and Cubes - Codeforces 492A

- **Platform:** Codeforces
- **Problem Link:** [492A - Vanya and Cubes](https://codeforces.com/problemset/problem/492/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Math`, `Brute Force`
- **Language:** C++

---

## 📌 Problem Statement

Vanya wants to build a pyramid using $n$ cubes. 

The $i$-th level from the top requires the $i$-th triangular number of cubes:
$$\text{Cubes in level } i = 1 + 2 + \dots + i = \frac{i(i + 1)}{2}$$

Find the **maximum height** of the pyramid that can be built using at most $n$ cubes ($1 \le n \le 10^4$).

---

## 💡 Key Intuition & Approach

### 1. Cumulative Sum of Triangular Numbers
The total number of cubes required to build a pyramid of height $h$ is:
$$\text{Total Cubes}(h) = \sum_{i=1}^h \frac{i(i + 1)}{2}$$

### 2. Algorithmic Steps
1. Read total cubes $n$.
2. Maintain:
   - `i = 1` (current height level to build).
   - `noPy = 0` (running total of cubes used so far).
3. In a loop, test if adding the $i$-th level $\frac{i(i+1)}{2}$ exceeds $n$:
   - If not, add $\frac{i(i+1)}{2}$ to `noPy` and increment `i`.
4. The maximum completed height is `i - 1`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n^{1/3})$ — Total cubes for height $h$ grows as $\approx \frac{h^3}{6}$. For $n \le 10^4$, $h \le 40$, executing in under 40 iterations.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses minimal integer variables.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `1` | `1` | Level 1 takes 1 cube. Total = 1 $\le 1$. |
| `25` | `4` | Level 1: 1 cube (total 1), Level 2: 3 cubes (total 4), Level 3: 6 cubes (total 10), Level 4: 10 cubes (total 20 $\le 25$). Level 5 would require 15 more (total 35 > 25). |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int i = 1;
    int noPy = 0;
    while (noPy + (i * (i + 1)) / 2 <= n) {
        noPy += (i * (i + 1)) / 2;
        i++;
    }
    cout << i - 1 << "\n";
    return 0;
}
```
