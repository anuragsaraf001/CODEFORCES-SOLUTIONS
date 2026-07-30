# A. Puzzles - Codeforces 337A

- **Platform:** Codeforces
- **Problem Link:** [337A - Puzzles](https://codeforces.com/problemset/problem/337/A)
- **Difficulty:** 900 / Easy
- **Tags:** `Greedy`, `Sorting`
- **Language:** Java

---

## 📌 Problem Statement

Ms. Manana wants to buy $n$ jigsaw puzzles for her $n$ students out of $m$ puzzles available in the shop. Each puzzle $i$ has $f_i$ pieces.

To avoid upsetting the children, she wants to minimize the difference between the largest puzzle size ($A$) and the smallest puzzle size ($B$) among the $n$ selected puzzles ($A - B$).

Find the minimum possible value of $A - B$.

---

## 💡 Key Intuition & Approach

### 1. Sorting & Sliding Window
To minimize $A - B$ when picking $n$ elements out of $m$:
1. If we sort the puzzle piece quantities in ascending order, any optimal subset of $n$ elements will form a **contiguous subsegment** in the sorted array.
2. After sorting, the smallest element in a subsegment starting at index $i$ is `arr[i]`, and the largest element (since we pick $n$ elements) is `arr[i + n - 1]`.
3. We can use a **sliding window of size $n$** across the sorted array from index $i = 0$ to $m - n$ and find the minimum value of `arr[i + n - 1] - arr[i]`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \log m)$ — Sorting the array of size $m$ takes $\mathcal{O}(m \log m)$. The sliding window pass takes $\mathcal{O}(m - n + 1) = \mathcal{O}(m)$.
- **Space Complexity:** $\mathcal{O}(m)$ — To store $m$ puzzle sizes in an array.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `4 6`<br>`10 12 10 7 5 22` | `5` | Sorted: `[5, 7, 10, 10, 12, 22]`. Windows of size 4:<br>- `[5, 7, 10, 10]` $\rightarrow 10 - 5 = 5$<br>- `[7, 10, 10, 12]` $\rightarrow 12 - 7 = 5$<br>- `[10, 10, 12, 22]` $\rightarrow 22 - 10 = 12$<br>Minimum difference is `5`. |

---

## 💻 Code

```java
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[m];
        for (int i = 0; i < m; i++) {
            arr[i] = sc.nextInt();
        }
        puzzles(n, m, arr);
    }

    static void puzzles(int n, int m, int[] arr) {
        Arrays.sort(arr);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i <= m - n; i++) {
            int currentDiff = arr[i + n - 1] - arr[i];
            minDiff = Math.min(minDiff, currentDiff);
        }
        System.out.println(minDiff);
    }
}
```
