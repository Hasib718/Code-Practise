import java.util.Random;

public class ArrayMatrix {
    Random random = new Random();

    public int[][] random(int m, int n){
        int[][] c = new int[m][n];

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                c[i][j] = random.nextInt(100);
            }
        }
        return c;
    }

    public int[][] multiply(int[][] A, int[][] B){
        int mA = A.length;
        int nA = A[0].length;
        int mB = B.length;
        int nB = B[0].length;
        if (nA != mB){
            throw new RuntimeException("Illegal Matrix Dimensions");
        }

        int[][] c = new int[mA][nB];
        for (int i = 0; i < mA; i++){
            for (int j = 0; j < nB; j++){
                for (int k = 0; k < nA; k++){
                    c[i][j] = A[i][k] * B[k][j];
                }
            }
        }
        return c;
    }

    public int[][] add(int[][] A, int[][] B){
        int[][] c = new int[A.length][A[0].length];

        for (int i = 0; i < A.length; i++){
            for (int j = 0; j < A[0].length; j++){
                c[i][j] = A[i][j] + B[i][j];
            }
        }
        return c;
    }

    public int[][] subtract(int[][] A, int[][] B){
        int[][] c = new int[A.length][A[0].length];

        for (int i = 0; i < A.length; i++){
            for (int j = 0; j < A[0].length; j++){
                c[i][j] = A[i][j] - B[i][j];
            }
        }
        return c;
    }

    public void print(int[][] x){
        for (int[] i : x){        //Each-for loop
            for (int j : i){
                System.out.printf("%7d ", j);
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        ArrayMatrix matrix = new ArrayMatrix();

        int[][] multi = matrix.multiply(matrix.random(5, 5), matrix.random(5, 5));
        System.out.println("Result # 1: ");
        matrix.print(multi);

        int[][] subs = matrix.subtract(matrix.random(5, 5), matrix.random(5, 5));
        System.out.println("Result # 2: ");
        matrix.print(subs);

        int[][] jog = matrix.add(matrix.random(5, 5), matrix.random(5, 5));
        System.out.println("Result # 3: ");
        matrix.print(jog);

    }
}
