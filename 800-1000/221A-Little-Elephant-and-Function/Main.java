// To get the final array in ascending order the order must be n,1,2,3,4,....n-1
// so that after the recusrsion the array becomes 1,2,3,4,....n
import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        recursion(n);
    }

    static void recursion(int n){
        System.out.print(n+" ");
        for(int i=1;i<=n-1;i++){
            System.out.print(i+" ");
        }
    }
}