# A. Boy or Girl - Codeforces 236A

- **Platform:** Codeforces
- **Problem Link:** [236A - Boy or Girl](https://codeforces.com/problemset/problem/236/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`, `Hashing`
- **Language:** C++

---

## 📌 Problem Statement

Determine the gender of a user based on their username:
- If the number of **distinct characters** in the username is **even**, the user is female $\rightarrow$ output `"CHAT WITH HER!"`.
- If the number of distinct characters is **odd**, the user is male $\rightarrow$ output `"IGNORE HIM!"`.

---

## 💡 Key Intuition & Approach

### 1. Distinct Character Counting
Since the username consists only of lowercase English letters (`'a'` to `'z'`):
1. Use a boolean array `seen[26]` initialized to `false` to mark character presence.
2. Iterate through each character `c` of string `s` and set `seen[c - 'a'] = true`.
3. Use STL `std::count` over `seen` to count how many entries are `true` (`distinct`).

### 2. Parity Check
- Check if `distinct % 2 == 0`.
- Print `"CHAT WITH HER!"` if even, otherwise print `"IGNORE HIM!"`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(|s|)$ — Single linear pass over string $s$ ($|s| \le 100$), followed by scanning a fixed array of size 26.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a constant-sized array `seen[26]`.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `wjmzbmr` | `CHAT WITH HER!` | Distinct characters: `w`, `j`, `m`, `z`, `b`, `r` (6 distinct $\rightarrow$ even). |
| `xiaodao` | `IGNORE HIM!` | Distinct characters: `x`, `i`, `a`, `o`, `d` (5 distinct $\rightarrow$ odd). |
| `sevenkplus` | `CHAT WITH HER!` | Distinct characters: `s`, `e`, `v`, `n`, `k`, `p`, `l`, `u` (8 distinct $\rightarrow$ even). |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    bool seen[26] = {};
    for (char c : s) {
        seen[c - 'a'] = true;
    }
    
    int distinct = count(seen, seen + 26, true);
    cout << (distinct % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << "
";
    
    return 0;
}
```
