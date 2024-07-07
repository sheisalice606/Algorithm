import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    static int N, M, Ans = Integer.MIN_VALUE;
    static int [] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    static int [][] Visit;
    static char [][] Map;
    static HashMap<Character, Integer> Hash = new HashMap<>();


    public static void Dfs(int x, int y, int count) {

        //System.out.println(x + " " + y);

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if(Hash.containsKey(Map[nx][ny]) || Visit[nx][ny] == 1) continue;

            //System.out.println("NO : " + nx + " " + ny);

            Visit[nx][ny] = 1;
            Hash.put(Map[nx][ny], 1);
            Dfs(nx, ny, count + 1);
            Hash.remove(Map[nx][ny]);
            Visit[nx][ny] = 0;
        }

        //System.out.println("CHECK");
        Ans = Math.max(Ans, count);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Map = new char[N+1][M+1];
        Visit = new int[N+1][M+1];
        //

        for(int i = 1; i <= N; i++) {
            String temp = br.readLine();
            for(int j = 1; j <= M; j++) {
                Map[i][j] = temp.charAt(j - 1);
            }
        }
        //


        Visit[1][1] = 1;
        Hash.put(Map[1][1], 1);
        Dfs(1, 1, 1);
        bw.write(String.valueOf(Ans));
        bw.flush();
        bw.close();

    }

}