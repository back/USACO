/*
LANG: JAVA
TASK: ride
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class ride {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(new File("ride.in"));
        String cometName = sc.nextLine();
        String groupName = sc.nextLine();

        int code = 1;
        for (char c : cometName.toCharArray()) {
            int thisLetterCode = c - 'A' + 1;
            code = code * thisLetterCode;
        }
        int result = code % 47;

        int code2 = 1;
        for (char c : groupName.toCharArray()) {
            int thisLetterCode = c - 64;
            code2 = code2 * thisLetterCode;
        }
        int result2 = code2 % 47;

        FileWriter fw = new FileWriter("ride.out");
        // PrintWriter pw = new PrintWriter(new File("ride.out"));
        // pw.print()
        // pw.println()
        if (result == result2) {
            System.out.println("GO");
            fw.write("GO\n");
        } else {
            System.out.println("STAY");
            fw.write("STAY\n");
        }
        fw.close();
    }
}
