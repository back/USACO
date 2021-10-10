import java.io.*;
import java.util.*;

public class Bronze2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int n = Integer.parseInt(br.readLine());
    int[] petals = new int[n];
    StringTokenizer st = new StringTokenizer(br.readLine());
    for(int i = 0; i < n; i++) {
      petals[i] = Integer.parseInt(st.nextToken());
    }
      
      
      
    int photos = n;
    for(int i = 0; i < n-1; i++) {
        
      boolean[] present = new boolean[1001];    // present[1000]
      present[petals[i]] = true;                // 513  -> present[513] = true
        
      int petalsSeen = 0;
      for(int j = i+1; j < n; j++) {
        petalsSeen += petals[j];
        present[petals[j]] = true;
        if(petalsSeen % (j-i+1) == 0 && present[petalsSeen / (j-i+1)]) {  // O(1)
          photos++;
        }
      }
    }
    pw.println(photos);
    pw.close();
  }
}