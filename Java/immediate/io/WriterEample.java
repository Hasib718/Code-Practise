package com.hasib.java.immediate.io;

import java.io.FileWriter;
import java.io.Writer;
import java.io.IOException;

public class WriterEample {
    public static void main(String[] args) {
        Writer writer = null;
        String text = "Fucking lady, fucking guy\n" +
                "After fucking,\n" +
                "Telling lie.\n";

        try {
            writer = new FileWriter("F:\\myDir\\old_fuck.txt");
            writer.write(text);
            writer.flush();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
