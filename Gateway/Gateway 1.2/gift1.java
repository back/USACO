/*
LANG: JAVA
TASK: gift1
*/

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class gift1 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("gift1.in"));
        int n = sc.nextInt();
        sc.nextLine();  // need to be put extra causions here!

        String[] names = new String[n];
        for (int i = 0; i < n; i++) {
            names[i] = sc.nextLine();
        }

        // name: money, name:money, name: money
        HashMap<String, Integer> pockets = new HashMap<>();  
        for (String s : names) {
            pockets.put(s, 0);
        }

        for (int i = 0; i < n; i++) {
            String giver = sc.nextLine();
            int cashOut = sc.nextInt();
            int shareCount = sc.nextInt();
            sc.nextLine();

            if (shareCount > 0) {
                String[] receivers = new String[shareCount];
                for (int j = 0; j < shareCount; j++) {
                    receivers[j] = sc.nextLine();
                }
                int moneyForOne = cashOut / shareCount;  // 100 / 3 = 33
                int remainder = cashOut % shareCount;    // 100 % 3 = 1
                for (String receiver : receivers) {
                    int currentbalance = pockets.get(receiver);
                    currentbalance += moneyForOne;
                    pockets.put(receiver,  currentbalance );
                }
                pockets.put(giver, pockets.get(giver) - cashOut + remainder);
            }
        }

        FileWriter fw = new FileWriter("gift1.out");
        for (String s : names)
            fw.write(s + " " + pockets.get(s) + "\n");
        fw.close();
    }
}
