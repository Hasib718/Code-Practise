package com.hasib.java.immediate.oop.polymorphism.Interface;

import java.util.Scanner;

interface Payment{
    long getAmount();
    void setAmount(long amount);
}

class BkashPayment implements Payment{
    public long amount;

    public BkashPayment(long amount){
        this.amount = amount;
    }

    @Override
    public long getAmount(){
        return amount;
    }
    @Override
    public void setAmount(long amount){
        this.amount = amount;
    }
}

class CashPayment implements Payment{
    public long amount;

    public CashPayment(long amount){
        this.amount = amount;
    }

    @Override
    public long getAmount(){
        return amount;
    }
    @Override
    public void setAmount(long amount){
        this.amount = amount;
    }
}

class PaymentEngine{
    public void accept(Payment payment){
        System.out.println("Accepting Payment: " + payment.getAmount()
                            + "\nAccepted!");
    }
    public void thankYou(){
        System.out.println("Thank You For Dealing With Us\n");
    }
}

public class PaymentEngineDemo {
    public static void main(String[] args){
        Scanner scr = new Scanner(System.in);
        PaymentEngine paymentEngine = new PaymentEngine();

        System.out.println("Choose Payment Method: "
                            + "\n" +
                            "1. Cash Payment."
                            + "\n" +
                            "2. Bkash Payment."
                            + "\n" +
                            "3. Cancel\n\n");
        int choice = scr.nextInt();

        if(choice != 3) {
            if (choice == 1) {
                System.out.println("Enter The Amount You Want To Pay: ");
                paymentEngine.accept(new CashPayment(scr.nextLong()));
                paymentEngine.thankYou();
            }
            else if (choice == 2) {
                System.out.println("Enter The Amount You Want To Pay: ");
                paymentEngine.accept(new BkashPayment(scr.nextLong()));
                paymentEngine.thankYou();
            }
        }
        else{
            paymentEngine.thankYou();
        }
    }
}
