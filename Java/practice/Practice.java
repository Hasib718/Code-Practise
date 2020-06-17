package com.hasib.java.practice;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Practice {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        int[][] mat = new int[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                mat[i][j] = in.nextInt();
            }
        }

        try {
            diagonal(mat);
        } catch (ArrayException e) {
            e.printStackTrace();
        }
    }

    private static void diagonal(int[][] matrix)
        throws ArrayException {
        int len = matrix.length;
        int inLen = matrix[0].length;

        if (len != inLen) {
            throw new ArrayException("Not a Square Matrix");
        }

        List<Integer> ans = new ArrayList<>();
        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                if (i == j && i!=0) {
                    ans.add(matrix[i][j]);
                }
            }
        }

        System.out.println(ans);
    }

    private static class ArrayException extends Exception {
        public ArrayException(String s) {
            super(s);
        }
    }
}
