# A. Magnets - Codeforces 344A

- **Platform:** Codeforces
- **Problem Link:** [344A - Magnets](https://codeforces.com/problemset/problem/344/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`
- **Language:** C++

---

## 📌 Problem Statement

Mike arranges $n$ domino-like magnets horizontally in a row. Each magnet is represented by either `"01"` (plus-minus) or `"10"` (minus-plus).

- Like poles repel (e.g., `"10"` followed by `"01"` brings negative poles together, repelling each other and creating a new group).
- Opposite poles attract (e.g., `"10"` followed by `"10"` brings a negative and positive pole together, linking into the same continuous group).

Find the **total number of magnet groups** formed.

---

## 💡 Key Intuition & Approach

### 1. Group Transition Logic
A new group of magnets starts every time a magnet's orientation differs from the immediately preceding magnet (`a != prevMag`).
- If consecutive magnets have the same orientation (e.g., `"10"` and `"10"`), opposite poles touch and they attach into the same group.
- If consecutive magnets differ (e.g., `"10"` and `"01"`), identical poles touch and repel, creating a distinct new group.

### 2. Algorithmic Steps
1. Initialize `noGroups = 0` and `prevMag = ""`.
2. For each of the $n$ magnets:
   - Read the current magnet string `a`.
   - If `a != prevMag`, increment `noGroups += 1`.
   - Update `prevMag = a`.
3. Output `noGroups`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — Single linear pass reading $n$ strings ($n \le 100\,000$).
- **Space Complexity:** $\mathcal{O}(1)$ — Processes each magnet string on the fly using constant memory.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `6`<br>`10`<br>`10`<br>`10`<br>`01`<br>`10`<br>`10` | `3` | Group 1: `[10, 10, 10]`, Group 2: `[01]`, Group 3: `[10, 10]`. Total = 3 groups. |

---

## 💻 Code

```cpp
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int noGroups = 0;
    string prevMag = "";

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a != prevMag) {
            noGroups += 1;
        }
        prevMag = a;
    }

    cout << noGroups;
    return 0;
}
```
