// https://dmoj.ca/problem/geometry1
import java.util.*;
import java.io.*;
import java.lang.Math; 

public class geometry1 {	

	public static double dist(int x1, int y1, int x2, int y2) {
		return Math.sqrt(Math.pow((x2-x1), 2) + Math.pow((y2-y1), 2));
	}

    public static void main(String[] args) {
    	try {
	        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	        int n = Integer.parseInt(input.readLine());
	        
	        for (int i = 0; i < n; i++) {
	        	StringTokenizer st = new StringTokenizer(input.readLine());
	        	int x1 = Integer.parseInt(st.nextToken());
	        	int y1 = Integer.parseInt(st.nextToken());
	        	int x2 = Integer.parseInt(st.nextToken());
	        	int y2 = Integer.parseInt(st.nextToken());
	        	int x3 = Integer.parseInt(st.nextToken());
	        	int y3 = Integer.parseInt(st.nextToken());
	        	
	        	double a = dist(x1, y1, x2, y2);
	        	double b = dist(x2, y2, x3, y3);
	        	double c = dist(x3, y3, x1, y1);
	        	double s = (a+b+c)/2.0;
	        
	        	System.out.printf("%.2f %.2f%n", Math.sqrt(s*(s-a)*(s-b)*(s-c)), 2*s);
	        }        
    	}
	    catch (IOException e) {};
    }
}