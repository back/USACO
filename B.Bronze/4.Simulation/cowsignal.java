import java.util.*;
import java.io.*;

class cowsignal {
    public static void main (String[] argv) throws Exception {
        Scanner sc = new Scanner(new File("cowsignal.in"));
        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();
        
        char[][] res = new char[m][n];

        for(int i = 0; i<m; i++)
            res[i] = sc.nextLine().toCharArray();
        
        FileWriter fw = new FileWriter("cowsignal.out");
        for(int i = 0; i<m*k; i++) {
            for(int j=0; j<n*k; j++)
                fw.write(res[i/k][j/k]);
            fw.write('\n');
        }
        fw.close();
    }
}