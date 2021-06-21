/*
LANG: JAVA
TASK: milk2
*/

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class milk2 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("milk2.in"));
        int n = sc.nextInt();

        ArrayList<int[]> t = new ArrayList<>();

        for(int i = 0; i<n; i++) {
            sc.nextLine();
            int a = sc.nextInt();
            int b = sc.nextInt();

            ArrayList<int[]> tmp = new ArrayList<>();

            for (int[] xy : t) {  // convenient

                if (b < xy[0] || a > xy[1]) {
                    // no overlapping, simply collect it.
                    tmp.add(xy);
                } else {
                    // if overlapping, merge it to [a,b]
                    a = Math.min(a, xy[0]);
                    b = Math.max(b, xy[1]);
                }

            }
            // finally add already-merged [a,b]
            tmp.add(new int[]{a, b});
            t = tmp;
        }

        int maxMilking = 0;
        for(int[] xy: t) {
            maxMilking = Math.max(maxMilking, xy[1]-xy[0]);
        }

        Comparator cmp = new Comparator<int[]>() {
            @Override
            public int compare(int[] item1, int[] item2) {
                return item1[0] - item2[0];
            }
        };
        t.sort(cmp);

        int maxNotMilking = 0;
        for(int i=1; i < t.size(); i++) {

            int[] thisItem = t.get(i);     // [ 1200, 4600 ]
            int[] previous = t.get(i-1);   // [  300,  800 ]

            int gap = thisItem[0] - previous[1];

            maxNotMilking = Math.max(maxNotMilking, gap);
        }

        FileWriter fw = new FileWriter(new File("milk2.out"));
        fw.write( String.format("%s %s\n", maxMilking, maxNotMilking) );
        fw.close();
    }
}
