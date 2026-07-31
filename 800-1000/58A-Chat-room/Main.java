import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        hello(s);
    }
    static void hello(String s){
        String target="hello";
        int targetInd=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==target.charAt(targetInd)){
                targetInd++;
            }
            if(targetInd==target.length()) break;
        }               
        if(targetInd==target.length()) System.out.println("YES");
        else System.out.println("NO");
    }
}