/*
Glenforest Winter Open 2015 Senior 1 - OR-deal
Key Concepts: Implementation
https://dmoj.ca/problem/gfssoc3s1
Solution by Kevin Guo
*/
import java.io.*;

public class gfssoc3s1 {	

	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        for (Long x = Long.parseLong(input.readLine()); x > 0; x >>= 1) System.out.print(1);
    }
}