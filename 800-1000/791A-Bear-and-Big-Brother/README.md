# A. Bear and Big Brother - Codeforces 791A

- **Platform:** Codeforces
- **Problem Link:** [791A - Bear and Big Brother](https://codeforces.com/problemset/problem/791/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

Bear Limak weighs $a$ and his brother Bob weighs $b$ ($1 \le a \le b \le 10$).

Every year:
- Limak's weight triples ($a \leftarrow a \cdot 3$).
- Bob's weight doubles ($b \leftarrow b \cdot 2$).

Find the minimum number of full years after which Limak's weight will become **strictly greater** than Bob's weight ($a > b$).

---

## 💡 Key Intuition & Approach

### 1. Direct Simulation
Since the initial weights are very small ($a, b \le 10$) and Limak's weight grows exponentially faster than Bob's ($3^t > 2^t$):
1. Initialize a year counter `yrs = 0`.
2. Run a loop while $a \le b$:
   - Increment `yrs`.
   - Update $a = a \cdot 3$ and $b = b \cdot 2$.
3. Once the loop terminates, output `yrs`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log_{1.5}(b/a)) = \mathcal{O}(1)$ — The loop executes at most $pprox 6$ times for $a, b \le 10$.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses constant auxiliary memory.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `4 7` | `2` | Year 1: $12 \le 14$. Year 2: $36 > 28$. Limak becomes larger after 2 years. |
| `4 9` | `3` | Year 1: $12, 18$. Year 2: $36, 36$ (equal is not strictly larger). Year 3: $108 > 72$. |
| `1 1` | `1` | Year 1: $3 > 2$. |

---

## 💻 Code

```cpp
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    int yrs = 0;
    while (a <= b) {
        yrs++;
        a = a * 3;
        b = b * 2;
    }
    cout << yrs << endl;
    return 0;
}
```
