// https://dmoj.ca/problem/ccc05j5
import java.io.*;

public class ccc05j5 {	
	
	public static boolean aWord(String s) {
		int e = s.length();
		if (s.equals("A"))
			return true;
		if (e >= 3) {
			if (s.charAt(0) == 'B') {
				int b = 0;
				for (int i = 1; i < e; i++) {
					if (s.charAt(i) == 'B')
						b++;
					if (s.charAt(i) == 'S')
						b--;
					if (b < 0) {
						if (i == e-1)
							return aWord(s.substring(1,i));
						if (e-1 >= i+2) {
							if (s.charAt(i+1) == 'N' && aWord(s.substring(i+2)))
								return true;
							return false;
						}
						return false;
					}
					if (i == e-1)
						return false;
				}
			}
			int n = s.indexOf("N");
			if (n == -1)
				return false;
			//System.out.println(s.substring(0, n) + " " + s.substring(n+1, e));
			if (aWord(s.substring(0, n)) && aWord(s.substring(n+1, e)))
				return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String str = input.readLine();
		while (!str.equals("X")) {
			if (aWord(str))
				System.out.println("YES");
			else 
				System.out.println("NO");
			str = input.readLine();
		}
	}
}