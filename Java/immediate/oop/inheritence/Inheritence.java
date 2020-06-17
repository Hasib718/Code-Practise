package com.hasib.java.immediate.oop.inheritence;

import com.hasib.java.immediate.generic.*;

public class Inheritence {
    public static void main(String[] args) {
//        MountainBike mb = new MountainBike(3, 100, 25);
//        System.out.println(mb.toString());
        String[] str = {"a", "b"};
        DemoContainer.main(str);
    }
}

//parent class
class Bicycle {
    public int gear;

    public int speed;

    public Bicycle(int gear, int speed) {
        this.gear = gear;
        this.speed = speed;
    }

    public void applyBrake(int decrement) {
        speed -= decrement;
    }

    public void speedUp(int increment) {
        speed += increment;
    }
    public String toString() {
        return ("No of gears are " + gear
                + "\n"
                + "speed of bicycle is " + speed);
    }

}
// child class
class MountainBike extends Bicycle {

    public int seatHeight;

    public MountainBike(int gear, int speed,
                        int seatHeight) {
        super(gear, speed);    //Calling parent's constructor
        this.seatHeight = seatHeight;
    }

    public void setHeight(int seatHeight) {
        this.seatHeight = seatHeight;
    }

    @Override
    public String toString() {
        return (super.toString() +   // Overriding parent's toString
                "\nseat height is " + seatHeight);
    }

}
