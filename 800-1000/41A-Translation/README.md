# A. Translation - Codeforces 41A

- **Platform:** Codeforces
- **Problem Link:** [41A - Translation](https://codeforces.com/problemset/problem/41/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** Python

---

## 📌 Problem Statement

The translation from the Berland language into the Birland language works as follows: a Berland word differs from a Birland word with the same meaning in that it is spelled (and pronounced) in reverse. For example, a Berland word `code` corresponds to a Birland word `edoc`.

Vasya translated the word $s$ from Berland into Birland as $t$. Help him find out if he translated the word correctly.

---

## 💡 Key Intuition & Approach

### 1. Reversibility Condition
A translation is correct if and only if string $t$ is the exact string $s$ reversed character by character. 

### 2. Two-Pointer Approach
To check if $t$ is the reverse of $s$:
1. **Length Check:** If `len(s) != len(t)`, string $t$ cannot be the reverse of $s$, so the answer is instantly `NO`.
2. **Character Comparison:** Set a pointer `i` starting from the beginning of string $s$ ($0$) and a pointer `j` starting from the end of string $t$ ($\\text{len}(t) - 1$).
3. Compare `s[i]` with `t[j]` character by character. Increment `i` and decrement `j` until all characters are verified or a mismatch is found.
4. If a mismatch is found at any index, set the flag to `False` and terminate early.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\\mathcal{O}(N)$ — Where $N$ is the length of string $s$. In the worst case, we compare every character once.
- **Space Complexity:** $\\mathcal{O}(1)$ — The algorithm checks characters in-place without requiring extra memory proportional to the input size.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `code`<br>`edoc` | `YES` | String `edoc` is the exact reverse of `code`. |
| `abb`<br>`aba` | `NO` | The last character of `abb` is `'b'`, but the reverse should start with `'b'`. `aba` does not match. |
| `code`<br>`code` | `NO` | `code` is not the reverse of `code` (unless it's a palindrome). |

---

## 💻 Code

```python
s = input()
t = input()

ans = True

if len(s) != len(t):
    ans = False
else:
    i = 0
    j = len(t) - 1
    while i < len(s):
        if s[i] != t[j]:
            ans = False
            break
        else: 
            i += 1
            j -= 1

print("YES" if ans else "NO")
```
