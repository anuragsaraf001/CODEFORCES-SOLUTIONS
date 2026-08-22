# A. Gennady and a Card Game - Codeforces 1097A

- **Platform:** Codeforces
- **Problem Link:** [1097A - Gennady and a Card Game](https://codeforces.com/problemset/problem/1097/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Brute Force`, `Implementation`, `Strings`
- **Language:** C++

---

## 📌 Problem Statement

There is a single card on the table and you hold 5 cards in your hand. Each card is represented by a 2-character string:
- The **first character** represents the card's rank: `2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A`.
- The **second character** represents the card's suit: `D` (Diamonds), `C` (Clubs), `S` (Spades), or `H` (Hearts).

You can play a card from your hand if it shares the **same rank** or the **same suit** with the card on the table.

Determine if you can play at least one card from your hand. Print `"YES"` if possible, otherwise print `"NO"`.

---

## 💡 Key Intuition & Approach

### 1. Condition Matching
A card in hand `hand` can be played on `table` if:
$$	ext{hand}[0] == 	ext{table}[0] \quad 	ext{or} \quad 	ext{hand}[1] == 	ext{table}[1]$$

### 2. Algorithmic Steps
1. Read the `table` card string.
2. Initialize boolean flag `ans = false`.
3. Loop 5 times to read each card in `hand`.
4. If either rank (`hand[0] == table[0]`) or suit (`hand[1] == table[1]`) matches, set `ans = true`.
5. Output `"YES"` if `ans` is true, otherwise `"NO"`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — Fixed check over exactly 5 cards.
- **Space Complexity:** $\mathcal{O}(1)$ — Constant memory usage.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `AS`<br>`2H 4C TH JH AD` | `YES` | Hand contains `AD`, which shares the rank `'A'` with `AS`. |
| `2H`<br>`3D 4C AC KD AS` | `NO` | No card in hand shares rank `'2'` or suit `'H'`. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string table;
    cin >> table;
    
    bool ans = false;
    for (int i = 0; i < 5; i++) {
        string hand;
        cin >> hand;
        if (hand[0] == table[0] || hand[1] == table[1]) {
            ans = true;
        }
    }
    
    (ans) ? cout << "YES
" : cout << "NO
";
    return 0;
}
```
