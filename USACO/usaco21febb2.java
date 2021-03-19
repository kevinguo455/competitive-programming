/*
USACO 2021 February Bronze P2 - Comfortable Cows
Key Concepts: Implementation
https://dmoj.ca/problem/usaco21febb2
Solution by Kevin Guo
*/
import java.io.*;
import java.util.*;

public class usaco21febb2 {	
	
    static final int MAXN = 1001;
    static boolean[][] arr = new boolean[MAXN][MAXN];   // current pasture state (1 == cow, 0 == no cow)

    // is (x, y) within bounds [0, MAXN)?
    static boolean in_range(int x, int y) {
        return (x >= 0 && y >= 0 && x < MAXN && y < MAXN);
    }

    // is (x, y) comfortable? 
    static boolean is_comfortable(int x, int y) {
        int c = 0;
        if (in_range(x-1, y) && arr[x-1][y]) c++;
        if (in_range(x+1, y) && arr[x+1][y]) c++;
        if (in_range(x, y-1) && arr[x][y-1]) c++;
        if (in_range(x, y+1) && arr[x][y+1]) c++;
        return c == 3;
    }

	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));	

        int score = 0;
		int cows = Integer.parseInt(input.readLine());

		for (int i = 0, x, y; i < cows; i++) {

            StringTokenizer st = new StringTokenizer(input.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            // calculate net impact of adding a cow at (x, y)
            if (in_range(x-1, y) && arr[x-1][y] && is_comfortable(x-1, y)) score--;
            if (in_range(x+1, y) && arr[x+1][y] && is_comfortable(x+1, y)) score--;
            if (in_range(x, y-1) && arr[x][y-1] && is_comfortable(x, y-1)) score--;
            if (in_range(x, y+1) && arr[x][y+1] && is_comfortable(x, y+1)) score--;
            
            arr[x][y] = true;
            
            if (is_comfortable(x, y)) score++;
            if (in_range(x-1, y) && arr[x-1][y] && is_comfortable(x-1, y)) score++;
            if (in_range(x+1, y) && arr[x+1][y] && is_comfortable(x+1, y)) score++;
            if (in_range(x, y-1) && arr[x][y-1] && is_comfortable(x, y-1)) score++;
            if (in_range(x, y+1) && arr[x][y+1] && is_comfortable(x, y+1)) score++;

            System.out.println(score);
		}
	}
}