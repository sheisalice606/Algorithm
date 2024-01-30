import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static int Arr[];
    
    public static void Solution() throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        Arr = new int [N + 1];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) Arr[i] = Integer.parseInt(st.nextToken());
        
        
        K = Integer.parseInt(br.readLine());
        while (K-- > 0) {
            st = new StringTokenizer(br.readLine());
            
            int Gender = Integer.parseInt(st.nextToken());
            int Num = Integer.parseInt(st.nextToken());
            switch (Gender) {
                case 1:
                    int Temp = Num;
                    while (Temp <= N) {
                        Arr[Temp] ^= 1;
                        Temp += Num;
                    }
                    break;
                case 2 :
                    Arr[Num] ^= 1;
                    int Len = Math.min(Num - 1, N - Num);
                    
                    for (int i = 1; i <= Len; i++) {
                        if (Arr[Num - i] != Arr[Num + i]) break;
                        Arr[Num - i] ^= 1;
                        Arr[Num + i] ^= 1;
                    }
                    break;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        int Cnt = 0;
        for (int i = 1; i <= N; i++) {
            sb.append(Arr[i]).append(' ');
            Cnt++;
            if (Cnt == 20) {
                Cnt = 0;
                System.out.println(sb);
                sb = new StringBuilder();
            }
        }
        System.out.println(sb);
    }
    

    public static void main(String[] args) throws Exception {
        Solution();
    }

}