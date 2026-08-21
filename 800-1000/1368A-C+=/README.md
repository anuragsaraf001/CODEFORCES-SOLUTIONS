# A. C+= - Codeforces 1368A

- **Platform:** Codeforces
- **Problem Link:** [1368A - C+=](https://codeforces.com/problemset/problem/1368/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Greedy`, `Math`, `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

Leo has two variables $a$ and $b$. He can perform two types of operations:
- `a += b` (adds $b$ to $a$)
- `b += a` (adds $a$ to $b$)

Given three integers $a, b,$ and $n$ ($1 \le a, b \le n \le 10^9$), find the **minimum number of operations** required so that at least one of the variables becomes **strictly greater** than $n$.

---

## 💡 Key Intuition & Approach

### 1. Fibonacci-Like Growth (Greedy Strategy)
To make either $a$ or $b$ exceed $n$ in the minimum number of steps, we should maximize the growth rate at each step:
- Always add the **larger number to the smaller number**.
- If $a \le b$, set $a \leftarrow a + b$.
- If $b < a$, set $b \leftarrow b + a$.

This greedy choice creates a **Fibonacci-like sequence** where the values grow exponentially, minimizing the number of operations needed to exceed $n$.

### 2. Algorithmic Steps
1. For each testcase, read $a, b, n$.
2. Initialize operation counter `op = 0`.
3. Loop while both $a \le n$ and $b \le n$:
   - Increment `op`.
   - Add the larger variable to the smaller one (`if (a <= b) a += b; else b += a;`).
4. Output `op`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log(\max(a, b, n)))$ per test case — The numbers grow at least at Fibonacci rate ($F_k pprox \phi^k$), requiring $\le 45$ iterations even for $n = 10^9$.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses minimal auxiliary memory.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `1 2 3` | `2` | Op 1: $a = 1 + 2 = 3$ ($a=3, b=2$). Op 2: $b = 2 + 3 = 5 > 3$. |
| `5 4 100` | `7` | Grows in 7 operations to exceed 100. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, n;
        cin >> a >> b >> n;
        int op = 0;
        while (a <= n && b <= n) {
            op++;
            if (a <= b) a += b;
            else b += a;
        }
        cout << op << "
";
    }
    return 0;
}
```
