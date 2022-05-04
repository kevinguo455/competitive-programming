import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    public static final int MAXN = 10; // Max vertices
    
    public static int pathLength;
    public static int ans = 0; // Final answer
    public static ArrayList<Integer> adj[] = new ArrayList[MAXN]; // Adjacency list

    // Recursively traverse all paths using DFS
    public static void dfs(boolean[] vis, int curr, int sum, int length) {
        
        // Check if path is already long enough
        if (length == pathLength) {
            ans += sum;
            return;
        }
        
        // Mark the current node as visited
        vis[curr] = true;
        
        // Visit all unvisited nodes reachable from this one
        for (int to : adj[curr]) {
            if (!vis[to]) {
                dfs(vis, to, sum * 10 + to, length + 1);
            }
        }
        
        // Reset vis array
        vis[curr] = false;
    }

    public static int sumPathsOfLengthN(int num, String edges) {
        
        for (int i = 0; i < MAXN; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        
        pathLength = num;
        
        TreeSet<Integer> nodes = new TreeSet<Integer>(); // Set of all nodes present in the graph
        
        // Parse the graph
        StringTokenizer st = new StringTokenizer(edges);
        while (st.hasMoreTokens()) {
            String edge = st.nextToken();
            
            // Convert string to adjacency list
            adj[edge.charAt(0)-'0'].add(edge.charAt(1)-'0');
            
            // Add nodes to set of total nodes 
            nodes.add(edge.charAt(0)-'0');
            nodes.add(edge.charAt(1)-'0');
        }
        
        // Run DFS on each node
        for (int start : nodes) {
            dfs(new boolean[MAXN], start, start, 0);   
        }
        
        return ans;
    }

}

public class acsl21c4s {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int num = Integer.parseInt(bufferedReader.readLine().trim());

        String edges = bufferedReader.readLine();

        int result = Result.sumPathsOfLengthN(num, edges);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
