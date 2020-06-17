package com.hasib.java.immediate.exception;

import java.util.Scanner;

public class Excep {
    public static void main(String[] args) {
        boolean c = true;
        Scanner scr = new Scanner(System.in);
        int result = 0;
        while (c) {
            System.out.println("Enter a Number: ");
            int a = scr.nextInt();
            System.out.println("Enter another Number: ");
            int b = scr.nextInt();

            if(a == -1 || b == -1) break;

            try {
                result = divide(a, b);
            } catch (ArithmeticException e) {
                e.printStackTrace();
                System.out.println(e.getMessage());
                System.out.println(e.toString());
                System.out.println("You can't divide " + a + " by " + b);
            }

            System.out.println("Result: " + result);
        }

    }

    public static int divide(int a, int b){
        return a/b;
    }
}
