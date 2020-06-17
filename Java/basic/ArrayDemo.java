import java.util.Arrays;

public class ArrayDemo {
    public static void main(String[] args){
        int[] array1 = new int[10];
        char array2[] = new char[10];
        int[] array3 = {545, 3546, -45, 13, 6, 45, 21, 9, 101, 102};
        int[] Clone;
        String[] str = {"toufiq", "aadud"};
        Arrays.sort(str);

        for (String s : str) {
            System.out.print(s + " ");
        }

        //int[] Clone = new int[10];

        Clone = array3.clone();
        //System.arraycopy(array3, 0, Clone, 0, array3.length);
        Arrays.sort(Clone);

        int[] array4 = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int[][] array2D_1 = new int[12][8];
        int array2D_2[][] = new int[5][7];
        int[][] array2D_3 = {{1, 2, 3}, {4, 5, 6}, {8, 9}};
        int[][] arrayOfArray = new int[3][];
        arrayOfArray[0] = new int[5];
        arrayOfArray[1] = new int[]{2, 34, 657, 1323, 356, 4646, 0, 54};
        arrayOfArray[2] = new int[2];
        arrayOfArray[2][0] = 4;
        arrayOfArray[2][1] = 823;

        for (int i=0; i<10; i++){
            array1[i] = 23 + i;
            array2[i] = (char)(48 + i);
        }

        for (int i = 0; i < array2D_1.length; i++){
            for (int j = 0; j < array2D_1[0].length; j++){
                array2D_1[i][j] = (i * array2D_1[0].length) + j + 1;
            }
        }

        System.out.println("\t\t\tArray 1D");
        System.out.println("array1\tarray2\t\tarray3\t\tarray3(sorted)\tarray4");
        for (int i=0; i<10; i++){
            String fmt = String.format("%4d\t" + "\t%c\t" + "\t%4d\t" + "\t%4d\t\t" + "\t%4d", array1[i], array2[i], array3[i], Clone[i], array4[i]);
            System.out.println(fmt);
        }

        System.out.println("\n\t\t\tArray 2D");
        System.out.println("array2D_1");
        for (int i = 0; i < array2D_1.length; i++){
            for (int j = 0; j < array2D_1[0].length; j++){
                System.out.printf("%3d", array2D_1[i][j]);
            }
            System.out.println();
        }
        System.out.println("arrayOfArray");
        for (int[] i : arrayOfArray){    //Each for loop
            for (int j : i){
                System.out.printf("%6d", j);
            }
            System.out.println();
        }
    }
}
