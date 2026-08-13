# A. Stones on the Table - Codeforces 266A

- **Platform:** Codeforces
- **Problem Link:** [266A - Stones on the Table](https://codeforces.com/problemset/problem/266/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** C++

---

## 📌 Problem Statement

There are $n$ stones placed in a row on a table, each colored red (`'R'`), green (`'G'`), or blue (`'B'`).

Find the minimum number of stones to remove from the table so that no two neighboring stones have the same color.

---

## 💡 Key Intuition & Approach

### 1. Counting Adjacent Equal Characters
Whenever two adjacent stones have the same color ($s[i-1] == s[i]$), one of them must be removed to prevent neighboring duplicate colors.

### 2. Algorithmic Steps
1. Read $n$ and string $s$.
2. Initialize counter `cnt = 0`.
3. Iterate $i$ from $1$ to $n-1$:
   - If $s[i-1] == s[i]$, increment `cnt`.
4. Output `cnt`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — Single pass through string $s$ of length $n \le 50$.
- **Space Complexity:** $\mathcal{O}(1)$ — Constant space complexity.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `3`<br>`RRG` | `1` | Remove 1 `'R'` to make `"RG"`. |
| `5`<br>`RRRRR` | `4` | Remove 4 `'R'`s to leave a single stone `"R"`. |
| `4`<br>`BRBG` | `0` | No two adjacent stones have the same color. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // number of stones on the table
    cin >> n;
    string s;
    cin >> s;
    
    int cnt = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            cnt++; // since two adjacent are same, we have to remove this stone
        }
    }
    
    cout << cnt << endl;
    return 0;
}
```
