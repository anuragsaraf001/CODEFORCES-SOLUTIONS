# A. Magic Numbers - Codeforces 320A

- **Platform:** Codeforces
- **Problem Link:** [320A - Magic Numbers](https://codeforces.com/problemset/problem/320/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Greedy`, `Implementation`, `Strings`, `Brute Force`
- **Language:** Python 3

---

## 📌 Problem Statement

A **magic number** is a number formed entirely by concatenating the building blocks **`1`**, **`14`**, and **`144`**. Each of these building blocks can be used any number of times in any order.

Given an integer $n$ ($1 \le n \le 10^9$), determine if it is a magic number. Output **`YES`** if it can be formed using only these blocks, or **`NO`** otherwise.

---

## 💡 Key Intuition & Approach

### 1. Greedy Token Matching (Greedy Parsing)
To check if the string can be parsed into valid tokens, we scan the number from left to right:
* Always try to match the **longest valid block first** (`"144"` before `"14"`, and `"14"` before `"1"`). Matching greedy token sizes prevents shorter prefixes from corrupting a longer valid pattern (e.g., treating `"144"` as `"14"` + `"4"` would cause a failure since `'4'` alone is invalid).

### 2. Step-by-Step Logic
1. **Convert to Digits:** Read input integer `n` and convert it into a list of string characters.
2. **Greedy Scan (`while` loop):**
   - Check if current position starts with `'1'`, followed by `'4'`, followed by `'4'`. If yes, replace current index with `'144'`, clear the next two indices (`''`), and advance pointer `i` by `3`.
   - Else, check if current position starts with `'1'`, followed by `'4'`. If yes, replace current index with `'14'`, clear the next index (`''`), and advance pointer `i` by `2`.
   - Otherwise, advance pointer `i` by `1`.
3. **Verification:** Iterate through the modified list. If any token is not in `['', '1', '14', '144']`, mark `isMagic = False`.
4. **Output:** Print `YES` if all tokens match, otherwise `NO`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(L)$ — where $L$ is the number of digits in $n$. Since $n \le 10^9$, $L \le 10$. The pointer traverses the string in a single linear pass, doing constant-time string comparisons.
- **Space Complexity:** $\mathcal{O}(L)$ — storing the list of characters for $n$, requiring minimal memory usage (well under the $256 \text{ MB}$ limit).

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `114114` | `YES` | Parsed as `1` + `14` + `1` + `14`. All blocks are valid. |
| `1111` | `YES` | Parsed as `1` + `1` + `1` + `1`. All blocks are valid. |
| `1444` | `NO` | Parsed as `144` + `4`. The remaining `'4'` is invalid on its own. |
| `514` | `NO` | Starts with `'5'`, which is not allowed. |
| `414` | `NO` | Starts with `'4'`. Must begin with `'1'`. |

---

## 💻 Code

```python
n = int(input())
lst = list(str(n))
i = 0

# Greedy replacement pass
while i < len(lst):
    if lst[i] == '1' and i + 2 < len(lst) and lst[i+1] == '4' and lst[i+2] == '4':
        lst[i] = '144'
        lst[i+1] = ''
        lst[i+2] = ''
        i += 3
    elif lst[i] == '1' and i + 1 < len(lst) and lst[i+1] == '4':
        lst[i] = '14'
        lst[i+1] = ''
        i += 2
    else:
        i += 1

# Validation pass
isMagic = True
for a in lst:
    if a not in ['', '1', '14', '144']:
        isMagic = False
        break

print("YES" if isMagic else "NO")