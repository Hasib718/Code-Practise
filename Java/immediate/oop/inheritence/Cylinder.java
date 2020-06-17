package com.hasib.java.immediate.oop.inheritence;

public class Cylinder extends Circle{
    double height;

    public Cylinder(){
        this.height = 1.0;
    }
    public Cylinder(double radius, String color, double height){
        super(radius, color);   //calling the contructor of it's parent class
        this.height = height;
    }

    @Override
    public double getArea() {
        double area = 2 * (Math.PI * radius * height + super.getArea());
        return area;
    }

    @Override
    public String toString(){
        return (super.toString() + "\n" +
                "Height of The Cylinder is " + height + "\n" +
                "Area of The Cylinder is " + getArea());
    }

    public double getVolume(){
        return super.getArea() * height;
    }
}
