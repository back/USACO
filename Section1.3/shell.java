import java.util.*;
import java.io.*;

public class shell {
	public static void main(String[] args) throws IOException {
		int[] shellAtPosition = new int[3];
		int[] counter = new int[3];

		for (int i = 0; i < 3; i++) {
			shellAtPosition[i] = i;
		}

		Scanner sc = new Scanner(new File("shell.in"));
		int n = sc.nextInt();
    sc.nextLine();
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int g = sc.nextInt() - 1;
      sc.nextLine();

			int t = shellAtPosition[b];
			shellAtPosition[b] = shellAtPosition[a];
			shellAtPosition[a] = t;

			counter[shellAtPosition[g]]++;
		}

		FileWriter fw = new FileWriter("shell.out");
    int ans = Math.max(counter[1], counter[2]);
    ans = Math.max(counter[0], ans);
    fw.write(ans + "\n");
		fw.close();
	}
}