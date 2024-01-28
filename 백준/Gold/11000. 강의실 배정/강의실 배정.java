import java.util.*;
import java.lang.*;
import java.io.*;

class Pair {
    int st;
    int en;
    Pair(int st, int en) {
        this.st = st;
        this.en = en;
    }
}

class Main {

    static int N, Ans = 1;
    static Pair Arr [];
    static PriorityQueue<Integer> PQ = new PriorityQueue<>();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Arr = new Pair[N];
        //초기화

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            Arr[i] = new Pair(start, end);
        }
        //입력

        Arrays.sort(Arr, Comparator.<Pair>comparingInt(e->e.st)
            .thenComparingInt(e->e.en)
        );
        //정렬

        int curr_st = Arr[0].st;
        int curr_en = Arr[0].en;
        PQ.add(curr_en);
        
        for(int i = 1; i < N; i++) {

            curr_st = Arr[i].st;
            curr_en = Arr[i].en;

            //안겹치고 시작 가능한 경우
            while(!PQ.isEmpty() && PQ.peek() <= curr_st) PQ.poll();      
            PQ.add(curr_en);
            Ans = Math.max(Ans, PQ.size());
        }

        System.out.println(Ans);
        
    }
}
