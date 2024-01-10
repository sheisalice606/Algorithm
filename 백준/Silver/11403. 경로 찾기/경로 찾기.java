import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static int N;
    static int[][] map;
    static int[] visit;
    static ArrayList<Integer>[] Arr;

    public static void dfs(int x) {
        for (int next : Arr[x]) {
            if (visit[next] == 1) continue;
            visit[next] = 1;
            dfs(next);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        map = new int[N + 1][N + 1];
        visit = new int[N + 1];
        Arr = new ArrayList[N + 1];

        for (int i = 1; i <= N; i++) {
            
            Arr[i] = new ArrayList<>();
            
            for (int j = 1; j <= N; j++) {
                map[i][j] = scanner.nextInt();
                if (map[i][j] == 1) {
                    Arr[i].add(j);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            dfs(i);
            for (int j = 1; j <= N; j++) {
                if (visit[j] == 1) {
                    map[i][j] = 1;
                }
                visit[j] = 0;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }
}



