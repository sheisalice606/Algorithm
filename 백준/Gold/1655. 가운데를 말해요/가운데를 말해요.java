import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    public static PriorityQueue<Integer> Q1 = new PriorityQueue<>(Collections.reverseOrder());
    public static PriorityQueue<Integer> Q2 = new PriorityQueue<>();
    public static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        N = Integer.parseInt(br.readLine());

        for(int i = 1; i <= N; i++) {
            int n = Integer.parseInt(br.readLine());
            if(i == 1) {
                sb.append(n + "\n");
                Q1.add(n);
                continue;
            }

            //전체 짝수인 경우
            if((Q1.size() == Q2.size())) {
                if(!Q2.isEmpty() && Q2.peek() >= n) {
                    Q1.add(n);
                    sb.append(Q1.peek() + "\n");
                }
                else {
                    Q2.add(n);
                    sb.append(Q2.peek() + "\n");
                    Q1.add(Q2.poll());
                }
            }
            else {
                if(!Q1.isEmpty() && Q1.peek() <= n) {
                    Q2.add(n);
                    sb.append(Q1.peek() + "\n");
                }
                else {
                    Q2.add(Q1.poll());
                    Q1.add(n);
                    sb.append(Q1.peek() + "\n");
                }
            }
        }

        bw.write(sb.toString());
        bw.close();
    }

}