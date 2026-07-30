import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[m];
        for (int i = 0; i < m; i++) {
            arr[i] = sc.nextInt();
        }
        puzzles(n, m, arr);
    }

    static void puzzles(int n, int m, int[] arr) {
        Arrays.sort(arr);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i <= m - n; i++) {
            int currentDiff = arr[i + n - 1] - arr[i];
            minDiff = Math.min(minDiff, currentDiff);
        }
        System.out.println(minDiff);
    }
}