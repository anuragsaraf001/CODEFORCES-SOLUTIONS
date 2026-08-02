import java.io.*;
import java.util.*;

public class Main {
    public static ArrayList<int[]> periods(ArrayList<Integer> nums){
        TreeMap<Integer,ArrayList<Integer>> mpp=new TreeMap<>();
        for(int i=0;i<nums.size();i++){
            if(!mpp.containsKey(nums.get(i))){
                mpp.put(nums.get(i),new ArrayList<>());
            }
            mpp.get(nums.get(i)).add(i);
        }
        ArrayList<int[]> res=new ArrayList<>();
        for(Map.Entry<Integer,ArrayList<Integer>> it:mpp.entrySet()){
            int num=it.getKey();
            ArrayList<Integer> vec=it.getValue();
            if(vec.size()==1) res.add(new int[]{num,0});
            else if (vec.size()==2) res.add(new int[]{num,vec.get(1)-vec.get(0)});
            else{
                int diff=vec.get(1)-vec.get(0);
                boolean ans=true;
                for(int i=1;i<vec.size()-1;i++){
                    if(vec.get(i+1)-vec.get(i)!=diff){
                        ans=false;
                        break;
                    }
                }
                if(ans) res.add(new int[]{num,diff});
            }
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        
        String line = br.readLine();
        if(line == null) return;
        
        int n = Integer.parseInt(line.trim());
        ArrayList<Integer> nums = new ArrayList<>(n);
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            nums.add(Integer.parseInt(st.nextToken()));
        }
        
        ArrayList<int[]> res = periods(nums);
        
        StringBuilder sb = new StringBuilder();
        sb.append(res.size()).append("\n");
        for(int[] it: res){
            sb.append(it[0]).append(" ").append(it[1]).append("\n");
        }
        
        System.out.print(sb.toString());
    }
}