/*
ID: royone1
LANG: JAVA
TASK: dualpal
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class dualpal {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner( new File("dualpal.in") );
        int n = sc.nextInt();
        int s = sc.nextInt();

        FileWriter fw = new FileWriter("dualpal.out");

        while(n > 0) {
            s++;

            int palCount = 0;

            // check s to see if it's a dual palindrome.
            for (int base=2; base <= 10; base++) {
                String strNumber = Integer.toString(s, base);

                StringBuilder builder = new StringBuilder (strNumber);
                String revNumber = builder.reverse().toString();

                if ( revNumber.equals(strNumber) ) {
                    // we found a palindrome!
                    palCount++;
                    if (palCount == 2) {
                        // Aha, we found a dual palindrome!
                        //System.out.println(s);
                        fw.write(s + "\n");
                        n--;
                        break;
                    }
                }
            }
        }

        fw.close();
    }
}
