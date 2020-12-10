// https://dmoj.ca/problem/ccc03s2
import java.io.*;

public class ccc03s2 {	
	
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(input.readLine());
        
        for (int casen = 0; casen < cases; casen++) {

            String s, p[] = new String[4];
            for (int i = 0; i < 4; i++) {
                s = input.readLine().toLowerCase();
                int m = Math.max(0, s.lastIndexOf('a'));
                m = Math.max(m, s.lastIndexOf('e'));
                m = Math.max(m, s.lastIndexOf('i'));
                m = Math.max(m, s.lastIndexOf('o'));
                m = Math.max(m, s.lastIndexOf('u'));
                m = Math.max(m, s.lastIndexOf(' '));
                p[i] = s.substring(m);
            }

            if (p[0].equals(p[1]) && p[2].equals(p[3])) {
                if (p[1].equals(p[2])) System.out.println("perfect");
                else System.out.println("even");
            }
            else if (p[0].equals(p[2]) && p[1].equals(p[3])) {
                System.out.println("cross");
            }
            else if (p[0].equals(p[3]) && p[1].equals(p[2])) {
                System.out.println("shell");
            }
            else {
                System.out.println("free");
            }
        }
	}
}
