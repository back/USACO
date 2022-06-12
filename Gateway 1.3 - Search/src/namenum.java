/*
LANG: JAVA
TASK: namenum
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class namenum {
    public static void main(String[] args) throws Exception {

        String mapK = "ABCDEFGHIJKLMNOPRSTUVWXYQZ";
        String mapV = "222333444555666777888999##";


        Scanner sc = new Scanner(new File("namenum.in"));
        String serial = sc.nextLine();
        boolean found = false;

        FileWriter fw = new FileWriter("namenum.out");

        sc = new Scanner(new File("dict.txt"));
        while(sc.hasNextLine()){
            String name = sc.nextLine(); // e.g. "GREG"
            String code = "";
            for (char c : name.toCharArray())  // loop through: ['G', 'R', 'E', 'G']
                 code += mapV.charAt(mapK.indexOf(c));
            if (serial.equals(code)) {
                fw.write(name + "\n");
                found = true;
            }
        }

        if (!found)
            fw.write("NONE\n");

        fw.close();
    }
}
