import java.io.*;
import java.util.*;

public class Main {
    static int N, D, K, C, Ans;
    static int[] Map;
    static HashMap<Integer, Integer> M = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        D = Integer.parseInt(input[1]);
        K = Integer.parseInt(input[2]);
        C = Integer.parseInt(input[3]);

        Map = new int[N];
        for (int i = 0; i < N; i++) {
            Map[i] = Integer.parseInt(br.readLine());
        }

        M.put(C, 1);

        for (int i = 0; i < K; i++) {
            M.put(Map[i], M.getOrDefault(Map[i], 0) + 1);
        }

        Ans = Math.max(Ans, M.size());

        for (int st = 0; st < N; st++) {
            if (M.get(Map[st]) == 1) M.remove(Map[st]);
            else M.put(Map[st], M.get(Map[st]) - 1);

            int en = Make_Range(st + K);
            M.put(Map[en], M.getOrDefault(Map[en], 0) + 1);
            Ans = Math.max(Ans, M.size());
        }

        bw.write(Ans + "\n");
        bw.flush();
        bw.close();
    }

    static int Make_Range(int Idx) {
        if (Idx >= N) return Idx - N;
        else return Idx;
    }
}
