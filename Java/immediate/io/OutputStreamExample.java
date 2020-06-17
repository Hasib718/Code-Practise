package com.hasib.java.immediate.io;

import java.io.FileOutputStream;
import java.io.IOException;

public class OutputStreamExample {
    public static void main(String[] args) {
        String destFile = "F:\\myDir\\output.txt";
        String data = "Fucking lady, fucking guy\n" +
                        "After fucking,\n" +
                        "Telling lie.\n";

        try {
            FileOutputStream fos = new FileOutputStream(destFile);
            fos.write(data.getBytes());
            fos.flush();
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
