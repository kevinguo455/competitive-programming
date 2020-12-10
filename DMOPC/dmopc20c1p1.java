/* 
DMOPC '20 Contest 1 P1 - Victor Gets Quizzed
Key Concepts: Implementation, String Algorithms
Solution by Kevin Guo
https://dmoj.ca/problem/dmopc20c1p1
*/

import java.util.*;

public class dmopc20c1p1 {	

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int a = Integer.parseInt(input.nextLine());

        for (int i = 0; i < a; i++) {
        	String str = input.nextLine();
        	if (str.indexOf("C") != -1 && str.indexOf("M") != -1) {
        		System.out.println("NEGATIVE MARKS");
        	}
        	else if (str.indexOf("C") != -1 || str.indexOf("M") != -1) {
        		System.out.println("FAIL");
        	}
        	else {
        		System.out.println("PASS");
        	}
		}
		
		input.close();

    }
}
