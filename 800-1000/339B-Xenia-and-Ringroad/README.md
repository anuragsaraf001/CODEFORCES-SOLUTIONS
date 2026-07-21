# B. Xenia and Ringroad - Codeforces 339B

- **Platform:** Codeforces
- **Problem Link:** [339B - Xenia and Ringroad](https://codeforces.com/problemset/problem/339/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Implementation`, `Math`
- **Language:** Python 3

---

## 📌 Problem Statement

Xenia lives in a city with $n$ houses arranged in a circle along a main ringroad, numbered $1$ to $n$ in clockwise order. Traffic flows strictly in a **one-way clockwise direction**.

Xenia starts at house $1$ and needs to complete $m$ tasks in sequence. To complete the $i$-th task, she must travel clockwise to house $a_i$. Moving to an adjacent house takes $1$ unit of time. If she is already at the target house, moving takes $0$ time units. 

Determine the total minimum time required to complete all $m$ tasks in order.

---

## 💡 Key Intuition & Approach

### 1. Clockwise Distance Calculations
Since movement is strictly clockwise around a circular array of size $n$, moving from house $u$ to house $v$ breaks down into three simple scenarios:

1. **Moving Forward ($v > u$):** 
   - Direct clockwise distance: $v - u$
2. **Wrapping Around ($v < u$):** 
   - Moving to the end of the ringroad ($n - u$) plus moving from house $n$ back around to house $v$ ($v$ steps): $(n - u) + v$
3. **Staying at Same House ($v = u$):** 
   - Distance is $0$.

### 2. Step-by-Step Logic
1. **Initialize Position:** Set `lastVisit = 1` and total time `ans = 0`.
2. **Iterate Tasks:** Loop through each target house $a$ in $a\_list$:
   - If $a > lastVisit$, add $a - lastVisit$ to `ans`.
   - If $a < lastVisit$, add $(n - lastVisit) + a$ to `ans`.
   - If $a = lastVisit$, do nothing (distance added is 0).
   - Update `lastVisit = a`.
3. **Print Output:** Output `ans`.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m)$ — We iterate through the $m$ task positions once, performing constant-time $\mathcal{O}(1)$ operations for each.
- **Space Complexity:** $\mathcal{O}(m)$ — Storing the list of tasks takes memory proportional to $m$, well within limits ($m \le 10^5$).

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `4 3`<br>`3 2 3` | `6` | $1 \rightarrow 3$ takes $2$ units.<br>$3 \rightarrow 2$ wraps around: $(4-3) + 2 = 3$ units.<br>$2 \rightarrow 3$ takes $1$ unit.<br>Total: $2 + 3 + 1 = 6$. |
| `4 3`<br>`2 3 3` | `2` | $1 \rightarrow 2$ takes $1$ unit.<br>$2 \rightarrow 3$ takes $1$ unit.<br>$3 \rightarrow 3$ takes $0$ units.<br>Total: $1 + 1 + 0 = 2$. |

---

## 💻 Code

```python
n, m = map(int, input().split())
a_list = list(map(int, input().split()))

lastVisit = 1  # Xenia starts at house 1
ans = 0

for a in a_list:
    if a > lastVisit:
        ans += (a - lastVisit)
    elif a < lastVisit:
        ans += ((n - lastVisit) + a)
    lastVisit = a

print(ans)