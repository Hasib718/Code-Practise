package com.hasib.java.immediate.collection;

import java.util.Queue;
import java.util.LinkedList;

public class QueueExample {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();

        for (int i=100; i>=0; i--) {
            queue.add(i);
        }
        while (!queue.isEmpty()) {
            Integer poll = queue.poll();
            dosomework(poll);
        }
    }

    private static void dosomework(Integer value) {
        System.out.println("Doing some work with+ " + value);
    }
}
