import java.util.Scanner;
import java.lang.Math;
import java.math.BigInteger;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        for (int i=0; i<t; i++)
        {
            int n = in.nextInt();
            
            int pw = log2(n);

            BigInteger sum = new BigInteger(Integer.toString(n));
            sum = sum.add(new BigInteger("1"));
            sum = sum.multiply(new BigInteger(Integer.toString(n)));
            sum = sum.divide(new BigInteger("2"));
            sum = sum.subtract(new BigInteger(Integer.toString((int)(2*(Math.pow(2, pw+1) - 1)))));

            System.out.println(sum);
        }
    }

    public static int log2(int x)
    {
	    return (int) (Math.log(x) / Math.log(2));
    }
}