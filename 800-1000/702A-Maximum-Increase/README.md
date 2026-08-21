# A. Maximum Increase - Codeforces 702A

- **Platform:** Codeforces
- **Problem Link:** [702A - Maximum Increase](https://codeforces.com/problemset/problem/702/A)
- **Difficulty:** 800 / Easy
- **Tags:** `DP`, `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

You are given an array consisting of $n$ positive integers $a_1, a_2, \dots, a_n$. 

Find the maximum length of a **strictly increasing contiguous subarray** (i.e., a contiguous sequence of elements where each element is strictly greater than the previous one).

---

## 💡 Key Intuition & Approach

### 1. Linear Scan / Kadane-like Window
To track the longest strictly increasing contiguous subarray:
- Maintain a running counter `cnt` for the current increasing streak length.
- Maintain `maxCnt` for the maximum length observed so far.
- Keep track of the previous element `prev`.

### 2. Algorithmic Steps
1. Initialize `cnt = 0`, `maxCnt = INT_MIN`, and `prev = -1` (since all $a_i \ge 1$).
2. For each element $a$ in the input:
   - If $a > prev$, the strictly increasing streak continues: increment `cnt`, update `maxCnt = max(cnt, maxCnt)`, and set `prev = a`.
   - Otherwise, the streak breaks: reset `cnt = 1` and update `prev = a`.
3. Print `maxCnt`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — Single linear scan over all $n$ integers ($n \le 10^5$).
- **Space Complexity:** $\mathcal{O}(1)$ — Processes input stream on the fly using constant auxiliary space.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `5`<br>`1 7 2 11 15` | `3` | Longest strictly increasing subarray is `[2, 11, 15]`. |
| `6`<br>`100 100 100 100 100 100` | `1` | Elements are equal (not strictly increasing), max length is 1. |
| `3`<br>`1 2 3` | `3` | Entire array is strictly increasing. |

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
    int prev = -1;
    int cnt = 0;
    int maxCnt = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > prev) {
            cnt++;
            maxCnt = max(cnt, maxCnt);
            prev = a;
        }
        else {
            cnt = 1;
            prev = a;
        }
    }
    
    cout << maxCnt << "
";
    return 0;
}
```
