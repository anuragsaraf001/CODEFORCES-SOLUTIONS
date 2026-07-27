# A. Football - Codeforces 96A

- **Platform:** Codeforces
- **Problem Link:** [96A - Football](https://codeforces.com/problemset/problem/96/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** Java

---

## 📌 Problem Statement

Petya is watching a football match and writing down the players' positions as a string of `'0'`s and `'1'`s.
- `'0'` represents players of team 0.
- `'1'` represents players of team 1.

The situation is considered **dangerous** if there are **at least 7 players of the same team standing consecutively** (one after another). Determine whether the situation is dangerous (`YES`) or not (`NO`).

---

## 💡 Key Intuition & Approach

### 1. Consecutive Character Tracking
To find if 7 or more identical characters appear consecutively:
1. Maintain a running counter `cnt` for the sequence length and a variable `prev` for the previous character.
2. Initialize `cnt = 1` and `prev = s.charAt(0)`.
3. Iterate through the string starting from index `1`:
   - If the current character equals `prev`, increment `cnt`.
   - Otherwise, reset `cnt = 1` and update `prev` to the current character.
   - If `cnt >= 7` at any point, set `situation = true` and break early.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$ — Where $N$ is the length of string $s$ ($N \le 100$). We traverse the string in a single pass.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses a few primitive variables for tracking counts and characters.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `001001` | `NO` | Maximum consecutive players of the same team is 2. |
| `1000000001` | `YES` | There are 8 consecutive `'0'`s ($\\ge 7$), making the situation dangerous. |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        football(sc);
    }

    static void football(Scanner sc) {
        String s = sc.next();
        boolean situation = false;
        int cnt = 1;
        int prev = s.charAt(0) - '0';
        
        for (int i = 1; i < s.length(); i++) {
            if ((s.charAt(i) - '0') == prev) {
                cnt++;
            } else {
                cnt = 1;
                prev = s.charAt(i) - '0';
            }

            if (cnt >= 7) {
                situation = true;
                break;
            }
        }
        
        System.out.println(situation ? "YES" : "NO");   
    }
}
```
