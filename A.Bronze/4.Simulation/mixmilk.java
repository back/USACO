import java.util.*;
import java.io.*;

public class mixmilk {

	static int[] capacity = new int[3];
	static int[] milk = new int[3];

	public static void pour(int i, int j) {
		int amount = Math.min(milk[i], capacity[j] - milk[j]);
		milk[i] -= amount;
		milk[j] += amount;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("mixmilk.in"));

		for (int i = 0; i < 3; i++) {
			capacity[i] = sc.nextInt();
			milk[i] = sc.nextInt();
      sc.nextLine();
		}

		for (int i = 0; i < 100; i++) {
			pour(i % 3, (i + 1) % 3);
		}

    FileWriter fw = new FileWriter("mixmilk.out");
		for (int i = 0; i < 3; i++) {
			fw.write(milk[i] + "\n");
		}
		fw.close();
	}
}