package com.hasib.java.immediate.nio;

import java.nio.charset.Charset;
import java.util.*;

public class AvailableCharsets {
    public static void main(String[] args) {
        Map<String, Charset> map = Charset.availableCharsets();

        Set<String> keys = map.keySet();
        int count = keys.size();

        System.out.println("Availabe Character Set Count: " + count);

        for (String charsetName : keys) {
            System.out.println(charsetName);
        }
    }
}
