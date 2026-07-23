# A. Football - Codeforces 43A

- **Platform:** Codeforces
- **Problem Link:** [43A - Football](https://codeforces.com/problemset/problem/43/A)
- **Difficulty:** 800 / Easy
- **Tags:** `Implementation`, `Strings`, `Hashing`
- **Language:** Java

---

## 📌 Problem Statement

Vasya is looking at the results of the Berland 1910 Football Championship finals. He has a description of the match containing $n$ lines, where each line represents a goal scored and contains the name of the team that scored it. 

It is guaranteed that:
- The match did not end in a tie.
- There are no more than two distinct teams in the description.

Help Vasya find the name of the winning team (the team that scored more goals).

---

## 💡 Key Intuition & Approach

### 1. Counting Goal Frequencies
Since there are at most two teams playing, we need to count how many goals each team scores and determine which team has the strictly higher count.

### 2. Frequency Map (HashMap)
1. **Goal Tracking:** We can use a `HashMap<String, Integer>` to track each team's score.
2. **Population:** For each of the $n$ input lines, we retrieve the current goal count of the team using `scores.getOrDefault(team, 0)` and increment it by $1$.
3. **Winner Identification:** Iterate through the entry set of the map to find the team with the maximum score.

---

## ⚡ Complexity Analysis

- **Time Complexity:** $\\mathcal{O}(n \\cdot L)$ — Where $n$ is the number of goals and $L \\le 10$ is the length of the team name. Updating the map takes linear time relative to the number of goals.
- **Space Complexity:** $\\mathcal{O}(L)$ — Since there are at most 2 distinct team names, the hash map stores at most 2 entries.

---

## 🧪 Test Cases

| Input | Output | Explanation / Notes |
| :--- | :--- | :--- |
| `1`<br>`ABC` | `ABC` | Only one goal scored by `ABC`. `ABC` wins with 1 goal. |
| `5`<br>`A`<br>`ABA`<br>`ABA`<br>`A`<br>`A` | `A` | Team `A` scored 3 goals, team `ABA` scored 2 goals. Team `A` wins. |

---

## 💻 Code

```java
import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        football(sc);
    }
    
    static void football(Scanner sc) {
        int n = sc.nextInt();
        Map<String, Integer> scores = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            String t = sc.next();
            scores.put(t, scores.getOrDefault(t, 0) + 1);
        }

        String maxKey = "";
        int maxValue = Integer.MIN_VALUE;
        for (Map.Entry<String, Integer> e : scores.entrySet()) {
            String key = e.getKey();
            int value = e.getValue();
            if (value > maxValue) {
                maxValue = value;
                maxKey = key;
            }
        }
        System.out.println(maxKey);
    } 
}
```
