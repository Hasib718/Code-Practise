package com.hasib.java.immediate.nio;

import java.nio.ByteBuffer;
import java.util.Arrays;

public class BufferReadWrite {
    public static void main(String[] args) {
        ByteBuffer bb = ByteBuffer.allocate(8);
        System.out.println("Right After Creation : ");
        BufferReadWrite.printBuffer(bb);

        for (int i=10; i<18; i++) {
            bb.put((byte) i);
        }
        System.out.println("After populating Data: ");
        BufferReadWrite.printBuffer(bb);
    }

    public static void printBuffer(ByteBuffer b) {
        int limit = b.limit();
        System.out.println("Position: " + b.position() + ", limit: " + limit);
        System.out.println("Data: ");
        System.out.println(Arrays.toString(b.array()));
//        for (int i=0; i<limit; i++) {
//            System.out.println(b.get(i) + ' ');
//        }
        System.out.println();
    }
}

//class CharBufferReadWrite {
//    public static void main(String[] args) {
//        CharBuffer cb = CharBuffer.allocate(8);
//        System.out.println("Right After Creation : ");
//        BufferReadWrite.printBuffer(cb);
//    }
//}