package com.hasib.java.immediate.io;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.DataInputStream;

public class ReadingPrimitivesExample {
    public static void main(String[] args) {
        String sourceFile = "F:\\myDir\\new_fuck.txt";

        try {
            DataInputStream dis = new DataInputStream(new
                    FileInputStream(sourceFile));

            System.out.println(dis.readInt());
            System.out.println(dis.readDouble());
            System.out.println(dis.readBoolean());
            System.out.println(dis.readLong());
            System.out.println(dis.readChar());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
