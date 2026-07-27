# A. k-String - Codeforces 219A

- **Platform:** Codeforces
- **Problem Link:** [219A - k-String](https://codeforces.com/problemset/problem/219/A)
- **Difficulty:** 1000 / Easy
- **Tags:** `Implementation`, `Strings`, `Hashing`
- **Language:** Java

---

## 📌 Problem Statement

A string is called a $k$-string if it can be represented as $k$ concatenated copies of some base string. 

Given a string $s$ consisting of lowercase English letters and an integer $k$, reorder the characters in $s$ so that the resulting string is a $k$-string. If no such rearrangement is possible, output `-1`.

---

## 💡 Key Intuition & Approach

### 1. Divisibility Condition
For a string to be constructed as $k$ identical repeated blocks:
- Every distinct character in $s$ must appear a total number of times that is **divisible by $k$**.
- If any character frequency $\\text{count} \\pmod k \\neq 0$, it is impossible to distribute it equally across $k$ blocks $\\rightarrow$ output `-1`.

### 2. Base Block Construction
1. Count character frequencies using a `HashMap<Character, Integer>`.
2. Check if every frequency is divisible by $k$.
3. Build the base repeating block `rep` by taking each character and appending it $\\text{count} / k$ times.
4. Repeat the base block `rep` exactly $k$ times to construct the final output string.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\\mathcal{O}(|s|)$ — Counting character frequencies and constructing the repeated string runs in linear time proportional to the length of string $s$.
- **Space Complexity:** $\\mathcal{O}(|s|)$ — Storing character counts in the hash map (at most 26 entries) and building the resulting string of length $|s|$.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `2`<br>`aazz` | `azaz` | Each character `'a'` and `'z'` appears twice (divisible by 2). Base block = `az`, repeated 2 times $\\rightarrow$ `azaz`. |
| `3`<br>`abcabcabz` | `-1` | Character `'z'` appears only 1 time, which is not divisible by 3. Output `-1`. |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        kString(sc);
    }

    static void kString(Scanner sc) {
        int k = sc.nextInt();
        String s = sc.next();
        HashMap<Character, Integer> mpp = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            mpp.put(ch, mpp.getOrDefault(ch, 0) + 1);
        }
        
        for (Integer val : mpp.values()) {
            if (val % k != 0) {
                System.out.println(-1);
                return;
            }
        }
        
        String rep = "";
        for (Character it : mpp.keySet()) {
            rep += String.valueOf(it).repeat(mpp.get(it) / k);
        }
        
        rep = String.valueOf(rep).repeat(k);
        System.out.println(rep);
    }
}
```
