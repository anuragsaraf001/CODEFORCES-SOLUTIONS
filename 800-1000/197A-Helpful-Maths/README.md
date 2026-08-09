# A. Helpful Maths - Codeforces 339A

- **Platform:** Codeforces
- **Problem Link:** [339A - Helpful Maths](https://codeforces.com/problemset/problem/339/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`, `Sorting`
- **Language:** C++

---

## 📌 Problem Statement

Xenia is learning addition, but she can only calculate sums if the numbers are written in non-decreasing order (e.g., $1+1+2+3$).

Given a summation expression consisting of numbers `1`, `2`, `3` separated by `+` signs, rearrange the summands in non-decreasing order and output the new expression.

---

## 💡 Key Intuition & Approach

### 1. Counting Sort Approach
Since the numbers in the input expression are limited to digits `1`, `2`, and `3`:
1. Use a fixed-size frequency array `cnt[4]` to count occurrences of each digit.
2. Iterate through input string $s$. Ignore `+` signs and increment `cnt[ch - '0']` for digit characters.
3. Iterate from $i = 1$ to $3$ and print digit $i$ according to its count `cnt[i]`.
4. Prepend a `+` sign before every digit except the very first printed digit (controlled via boolean flag `first`).

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(|s|)$ — Single linear pass over string $s$ ($|s| \le 100$) to count frequencies, followed by printing $\le 100$ characters.
- **Space Complexity:** $\mathcal{O}(1)$ — Fixed-size array `cnt[4]` for digit frequencies.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `3+2+1` | `1+2+3` | Digits sorted in ascending order. |
| `1+1+3+1+3` | `1+1+1+3+3` | Identical numbers grouped together in non-decreasing order. |
| `2` | `2` | Single summand remains unchanged. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int cnt[4] = {};
    for (auto ch : s) {
        if (ch != '+') {
            cnt[ch - '0']++;
        }
    }
    
    bool first = true;
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            if (!first) cout << "+" << i;
            else {
                cout << i;
                first = false;
            }
        }
    }
    return 0;
}
```
