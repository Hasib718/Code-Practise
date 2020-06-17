package com.hasib.java.immediate.nio;

import java.io.*;
import java.nio.*;
import java.nio.channels.FileChannel;

public class FileChannelWrite {
    public static void main(String[] args) {
        File outputFile = new File("F:\\myDir\\new_fuck.txt");
        String text = "I want to break free";

        try {
            FileOutputStream fos = new FileOutputStream(outputFile);
            FileChannel fileChannel = fos.getChannel();

            byte[] bytes = text.getBytes();
            ByteBuffer buffer = ByteBuffer.wrap(bytes);

            fileChannel.write(buffer);
            fileChannel.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
