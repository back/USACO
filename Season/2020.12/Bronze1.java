import java.util.Arrays;
import java.util.Scanner;

public class Bronze1 {


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] inputs = new int[7];

        for(int i = 0; i<7; i++) {
            inputs[i] = sc.nextInt();
        }

        Arrays.sort(inputs);

        int a = inputs[0];
        int b = inputs[1];
        int c = inputs[6] - a - b;

        System.out.println(a + " " + b + " " + c);

    }

}
