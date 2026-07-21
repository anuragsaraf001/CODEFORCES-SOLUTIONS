import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        largestPossible(n, sc);
    }
 
    static void largestPossible(int n, Scanner sc) {
        int cnt0 = 0, cnt5 = 0;
        for (int i = 0; i < n; i++) {
            int digit = sc.nextInt();
            if (digit == 5) cnt5++;
            else cnt0++;
        }
        if (cnt0 < 1) System.out.println(-1);
        else if (cnt5 < 9 && cnt0 > 0) System.out.println(0);
        else {
            String repeated5 = "5".repeat((cnt5 / 9) * 9);
            String repeated0 = "0".repeat(cnt0);
            System.out.println(repeated5 + repeated0);
        }
    }
}