import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    //static int N;
    //static HashMap<Integer, Integer> Hash = new HashMap<>();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int len = str.length();
        int idx = 0;        
        int ans = 1;
        
        while(true) {
            
            String temp = Integer.toString(ans);
            for(int i = 0; i < temp.length(); i++) {
                if(temp.charAt(i) == str.charAt(idx)) {
                    idx++;
                    if(idx == len) break;
                }
            }
            
            if(idx == len) break;
            ans++;
        }

        System.out.println(ans);

    }

    
}