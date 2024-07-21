import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    static int N, Ans = Integer.MIN_VALUE;
    static int [][] Map;
    static int [] dx = {1, -1, 0, 0};
    static int [] dy = {0, 0, 1, -1};

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void Input() throws IOException{
        N = Integer.parseInt(br.readLine());
        Map = new int[N + 1][N + 1];
        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= N; j++) {
                Map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static int Make_Ans(int [][] temp) {
        int res = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                res = Math.max(res, temp[i][j]);
            }
        }
        return res;
    }

    public static void Print(int [][] temp) {
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                sb.append(temp[i][j] + " ");
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }

    public static void Dfs(int count, int [][] curr) {
        if(count == 5) {
            Ans = Math.max(Ans, Make_Ans(curr));
            return;
        }

        for(int d = 0; d < 4; d++) {

            int [][] temp = new int [N + 1][N + 1];
            for(int i = 1; i <= N; i++) {
                temp[i] = curr[i].clone();
            } //이렇게 해야지 깊은 복사가 된다.

            if(d == 0) {
                for(int i = 1; i <= N; i++) {
                    Stack<Integer> Stack = new Stack<>();

                    for(int j = 1; j <= N; j++) {
                        if(temp[j][i] > 0) {
                            Stack.push(temp[j][i]);
                            temp[j][i] = 0;
                        }
                    }

                    for(int j = N; j >= 1; j--) {
                        if(Stack.size() >= 2) {
                            int first = Stack.pop();
                            int second = Stack.pop();
                            if(first == second) temp[j][i] = first + second;
                            else {
                                temp[j][i] = first;
                                Stack.push(second);
                            }
                        }
                        else if(Stack.size() == 1) {
                            temp[j][i] = Stack.pop();
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            else if(d == 1) {
                for(int i = 1; i <= N; i++) {
                    Stack<Integer> Stack = new Stack<>();

                    for(int j = N; j >= 1; j--) {
                        if(temp[j][i] > 0) {
                            Stack.push(temp[j][i]);
                            temp[j][i] = 0;
                        }
                    }

                    for(int j = 1; j <= N; j++) {
                        if(Stack.size() >= 2) {
                            int first = Stack.pop();
                            int second = Stack.pop();
                            if(first == second) temp[j][i] = first + second;
                            else {
                                temp[j][i] = first;
                                Stack.push(second);
                            }
                        }
                        else if(Stack.size() == 1) {
                            temp[j][i] = Stack.pop();
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            else if(d == 2) {
                for(int i = 1; i <= N; i++) {
                    Stack<Integer> Stack = new Stack<>();

                    for(int j = 1; j <= N; j++) {
                        if(temp[i][j] > 0) {
                            Stack.push(temp[i][j]);
                            temp[i][j] = 0;
                        }
                    }

                    for(int j = N; j >= 1; j--) {
                        if(Stack.size() >= 2) {
                            int first = Stack.pop();
                            int second = Stack.pop();
                            if(first == second) temp[i][j] = first + second;
                            else {
                                temp[i][j] = first;
                                Stack.push(second);
                            }
                        }
                        else if(Stack.size() == 1) {
                            temp[i][j] = Stack.pop();
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            else {
                for(int i = 1; i <= N; i++) {
                    Stack<Integer> Stack = new Stack<>();

                    for(int j = N; j >= 1; j--) {
                        if(temp[i][j] > 0) {
                            Stack.push(temp[i][j]);
                            temp[i][j] = 0;
                        }
                    }

                    for(int j = 1; j <= N; j++) {
                        if(Stack.size() >= 2) {
                            int first = Stack.pop();
                            int second = Stack.pop();
                            if(first == second) temp[i][j] = first + second;
                            else {
                                temp[i][j] = first;
                                Stack.push(second);
                            }
                        }
                        else if(Stack.size() == 1) {
                            temp[i][j] = Stack.pop();
                        }
                        else {
                            break;
                        }
                    }
                }
            }

            Dfs(count + 1, temp);

        }
    }

    public static void main(String[] args) throws IOException {
        Input();
        Dfs(0, Map);
        System.out.println(Ans);
    }

}