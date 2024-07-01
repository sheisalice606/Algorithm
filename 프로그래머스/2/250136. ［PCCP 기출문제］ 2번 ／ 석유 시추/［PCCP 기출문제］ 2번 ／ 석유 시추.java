import java.io.*;
import java.util.*;
import java.lang.*;


class Point {
    int x;
    int y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    
    static int N, M, Ans;
    static int [][] Map;
    static int [][] Visit;
    
    static int [] dx = {1, -1, 0, 0};
    static int [] dy = {0, 0, 1, -1};
    
    static int [] Sum;
    
    //BFS
    public static void Bfs(int x, int y) {
    
        Queue<Point> Q = new LinkedList<>();
        Q.add(new Point(x, y));
        
        int [] Temp = new int [M + 1];
        Visit[x][y] = 1;
        Temp[y] = 1;
        int Cnt = 1;
        
        while(!Q.isEmpty()) {
            int px = Q.peek().x;
            int py = Q.peek().y;
            Q.poll();
            
            for(int i = 0; i < 4; i++) {
                int nx = px + dx[i];
                int ny = py + dy[i];
                if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
                if(Visit[nx][ny] == 1 || Map[nx][ny] == 0) continue;
                
                Visit[nx][ny] = 1;
                Temp[ny] = 1;
                Cnt++;
                Q.add(new Point(nx ,ny));
            }
        }
    
        //각 석유덩어리가 퍼진 가로행을 체크
        for(int i = 1; i <= M; i++) {
            if(Temp[i] == 1) {
                Sum[i] += Cnt;
            }
        }
        
    }
    
    
    public int solution(int[][] land) {
        
        N = land.length;
        M = land[0].length;
        Map = new int [N + 1][M + 1];
        Visit = new int [N + 1][M + 1];
        Sum = new int [M + 1];
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                Map[i + 1][j + 1] = land[i][j];
            }
        }
        //전역화
       
        for(int i = 1; i <= M; i++) {
            int sum = 0;
            for(int j = 1; j <= N; j++) {
                if(Map[j][i] == 0 || Visit[j][i] == 1) continue;
                Bfs(j, i);
            }
        }
        
        for(int i = 1; i <= M; i++) {
            //System.out.print(Sum[i] + " ");
            Ans = Math.max(Ans, Sum[i]);
        }
        return Ans;
        
        
    }
    
}