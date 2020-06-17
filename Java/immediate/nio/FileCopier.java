package com.hasib.java.immediate.nio;

import java.nio.charset.Charset;
import java.io.*;
import java.nio.*;
import java.nio.channels.FileChannel;

public class FileCopier {
    public static void main(String[] args) {
        File sourceFile = new File("F:\\myDir\\toufiq.txt");
        File sinkFile = new File("F:\\myDir\\wadud.txt");
        try (FileChannel fis = new FileInputStream(sourceFile).getChannel()) {
            sourceFile.createNewFile();
            sinkFile.createNewFile();

            ByteBuffer buffer = ByteBuffer.allocate(1024);
            Charset cs = Charset.forName("UTF-8");

            while (fis.read(buffer) > 0) {
                buffer.flip();

                while (buffer.hasRemaining()) {
                    System.out.print(cs.decode(buffer));
                }
                System.out.println();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        FileCopier.copy(sourceFile, sinkFile);
    }

    public static void copy(File sourceFile, File sinkFile) {
        if (!sinkFile.exists() || !sourceFile.exists()) {
            System.out.println("Source or destination file does not exist!");
            return;
        }

        try (FileChannel srcChannel = new FileInputStream(sourceFile).getChannel();
            FileChannel sinkChannel = new FileOutputStream(sinkFile).getChannel()) {
            srcChannel.transferTo(0, srcChannel.size(), sinkChannel);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
