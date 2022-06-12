/*
LANG: JAVA
TASK: beads
*/
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class beads {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(new File("beads.in"));
        int length = sc.nextInt();
        sc.nextLine();
        String rings = sc.nextLine();
        rings += rings;

        int maxLength = 0;
        for (int i = 0; i<length; i++) {
            int tryoutLength = 0;
            int colorChanged = 0;
            char currentColor = ' ';
            for (int j = i; j<i+length; j++) {
                char c = rings.charAt(j);
                if (c == 'b' || c == 'r'){
                    if (colorChanged == 0) {
                        currentColor = c;
                        colorChanged++;
                    } else if (colorChanged == 1 && currentColor != c) {
                        currentColor = c;
                        colorChanged++;
                    } else if (colorChanged == 2 && currentColor != c) {
                        break;
                    }
                }
                tryoutLength++;
            }
            if (tryoutLength > maxLength)
                maxLength = tryoutLength;
        }

        FileWriter fw = new FileWriter(new File("beads.out"));
        fw.write(maxLength + "\n");
        fw.close();
    }
}
