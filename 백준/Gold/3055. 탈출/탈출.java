import java.util.*;
import java.lang.*;
import java.io.*;


class Point {
    int x;
    int y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Main {

    static int N, M;
    static int Sx, Sy;
    static int Gx, Gy;

    static int dx [] = {1, -1, 0, 0};
    static int dy [] = {0, 0, 1, -1};
    
    
    static char Map[][];
    static int Visit[][];
    
    static int Water[][];
    static Queue<Point> Q = new LinkedList<>();
    static Queue<Point> Q2 = new LinkedList<>();

    public static void Print() {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                System.out.print(Water[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();
    }

    
    //1초 전이
    public static void Spread() {
        int Size = Q.size();
        while(Size > 0) {

            int x = Q.peek().x;
            int y = Q.peek().y;
            Q.poll();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
                if(Water[nx][ny] == 1) continue; //물
                if(Map[nx][ny] == 'X' || Map[nx][ny] == 'D') continue; //돌 or 목적지

                Water[nx][ny] = 1;
                Q.add(new Point(nx, ny));
            }   

            Size--;
        }
    }

    //1초 이동
    public static int Move() {
        
        int Size = Q2.size();
        if(Size == 0) {
            return -1;
            //이동 불가능한 상황
        }
        
        while(Size > 0) {

            int x = Q2.peek().x;
            int y = Q2.peek().y;
            Q2.poll();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];        

                if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
                if(Map[nx][ny] == '*' || Map[nx][ny] == 'X') continue;
                if(Water[nx][ny] == 1) continue;
                if(Visit[nx][ny] == 1) continue;

                if(Map[nx][ny] == 'D') {
                    return 1;
                    //목적지에 도착한 상황
                }

                Visit[nx][ny] = 1;
                Q2.add(new Point(nx, ny));
            }   

            Size--;
        }

        return 0;
        //진전이 없는 상황
    }


    
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
       
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Map = new char [N+1][M+1];
        Water = new int [N+1][M+1];
        Visit = new int [N+1][M+1];

        //다닥다닥 붙어있는 경우는 StringTokenizer 사용하지 않는다.
        //String Temp = br.readLine() 로 해서
        //Map[i][j] = Temp.charAt(i) 형식으로 사용한다.
        
        for(int i = 1; i <= N; i++) {
            String Temp = br.readLine();
            for(int j = 1; j <= M; j++) {
                Map[i][j] = Temp.charAt(j - 1);
                if(Map[i][j] == 'D') {
                    Gx = i;
                    Gy = j;
                }
                if(Map[i][j] == 'S') {
                    Sx = i;
                    Sy = j;
                    Visit[i][j] = 1;
                    Q2.add(new Point(i, j));
                }
                if(Map[i][j] == '*') {
                    Q.add(new Point(i, j));
                    Water[i][j] = 1;
                }
            }
        }
        //초기 입력


        int Time = 1;
        while(true) {
            Spread(); //물 퍼짐
            int Result = Move(); //이동
            
            if(Result == 0) {
                Time++;
                continue;
            }
            else if(Result == -1) {
                System.out.println("KAKTUS");
                break;
            } 
            else if(Result == 1) {
                System.out.println(Time);
                break;
            }
        }
        //시뮬레이션

        
        
    }
}