# A. Repeating Cipher - Codeforces 1095A

- **Platform:** Codeforces
- **Problem Link:** [1095A - Repeating Cipher](https://codeforces.com/problemset/problem/1095/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** C++

---

## 📌 Problem Statement

Polycarp encrypted a string $s$ of length $m$ by repeating its characters: the first character once, the second twice, the third three times, ..., and the $m$-th character $m$ times.

Given an encrypted string $t$ of length $n$ ($1 \le n \le 55$), decrypt the string to retrieve the original string $s$.

---

## 💡 Key Intuition & Approach

### 1. Reverse the Triangular Progression
In the encrypted string:
- Character $s[0]$ is at index $0$.
- Character $s[1]$ starts at index $0 + 1 = 1$.
- Character $s[2]$ starts at index $1 + 2 = 3$.
- Character $s[k]$ starts at index $\frac{k(k + 1)}{2}$.

### 2. Algorithmic Steps
1. Read length $n$ and the encrypted string $s$.
2. Maintain index `j = 0` and step increment `i = 1`.
3. Loop while `j < n`:
   - Append `s[j]` to `ans`.
   - Advance `j += i`.
   - Increment `i++`.
4. Output `ans`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\sqrt{n})$ — The loop executes $m$ times where $\frac{m(m+1)}{2} = n \le 55$ ($m \le 10$).
- **Space Complexity:** $\mathcal{O}(m) = \mathcal{O}(\sqrt{n})$ — To store the decrypted result string.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `6`<br>`baabbb` | `bab` | Takes characters at index $0$ (`'b'`), $1$ (`'a'`), $3$ (`'b'`). |
| `10`<br>`ooopppssss` | `oops` | Indices $0$ (`'o'`), $1$ (`'o'`), $3$ (`'p'`), $6$ (`'s'`). |

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
    string s;
    cin >> s;
    
    int i = 1; // step jump
    int j = 0; // current index
    string ans = "";
    
    while (j < n) {
        ans += s[j];
        j += i;
        i++;
    }
    
    cout << ans << "\n";
    return 0;
}
```
