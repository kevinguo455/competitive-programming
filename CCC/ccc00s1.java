// https://dmoj.ca/problem/ccc00s1
import java.io.*;

public class ccc00s1 {	

	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

		int quarters = Integer.parseInt(input.readLine());
		
		int a = Integer.parseInt(input.readLine());
		int b = Integer.parseInt(input.readLine());
		int c = Integer.parseInt(input.readLine());
		
		int i = 0;
		while (quarters > 0) {
			if (i % 3 == 0) {
				a++;
				if (a % 35 == 0) {
					quarters += 30;
				}
			} 
			else if (i % 3 == 1) {
				b++;
				if (b % 100 == 0) {
					quarters += 60;
				}
			}
			else {
				c++;
				if (c % 10 == 0) {
					quarters += 9;
				}
			}
			i++;
			quarters--;
		}
		System.out.printf("Martha plays %d times before going broke.%n", i);
	}
}