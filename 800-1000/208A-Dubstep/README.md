# A. Dubstep - Codeforces 208A

- **Platform:** Codeforces
- **Problem Link:** [208A - Dubstep](https://codeforces.com/problemset/problem/208/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Strings`, `Implementation`
- **Language:** Python

---

## 📌 Problem Statement

Vasya made a dubstep remix of a song by inserting the substring `"WUB"` an arbitrary number of times before the first word, after the last word, and between words of the original song.

Given the remixed song string, restore the original song words separated by single spaces.

---

## 💡 Key Intuition & Approach

### 1. String Splitting
Since `"WUB"` was inserted as a delimiter throughout the original text:
1. Splitting the input string `s` using `"WUB"` as the delimiter via `s.split("WUB")` extracts all individual words.
2. Consecutive `"WUB"` occurrences or `"WUB"` at the start/end will result in empty strings `""` in the list.

### 2. Filtering Empty Strings
Iterate through the list of split substrings and print non-empty strings separated by spaces.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$ — Where $N$ is the length of the string ($N \le 200$). Splitting and printing take linear time.
- **Space Complexity:** $\mathcal{O}(N)$ — To store the split substrings.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB` | `WE ARE THE CHAMPIONS MY FRIEND` | Substring `"WUB"` is removed from all positions, leaving original words. |
| `WUBWUBABCWUB` | `ABC` | Leading and trailing `"WUB"` delimiters are ignored. |

---

## 💻 Code

```python
s = input()
aList = s.split("WUB")

for i in aList:
    if i != '':
        print(i, end=" ")
```
