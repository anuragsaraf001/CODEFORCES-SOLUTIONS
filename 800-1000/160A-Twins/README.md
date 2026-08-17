# A. Twins - Codeforces 160A

- **Platform:** Codeforces
- **Problem Link:** [160A - Twins](https://codeforces.com/problemset/problem/160/A)
- **Difficulty:** 900 / Easy
- **Tags:** `Greedy`, `Sorting`
- **Language:** C++

---

## 📌 Problem Statement

You are given $n$ coins with values $a_1, a_2, \dots, a_n$. You want to take the **minimum number of coins** such that the total sum of your chosen coins is **strictly greater** than the sum of the remaining coins.

---

## 💡 Key Intuition & Approach

### 1. Greedy Choice Strategy
To minimize the count of coins needed to exceed the remaining sum:
- Always choose the **largest available coins first**.
- Each large coin maximizes your sum increase while simultaneously reducing the twin's potential share by the largest possible amount.

### 2. Algorithmic Steps
1. Read $n$ and all coin values into a vector `coins`.
2. Compute `total_sum`, which is the sum of all coin values.
3. Sort `coins` in **descending order** using `std::sort(coins.rbegin(), coins.rend())`.
4. Iterate through the sorted coins, accumulating `my_sum` and incrementing `coin_count`.
5. Break out of the loop as soon as `my_sum > total_sum - my_sum` (equivalently, $2 \cdot 	ext{my\_sum} > 	ext{total\_sum}$).
6. Output `coin_count`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \log n)$ — Sorting $n \le 100$ coins dominates the time complexity. The subsequent linear pass takes $\mathcal{O}(n)$.
- **Space Complexity:** $\mathcal{O}(n)$ — To store the coin values in a vector.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2`<br>`3 3` | `2` | Total sum $= 6$. Taking 1 coin gives $3$ ($3 \le 3$, not strictly greater). Taking both coins gives $6 > 0$. |
| `3`<br>`2 1 2` | `2` | Total sum $= 5$. Sorted: `[2, 2, 1]`. Taking two largest coins gives $4 > 1$. |

---

## 💻 Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> coins(n);
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
        total_sum += coins[i];
    }
    
    std::sort(coins.rbegin(), coins.rend());
    
    int my_sum = 0;
    int coin_count = 0;
    for (int coin : coins) {
        my_sum += coin;
        coin_count++;
        if (my_sum > total_sum - my_sum) {
            break;
        }
    }
    
    std::cout << coin_count << "\n";
    return 0;
}
```
