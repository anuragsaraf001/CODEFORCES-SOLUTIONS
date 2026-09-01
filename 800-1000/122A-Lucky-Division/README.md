# A. Lucky Division - Codeforces 122A

- **Platform:** Codeforces
- **Problem Link:** [122A - Lucky Division](https://codeforces.com/problemset/problem/122/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Brute Force`, `Math`, `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

A number is **lucky** if its decimal representation contains only the digits `4` and `7` (e.g., $4, 7, 44, 47, \dots$).

A number $n$ ($1 \le n \le 1000$) is called **almost lucky** if it is evenly divisible by at least one lucky number. Determine if $n$ is almost lucky.

---

## 💡 Key Intuition & Approach

### 1. Precomputed Lucky Numbers
Since $n \le 1000$, all possible lucky numbers up to $1000$ can be listed statically:
$$\{4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777\}$$

### 2. Divisibility Check
- Read integer $n$.
- Iterate through the list of precomputed lucky numbers.
- If $n \pmod x == 0$ for any lucky number $x$, print `"YES"` and exit.
- If no lucky divisor is found, print `"NO"`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — Tests at most 14 precomputed lucky numbers.
- **Space Complexity:** $\mathcal{O}(1)$ — Stores a fixed list of 14 integers.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `47` | `YES` | $47$ is itself a lucky number ($47 \pmod{47} == 0$). |
| `16` | `YES` | $16$ is divisible by lucky number $4$ ($16 \pmod 4 == 0$). |
| `78` | `NO` | $78$ is not divisible by any lucky number $\le 78$. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    for (int x : lucky) {
        if (n % x == 0) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
```
