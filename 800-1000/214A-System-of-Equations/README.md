# A. System of Equations - Codeforces 214A

- **Platform:** Codeforces
- **Problem Link:** [214A - System of Equations](https://codeforces.com/problemset/problem/214/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Brute Force`, `Math`, `Implementation`
- **Language:** Java

---

## 📌 Problem Statement

You are given a system of equations with parameters $n$ and $m$:

$$\\begin{cases} a^2 + b = n \\\\ a + b^2 = m \\end{cases}$$

Count how many pairs of non-negative integers $(a, b)$ ($0 \\le a, b$) satisfy both equations simultaneously.

---

## 💡 Key Intuition & Approach

### 1. Constraint Analysis
The input constraints state $1 \\le n, m \\le 1000$. Since $a$ and $b$ must be non-negative integers:
- From $a^2 + b = n$, we know $a^2 \\le n$, which implies $0 \\le a \\le \\sqrt{n}$.
- For $n \\le 1000$, $a$ can range at most from $0$ to $31$.

Because the upper bound on $a$ is extremely small, a **Brute Force** search over all valid values of $a$ is both optimal and straightforward.

### 2. Step-by-Step Logic
1. Loop over all non-negative integers $a$ such that $a^2 \\le n$.
2. For each $a$, determine $b$ directly from the first equation: $b = n - a^2$.
3. Check if this pair $(a, b)$ satisfies the second equation: $a + b^2 == m$.
4. Increment a counter `cnt` whenever the condition holds.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\\mathcal{O}(\\sqrt{n})$ — The loop runs at most $\\sqrt{n} + 1$ times (at most $32$ iterations for $n \\le 1000$).
- **Space Complexity:** $\\mathcal{O}(1)$ — Only a few primitive variables (`n`, `m`, `a`, `b`, `cnt`) are used.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `9 3` | `1` | Pair $(3, 0)$: $3^2 + 0 = 9$ and $3 + 0^2 = 3$. |
| `14 28` | `1` | Pair $(3, 5)$: $3^2 + 5 = 14$ and $3 + 5^2 = 28$. |
| `4 20` | `0` | No non-negative pair $(a, b)$ satisfies both equations. |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SysOfEqn(sc);
    }

    static void SysOfEqn(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int cnt = 0;
        
        for (int a = 0; a * a <= n; a++) {
            int b = n - (a * a);
            if (a + (b * b) == m) {
                cnt++;
            }
        }
        
        System.out.println(cnt);
    }
}
```
