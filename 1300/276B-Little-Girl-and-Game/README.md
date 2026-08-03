# B. Little Girl and Game - Codeforces 276B

- **Platform:** Codeforces
- **Problem Link:** [276B - Little Girl and Game](https://codeforces.com/problemset/problem/276/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Games`, `Greedy`, `Strings`
- **Language:** Java

---

## 📌 Problem Statement

Two players, First and Second, play a game on a string $s$. 

In each turn, a player can remove any single character from the string. A player wins if, after their move (or initially before any move), the remaining string can be rearranged to form a **palindrome**. 

Assuming both players play optimally, determine who wins: `"First"` or `"Second"`.

---

## 💡 Key Intuition & Approach

### 1. Palindrome Condition
A string can be rearranged into a palindrome if and only if **at most one** character has an **odd frequency count**:
- If `oddCount <= 1`, the initial string is already a palindrome anagram, so the **First** player wins immediately without making any moves.

### 2. Game Theory Parity Strategy
If `oddCount > 1`, players will greedily remove characters to reduce or maintain odd frequencies:
- Each turn, a player removes a character belonging to an odd frequency count, reducing `oddCount` by 1.
- If `oddCount` is **odd**, it will take an odd number of total moves to reduce `oddCount` down to 1. Since the First player takes the 1st, 3rd, 5th... moves, the **First** player will make the final move that reduces `oddCount` to 1 and wins.
- If `oddCount` is **even**, it will take an even number of total moves to reach `oddCount == 1`, meaning the **Second** player will make the winning move.

### 3. Summary Decision Rule
- If `oddCount <= 1` or `oddCount` is **odd** $\rightarrow$ `"First"` wins.
- If `oddCount > 1` and `oddCount` is **even** $\rightarrow$ `"Second"` wins.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(|s|)$ — Counting character frequencies requires a single pass over string $s$. Scanning the frequency array of size 26 takes $\mathcal{O}(1)$ time.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a fixed-size frequency array of length 26.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `aba` | `First` | Initial string is already a palindrome (`oddCount = 1`). First wins immediately. |
| `abacaba` | `First` | `oddCount = 1` (`'c'`). First wins immediately. |
| `ab` | `First` | `oddCount = 2` (`'a'`, `'b'`). First removes 1 character $\rightarrow$ 1 character remaining (`oddCount = 1`). First wins. |

---

## 💻 Code

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            int[] charCount = new int[26];
            for (int i = 0; i < s.length(); i++) {
                charCount[s.charAt(i) - 'a']++;
            }
            int oddCount = 0;
            for (int count : charCount) {
                if (count % 2 != 0) {
                    oddCount++;
                }
            }
            if (oddCount <= 1 || oddCount % 2 != 0) {
                System.out.println("First");
            } else {
                System.out.println("Second");
            }
        }
        sc.close();
    }
}
```
