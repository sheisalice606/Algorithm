import java.io.*;
import java.util.*;


class Team {
    int id;
    int[] scoreList;
    int submitNum;
    int lastSubmit;
    int totalScore;
}


public class Main {

    static int T, N, K, MID, M;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;


    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());

        for (int t = 0; t < T; t++) {

            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            MID = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());


            Team[] Arr = new Team[N];
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int ID = Integer.parseInt(st.nextToken());
                int J = Integer.parseInt(st.nextToken());
                int S = Integer.parseInt(st.nextToken());

                //처음 등장한 팀 초기화
                if (Arr[ID - 1] == null) {
                    Arr[ID - 1] = new Team();
                    Arr[ID - 1].id = ID;
                    Arr[ID - 1].scoreList = new int[K + 1];
                }

                Arr[ID - 1].scoreList[J] = Math.max(S, Arr[ID - 1].scoreList[J]);
                Arr[ID - 1].submitNum++;
                Arr[ID - 1].lastSubmit = i;
            }


            for (int i = 0; i < N; i++) {
                int sum = 0;
                for (int j = 1; j <= K; j++) {
                    sum += Arr[i].scoreList[j];
                }
                Arr[i].totalScore = sum;
            }

            Arrays.sort(Arr, Comparator
                    .<Team>comparingInt(e -> e.totalScore).reversed()
                    .thenComparingInt(e -> e.submitNum)
                    .thenComparingInt(e -> e.lastSubmit));


            for (int i = 0; i < N; i++) {
                if (Arr[i].id == MID)
                    System.out.println(i + 1);
            }

        }


        br.close();
    }


}
