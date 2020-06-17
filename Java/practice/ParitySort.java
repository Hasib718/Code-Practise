package com.hasib.java.practice;

import java.util.Arrays;

public class ParitySort {
    public static void main(String[] args) {
        int[] arr = {42, 15, 11, 17, 666, 555, 4};
        System.out.println(Arrays.toString(arr));

        arr = paritySort(arr);

        System.out.println(Arrays.toString(arr));
    }

    private static int[] paritySort(int[] arr) {
        boolean swap1 = false;
        boolean swap2 = false;

        while(!swap1 || !swap2) {
            swap1 = true;
            for (int i=0; i<arr.length-1; i+=2) {
                if (arr[i] > arr[i+1]) {
                    Swap(arr[i], arr[i+1]);
                    swap1 = false;
                }
            }
            swap2 = true;
            for (int i=0; i<arr.length-2; i+=2) {
                if (arr[i+1] > arr[i+2]) {
                    Swap(arr[i+1], arr[i+2]);
                }
            }
        }

        return arr;
    }

    static void Swap(int a, int b)
    {
        if (a != b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
    }
}
