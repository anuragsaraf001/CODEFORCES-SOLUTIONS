# A. DZY Loves Chessboard - Codeforces 445A

- **Platform:** Codeforces
- **Problem Link:** [445A - DZY Loves Chessboard](https://codeforces.com/problemset/problem/445/A)
- **Difficulty:** 1000 / Easy
- **Tags:** `Implementation`, `DFS`, `Graphs`
- **Language:** Java

---

## 📌 Problem Statement

DZY has a chessboard of $n$ rows and $m$ columns.
- Good cells are represented by `'.'`.
- Bad cells are represented by `'-'`.

DZY wants to place a black (`'B'`) or white (`'W'`) chessman on every good cell such that **no two adjacent good cells share the same color**. Bad cells `'-'` remain unchanged.

Find any suitable placement of chessmen.

---

## 💡 Key Intuition & Approach

### 1. Global Alternating Pattern
Instead of running a Graph DFS/BFS to color connected components, we can leverage a fundamental property of standard chessboards:
- If we color cells based on the parity of their coordinates $(i + j)$:
  - Cells with **even parity** ($(i + j) \pmod 2 == 0$) are assigned `'B'`.
  - Cells with **odd parity** ($(i + j) \pmod 2 
eq 0$) are assigned `'W'`.

This global checkerboard pattern guarantees that **any** two adjacent cells $(i, j)$ and $(i+1, j)$ or $(i, j+1)$ will always have different parities, ensuring no two adjacent good cells share the same color.

### 2. Algorithmic Steps
1. Initialize an output grid with bad cells `'-'`.
2. Iterate through each cell $(i, j)$ of the input matrix.
3. If `matrix[i][j] == '.'`:
   - Set output cell to `'B'` if $(i + j)$ is **even**.
   - Set output cell to `'W'` if $(i + j)$ is **odd**.
4. Print the final grid.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \cdot m)$ — A single pass traverses all $n \times m$ cells. For $n, m \le 100$, total operations are $\le 10,000$.
- **Space Complexity:** $\mathcal{O}(n \cdot m)$ — To store the input and output character matrices.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `1 1`<br>`.` | `B` | Single good cell at $(0, 0)$. Sum $0 + 0 = 0$ (even) $\rightarrow$ `'B'`. |
| `2 2`<br>`..`<br>`..` | `BW`<br>`WB` | Alternating grid pattern applied across all four good cells. |
| `3 3`<br>`.-.`<br>`---`<br>`.-.` | `B-B`<br>`---`<br>`B-B` | Bad cells `'-'` remain unchanged while good cells follow parity rules. |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    public static ArrayList<ArrayList<Character>> chessboard(ArrayList<ArrayList<Character>> matrix, int n, int m) {
        ArrayList<ArrayList<Character>> output = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            ArrayList<Character> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                row.add('-');
            }
            output.add(row);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0 && matrix.get(i).get(j) == '.') {
                    output.get(i).set(j, 'B');
                } else if ((i + j) % 2 != 0 && matrix.get(i).get(j) == '.') {
                    output.get(i).set(j, 'W');
                }
            }
        }
        return output;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<ArrayList<Character>> matrix = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            ArrayList<Character> row = new ArrayList<>();
            String s = sc.next();
            for (int j = 0; j < m; j++) {
                char a = s.charAt(j);
                row.add(a);
            }
            matrix.add(row);
        }
        
        ArrayList<ArrayList<Character>> output = chessboard(matrix, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(output.get(i).get(j));
            }
            System.out.println();
        }
    }
}
```
