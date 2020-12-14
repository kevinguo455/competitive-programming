/*
CCC '06 S2 - Attack of the CipherTexts
Key Concepts: Implementation
https://dmoj.ca/problem/ccc06s2
Solution by Kevin Guo
*/

import java.io.*;

public class ccc06s2 {	
	
	public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String a = input.readLine();
        String b = input.readLine();
        String c = input.readLine();

        char[] key = new char[27]; // 0-25 is A to Z, 26 is space
        for (int i = 0; i < 27; i++) {
            key[i] = '.';  // . by default
        }
        for (int i = 0; i < b.length(); i++) {  // set key using decoded string
            int l;
            if (b.charAt(i) == ' ') l = 26;
            else l = b.charAt(i) - 'A';
            key[l] = a.charAt(i);
        }
        for (int i = 0; i < c.length(); i++) {  // decode
            int l;
            if (c.charAt(i) == ' ') l = 26;
            else l = c.charAt(i) - 'A';
            System.out.print(key[l]);
        }
    }
    
}