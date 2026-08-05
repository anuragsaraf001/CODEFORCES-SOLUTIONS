# B. Shower Line - Codeforces 431B

- **Platform:** Codeforces
- **Problem Link:** [431B - Shower Line](https://codeforces.com/problemset/problem/431/B)
- **Difficulty:** 1100 / Easy
- **Tags:** `Brute Force`, `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

Five students (numbered $0$ to $4$) line up to take a shower. While waiting, students talk in pairs: the $(2i - 1)$-th person talks with the $(2i)$-th person in the current line.

As each student finishes their shower and leaves, the remaining students advance in line, forming new adjacent pairs:
1. **Initial line $(p_0, p_1, p_2, p_3, p_4)$:** Pairs $(p_0, p_1)$ and $(p_2, p_3)$ talk.
2. **$p_0$ leaves:** Pairs $(p_1, p_2)$ and $(p_3, p_4)$ talk.
3. **$p_1$ leaves:** Pair $(p_2, p_3)$ talks.
4. **$p_2$ leaves:** Pair $(p_3, p_4)$ talks.
5. **$p_3$ & $p_4$ shower:** No more talks.

When student $i$ talks to student $j$, total happiness increases by $g_{i, j} + g_{j, i}$. Find the initial line permutation that **maximizes total happiness**.

---

## 💡 Key Intuition & Approach

### 1. Brute Force via Permutations
Since there are only $5$ students, the total number of line permutations is:
$$5! = 120$$
With such a small search space ($120$ iterations), we can evaluate every permutation using C++'s `std::next_permutation`.

### 2. Total Happiness Formula
For any ordered permutation array `p = [p0, p1, p2, p3, p4]`, the total happiness generated is:
$$\begin{aligned}
\text{sum} = &(g_{p_0, p_1} + g_{p_1, p_0} + g_{p_2, p_3} + g_{p_3, p_2}) \\
+ &(g_{p_1, p_2} + g_{p_2, p_1} + g_{p_3, p_4} + g_{p_4, p_3}) \\
+ &(g_{p_2, p_3} + g_{p_3, p_2}) \\
+ &(g_{p_3, p_4} + g_{p_4, p_3})
\end{aligned}$$

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(5! \cdot 1) = \mathcal{O}(1)$ — Exactly $120$ permutations evaluated in under a millisecond.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a fixed $5 \times 5$ grid and a 5-element array.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| $5 \times 5$ matrix with $g_{0, 4} = 9$ | `18` | Optimal line puts student $0$ and $4$ together when they can talk multiple times ($g_{0, 4} + g_{4, 0} = 9 + 9 = 18$). |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void showerLine(vector<vector<int>> &matrix) {
    int maxHap = -1;
    vector<int> nums = {0, 1, 2, 3, 4};
    
    do {
        int sum = 0;
        sum = (matrix[nums[0]][nums[1]] + matrix[nums[1]][nums[0]] + matrix[nums[2]][nums[3]] + matrix[nums[3]][nums[2]]) +
              (matrix[nums[1]][nums[2]] + matrix[nums[2]][nums[1]] + matrix[nums[3]][nums[4]] + matrix[nums[4]][nums[3]]) +
              (matrix[nums[2]][nums[3]] + matrix[nums[3]][nums[2]]) +
              (matrix[nums[3]][nums[4]] + matrix[nums[4]][nums[3]]);
              
        maxHap = max(maxHap, sum);
    } while (next_permutation(nums.begin(), nums.end()));
    
    cout << maxHap << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> matrix(5, vector<int>(5, 0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
        }
    }
    
    showerLine(matrix);
    return 0;
}
```
