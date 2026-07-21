# A. Jeff and Digits - Codeforces 352A

- **Platform:** Codeforces
- **Problem Link:** [352A - Jeff and Digits](https://codeforces.com/problemset/problem/352/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Math`, `Greedy`, `Implementation`
- **Language:** Java

---

## 📌 Problem Statement

Jeff has $n$ cards, where each card contains either the digit `0` or `5`. He wants to select a subset of these cards and arrange them into the **largest possible number** divisible by **$90$** without leading zeroes.

If no such number can be formed, output `-1`.

---

## 💡 Key Intuition & Approach

### 1. Divisibility Rules for 90
A number is divisible by $90$ if and only if it satisfies two conditions simultaneously:
1. **Divisible by 10:** The number must end with at least one `0`. Therefore, if we have no `0` cards (`cnt0 == 0`), it is impossible to form a valid number $\rightarrow$ output `-1`.
2. **Divisible by 9:** The sum of the digits must be a multiple of $9$. Since our non-zero cards are all `5`, the sum of the `5`s must be a multiple of $9$. This means the count of `5`s used must be a multiple of $9$ ($9, 18, 27, \dots$).

### 2. Edge Case & Greedy Construction
* **Fewer than 9 Fives (`cnt5 < 9`):** We cannot use any `5`s because we can't reach a sum divisible by $9$. Since we must include at least one `0` for divisibility by $10$, the largest number we can form is just `0` (leading zeros like `000` are invalid, so it simplifies to a single `0`).
* **At least 9 Fives (`cnt5 >= 9`):** To maximize the value, we should use as many `5`s as possible (rounded down to the nearest multiple of $9$), followed by **all** available `0`s at the end.

### 3. Step-by-Step Logic
1. Count the number of `0`s (`cnt0`) and `5`s (`cnt5`).
2. If `cnt0 == 0`, print `-1`.
3. Else if `cnt5 < 9`, print `0`.
4. Else, append `(cnt5 / 9) * 9` copies of `'5'` followed by `cnt0` copies of `'0'` and print the string.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$ — Reading $n$ inputs and constructing the output string of length up to $n$ runs in linear time.
- **Space Complexity:** $\mathcal{O}(n)$ — Allocating string buffers to hold up to $n$ characters.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `4`<br>`5 0 5 0` | `0` | We have two `5`s and two `0`s. Since `cnt5 < 9`, we cannot use any `5`s. Largest number is `0`. |
| `11`<br>`5 5 5 5 5 5 5 5 5 5 0` | `5555555550` | We have ten `5`s and one `0`. We can use nine `5`s (sum = 45, divisible by 9) + one `0` at the end. |
| `1`<br>`5` | `-1` | No `0`s available, so we cannot make a number divisible by 10. Output `-1`. |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        largestPossible(n, sc);
    }

    static void largestPossible(int n, Scanner sc) {
        int cnt0 = 0, cnt5 = 0;
        for (int i = 0; i < n; i++) {
            int digit = sc.nextInt();
            if (digit == 5) cnt5++;
            else cnt0++;
        }
        
        if (cnt0 < 1) {
            System.out.println(-1);
        } else if (cnt5 < 9) {
            System.out.println(0);
        } else {
            String repeated5 = "5".repeat((cnt5 / 9) * 9);
            String repeated0 = "0".repeat(cnt0);
            System.out.println(repeated5 + repeated0);
        }
    }
}