package com.hasib.java.extra;


/**
 * This class a example of java builder pattern in other word method chaining..
 */
public class BuilderPatternDemo {
    public static void main(String[] args) {
        Student student1 = new Student();
        Student student2 = new Student();

        student1.setId(1).setName("Hasib").setAddress("Dhaka");
        student2.setId(2).setName("Wadud").setAddress("Pabna");

        System.out.println(student1);
        System.out.println(student2);
    }
}

final class Student {
    private int id;
    private String name;
    private String address;

    /**
     * In order to set method chaining method of the class should return "this" reference.
     */
    public Student setId(int id) {
        this.id = id;
        return this;
    }

    public Student setName(String name) {
        this.name = name;
        return this;
    }

    public Student setAddress(String address) {
        this.address = address;
        return this;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", address='" + address + '\'' +
                '}';
    }
}