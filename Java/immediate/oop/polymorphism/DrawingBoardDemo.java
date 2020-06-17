package com.hasib.java.immediate.oop.polymorphism;

import java.util.Scanner;

public class DrawingBoardDemo {
    public static void main(String[] args){
        DrawingBoard drawingBoard = new DrawingBoard();
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter a Name: ");
        Circle circle = new Circle(scr.nextLine());
        System.out.println("Enter another Name: ");
        Square square = new Square(scr.nextLine());

        drawingBoard.draw(circle);
        drawingBoard.draw(square);
    }
}