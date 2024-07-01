import java.io.*;
import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {

    static int N, K, Ans;
    static char [] Map;

    static Stack<Integer> Person = new Stack<>();
    static Stack<Integer> Burger = new Stack<>();


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        Map = br.readLine().toCharArray();

        for(int i = N - 1; i >= 0; i--) {
            if(Map[i] == 'H') Burger.push(i);
            else Person.push(i);
        }


        while(!Person.isEmpty() && !Burger.isEmpty()) {
            int p = Person.pop();

            while(!Burger.isEmpty() && p - Burger.peek() > K) {
                Burger.pop();
            }

            if(!Burger.isEmpty() && Math.abs(p - Burger.peek()) <= K) {
                Ans++;
                Burger.pop();
            }
        }

        System.out.println(Ans);
    }


}