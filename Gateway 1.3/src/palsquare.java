/*
ID: royone1
LANG: JAVA
TASK: palsquare
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class palsquare {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner( new File("palsquare.in") );
        int base = sc.nextInt();

        FileWriter fw = new FileWriter("palsquare.out");
        for (int i=1; i <= 300; i++) {

            int x = i*i;
            String s = Integer.toString(x, base);

            StringBuilder sb = new StringBuilder(s);
            sb.reverse();

            if (sb.toString().equals(s)) {
                fw.write(Integer.toString(i, base).toUpperCase());
                fw.write(" ");
                fw.write(s.toUpperCase());
                fw.write("\n");
            }
        }
        fw.close();
    }


}
