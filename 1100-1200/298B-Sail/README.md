# B. Sail - Codeforces 298B

- **Platform:** Codeforces
- **Problem Link:** [298B - Sail](https://codeforces.com/problemset/problem/298/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Greedy`, `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

A boat wants to sail from starting coordinates $(s_x, s_y)$ to destination coordinates $(e_x, e_y)$ using wind power over $t$ seconds.

At each second $i$, the wind blows in one of four directions:
- `'E'` (East): moves to $(x + 1, y)$
- `'S'` (South): moves to $(x, y - 1)$
- `'W'` (West): moves to $(x - 1, y)$
- `'N'` (North): moves to $(x, y + 1)$

Alternatively, the boat can drop anchor and stay at $(x, y)$. Find the earliest second (1-indexed) by which the boat can reach $(e_x, e_y)$. If it's impossible to reach within $t$ seconds, print `-1`.

---

## 💡 Key Intuition & Approach

### 1. Greedy Strategy
Since the boat can choose to stay in place (by holding anchor), wind blowing in an unfavorable or unneeded direction can simply be ignored.

To reach $(e_x, e_y)$ as quickly as possible:
- If $s_x < e_x$ and the wind blows East (`'E'`), move East ($s_x \leftarrow s_x + 1$).
- If $s_x > e_x$ and the wind blows West (`'W'`), move West ($s_x \leftarrow s_x - 1$).
- If $s_y < e_y$ and the wind blows North (`'N'`), move North ($s_y \leftarrow s_y + 1$).
- If $s_y > e_y$ and the wind blows South (`'S'`), move South ($s_y \leftarrow s_y - 1$).

### 2. Early Termination
Check at each step whether $s_x == e_x$ and $s_y == e_y$. The first second (index $+ 1$) this condition becomes true is guaranteed to be the earliest possible arrival time.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(t)$ — Single linear pass through the wind direction string of length $t \le 10^5$.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses constant auxiliary memory (excluding input string storage).

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `5 0 0 1 1`<br>`SESNW` | `4` | Moves: second 2 (`'E'` to $(1,0)$), second 4 (`'N'` to $(1,1)$). Reaches at second 4. |
| `10 5 3 3 6`<br>`NENSWESNEE` | `-1` | Cannot reach destination $(3, 6)$ within 10 seconds. |

---

## 💻 Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long sx, sy, ex, ey;
    
    // Read the inputs properly
    cin >> t >> sx >> sy >> ex >> ey;
    
    string s;
    cin >> s;

    // Simulate the boat ride second by second
    for (int i = 0; i < t; i++) {
        // If the wind takes us closer to the destination on the X-axis
        if (sx < ex && s[i] == 'E') {
            sx++;
        } else if (sx > ex && s[i] == 'W') {
            sx--;
        } 
        // If the wind takes us closer to the destination on the Y-axis
        else if (sy < ey && s[i] == 'N') {
            sy++;
        } else if (sy > ey && s[i] == 'S') {
            sy--;
        }

        // Check if we have arrived at the destination
        if (sx == ex && sy == ey) {
            // Time is 1-indexed, so we print i + 1
            cout << i + 1 << "
";
            return 0;
        }
    }

    // If the loop finishes and we haven't reached the destination
    cout << -1 << "
";
    return 0;
}
```
