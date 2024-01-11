import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import static java.lang.System.exit;

public class Main {

    static int N, R, C;
    static long Cnt = 0;


    public static void Search(long x, long y, long Size) {

        if (Size == 1)
        {
            if (x == R && y == C)
            {
                System.out.println(Cnt);
                System.exit(0);
            }
        }

        long next = Size / 2;

        if (R >= x && R < x + next && C >= y && C < y + next)
        {
            Search(x, y, next);
        }
        else if (R >= x && R < x + next && C >= y + next && C < y + Size)
        {
            Cnt += Math.pow(next, 2);
            Search(x, y + next, next);
        }
        else if (R >= x + next && R < x + Size && C >= y && C < y + next)
        {
            Cnt += 2 * Math.pow(next, 2);
            Search(x + next, y, next);
        }
        else
        {
            Cnt += 3 * Math.pow(next, 2);
            Search(x + next, y + next, next);
        }

    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        //입력 받기

        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        //공백 단위로 읽기

        Search(0L, 0, (long)Math.pow(2, N));
        //함수 출력

    }
}