# A. Next Round - Codeforces 158A

- **Platform:** Codeforces
- **Problem Link:** [158A - Next Round](https://codeforces.com/problemset/problem/158/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

A total of $n$ participants took part in a contest. Participant scores $a_1, a_2, \dots, a_n$ are given in non-increasing order.

A contestant advances to the next round if and only if:
1. Their score is **equal to or greater than** the score of the $k$-th place finisher ($a_k$).
2. Their score is **strictly positive** ($a_i > 0$).

Calculate the total number of participants who advance to the next round.

---

## 💡 Key Intuition & Approach

### 1. Determining Cutoff Score
Since array indexing in 0-based systems maps the $k$-th finisher to index `k - 1`:
- Store the score of the $k$-th place finisher as `cutoff = arr[k - 1]`.

### 2. Counting Advancers
Iterate through each score `it` in `arr`:
- Increment counter `cnt` if `it >= cutoff` **and** `it > 0`.
- Print `cnt`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — Single linear scan over $n$ elements ($n \le 50$).
- **Space Complexity:** $\mathcal{O}(n)$ — To store scores in a vector.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `8 5`<br>`10 9 8 7 7 7 5 5` | `6` | 5th finisher has $7$ points. Scores $\ge 7$ and $> 0$: $10, 9, 8, 7, 7, 7$ ($6$ total). |
| `4 2`<br>`0 0 0 0` | `0` | No contestant earned a score $> 0$. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    int cutoff = arr[k - 1];
    int cnt = 0;
    for (auto it : arr) {
        if (it >= cutoff && it > 0) cnt++;
    }
    
    cout << cnt;
    return 0;
}
```
