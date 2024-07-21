import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    static int N, K, L;
    static int [][] Apple, Snake_Map;
    static int [] dx = {1, 0, -1, 0};
    static int [] dy = {0, 1, 0, -1};

    static ArrayList<Point> Snake_Point = new ArrayList<>();
    static Queue<Info> Cmd = new LinkedList<>();


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    private static class Point {
        int x, y;
        Point(int x, int y) {this.x=x; this.y=y;}
    }
    private static class Info {
        int time, dir;
        Info(int time, char dir) {this.time=time; this.dir=dir;}
    }

    public static void Input() throws IOException {
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        Apple = new int[N + 1][N + 1];
        Snake_Map = new int[N + 1][N + 1];

        for(int i = 1; i <= K; i++) {
            st = new StringTokenizer(br.readLine());
            Apple[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = 1;
        }

        L = Integer.parseInt(br.readLine());
        for(int i = 1; i <= L; i++) {
            st = new StringTokenizer(br.readLine());
            Cmd.add(new Info(Integer.parseInt(st.nextToken()), st.nextToken().charAt(0)));
        }
    }

    public static void main(String[] args) throws IOException {

        Input();
        int time = 1, dir = 1;
        //초기 방향은 오른쪽이다.
        Snake_Point.add(new Point(1, 1));
        Snake_Map[1][1] = 1;

        while(true) {

            int x = Snake_Point.get(Snake_Point.size() - 1).x;
            int y = Snake_Point.get(Snake_Point.size() - 1).y;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            //머리 늘리기 시도

            if(nx < 1 || ny < 1 | nx > N || ny > N) break;
            if(Snake_Map[nx][ny] == 1) break;

            Snake_Point.add(new Point(nx, ny));
            Snake_Map[nx][ny] = 1;
            //머리 늘리기 확정

            if(Apple[nx][ny] == 1) {
                Apple[nx][ny] = 0;
            }
            else {
                Snake_Map[Snake_Point.get(0).x][Snake_Point.get(0).y] = 0;
                Snake_Point.remove(0);
            }
            //사과의 유무에 따라서 꼬리 단축을 결정한다.

            if(!Cmd.isEmpty() && Cmd.peek().time == time) {
                if(Cmd.peek().dir == 'D') {
                    if(dir == 0) dir = 3;
                    else dir--;
                }
                else if(Cmd.peek().dir == 'L') {
                    if(dir == 3) dir = 0;
                    else dir++;
                }
                Cmd.poll();
            }
            //방향 전환의 타이밍이라면
            time++;
        }

        System.out.println(time);
    }

}