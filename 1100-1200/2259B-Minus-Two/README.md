# B. Minus Two

- **Platform:** Codeforces
- **Difficulty:** Easy
- **Tags:** `Math`, `Number Theory`, `Greedy`, `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

You are given an array $a_1, a_2, \dots, a_n$ of positive integers. In one operation, you update **all** elements simultaneously:
$$a_i \leftarrow |a_i - 2| \quad 	ext{for all } 1 \le i \le n$$

Find the **maximum possible frequency** of any single integer in $a$ after applying the operation an arbitrary (possibly zero) number of times.

---

## 💡 Key Intuition & Approach

### 1. Behavior of $x \leftarrow |x - 2|$ Under Iterations
Notice how values evolve as the operation is repeatedly applied:
- **Odd numbers:**
  - $x 	o x - 2 	o x - 4 	o \dots 	o 3 	o 1 	o |-1| = 1 	o 1 	o \dots$
  - Any odd integer eventually stabilizes at **$1$**.
  - Since all odd integers eventually become $1$ and stay at $1$, we can always make **all odd elements equal to $1$** after enough operations.
- **Even numbers:**
  - An even integer decreases by $2$ until it reaches $0$ or $2$.
  - Once $0$ is reached: $|0 - 2| = 2$.
  - Once $2$ is reached: $|2 - 2| = 0$.
  - Thus, even numbers alternate in a 2-cycle: $0 \leftrightarrow 2$.
  - Specifically:
    - If $x \equiv 0 \pmod 4$: $4k 	o \dots 	o 4 	o 2 	o 0 	o 2 	o 0 \dots$
    - If $x \equiv 2 \pmod 4$: $4k + 2 	o \dots 	o 2 	o 0 	o 2 	o 0 \dots$
  - Since the two classes ($x \equiv 0 \pmod 4$ and $x \equiv 2 \pmod 4$) are shifted by one step in the cycle:
    - At certain steps, all elements with $x \equiv 0 \pmod 4$ can become $0$ (or $2$).
    - At alternate steps, all elements with $x \equiv 2 \pmod 4$ can become $0$ (or $2$).

### 2. Frequency Candidates
The maximum possible frequency can come from:
1. **Zero operations:** The maximum initial frequency of any single element in the original array.
2. **All odd numbers:** Synchronizing all odd numbers to value $1$ (`oddCnt`).
3. **Even numbers with $a_i \equiv 0 \pmod 4$:** Synchronizing to $0$ or $2$ (`cntMod0`).
4. **Even numbers with $a_i \equiv 2 \pmod 4$:** Synchronizing to $0$ or $2$ (`cntMod2`).

Taking the maximum among these candidates yields the optimal answer:
$$	ext{Max Frequency} = \max(	ext{initial max frequency}, 	ext{oddCnt}, 	ext{cntMod0}, 	ext{cntMod2})$$

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \log n)$ per testcase using `std::map` (or $\mathcal{O}(n)$ using `std::unordered_map`). Across all test cases, total time is well within 2.0 seconds since $\sum n \le 2 \cdot 10^5$.
- **Space Complexity:** $\mathcal{O}(n)$ — To store frequencies and array elements.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2`<br>`1 3` | `2` | Both are odd; applying operation once gives $[1, 1]$ (frequency 2). |
| `4`<br>`1 1 1 2` | `3` | Three $1$s initially (frequency 3). |
| `3`<br>`6 7 8` | `1` | One odd ($7$), one $\equiv 2 \pmod 4$ ($6$), one $\equiv 0 \pmod 4$ ($8$). Max frequency is 1. |
| `4`<br>`2 2 2 2` | `4` | All four elements are initially $2$ (frequency 4). |

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
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        map<int, int> mpp;
        int oddCnt = 0, cntMod0 = 0, cntMod2 = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] % 2 != 0) {
                oddCnt++;
            } else {
                if (arr[i] % 4 == 2) {
                    cntMod2++;
                } else {
                    cntMod0++;
                }
            }
            mpp[arr[i]]++;
        }

        int ans = INT_MIN;
        for (auto it : mpp) {
            ans = max(ans, it.second);
        }

        cout << max(ans, max(cntMod0, max(cntMod2, oddCnt))) << "
";
    }
    return 0;
}
```
