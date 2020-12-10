/*
VM7WC '16 #1 Bronze - A New Prime Factorization 
Key Concepts: Number theory
https://dmoj.ca/problem/vmss7wc16c1p1
Solution by Kevin Guo
*/
import java.io.*;
import java.lang.Math; 

public class vmss7wc16c1p1 {	
	
	public static boolean isPrime(int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		//int cases = Integer.parseInt(input.readLine());
		//for (int test = 0; test < cases; test++) {
			int n = Integer.parseInt(input.readLine());
			if (n <= 1)
				return;
			
			int lim = (int) Math.floor(Math.sqrt(n));
			while (!isPrime(n)) {
				for (int i = 2; i <= lim; i++) {
					if (n % i == 0) {
						System.out.println(i);
						n /= i;
						break;
					}
				}
			}
			System.out.println(n);
		//}
	}
}