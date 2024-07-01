import java.io.*;
import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {


    static int N, M;
    static int [][] Map;
    static int [][][] Dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Map = new int[N + 1][M + 1];
        Dp = new int[N + 1][M + 1][3];
        //Input()

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= M; j++) {
                Map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        //Map

        for(int i = 1; i <= M; i++) {
            for (int j = 0; j < 3; j++) {
                Dp[1][i][j] = Map[1][i];
            }
        }
        //초기값 설정

        for(int i = 2; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(j == 1) {
                    Dp[i][j][0] = 0;
                    Dp[i][j][1] = Dp[i - 1][j][2] + Map[i][j];
                    Dp[i][j][2] = Math.min(Dp[i - 1][j + 1][0], Dp[i - 1][j + 1][1]) + Map[i][j];
                }
                else if(j == M) {
                    Dp[i][j][0] = Math.min(Dp[i - 1][j - 1][1], Dp[i - 1][j -1][2]) + Map[i][j];
                    Dp[i][j][1] = Dp[i - 1][j][0] + Map[i][j];
                    Dp[i][j][2] = 0;
                }
                else {
                    Dp[i][j][0] = Math.min(Dp[i - 1][j - 1][1], Dp[i - 1][j -1][2]) + Map[i][j];
                    Dp[i][j][1] = Math.min(Dp[i - 1][j][0], Dp[i - 1][j][2]) + Map[i][j];
                    Dp[i][j][2] = Math.min(Dp[i - 1][j + 1][0], Dp[i - 1][j + 1][1]) + Map[i][j];
                }
            }
        }
        //DP

        int ans = Integer.MAX_VALUE;
        for(int i = 1; i <= M; i++) {
            for(int j = 0; j < 3; j++) {
                if(Dp[N][i][j] == 0) continue;
                ans = Math.min(ans, Dp[N][i][j]);
            }
        }
        System.out.println(ans);
        
    }



}