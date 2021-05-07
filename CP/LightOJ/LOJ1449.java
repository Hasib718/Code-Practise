import java.util.Scanner;

public class LOJ1449 {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int n = in.nextInt();
        in.nextLine();
        for (int i=1; i<=n; i++) {
            String str = in.nextLine();
            if (str.charAt(4) == ':') {
                StringBuilder stringBuilder = new StringBuilder(str);
                stringBuilder.insert(4, 's');
                System.out.println("Case " + i + ": " + stringBuilder.toString());
            } else {
                System.out.println("Case "+i+": "+str);
            }
        }
    }
}