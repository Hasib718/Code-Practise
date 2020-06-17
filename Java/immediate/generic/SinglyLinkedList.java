package com.hasib.java.immediate.generic;

public class SinglyLinkedList<Type> {
    private long size;

    private Node<Type> head;
    private Node<Type> tail;

    public void addFirst(Type value) {
        addFirst(new Node<>(value));
    }

    public void addLast(Type value) {
        addLast(new Node<>(value));
    }

    private void addLast(Node<Type> node) {
        if (size == 0) {
            head = node;
        } else {
            tail.setNext(node);
        }
        tail = node;
        size++;
    }

    public void addFirst(Node<Type> node) {
        Node<Type> temp = head;
        head = node;
        head.setNext(temp);

        size++;

        if (size == 1) {
            tail = head;
        }
    }

    public Node<Type> getHead() {
        return head;
    }

    public Node<Type> getTail() {
        return tail;
    }

    public void removeFirst() {
        if (size != 0) {
            head = head.getNext();
            size--;
        }

        if (size == 0) {
            tail = null;
        }
    }

    public void removeLast() {
        if (size != 0) {
            if (size == 1) {
                head = tail = null;
            } else {
                Node<Type> current = head;

                while (current.getNext() != tail) {
                    current = current.getNext();
                }
                current.setNext(null);
                tail = current;
            }
            size--;
        }
    }

    public Type getFirst() {
        return getHead().getValue();
    }

    public boolean remove(Type type) {
        Node<Type> prev = null;
        Node<Type> current = head;

        while (current != null) {
            if (current.getValue().equals(type)) {
                if (prev != null) {
                    prev.setNext(current.getNext());

                    if (current.getNext() == null) {
                        tail = prev;
                    }

                    size--;
                } else {
                    removeFirst();
                }

                return true;
            }

            prev = current;
            current = current.getNext();
        }

        return false;
    }

    public  long getSize() {
        return size;
    }

    public void print() {
        System.out.print("Total elements : " + size + " -> ");

        Node node = head;
        while (node != null) {
            System.out.print(node.getValue().toString() + ",");
            node = node.getNext();
        }
        System.out.println();
    }

    public void clear() {
        for (Node<Type> x = head; x != null; ) {
            Node<Type> next = x.next;
            x.next = null;
            x.value = null;
            x = next;
        }

        head = tail = null;
        size = 0;
    }

    private class Node<Type> {
        private Type value;
        private Node<Type> next=null;

        public Node(Type value) {
            this.value = value;
        }

        public Type getValue() {
            return value;
        }

        public void setValue(Type value) {
            this.value = value;
        }

        public Node<Type> getNext() {
            return next;
        }

        public void setNext(Node<Type> next) {
            this.next = next;
        }
    }
}
