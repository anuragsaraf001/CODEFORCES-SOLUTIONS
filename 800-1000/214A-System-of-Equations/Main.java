import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        SysOfEqn(sc);
    }

    static void SysOfEqn(Scanner sc){
        int n=sc.nextInt();
        int m=sc.nextInt();
        int cnt=0;
        for(int a=0;a*a<=n;a++){
            int b=n-(a*a);
            if(a+(b*b)==m) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}