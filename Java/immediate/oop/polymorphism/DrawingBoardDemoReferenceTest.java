package com.hasib.java.immediate.oop.polymorphism;

public class DrawingBoardDemoReferenceTest {
    public static void main(String[] args){
        Shape shape = new Prism("anything"); //Upcasting of Prism

        System.out.println(((Prism)shape).getNamE()); //Downcasting of shape
        System.out.println(shape.getName());
        shape.name = "asdlfbl";
        System.out.println(shape.getName());

        if (shape instanceof Prism){
            Prism prism = (Prism) shape;
            prism.setName("Toufiq");
        }
        System.out.println(((Prism)shape).getNamE());
    }
}
