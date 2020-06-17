package com.hasib.java.immediate.generic;

public class LinkedListDemo {
    public static void main(String[] args) {
        SinglyLinkedList<Integer> integers = new SinglyLinkedList<>();

        integers.addFirst(8);
        integers.addFirst(7);
        integers.addFirst(6);
        integers.addFirst(5);
        integers.addFirst(4);
        integers.addFirst(3);
        integers.addFirst(2);
        integers.addFirst(1);

        integers.print();

        System.out.println(integers.getFirst());

        System.out.println("\n\nRemove first and last elements...");
        integers.removeFirst();
        integers.removeLast();
        integers.print();

        Integer Int = 5;
        integers.remove(Int);
        integers.print();
    }
}
