package com.hasib.java.immediate.oop.polymorphism;

class Liquid{
    public void swirl(boolean clockwiae){
        System.out.println("Swirling Liquid");
    }
}

class Coffee extends Liquid{
    @Override
    public void swirl(boolean clockwiae) {
        System.out.println("Swirling Coffee");
    }
}

class Milk extends Liquid{
    @Override
    public void swirl(boolean clockwiae) {
        System.out.println("Swirling Milk");
    }
}

public class CoffeCup {
    private Liquid innerLiquid;

    void addLiquid(Liquid liq){
        innerLiquid = liq;

        innerLiquid.swirl(false);
    }
}
