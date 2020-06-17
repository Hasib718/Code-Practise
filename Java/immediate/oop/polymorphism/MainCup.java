package com.hasib.java.immediate.oop.polymorphism;

public class MainCup {
    public static void main(String[] args){
        CoffeCup mycup = new CoffeCup();

        Liquid genericLiquid = new Liquid();
        Coffee coffee = new Coffee();
        Milk milk = new Milk();

        mycup.addLiquid(genericLiquid);
        mycup.addLiquid(coffee);
        mycup.addLiquid(milk);
    }
}
