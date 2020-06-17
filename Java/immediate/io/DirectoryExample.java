package com.hasib.java.immediate.io;

import java.io.File;
import java.io.IOException;

public class DirectoryExample {
    public static void main(String[] args)
        throws IOException {
        File dir = new File("F:\\myDir");

        dir.mkdir();

        System.out.println("Directory Path: " + dir.getPath());

        //Creating a new file
        File file = new File(dir.getPath() + File.separator + "hello1.txt");

        file.createNewFile();
        System.out.println("File Path: " + file.getPath());
    }
}
