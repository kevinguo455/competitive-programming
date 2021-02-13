/*
CCC '96 S3 - Pattern Generator
Key Concepts: Recursion
https://dmoj.ca/problem/ccc96s3
Solution by Kevin Guo
*/
import java.io.*;
import java.util.*;

public class ccc96s3 {	

    static void solve(String currentString, int currentIndex, int totalLength, int bitsToSet) {
        
        // Stop appending if the string is already at the desired length
        if (currentIndex == totalLength) {
            System.out.println(currentString);
            return;
        }

        // Append a 1 unless there are no more 1s to set
        if (bitsToSet != 0) 
            solve(currentString + "1", currentIndex + 1, totalLength, bitsToSet - 1);
        
        // Append a 0 unless all the remaining bits need to be 1s
        if (totalLength - currentIndex != bitsToSet) 
            solve(currentString + "0", currentIndex + 1, totalLength, bitsToSet);

    }

	public static void main(String[] args) throws IOException {
		
		int n = readInt();

        for (int i = 0; i < n; i++) {
            int a = readInt();
            int b = readInt();
            
            System.out.println("The bit patterns are");
            
            solve("", 0, a, b);
            
            System.out.println();
        }

	}

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException {
    while (st == null || !st.hasMoreTokens())
        st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
    
    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }
    
    static char readCharacter() throws IOException {
        return next().charAt(0);
    }
    
    static String readLine() throws IOException {
        return br.readLine().trim();
    }

}