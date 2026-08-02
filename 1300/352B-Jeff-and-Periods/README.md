# B. Jeff and Periods - Codeforces 352B

- **Platform:** Codeforces
- **Problem Link:** [352B - Jeff and Periods](https://codeforces.com/problemset/problem/352/B)
- **Difficulty:** 1000 / Easy
- **Tags:** `Implementation`, `Sorting`, `Hashing`
- **Language:** Java

---

## 📌 Problem Statement

Given a sequence $a_1, a_2, \dots, a_n$, find all unique values $x$ present in the sequence such that the 1-based index positions where $x$ occurs form an **arithmetic progression**.

For each valid $x$:
- If $x$ occurs **exactly once**, its common difference $p_x$ is $0$.
- If $x$ occurs **more than once**, all consecutive index differences must be identical ($p_x$).

Output the total number of valid numbers $t$, followed by each pair $(x, p_x)$ sorted in **ascending order of $x$**.

---

## 💡 Key Intuition & Approach

### 1. Fast I/O & Grouping Indices
For input sizes up to $n = 10^5$, standard `Scanner` can cause Time Limit Exceeded (TLE) in Java. Using `BufferedReader` and `StringBuilder` guarantees fast execution.

To analyze the occurrences of each number:
1. Store occurrence indices of each number using `TreeMap<Integer, ArrayList<Integer>>`.
2. `TreeMap` ensures that keys are automatically processed in **ascending order**, eliminating the need for sorting the output pairs later.

### 2. Checking Arithmetic Progression
For each entry in the map:
- **Size = 1:** Single occurrence $\rightarrow$ valid pair $(x, 0)$.
- **Size = 2:** Two occurrences $\rightarrow$ valid pair $(x, \text{vec}[1] - \text{vec}[0])$.
- **Size > 2:** Calculate common difference $d = \text{vec}[1] - \text{vec}[0]$. Iterate through the list to verify $\text{vec}[i+1] - \text{vec}[i] == d$ for all adjacent pairs. If consistent, add $(x, d)$.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \log k)$ — Where $n$ is the sequence length and $k \le n$ is the number of distinct elements. Inserting into a `TreeMap` takes $\mathcal{O}(n \log k)$. Checking differences takes linear time $\mathcal{O}(n)$ overall.
- **Space Complexity:** $\mathcal{O}(n)$ — To store the index lists in the map.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `1`<br>`2` | `1`<br>`2 0` | Element `2` occurs once at index 0. Output `2 0`. |
| `8`<br>`1 2 1 3 1 2 1 5` | `4`<br>`1 2`<br>`2 4`<br>`3 0`<br>`5 0` | Indices for `1`: `[0, 2, 4, 6]` (diff = 2) $\rightarrow$ `1 2`<br>Indices for `2`: `[1, 5]` (diff = 4) $\rightarrow$ `2 4`<br>Indices for `3` & `5`: single occurrences $\rightarrow$ `3 0`, `5 0`. |

---

## 💻 Code

```java
import java.io.*;
import java.util.*;

public class Main {
    public static ArrayList<int[]> periods(ArrayList<Integer> nums) {
        TreeMap<Integer, ArrayList<Integer>> mpp = new TreeMap<>();
        for (int i = 0; i < nums.size(); i++) {
            if (!mpp.containsKey(nums.get(i))) {
                mpp.put(nums.get(i), new ArrayList<>());
            }
            mpp.get(nums.get(i)).add(i);
        }
        ArrayList<int[]> res = new ArrayList<>();
        for (Map.Entry<Integer, ArrayList<Integer>> it : mpp.entrySet()) {
            int num = it.getKey();
            ArrayList<Integer> vec = it.getValue();
            if (vec.size() == 1) res.add(new int[]{num, 0});
            else if (vec.size() == 2) res.add(new int[]{num, vec.get(1) - vec.get(0)});
            else {
                int diff = vec.get(1) - vec.get(0);
                boolean ans = true;
                for (int i = 1; i < vec.size() - 1; i++) {
                    if (vec.get(i + 1) - vec.get(i) != diff) {
                        ans = false;
                        break;
                    }
                }
                if (ans) res.add(new int[]{num, diff});
            }
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        
        String line = br.readLine();
        if (line == null) return;
        
        int n = Integer.parseInt(line.trim());
        ArrayList<Integer> nums = new ArrayList<>(n);
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nums.add(Integer.parseInt(st.nextToken()));
        }
        
        ArrayList<int[]> res = periods(nums);
        
        StringBuilder sb = new StringBuilder();
        sb.append(res.size()).append("
");
        for (int[] it : res) {
            sb.append(it[0]).append(" ").append(it[1]).append("
");
        }
        
        System.out.print(sb.toString());
    }
}
```
