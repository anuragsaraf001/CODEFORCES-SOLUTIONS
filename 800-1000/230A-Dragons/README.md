# A. Dragons - Codeforces 230A

- **Platform:** Codeforces
- **Problem Link:** [230A - Dragons](https://codeforces.com/problemset/problem/230/A)
- **Difficulty:** 1000 / Easy
- **Tags:** `Greedy`, `Sorting`
- **Language:** C++

---

## 📌 Problem Statement

Kirito is playing an MMORPG and needs to defeat $n$ dragons to move to the next level. Kirito's initial strength is $s$.

For each dragon $i$:
- The dragon has a strength of $x_i$.
- If Kirito defeats the dragon, he gains a bonus strength of $y_i$.

Kirito can defeat a dragon **only if** his current strength $s > x_i$. Kirito can fight dragons in **any order**. Determine if he can defeat all $n$ dragons without losing a single duel.

---

## 💡 Key Intuition & Approach

### 1. Greedy Strategy
To maximize Kirito's chances of defeating all dragons, he should always fight the **weakest available dragon first**. 

By defeating weaker dragons early:
1. Kirito avoids tougher dragons when his strength is still low.
2. He accumulates bonus strength ($y_i$), making it easier to defeat stronger dragons later.

### 2. Algorithmic Steps
1. Store dragon strength $x_i$ and bonus $y_i$ as pairs: `pair<int, int>`.
2. **Sort** the list of dragons in ascending order based on their strength $x_i$ (`sort(power.begin(), power.end())`).
3. Iterate through the sorted list:
   - If Kirito's strength $s \le x_i$, output `NO` and terminate (he cannot defeat this dragon).
   - Otherwise, defeat the dragon and increase strength: $s \leftarrow s + y_i$.
4. If all dragons are defeated, output `YES`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \log n)$ — Sorting $n$ dragon pairs takes $\mathcal{O}(n \log n)$ time. The subsequent linear scan takes $\mathcal{O}(n)$ time.
- **Space Complexity:** $\mathcal{O}(n)$ — To store the list of $n$ dragon pairs in a vector.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2 2`<br>`1 99`<br>`100 0` | `YES` | Kirito starts with strength $2$. Defeats dragon 1 ($1 < 2$), gaining $+99$ strength ($s = 101$). Then defeats dragon 2 ($100 < 101$). |
| `10 1`<br>`100 100` | `NO` | Kirito's initial strength $10 \le 100$, so he loses immediately. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void dragons(int s, vector<pair<int, int>> &power) {
    for (auto it : power) {
        if (s <= it.first) {
            cout << "NO";
            return;
        }
        s += it.second;
    }
    cout << "YES"; 
}

int main() {
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> power;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        power.push_back({x, y});
    }
    sort(power.begin(), power.end());
    dragons(s, power);
    return 0;
}
```
