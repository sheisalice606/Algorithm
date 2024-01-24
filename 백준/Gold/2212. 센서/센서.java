import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.*;
import java.util.StringTokenizer;

import static java.lang.System.exit;

class Edge {
    int cost;
    int start;
    int end;
    Edge(int cost, int start, int end) {
        this.cost = cost;
        this.start = start;
        this.end = end;
    }
}



public class Main {

    static int N, K, Total;
    static List<Integer> Arr = new ArrayList<>();

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;



    static PriorityQueue<Edge> PQ = new PriorityQueue<>(
            Comparator.
                    <Edge>comparingInt(e -> e.cost)
                    .thenComparingInt(e -> e.start)
                    .thenComparingInt(e -> e.end)
                    .reversed()
    );

    public static void Input() throws IOException {
        //N
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        //K
        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        //센서 좌표
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            Arr.add(Integer.parseInt(st.nextToken()));
    }

    public static void main(String[] args) throws IOException {
        Input();

        Collections.sort(Arr);
        Total = Arr.get(Arr.size() - 1) - Arr.get(0);
        //전체 영역의 길이

        for(int i = 0; i < Arr.size() - 1; i++)
            PQ.add(new Edge(Arr.get(i + 1) - Arr.get(i), Arr.get(i), Arr.get(i + 1)));
        //간선 정보 저장

        for(int i = 0; i < K - 1; i++)
        {
            if(PQ.isEmpty()) break;
            Total -= PQ.peek().cost;
            PQ.poll();
        }

        System.out.println(Total);
    }

}