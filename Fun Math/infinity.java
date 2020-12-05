// https://dmoj.ca/problem/infinity
import java.io.*;

public class infinity {	
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		int a = Integer.parseInt(input.readLine(), 16);
		int b = Integer.parseInt(input.readLine(), 16);
		if (a + b > 0x3f3f3f3f) System.out.println("Yes");
		else System.out.println("No");
		
	}
}