/*
ID: royone1
LANG: JAVA
TASK: test
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

class test {
    public static void main (String [] args) throws Exception {
        Scanner sc = new Scanner(new File("test.in"));
        int x = sc.nextInt();
        int y = sc.nextInt();

        FileWriter fw = new FileWriter("test.out");
        fw.write( (x+y) + "\n" );
        fw.close();
    }
}