package com.hasib.java.immediate.collection;

import java.util.Queue;
import java.util.PriorityQueue;
import java.lang.Comparable;

public class PriorityQueueExample {
    public static void main(String[] args) {
        Queue<PersoN> persons = new PriorityQueue<>();

        persons.offer(new PersoN("Person 1", 14));
        persons.offer(new PersoN("Person 2", 35));
        persons.offer(new PersoN("Person 3", 15));
        persons.offer(new PersoN("Person 4", 12));
        persons.offer(new PersoN("Person 5", 40));
        persons.offer(new PersoN("Person 5", 15));

        while (!persons.isEmpty()) {
            System.out.println("Serving Person - name: " +
                    persons.peek().getName() + ", age: " + persons.peek().getAge());
            persons.poll();
        }
    }
}

class PersoN implements Comparable<PersoN> {
    private String name;
    private Integer age;

    public PersoN(String name, Integer age) {
        this.name = name;
        this.age = age;
    }
    public String getName() {
        return name;
    }
    public Integer getAge() {
        return age;
    }

    @Override
    public String toString() {
        return name + "(" + age + ")";
    }

    @Override
    public int compareTo(PersoN o) {
        int r = o.age.compareTo(this.age);
        return r == 0 ? o.name.compareTo(this.name) : r;
    }
}