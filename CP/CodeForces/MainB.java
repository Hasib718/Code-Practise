/**
 * CodeForces 1337B
 */

import java.lang.Math;
import java.util.Scanner;

public class MainB {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int t = in.nextInt();

        for (int i=0; i<t; i++) {
            int x = in.nextInt();
            int n = in.nextInt();
            int m = in.nextInt();

            int p=x;
            for (int j=0; j<n; j++) {
                x = (int)Math.floor((double)x/2.0) + 10;
                if (x < 0)
                    break;
                else if (x > p) {
                    x = p;
                    break;
                }
                p = x;
            }

            while (x > 0 && m > 0) {
                x -= 10;
                m--;
            }

            if (x < 1)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}