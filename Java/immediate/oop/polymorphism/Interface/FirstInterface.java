package com.hasib.java.immediate.oop.polymorphism.Interface;

import java.util.Scanner;

interface MyInterface{
    void sayHello();  //here we are not adding public keyword, because javac compiler +
                      //will automatically add it
}
interface MyAnotherInterface extends MyInterface{
    void sayBye();
}

interface AgainInterface{
    void setName(String name);
    String getName();
}

class MyInterfaceImpl implements MyAnotherInterface, AgainInterface{
    String name;

    @Override
    public void sayHello(){
        System.out.println("Hello, World!");
    }
    @Override
    public void sayBye(){
        System.out.println("Bye, World!");
    }
    @Override
    public void setName(String name){
        this.name = name;
    }
    @Override
    public String getName(){
        return name;
    }
}

public class FirstInterface {
    public static void main(String[] args){
        Scanner scr = new Scanner(System.in);
        MyAnotherInterface myAnotherInterface = new MyInterfaceImpl();
        MyInterfaceImpl myInterfaceImpl = new MyInterfaceImpl();

        myAnotherInterface.sayHello();  //We cannot call the methods from AgainInterface because +
        myAnotherInterface.sayBye();    //MyAnotherInterface and AgainInterface are not linked
        myInterfaceImpl.sayHello();
        myInterfaceImpl.sayBye();

        System.out.println("Enter your name: ");
        myInterfaceImpl.setName(scr.nextLine());
        System.out.println(myInterfaceImpl.getName());
    }
}
