# A. Anton and Danik - Codeforces 734A

- **Platform:** Codeforces
- **Problem Link:** [734A - Anton and Danik](https://codeforces.com/problemset/problem/734/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** C++

---

## 📌 Problem Statement

Anton and Danik played $n$ chess games in a row. The outcome of each game is given as a string $s$ of length $n$:
- `'A'` means Anton won the game.
- `'D'` means Danik won the game.

Determine who won more games:
- If Anton won more games, output `"Anton"`.
- If Danik won more games, output `"Danik"`.
- If both won the same number of games, output `"Friendship"`.

---

## 💡 Key Intuition & Approach

### 1. Counting Wins
Iterate through the string $s$ and count occurrences of character `'A'` and `'D'`:
- `cntA`: total games won by Anton.
- `cntD`: total games won by Danik.

### 2. Comparison
- If `cntA == cntD` $ightarrow$ output `"Friendship"`.
- Else if `cntA > cntD` $ightarrow$ output `"Anton"`.
- Else $ightarrow$ output `"Danik"`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — Single linear pass over string $s$ ($n \le 100\,000$).
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (excluding input string storage).

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `6`<br>`ADAAAA` | `Anton` | Anton won 5 games, Danik won 1 game ($5 > 1$). |
| `7`<br>`DDDAADA` | `Danik` | Danik won 4 games, Anton won 3 games ($4 > 3$). |

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

    int cntA = 0, cntD = 0;
    for (auto it : s) {
        if (it == 'A') cntA++;
        else cntD++;
    }

    if (cntA == cntD) {
        cout << "Friendship";
        return 0;
    }

    (cntA > cntD) ? cout << "Anton" : cout << "Danik";
    return 0;
}
```
