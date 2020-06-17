package com.hasib.java.immediate.io;

import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

public class ReaderExample {
    public static void main(String[] args) {
        Reader reader = null;

        try {
            reader = new FileReader("F:\\myDir\\input.txt");

            int c;
            while ((c = reader.read()) != -1) {
                System.out.print((char)c + " ");
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }
    }
}
