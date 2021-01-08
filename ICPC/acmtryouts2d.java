/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 2D - Diablo Bot
Key Concepts: Logic (if and only if)
https://dmoj.ca/problem/acmtryouts2d
Solution by Kevin Guo
*/
import java.io.*;
import java.util.*;

public class acmtryouts2d {	
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(input.readLine());
		for (int i = 0; i < n; i++) {
			String item = input.readLine().toLowerCase();
			StringTokenizer st = new StringTokenizer(item);
			int c = st.countTokens();
			String first = st.nextToken();
			
			if (first.length() > 1 && first.substring(first.length()-2, first.length()).equals("'s")) {
				System.out.println("Set");
				continue;
			}
			if (first.equals("damaged")) {
				System.out.println("Normal");
				continue;
			}
			if (c == 2) {
				if (first.equals("of")) {
					System.out.println("Rare");
					continue;
				}
				System.out.println("Not sure, take anyways");
				continue;
			}
			if (c <= 4) {
				String word = "";
				for (int j = 1; j < c-1; j++) {
					word = st.nextToken();
				}
				if (word.equals("of")) {
					System.out.println("Magic");
					continue;
				}
			}
			System.out.println("Normal");
		}
		
	}
}