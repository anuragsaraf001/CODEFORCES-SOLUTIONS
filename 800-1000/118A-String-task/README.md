# A. String Task - Codeforces 118A

- **Platform:** Codeforces
- **Problem Link:** [118A - String Task](https://codeforces.com/problemset/problem/118/A)
- **Difficulty:** 1000 / Easy
- **Tags:** `Implementation`, `Strings`
- **Language:** Python

---

## 📌 Problem Statement

Petya needs to write a program that processes a string consisting of uppercase and lowercase Latin letters as follows:
1. Deletes all the vowels (`'A'`, `'O'`, `'Y'`, `'E'`, `'U'`, `'I'`, and their lowercase counterparts).
2. Inserts a dot (`'.'`) before each remaining consonant.
3. Replaces all uppercase consonants with their corresponding lowercase ones.

Return the final transformed string.

---

## 💡 Key Intuition & Approach

### 1. Case Normalization
Converting the entire string to lowercase (`s = s.lower()`) upfront handles step 3 completely, simplifying vowel checks to just 6 lowercase letters: `{'a', 'o', 'y', 'e', 'u', 'i'}`.

### 2. Filtering & Formatting
1. Store vowels in a set for $\mathcal{O}(1)$ lookup time.
2. Iterate through each character `i` in the lowercase string `s`.
3. If `i` is not in the vowel set, format it as `"." + i` and append it to a result list `res`.
4. Join the list into a single string using `"".join(res)` and print it.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$ — Where $N$ is the length of string $s$ ($N \le 100$). Checking set membership and appending takes linear time.
- **Space Complexity:** $\mathcal{O}(N)$ — To store the transformed characters in the list `res`.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `tour` | `.t.r` | `'o'` and `'u'` are vowels and get removed. `'t'` and `'r'` become `.t` and `.r`. |
| `Codeforces` | `.c.d.f.r.c.s` | Vowels `'o'`, `'e'`, `'o'`, `'e'` are removed; remaining consonants converted to lowercase and prepended with `.`. |
| `aBACABA` | `.b.c.b` | Vowels `'a'`, `'A'` are removed; uppercase `'B'`, `'C'` converted to lowercase `.b`, `.c`. |

---

## 💻 Code

```python
s = input()
s = s.lower()
vowels = {"a", "o", "y", "e", "u", "i"}
res = []

for i in s:
    if i not in vowels:
        res.append("." + i)

print("".join(res))
```
