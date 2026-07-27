import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        kString(sc);
    }

    static void kString(Scanner sc){
        int k=sc.nextInt();
        String s=sc.next();
        HashMap<Character,Integer> mpp=new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            mpp.put(ch, mpp.getOrDefault(ch, 0) + 1);
        }
        for(Integer val:mpp.values()){
            if(val%k!=0){
                System.out.println(-1);
                return;
            }
        }
        String rep="";
        for(Character it: mpp.keySet()){
            rep+=String.valueOf(it).repeat(mpp.get(it)/k);
        }
        rep=String.valueOf(rep).repeat(k);
        System.out.println(rep);
    }
}