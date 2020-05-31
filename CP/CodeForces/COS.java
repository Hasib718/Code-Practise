import java.util.*;

public class COS {
    public static void main(String[] args) {
        Scanner scr = new Scanner(System.in);

        int T = scr.nextInt();
        for(int j = 0; j<T; j++) {
            ArrayList<Integer> lst = new ArrayList<>();
            for(int i=0; i<3; i++)
                lst.add(scr.nextInt());
            int n = scr.nextInt();
            Collections.sort(lst);
            
            if(lst.get(2) - lst.get(0) + lst.get(2) - lst.get(1) > n) {
                System.out.println("NO");
                continue;
            }
            if((lst.get(0)+lst.get(1)+lst.get(2)+n)%3 != 0) {
                System.out.println("NO");
                continue;
            } else {
                System.out.println("YES");
                continue;
            }
        }
    }
}