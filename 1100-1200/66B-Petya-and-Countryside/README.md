# B. Petya and Countryside - Codeforces 66B

- **Platform:** Codeforces
- **Problem Link:** [66B - Petya and Countryside](https://codeforces.com/problemset/problem/66/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Brute Force`, `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

A garden is represented by $n$ contiguous sections in a $1 \times n$ row, where the $i$-th section has height $h_i$.

Artificial rain can be created over exactly one section. Water flows from a watered section to an adjacent section if the adjacent section's height is **less than or equal to** the current section's height.

Find the **maximum number of sections** that can be watered if the rain is poured optimally over one section.

---

## 💡 Key Intuition & Approach

### 1. Brute Force over All Starting Sections
Since $n \le 1000$, we can simulate watering each section $i$ from $0$ to $n-1$ and determine how far water will flow to the left and to the right.

### 2. Simulation Steps for Section $i$:
1. **Initialize:** `cnt = 1` (the selected section itself is watered).
2. **Left Expansion:**
   - Move `left` from $i - 1$ down to $0$.
   - Water continues flowing as long as $\text{height}[left] \le \text{currHeight}$.
   - Update $\text{currHeight} \leftarrow \text{height}[left]$ and increment `cnt`.
   - Stop as soon as an adjacent left section is strictly taller.
3. **Right Expansion:**
   - Reset $\text{currHeight} \leftarrow \text{height}[i]$.
   - Move `right` from $i + 1$ up to $n - 1$.
   - Water flows as long as $\text{height}[right] \le \text{currHeight}$.
   - Update $\text{currHeight} \leftarrow \text{height}[right]$ and increment `cnt`.
   - Stop as soon as an adjacent right section is strictly taller.
4. Update the answer: $\text{maxSecWatered} = \max(\text{maxSecWatered}, cnt)$.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n^2)$ — For each of the $n$ sections, scanning both left and right takes at most $\mathcal{O}(n)$ steps. For $n \le 1000$, $\approx 10^6$ operations, which easily runs well under the 2.0-second time limit.
- **Space Complexity:** $\mathcal{O}(n)$ — To store the section heights in a vector.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `5`<br>`4 2 3 3 2` | `4` | Rain on section 3 (height 3): water reaches sections 2, 3, 4, 5 (total 4 sections). |
| `1`<br>`1` | `1` | A single section will always have 1 watered section. |

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
    vector<int> heights(n, 0);
    int maxSecWatered = -1;

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i < n; i++) {
        int left = i - 1, right = i + 1;
        int cnt = 1;
        int currHeight = heights[i];

        while (left >= 0) {
            if (heights[left] <= currHeight) {
                cnt++;
                currHeight = heights[left];
            } else {
                break;
            }
            left--;
        }

        currHeight = heights[i];
        while (right < n) {
            if (heights[right] <= currHeight) {
                cnt++;
                currHeight = heights[right];
            } else {
                break;
            }
            right++;
        }

        maxSecWatered = max(maxSecWatered, cnt);
    }

    cout << maxSecWatered << "\n";
    return 0;
}
```
