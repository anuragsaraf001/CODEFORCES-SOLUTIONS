# A. Boring Apartments - Codeforces 1433A

- **Platform:** Codeforces
- **Problem Link:** [1433A - Boring Apartments](https://codeforces.com/problemset/problem/1433/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Math`
- **Language:** C++

---

## 📌 Problem Statement

An apartment number is called **boring** if all its digits are identical (e.g., $1, 11, 111, 1111, 2, 22, \dots$).

A character calls boring apartments in increasing order by digits:
- First, digit `1`: $1, 11, 111, 1111$
- Next, digit `2`: $2, 22, 222, 2222$
- ... and so on up to digit `9`.

The resident of apartment $x$ answers the call, and no further apartments are dialed. Find the **total number of keypresses (digits pressed)** to reach apartment $x$.

---

## 💡 Key Intuition & Approach

### 1. Digits for Fully Completed Blocks
For each digit $d < 	ext{last\_digit}$, dialing all 4 numbers ($d, dd, ddd, dddd$) requires:
$$1 + 2 + 3 + 4 = 10 	ext{ keypresses}$$
So, preceding completed digit groups contribute:
$$(	ext{last\_digit} - 1) 	imes 10 	ext{ digits}$$

### 2. Digits in the Current Group
For the current digit group up to apartment $x$ of length $n$:
$$	ext{Digits pressed} = 1 + 2 + \dots + n = rac{n(n + 1)}{2}$$

### 3. Total Formula
$$	ext{Total Keypresses} = (	ext{last\_digit} - 1) 	imes 10 + rac{n(n + 1)}{2}$$

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ per test case — Calculated directly using elementary math operations.
- **Space Complexity:** $\mathcal{O}(1)$ — Constant auxiliary space.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `22` | `13` | Digit 1: $1+2+3+4 = 10$. Digit 2: $1+2 = 3$. Total $= 10 + 3 = 13$. |
| `9999` | `90` | All digits $1$ through $9$ fully dialed ($9 	imes 10 = 90$). |
| `1` | `1` | Only a single keypress for apartment `1`. |

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
        int x;
        cin >> x;
        int ans = 0;
        int last_digit = x % 10;
        ans += (last_digit - 1) * 10;
        int n = to_string(x).length();
        ans += (n * (n + 1)) / 2;
        cout << ans << "
";
    }
    return 0;
}
```
