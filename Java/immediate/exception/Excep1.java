package com.hasib.java.immediate.exception;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

public class Excep1 {
    private static List<Integer> list;
    private static final int SIZE = 10;

    public static void writeList(){
        PrintWriter out = null;

        try {
            System.out.println("Entered try statement");
            out = new PrintWriter(new FileWriter("file.txt"));
            for (int i=0; i<SIZE; i++){
                Integer integer = list.get(i);
                out.write(integer);
            }
        }catch (IOException | NullPointerException e){
            System.out.println("Here in catch Block");
        }
    }

    public static void main(String[] args){
        writeList();
    }
}
