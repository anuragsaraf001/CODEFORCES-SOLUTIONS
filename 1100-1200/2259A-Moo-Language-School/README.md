# A. Moo Language School

- **Platform:** Codeforces
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`, `Greedy`
- **Language:** C++

---

## 📌 Problem Statement

The United Cows of Farmer John (UCFJ) consists of $n$ fields partitioned into $\frac{n}{k}$ consecutive farms, where each farm contains exactly $k$ consecutive fields.

Farmer John wants to build at least one school in every farm:
- If a field has $s_i = 1$, it is owned by Farmer Nhoj (building here incurs extra cost).
- If $s_i = 0$, it is not owned by Farmer Nhoj (can be built for free).

Find the **minimum number of times** Farmer John must build a school on Farmer Nhoj's land across all farms.

---

## 💡 Key Intuition & Approach

### 1. Independent Farm Evaluation
Since each farm needs at least one school, we examine each farm of size $k$ independently:
- If a farm contains **at least one `'0'` field**, Farmer John can simply build the school on that field without needing Farmer Nhoj's land.
- If a farm consists **entirely of `'1'` fields**, Farmer John has no alternative and is forced to build on Farmer Nhoj's land.

### 2. Algorithmic Steps
1. Divide the binary string $s$ into contiguous chunks of length $k$.
2. For each chunk $i$ from $0$ to $n-1$ in steps of $k$:
   - Check if any character in $[i, i+k-1]$ is `'0'`.
   - If no `'0'` exists in this block, increment `cnt`.
3. Print `cnt`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ per test case — Each character in string $s$ is visited exactly once. With $n \le 20$ and $t \le 10^4$, total operations $\approx 2 \cdot 10^5$, executing well within 1.0 second.
- **Space Complexity:** $\mathcal{O}(n)$ — To store the input binary string.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `8 2`<br>`10011100` | `1` | Farms are `10`, `01`, `11`, `00`. Only farm `11` has no `'0'`, requiring 1 school on Nhoj's land. |
| `5 1`<br>`11111` | `5` | Every single-element farm is `'1'`, requiring 5 schools. |
| `8 4`<br>`01111110` | `0` | Farms are `0111` and `1110`. Both contain at least one `'0'`. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        int cnt = 0;
        for (int i = 0; i < n; i += k) {
            bool atLeastOne = false;
            for (int j = i; j < i + k; j++) {
                if (s[j] == '0') {
                    atLeastOne = true;
                }
            }
            if (!atLeastOne) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
```
