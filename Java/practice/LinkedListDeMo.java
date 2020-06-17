package com.hasib.java.practice;

import java.util.Random;

public class LinkedListDeMo {
    public static void main(String[] args) {
        LinkedListSub linkedListSub = new LinkedListSub();

        linkedListSub.add(1);
        linkedListSub.add(2);
        linkedListSub.add(3);
        linkedListSub.add(4);
        linkedListSub.add(5);
        linkedListSub.add(6);

        linkedListSub.print();
    }
}

class LinkedListSub extends LinkedList {
    int size = 0;
    @Override
    public void add(int value) {
        Random random = new Random();

        switch (random.nextInt(3)) {
            case 0:
                first = addNodefirst(value, first);
                break;
            case 1:
                first = addNodeLast(value, first);
                break;
            case 2:
                if(size > 2) {
                    first = addNodeMiddle(value, first);
                } else {
                    add(value);
                }
                break;
        }
        size++;
    }

    private Node addNodeLast (int value, Node node) {
        if (node == null) {
            node = new Node(value, null);
            return node;
        }

        node.setNext(addNodeLast(value, node.getNext()));
        return node;
    }

    private Node addNodefirst (int value, Node node) {
        if (node == null) {
            node = new Node(value, null);
            return node;
        }

        Node temp = new Node(value, node);
        return temp;
    }

    private Node addNodeMiddle (int value, Node node) {
        Node tempFirst = node;

        if (node == null) {
            node = new Node(value, null);
            return tempFirst;
        }

        Node temp = node;
        Node nextTemp = node.getNext();
        for (int i=0; i<(size/2)-1; i++) {
            node = node.getNext();
            nextTemp = nextTemp.getNext();
        }
        node.setNext(new Node(value, nextTemp));

        return tempFirst;
    }

    public void print() {
        Node node = first;
        while (node != null) {
            System.out.print(node.getDatum() + ",");
            node = node.getNext();
        }
        System.out.println();
    }
}

class LinkedList {
    protected Node first;

    public int get() {
        int out = Integer.MIN_VALUE;
        if (first != null) {
            out = first.getDatum();
            first = first.getNext();
        }

        return out;
    }

    public void add(int value) {

    }
}

class Node {
    private int datum;
    private Node next;

    public Node(int datum) {
        this.datum = datum;
    }

    public Node(int datum, Node next) {
        this.datum = datum;
        this.next = next;
    }

    public int getDatum() {
        return datum;
    }

    public void setDatum(int datum) {
        this.datum = datum;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}