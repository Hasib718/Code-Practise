package com.hasib.java.immediate.oop.inheritence;

public class Circle {
    double radius;
    String color;

    public Circle(double radius, String color){
        this.radius = radius;
        this.color = color;
    }
    public Circle(){
        this.radius = 1.0;
        this.color = "ORANGE";
    }
    public double getArea(){
        return radius * radius * Math.PI;
    }
    public String toString(){
        return ("Radius of The Circle is " + radius
                + "\n" +
                "Color of The Circle is " + color
                + "\n" +
                "Area of THe Circle is " + getArea());
    }
}
