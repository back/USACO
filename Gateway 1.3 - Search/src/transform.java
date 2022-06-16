/*
ID: royone1
LANG: JAVA
TASK: transform
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class transform {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("transform.in"));

        int n = sc.nextInt();
        sc.nextLine();

        char[][] mtx = new char[n][];
        char[][] tgt = new char[n][];

        for (int i = 0; i < n; i++)
            mtx[i] = sc.nextLine().toCharArray();
        for (int i = 0; i < n; i++)
            tgt[i] = sc.nextLine().toCharArray();

        int answer = 7;

        if (match(trans(mtx, 1), tgt))
            answer = 1;
        else if (match(trans(mtx, 2), tgt))
            answer = 2;
        else if (match(trans(mtx, 3), tgt))
            answer = 3;
        else {
            char[][] middle = trans(mtx, 4);
            if (match(middle, tgt))
                answer = 4;
            else if (match(trans(middle, 1), tgt)
                    || match(trans(middle, 2), tgt)
                    || match(trans(middle, 3), tgt))
                answer = 5;
            else if (match(mtx, tgt))
                answer = 6;
        }

        FileWriter fw = new FileWriter(new File("transform.out"));
        fw.write(answer + "\n");
        fw.close();
    }

    private static char[][] trans(char[][] origin, int method) {
        int n = origin.length;
        char[][] result = new char[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                
                
                
                if (method == 1)
                    result[i][j] = origin[n - j - 1][i];
                else if (method == 2)
                    result[i][j] = origin[n - i - 1][n - j - 1];
                else if (method == 3)
                    result[i][j] = origin[j][n - i - 1];
                else if (method == 4)
                    result[i][j] = origin[i][n - j - 1];
 
        
        
        return result;
    }

    private static boolean match(char[][] origin, char[][] target) {
        int n = origin.length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (target[i][j] != origin[i][j])
                    return false; // this will break all the loops and immediately return!
        return true;
    }

}
