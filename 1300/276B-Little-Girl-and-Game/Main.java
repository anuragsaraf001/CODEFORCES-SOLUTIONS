import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            int[] charCount = new int[26];
            for (int i = 0; i < s.length(); i++) {
                charCount[s.charAt(i) - 'a']++;
            }
            int oddCount = 0;
            for (int count : charCount) {
                if (count % 2 != 0) {
                    oddCount++;
                }
            }
            if (oddCount <= 1 || oddCount % 2 != 0) {
                System.out.println("First");
            } else {
                System.out.println("Second");
            }
        }
        sc.close();
    }
}