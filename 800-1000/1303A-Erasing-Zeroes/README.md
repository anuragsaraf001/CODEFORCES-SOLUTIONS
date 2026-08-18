# A. Erasing Zeroes - Codeforces 1303A

- **Platform:** Codeforces
- **Problem Link:** [1303A - Erasing Zeroes](https://codeforces.com/problemset/problem/1303/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** C++

---

## 📌 Problem Statement

You are given a binary string $s$. You want to make all `'1'`s in the string form a single contiguous subsegment by erasing the minimum number of `'0'`s.

Output the minimum number of `'0'`s that need to be erased for each testcase.

---

## 💡 Key Intuition & Approach

### 1. Identifying the Boundaries of `'1'`s
For all `'1'`s to form a contiguous block:
- Leading `'0'`s (before the first `'1'`) and trailing `'0'`s (after the last `'1'`) do not need to be removed.
- Only the `'0'`s located **between** the very first occurrence of `'1'` and the very last occurrence of `'1'` break contiguity and must be erased.

### 2. Algorithmic Steps
1. Scan string $s$ to find the first index (`first_one`) and last index (`last_one`) containing `'1'`.
2. If no `'1'` exists (`first_one == -1`), the answer is `0`.
3. Count all `'0'`s within the index range `[first_one, last_one]`.
4. Output the count.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(|s|)$ per test case — Two linear passes over string $s$ ($|s| \le 100$). Across $t$ test cases, total time is $\mathcal{O}(t \cdot |s|)$.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a few integer variables for index tracking.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `010011` | `2` | First `'1'` at index 1, last `'1'` at index 5. Two `'0'`s between them at indices 2 and 3. |
| `0` | `0` | No `'1'` present in the string. |
| `1111000` | `0` | All `'1'`s are already contiguous; trailing `'0'`s can remain. |

---

## 💻 Code

```cpp
#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int first_one = -1;
    int last_one = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            if (first_one == -1) {
                first_one = i;
            }
            last_one = i;
        }
    }
    if (first_one == -1) {
        cout << 0 << "\n";
        return;
    }
    int zeroes_to_erase = 0;
    for (int i = first_one; i <= last_one; ++i) {
        if (s[i] == '0') {
            zeroes_to_erase++;
        }
    }
    cout << zeroes_to_erase << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
