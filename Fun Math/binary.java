// https://dmoj.ca/problem/binary
import java.io.*;

public class binary {	
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		int cases = Integer.parseInt(input.readLine());
		for (int casen = 0; casen < cases; casen++) {
			int n = Integer.parseInt(input.readLine());
			
			StringBuilder st = new StringBuilder();
			while (n > 0) {
				if (n % 2 == 0) st.append(0);
				else st.append(1);
				n /= 2;
			}
			while (st.length() % 4 != 0 || st.length() < 4) st.append(0);
			st.reverse();
			
			for (int i = st.length() - 4; i > 0; i -= 4) {
				st.insert(i, " ");
			}
			System.out.println(st.toString());	
		}
	}
}