# A. Little Elephant and Function - Codeforces 221A

- **Platform:** Codeforces
- **Problem Link:** [221A - Little Elephant and Function](https://codeforces.com/problemset/problem/221/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Math`, `Implementation`
- **Language:** Java

---

## 📌 Problem Statement

The Little Elephant defines a recursive sorting function $f(x)$ on a permutation $a$ of numbers from $1$ to $n$:
- If $x = 1$, exit the function.
- Otherwise, recursively call $f(x - 1)$, and then swap $a_{x-1}$ and $a_x$.

Find an initial permutation of numbers from $1$ to $n$ such that executing $f(n)$ leaves the permutation sorted in strictly ascending order ($1, 2, 3, \dots, n$).

---

## 💡 Key Intuition & Approach

### 1. Tracing the Swaps
When $f(n)$ is called:
1. $f(n-1)$ is called first, which recursively processes elements up to index $n-1$.
2. After returning from $f(n-1)$, a swap between $a_{n-1}$ and $a_n$ occurs.

By induction:
- Calling $f(n)$ shifts the element currently at the front (index 1) all the way to the end (index $n$) through a series of adjacent swaps.
- To end up with $n$ at the last index, $n$ must start at index 1.
- All other elements $1, 2, \dots, n-1$ shift to the left by one position.

### 2. Required Initial Permutation
To obtain the sorted array $1, 2, 3, \dots, n$ after execution, the starting permutation must be:
$$n, 1, 2, 3, \dots, n-1$$

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — Printing $n$ integers in a single loop.
- **Space Complexity:** $\mathcal{O}(1)$ — No extra data structures are allocated.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2` | `2 1` | Calling $f(2)$ swaps index 1 and 2, turning `2 1` into `1 2`. |
| `4` | `4 1 2 3` | $f(4)$ recursively shifts `4` to the end, resulting in `1 2 3 4`. |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        recursion(n);
    }

    static void recursion(int n) {
        System.out.print(n + " ");
        for (int i = 1; i <= n - 1; i++) {
            System.out.print(i + " ");
        }
    }
}
```
