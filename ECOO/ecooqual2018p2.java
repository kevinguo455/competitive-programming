import java.io.*;

public class ecooqual2018p2 {	
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(input.readLine());
		for (int i = 0; i < n; i++) {
			String s = input.readLine();
			int l = s.length();
			int c = s.indexOf('C');
			for (int j = 0; j < c; j++) {
				System.out.print("Educational ");
			}
			System.out.print("Computing");
			for (int j = c+1; j < l; j+=2) {
				System.out.print(" Organization of Ontario");
			}
			System.out.println();
		}
	}
}