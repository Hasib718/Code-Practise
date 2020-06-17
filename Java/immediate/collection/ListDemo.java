package com.hasib.java.immediate.collection;

import java.util.List;
import java.util.ArrayList;
import java.util.Vector;

public class ListDemo {
    public static void main(String[] args) {
        List<String> arrayList = new ArrayList<>();

        arrayList.add("Babor");
        arrayList.add("Humayun");
        arrayList.add("Akbar");
        arrayList.add("Jahangir");
        arrayList.add("Shah Jahan");
        arrayList.add("Aurngzeb");

        System.out.println("ArrayList\n");

        System.out.println("Name of Emperors : " + arrayList);
        System.out.println("Total Emperors: " + arrayList.size());

        System.out.println("Second Emperor: " + arrayList.get(1));

        arrayList.set(2, "Akbar The Great");
        System.out.println("Name of Emperors : " + arrayList);

        arrayList.remove(3);
        System.out.println("Name of Emperors : " + arrayList);

        arrayList.remove("Aurngzeb");
        System.out.println("Name of Emperors : " + arrayList);

        arrayList.add("Shah Jahan");
        System.out.println("Name of Emperors : " + arrayList);

        System.out.println("Index of Human: " + arrayList.indexOf("Humayun"));

        System.out.println("Last Index of \"Shah Jahan\" : " + arrayList.lastIndexOf("Shah Jahan"));

        String[] str = {"A", "B"};
        VecTor.main(str);
        LinkeDList.main(str);
    }
}

class VecTor {
    public static void main(String[] args) {
        List<String> vector = new Vector<>();
        vector.add("Babor");
        vector.add("Humayun");
        vector.add("Akbar");
        vector.add("Jahangir");
        vector.add("Shah Jahan");
        vector.add("Aurngzeb");

        System.out.println("Vector\n");

        System.out.println("Name of Emperors : " + vector);
        System.out.println("Total Emperors: " + vector.size());

        System.out.println("Second Emperor: " + vector.get(1));

        vector.set(2, "Akbar The Great");
        System.out.println("Name of Emperors : " + vector);

        vector.remove(3);
        System.out.println("Name of Emperors : " + vector);

        vector.remove("Aurngzeb");
        System.out.println("Name of Emperors : " + vector);

        vector.add("Shah Jahan");
        System.out.println("Name of Emperors : " + vector);

        System.out.println("Index of Human: " + vector.indexOf("Humayun"));

        System.out.println("Last Index of \"Shah Jahan\" : " + vector.lastIndexOf("Shah Jahan"));
    }
}

class LinkeDList {
    public static void main(String[] args) {
        List<String> linkedlist = new Vector<>();
        linkedlist.add("Babor");
        linkedlist.add("Humayun");
        linkedlist.add("Akbar");
        linkedlist.add("Jahangir");
        linkedlist.add("Shah Jahan");
        linkedlist.add("Aurngzeb");

        System.out.println("LinkedList\n");

        System.out.println("Name of Emperors : " + linkedlist);
        System.out.println("Total Emperors: " + linkedlist.size());

        System.out.println("Second Emperor: " + linkedlist.get(1));

        linkedlist.set(2, "Akbar The Great");
        System.out.println("Name of Emperors : " + linkedlist);

        linkedlist.remove(3);
        System.out.println("Name of Emperors : " + linkedlist);

        linkedlist.remove("Aurngzeb");
        System.out.println("Name of Emperors : " + linkedlist);

        linkedlist.add("Shah Jahan");
        System.out.println("Name of Emperors : " + linkedlist);

        System.out.println("Index of Human: " + linkedlist.indexOf("Humayun"));

        System.out.println("Last Index of \"Shah Jahan\" : " + linkedlist.lastIndexOf("Shah Jahan"));
    }
}