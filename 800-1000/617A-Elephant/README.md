# A. Elephant - Codeforces 617A

- **Platform:** Codeforces
- **Problem Link:** [617A - Elephant](https://codeforces.com/problemset/problem/617/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Greedy`, `Math`
- **Language:** C++

---

## 📌 Problem Statement

An elephant wants to visit his friend whose house is located at coordinate point $x$ ($1 \le x \le 1\,000\,000$). The elephant starts at coordinate point $0$.

In a single step, the elephant can move $1, 2, 3, 4,$ or $5$ positions forward. Determine the **minimum number of steps** needed to reach point $x$.

---

## 💡 Key Intuition & Approach

### 1. Greedy Strategy
To minimize the number of steps, the elephant should take the **largest possible jump** (step length of $5$) as many times as possible:
- If remaining distance $x \ge 5$, take jumps of size $5$.
- For any remaining distance, greedily take the largest valid step from $4, 3, 2,$ down to $1$.

### 2. Algorithmic Steps
1. Read distance $x$.
2. Iterate through possible step sizes $i$ from $5$ down to $1$:
   - Add $x / i$ to `steps`.
   - Update remaining distance $x \leftarrow x \pmod i$.
   - If $x == 0$, return and print `steps`.
3. Alternatively, the formula $\lceil x / 5 ceil = (x + 4) / 5$ can compute the answer directly in $\mathcal{O}(1)$.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — Loops through a constant 5 step sizes ($5$ to $1$).
- **Space Complexity:** $\mathcal{O}(1)$ — Uses minimal integer variables.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `5` | `1` | One single step of size $5$. |
| `12` | `3` | Two steps of size $5$ ($5 + 5 = 10$) and one step of size $2$ ($10 + 2 = 12$). |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;
    int steps = 0;
    for (int i = 5; i >= 1; i--) {
        if (x == 0) {
            cout << steps;
            return 0;
        }
        steps += x / i;
        x = x % i;
    }
    cout << steps;
    return 0;
}
```
