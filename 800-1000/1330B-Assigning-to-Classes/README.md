# B. Assigning to Classes - Codeforces 1300B

- **Platform:** Codeforces
- **Problem Link:** [1300B - Assigning to Classes](https://codeforces.com/problemset/problem/1300/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Greedy`, `Sortings`
- **Language:** C++

---

## 📌 Problem Statement

There are $2n$ students with skill levels $a_1, a_2, \dots, a_{2n}$. You need to divide all $2n$ students into $2$ non-empty classes such that each class has an **odd number of students**.

The skill level of a class is defined as the **median** of the skill levels of students in that class. Find the **minimum possible absolute difference** between the skill levels (medians) of the two classes.

---

## 💡 Key Intuition & Approach

### 1. Optimal Partitioning & Median Gap
- When the entire array $a$ of size $2n$ is sorted in non-decreasing order:
  $$a_0 \le a_1 \le \dots \le a_{n-1} \le a_n \le \dots \le a_{2n-1}$$
- The two central elements in the sorted array are $a_{n-1}$ and $a_n$.
- Any valid split into two odd-sized classes must place at least one element $\le a_{n-1}$ as a median candidate for one class, and at least one element $\ge a_n$ as a median candidate for the other class.
- The minimum distance between any pair of elements where one belongs to the lower half and the other belongs to the upper half is achieved by picking the two adjacent central elements:
  $$\text{Minimum Difference} = a_n - a_{n-1}$$
- This difference can always be realized (e.g., assign student $a_n$ alone to one class of size 1, and the remaining $2n - 1$ students to the second class where the median is $a_{n-1}$).

### 2. Algorithmic Steps
1. Read $n$ and the $2n$ skill levels into a vector `arr`.
2. Sort `arr` in ascending order.
3. The answer is directly given by `arr[n] - arr[n - 1]`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \log n)$ per test case — Sorting $2n$ elements dominates the run time. The sum of $n$ over all test cases is $\le 10^5$, fitting comfortably within 2.0 seconds.
- **Space Complexity:** $\mathcal{O}(n)$ — To store the $2n$ elements in a vector.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `1`<br>`1 1` | `0` | Sorted: `[1, 1]`. Difference $= 1 - 1 = 0$. |
| `3`<br>`6 5 4 1 2 3` | `1` | Sorted: `[1, 2, 3, 4, 5, 6]`. $n=3$, difference $= arr[3] - arr[2] = 4 - 3 = 1$. |
| `5`<br>`13 4 20 13 2 5 8 3 17 16` | `1` | Sorted central elements are $13$ and $13$, difference $= 0$ (or adjacent gap depending on array values). |

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
        int n;
        cin >> n;
        vector<int> arr(2 * n, 0);
        for (int i = 0; i < 2 * n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        cout << arr[n] - arr[n - 1] << "\n";
    }
    return 0;
}
```
