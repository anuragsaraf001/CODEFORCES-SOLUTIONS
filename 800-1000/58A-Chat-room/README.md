# A. Chat room - Codeforces 58A

- **Platform:** Codeforces
- **Problem Link:** [58A - Chat room](https://codeforces.com/problemset/problem/58/A)
- **Difficulty:** 1000 / Easy
- **Tags:** `Greedy`, `Strings`, `Two Pointers`
- **Language:** Java

---

## 📌 Problem Statement

Vasya typed a word $s$ in a chat room. He managed to say `"hello"` if we can delete zero or more characters from $s$ such that the remaining characters form the exact word `"hello"`.

Determine whether Vasya managed to say `"hello"` (`YES`) or not (`NO`).

---

## 💡 Key Intuition & Approach

### 1. Subsequence Matching
The problem requires checking whether `"hello"` is a **subsequence** of the input string $s$.

### 2. Two-Pointer / Linear Scan
1. Define a target string `target = "hello"` and a pointer `targetInd = 0` to track how many characters of `"hello"` have been matched.
2. Iterate through each character of the input string $s$:
   - If `s.charAt(i)` matches `target.charAt(targetInd)`, increment `targetInd`.
   - If `targetInd` reaches the length of `"hello"` ($5$), break early as all required characters have been found in order.
3. If `targetInd == target.length()`, print `YES`; otherwise, print `NO`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(|s|)$ — Where $|s|$ is the length of string $s$ ($|s| \le 100$). A single linear pass processes each character once.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a few primitive variables and a constant target string of length 5.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `ahhellllloou` | `YES` | Subsequence `'h'`, `'e'`, `'l'`, `'l'`, `'o'` can be matched in order. |
| `hlelo` | `NO` | Characters are out of order (starts with `'h'`, then `'l'` instead of `'e'`). |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        hello(s);
    }

    static void hello(String s) {
        String target = "hello";
        int targetInd = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == target.charAt(targetInd)) {
                targetInd++;
            }
            if (targetInd == target.length()) break;
        }               
        
        if (targetInd == target.length()) System.out.println("YES");
        else System.out.println("NO");
    }
}
```
