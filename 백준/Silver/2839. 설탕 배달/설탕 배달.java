import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {

    static int N, Ans = Integer.MAX_VALUE;
    static int C5, C3;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        
        while(C5 * 5 <= N) {
            int Total = C5 * 5;
            int C3 = 0;
            
            while(Total < N) {
                Total += 3;
                C3 += 1;
            }

            if(Total == N) {
                Ans = Math.min(Ans, C5 + C3);
            }
            C5 += 1;
        }

        if(Ans == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(Ans);
    }
}