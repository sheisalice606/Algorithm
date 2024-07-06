import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    public static int T, N, M, W, Ans;
    public static int [] Cost, Dp, Degree;
    public static ArrayList<Integer> [] Node;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {

            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            Cost = new int[N + 1];
            Dp = new int[N + 1];
            Degree = new int[N + 1];
            Node = new ArrayList[N + 1];
            for(int i = 0; i <= N; i++) {
                Node[i] = new ArrayList<>();
            }
            //초기화

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                Cost[i] = Integer.parseInt(st.nextToken());
            }

            for(int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                Node[from].add(to);
                Degree[to]++;
            }

            W = Integer.parseInt(br.readLine());
            Queue<Integer> Q = new LinkedList<>();

            for(int i = 1; i <= N; i++) {
                if(Degree[i] == 0) {
                    Dp[i] = Cost[i];
                    Q.add(i);
                }
            }
            //입력


            while(!Q.isEmpty()) {
                int curr = Q.poll();
                for(int i = 0; i < Node[curr].size(); i++) {
                    int next = Node[curr].get(i);
                    Dp[next] = Math.max(Dp[next], Dp[curr] + Cost[next]);
                    if(--Degree[next] == 0) {
                        Q.add(next);
                    }
                }
            }

            System.out.println(Dp[W]);

        }

    }

}