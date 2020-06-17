package com.hasib.java.immediate.generic;

import javafx.util.Pair;

class Generic<T> {
    private T obj;

    public Generic(T obj) {
        this.obj = obj;
    }

    public T getObj() {
        return obj;
    }
    public void showType() {
        System.out.println("Type of T is: "
                            + obj.getClass().getName());
    }

    public <K, V> boolean compare(Pair<K, V> p1, Pair<K, V> p2) {
        return p1.getKey().equals(p2.getKey()) && p1.getValue().equals(p2.getValue());
    }
}

public class Generics {
    public static void main(String[] args) {
        Generic<Integer> integerGeneric = new Generic<Integer>(88);
        Generic<String> stringGeneric = new Generic<String>("This is a Generic Test");

        integerGeneric.showType();
        System.out.println("Value: " + integerGeneric.getObj());
        stringGeneric.showType();
        System.out.println("Value: " + stringGeneric.getObj());

        Pair<String, Integer> p1 = new Pair<>("Hashu", 94);
        Pair<String, Integer> p2 = new Pair<>("Toufiqqa", 84);

        if (!integerGeneric.compare(p1, p2)) {
            System.out.println("\n\nIts Works!.......");
        }
    }
}
