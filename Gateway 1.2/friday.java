/*
ID: royone1
LANG: JAVA
TASK: friday
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class friday {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("friday.in"));
        int n = sc.nextInt();

        int[] results = new int[7];
        int d = 13 - 31;

        for (int year = 1900; year < 1900 + n; year++)
            for (int month = 1; month < 13; month++) {
                switch (month - 1) { // based on previous month days
                    case 0: case 1: case 3:
                    case 5: case 7: case 8:
                    case 10:
                        d += 31;
                        break;
                    case 4:case 6: case 9:case 11:
                        d += 30;
                        break;
                    default:
                        d += 28;
                        if (year % 400 == 0 || year % 4 == 0 && year % 100 > 0)
                            d++;
                        break;
                }
                results[(d + 1) % 7]++;
            }

        FileWriter fw = new FileWriter(new File("friday.out"));
        StringBuffer sb = new StringBuffer();

        for (int i : results) sb.append(i).append(' ');
        sb.replace(sb.length()-1,sb.length(),"\n");

        fw.write(sb.toString());
        fw.close();
    }
}
