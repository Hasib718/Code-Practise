import java.util.Scanner;

public class input1 {
    public static void main(String[] args){
        Scanner scr = new Scanner(System.in);
        boolean okey = true;

        do {
            System.out.println("Enter a Line: ");
            String line = scr.nextLine(); // takes the whole line as input
            System.out.println("You Entered: " + line);

            if ("quit".equals(line)){
                okey = false;
            }
        } while (okey);
    }
}