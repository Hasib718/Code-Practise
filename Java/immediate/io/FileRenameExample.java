package com.hasib.java.immediate.io;

import java.io.File;
import java.io.IOException;

public class FileRenameExample {
    public static void main(String[] args)
        throws IOException {
        File file = new File("F:\\myDir\\");
        File newFile = new File(file.getPath() + File.separator + "new_fuck.txt");
        File oldFile = new File(file.getPath() + File.separator + "old_fuck.txt");
        newFile.createNewFile();
        oldFile.createNewFile();

        File[] listRoots = oldFile.listRoots();

        for(File filE : listRoots) {
            System.out.println(filE.getPath());
        }

        boolean fileRenamed = oldFile.renameTo(newFile);

        if (fileRenamed) {
            System.out.println(oldFile + " renamed to " + newFile);
        } else {
            System.out.println("Renaming " + oldFile + " to " + newFile + " failed.");
        }
    }
}
