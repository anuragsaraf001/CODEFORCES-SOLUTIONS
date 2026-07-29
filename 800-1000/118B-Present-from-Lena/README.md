# B. Present from Lena - Codeforces 118B

- **Platform:** Codeforces
- **Problem Link:** [118B - Present from Lena](https://codeforces.com/problemset/problem/118/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Implementation`
- **Language:** Python

---

## 📌 Problem Statement

Lena wants to sew a patterned handkerchief for Vasya using digits from $0$ to $n$. The digits form a **rhombus** pattern where:
- The largest digit $n$ is at the center.
- Digits decrease as they approach the edges.
- Each line has leading spaces to align the rhombus.
- Numbers on each line are separated by a single space, with **no trailing spaces** after the last digit of any line.

Given $n$ ($2 \le n \le 9$), output the resulting handkerchief pattern.

---

## 💡 Key Intuition & Approach

### 1. Mathematical Symmetry
Instead of splitting the top and bottom halves into separate nested loops, we can use absolute values to model the rhombus symmetrically:
- Total number of rows is $2n + 1$ (indexed from $i = 0$ to $2n$).
- The maximum digit for row $i$ is $k = n - |n - i|$.
- As $i$ goes from $0 \to n \to 2n$, $k$ seamlessly increases from $0 \to n$ and then decreases back to $0$.

### 2. Row Formatting
For each row with maximum value $k$:
1. **Digits Array:** Construct `row_nums` by concatenating ascending values `[0, ..., k]` with descending values `[k-1, ..., 0]`.
2. **Leading Spaces:** Calculate leading spaces as `"  " * (n - k)` to align the peak at the center.
3. **Output String:** Join the digits with single spaces (`" ".join(...)`) to ensure no trailing spaces exist at the end of the line.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\\mathcal{O}(n^2)$ — Iterates through $2n + 1$ rows, generating $\\mathcal{O}(n)$ digits per row. Given $n \\le 9$, it runs in well under a millisecond.
- **Space Complexity:** $\\mathcal{O}(n)$ — To store the list of digits per row.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2` | `  0`<br>` 0 1 0`<br>`0 1 2 1 0`<br>` 0 1 0`<br>`  0` | Rhombus pattern centered around $2$. |
| `3` | `    0`<br>`  0 1 0`<br>` 0 1 2 1 0`<br>`0 1 2 3 2 1 0`<br>` 0 1 2 1 0`<br>`  0 1 0`<br>`    0` | Rhombus pattern centered around $3$. |

---

## 💻 Code

```python
n = int(input())

for i in range(2 * n + 1):
    k = n - abs(n - i)
    row_nums = list(range(k + 1)) + list(range(k - 1, -1, -1))
    leading_spaces = "  " * (n - k)
    digits_str = " ".join(str(x) for x in row_nums)
    
    if leading_spaces:
        print(leading_spaces + digits_str)
    else:
        print(digits_str)
```
