import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        football(sc);
    }

    static void football(Scanner sc){
        String s=sc.next();
        boolean situation=false;
        int cnt=1;
        int prev=s.charAt(0)-'0';
        for(int i=1;i<s.length();i++){
            if((s.charAt(i)-'0')==prev) cnt++;
            else{
                cnt=1;
                prev=s.charAt(i)-'0';
            }

            if(cnt>=7){
                situation=true;
                break;
            }
        }
        System.out.println(situation ? "YES" : "NO");   
    }
}
