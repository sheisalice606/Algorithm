import java.io.*;
import java.util.*;

public class Main {

    static int N, M, Time = 1;
    static int [] Parent, Visit, Rank;
    static boolean[] isCycle;

    public static void Init() {
        for(int i = 1; i <= N; i++) {
            Parent[i] = i;
            Rank[i] = 1;
            isCycle[i] = false;
        }
    }

    public static int Find(int x) {
        if(x == Parent[x]) return x;
        else return Parent[x] = Find(Parent[x]);
    }

    public static void Merge(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a != b) {
            if (Rank[a] > Rank[b]) {
                Parent[b] = a;
            } else if (Rank[a] < Rank[b]) {
                Parent[a] = b;
            } else {
                Parent[b] = a;
                Rank[a]++;
            }
        } else {
            isCycle[a] = true;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        while(true) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            if(N == 0 && M == 0) break;
            Parent = new int[N + 1];
            Visit = new int[N + 1];
            Rank = new int[N + 1];
            isCycle = new boolean[N + 1];
            Init();

            for(int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                Merge(a, b);
            }

            HashSet<Integer> Set = new HashSet<>();
            for(int i = 1; i <= N; i++) {
                int root = Find(i);
                if(!isCycle[root]) Set.add(root);
            }

            int Ans = Set.size();
            if(Ans == 0) {
                sb.append("Case " + Time++ + ": No trees.\n");
            }
            else if(Ans == 1) {
                sb.append("Case " + Time++ + ": There is one tree.\n");
            }
            else {
                sb.append("Case " + Time++ + ": A forest of " + Ans + " trees.\n");
            }
        }

        bw.write(sb.toString());
        bw.close();
        br.close();
    }
}
