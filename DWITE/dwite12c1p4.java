/*
DWITE '12 R1 #4 - Trick or Tree'ing
Key Concepts: Graph Theory (Trees), String Algorithms, Implementation
https://dmoj.ca/problem/dwite12c1p4
Solution by Kevin Guo
*/
import java.io.*;
import java.util.*;

public class dwite12c1p4 {	
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		for (int cases = 0; cases < 5; cases++) {
            String str = input.readLine();
            int spaces = 0, score = 0, brackets = 0, maxBrackets = 0;       
            
            StringTokenizer st = new StringTokenizer(str, "() ", true); // parse input
            while (st.hasMoreTokens()) {
                String s = st.nextToken();
                if (s.equals("(")) brackets++;
                else if (s.equals(")")) {
                    if (brackets > maxBrackets) maxBrackets = brackets; // track height of tree
                    brackets--;
                }
                else if (s.equals(" ")) spaces++;                   // 1 space for every 2 children
                else score += Integer.parseInt(s);                  // 1 path to and from each child
            }                                                       //   = 4 paths per space
                                                                    // no need to return back to root --> subtract height of tree
            System.out.printf("%d %d\n", spaces * 4 - maxBrackets, score);
        }
	}
}