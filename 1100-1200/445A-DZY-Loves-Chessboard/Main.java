import java.util.*;

public class Main {
    public static ArrayList<ArrayList<Character>> chessboard(ArrayList<ArrayList<Character>> matrix,int n,int m){
        ArrayList<ArrayList<Character>> output=new ArrayList<>();
        for(int i=0;i<n;i++){
            ArrayList<Character> row=new ArrayList<>();
            for(int j=0;j<m;j++){
                row.add('-');
            }
            output.add(row);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+j)%2==0 && matrix.get(i).get(j)=='.') output.get(i).set(j,'B');
                else if((i+j)%2!=0 && matrix.get(i).get(j)=='.') output.get(i).set(j,'W');
            }
        }
        return output;
    }

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        ArrayList<ArrayList<Character>> matrix=new ArrayList<>();
        for(int i=0;i<n;i++){
            ArrayList<Character> row=new ArrayList<>();
            String s=sc.next();
            for(int j=0;j<m;j++){
                char a=s.charAt(j);
                row.add(a);
            }
            matrix.add(row);
        }
        ArrayList<ArrayList<Character>> output=chessboard(matrix,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                System.out.print(output.get(i).get(j));
            }
            System.out.println();
        }
    }
}