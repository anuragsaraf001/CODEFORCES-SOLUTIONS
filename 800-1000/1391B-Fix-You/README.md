# B. Fix You - Codeforces 1391B

- **Platform:** Codeforces
- **Problem Link:** [1391B - Fix You](https://codeforces.com/problemset/problem/1391/B)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Greedy`
- **Language:** C++

---

## 📌 Problem Statement

A conveyor belt is represented by an $n \times m$ grid. The cell at the bottom-right corner $(n, m)$ houses the collection counter denoted by `'C'`. Every other cell has a direction assigned to it:
- `'R'` moves luggage to the right $(i, j + 1)$.
- `'D'` moves luggage downwards $(i + 1, j)$.

Luggage moving outside the grid boundaries is lost. The conveyor belt is **functional** if luggage placed at any cell eventually reaches $(n, m)$.

Find the **minimum number of cells** whose direction must be changed to make the system functional.

---

## 💡 Key Intuition & Approach

### 1. Border Bottleneck Analysis
- Luggage starting from any inner cell only moves down (`'D'`) or right (`'R'`), moving monotonically closer to the bottom-right corner.
- The only cells where luggage can potentially fall out of the grid boundaries are:
  1. **The last row ($n-1$):** Moving down (`'D'`) falls off the grid. Therefore, every cell in the bottom row except the counter must be `'R'`.
  2. **The last column ($m-1$):** Moving right (`'R'`) falls off the grid. Therefore, every cell in the rightmost column except the counter must be `'D'`.
- Any cell not in the last row or column will eventually reach either the last row or last column safely, provided the boundaries guide it correctly to $(n, m)$.

### 2. Algorithmic Steps
1. For each test case, read dimensions $n$ and $m$, and the matrix of characters.
2. Check the bottom row (`i = n - 1`) for $j = 0$ to $m - 2$: count every `'D'` cell (needs to become `'R'`).
3. Check the rightmost column (`j = m - 1`) for $i = 0$ to $n - 2$: count every `'R'` cell (needs to become `'D'`).
4. Output the total count `cnt`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n + m)$ per test case — Only traverses the boundary row and boundary column. Overall time across all test cases is $\mathcal{O}(t \cdot (n + m))$.
- **Space Complexity:** $\mathcal{O}(n \cdot m)$ — Space to store the grid strings.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `3 3`<br>`RRD`<br>`DDR`<br>`RRC` | `1` | In row 3 (bottom row), `RRC` has no `'D'`. In column 3 (right column), `D`, `R`, `C` has 1 `'R'` at index (1, 2) which falls out. Total changes = 1. |
| `1 4`<br>`DDDC` | `3` | Single row: all three `'D'` cells must become `'R'` to reach `'C'`. |

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
        int n, m;
        cin >> n >> m;
        vector<string> mat(n);
        for (int i = 0; i < n; i++) {
            cin >> mat[i];
        }

        // check only the last row and the last col
        int cnt = 0;
        for (int j = 0; j < m - 1; j++) {
            if (mat[n - 1][j] == 'D') cnt++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (mat[i][m - 1] == 'R') cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}
```
