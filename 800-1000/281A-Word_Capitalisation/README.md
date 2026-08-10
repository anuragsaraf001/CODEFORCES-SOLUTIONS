# A. Word Capitalization - Codeforces 281A

- **Platform:** Codeforces
- **Problem Link:** [281A - Word Capitalization](https://codeforces.com/problemset/problem/281/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** C++

---

## 📌 Problem Statement

Capitalization is writing a word with its first letter in uppercase and the remaining letters as they were originally.

Given a single word, capitalize its first letter if it is lowercase, and leave all other characters untouched.

---

## 💡 Key Intuition & Approach

### 1. ASCII Value Manipulation
In ASCII encoding:
- Lowercase letters `'a'` to `'z'` have integer values $97$ to $122$.
- Uppercase letters `'A'` to `'Z'` have integer values $65$ to $90$.
- The difference between a lowercase letter and its uppercase counterpart is exactly $32$.

### 2. Check and Convert
1. Read the input string $s$.
2. Check if the first character $s[0]$ is a lowercase letter (`s[0] >= 'a' && s[0] <= 'z'`).
3. If it is lowercase, subtract $32$ from its ASCII value (`s[0] -= 32`).
4. Output the modified string $s$.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(|s|)$ to read and print — Checking and modifying the first character is an $\mathcal{O}(1)$ constant-time operation.
- **Space Complexity:** $\mathcal{O}(1)$ — Uses standard string storage.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `ApPlE` | `ApPlE` | First character `'A'` is already uppercase, left unchanged. |
| `konjac` | `Konjac` | First character `'k'` is lowercase, converted to `'K'`. |

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] -= 32;
    }

    cout << s;
    return 0;
}
```
