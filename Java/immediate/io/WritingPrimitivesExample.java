package com.hasib.java.immediate.io;

import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class WritingPrimitivesExample {
    public static void main(String[] args) {
        String destFileName = "F:\\myDir\\new_fuck.txt";

        try {
            DataOutputStream dos = new DataOutputStream(new
                    FileOutputStream(destFileName));

            dos.writeInt(152);
            dos.writeDouble(4.566);
            dos.writeBoolean(true);
            dos.writeLong(Long.MAX_VALUE);
            dos.writeChar(Character.MAX_HIGH_SURROGATE);

            dos.flush();
            dos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
