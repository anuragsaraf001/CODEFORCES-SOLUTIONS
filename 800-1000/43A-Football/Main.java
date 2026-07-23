import java.util.*;

public class Main{
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        football(sc);
    }
    
    static void football(Scanner sc){
        int n=sc.nextInt();
        Map<String,Integer> scores=new HashMap<>();
        for(int i=0;i<n;i++){
            String t=sc.next();
            scores.put(t, scores.getOrDefault(t, 0) + 1);
        }

        String maxKey = "";
        int maxValue = Integer.MIN_VALUE;
        for (Map.Entry<String,Integer> e : scores.entrySet()) {
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