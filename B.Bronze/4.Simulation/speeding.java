import java.io.*;
import java.util.*;

public class speeding {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("speeding.in"));
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();
        
        int[] speedLimits = new int[100];
        int currentMile = 0;
        
        for(int i = 0; i < n; i++) {
            int lengthOfSegment = sc.nextInt();
            int speedLimit = sc.nextInt();
            sc.nextLine();
            for(int j = 0; j < lengthOfSegment; j++) {
                speedLimits[currentMile] = speedLimit;
                currentMile++;
            }
        }
        
        int[] travelSpeed = new int[100];
        currentMile = 0;
        for(int i = 0; i < m; i++) {
            int lengthOfSegment = sc.nextInt();
            int speedLimit = sc.nextInt();
            sc.nextLine();
            for(int j = 0; j < lengthOfSegment; j++) {
                travelSpeed[currentMile] = speedLimit;
                currentMile++;
            }
        }
        
        int maxOver = 0;
        for(int i = 0; i < 100; i++) {
            int amountExceeded = travelSpeed[i] - speedLimits[i];
            if(amountExceeded > maxOver) {
                maxOver = amountExceeded;
            }
        }
        
        FileWriter fw = new FileWriter("speeding.out");
        fw.write(maxOver + "\n");
        fw.close();
    }
}