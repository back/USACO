/*
LANG: JAVA
TASK: stamps
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class stamps {
    public static void main(String[] args) throws Exception {
        String task = "stamps";
        Scanner sc = new Scanner(new File(task + ".in"));

        int k = sc.nextInt();
        int n = sc.nextInt();
        sc.nextLine();

        int[] stamps = new int[n];
        for(int i=0; i<stamps.length; i++) stamps[i]=sc.nextInt();
        Arrays.sort(stamps);

        int[] p = new int[k*stamps[stamps.length-1] + 2];
        for(int i=1; i<p.length; i++) p[i]=201;
        p[0]=0;

        for(int v : stamps)
            for(int i=v; i<p.length; i++)
                if(p[i-v] < k && p[i-v]+1<p[i])
                    p[i] = p[i-v]+1;

        int answer = 0;
        for(int i=0; i<p.length; i++)
            if(p[i]>k) {
                answer=i-1;
                break;
            }


        FileWriter fw = new FileWriter(new File(task + ".out"));
        fw.write(answer + "\n");
        fw.close();
    }
}
