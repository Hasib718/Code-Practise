package com.hasib.java.immediate.io;

import java.io.File;
import java.io.FileFilter;

public class FileFillter {
    public static void main(String[] args) {
        File home = new File("D:\\Pictures\\Others\\ETC");

        FileFilter jpgFilter = new FileFilter() {

            @Override
            public boolean accept(File pathname) {
                String fileName = pathname.getName();
                if (fileName.endsWith(".jpg")) {
                    return true;
                }
                return false;
            }
        };

        File[] listRoots = home.listFiles(jpgFilter);
        for (File file : listRoots) {
            System.out.println(file.getPath());
        }
    }
}
