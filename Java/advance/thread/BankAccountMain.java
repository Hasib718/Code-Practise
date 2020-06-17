/**
 * This program is a example of "Race Condition", which occurs while
 * accessing shared reference from different threads. This problem also
 * happens while accessing volatile field variables.
 *
 * "Race Condition' can be solved through "Atomic Operation". And this
 * "Atomic Operation" can be achieved by adding @synchronized
 * statement(Key word) in methods, otherwise enclosing "Critical Section"
 * within @synchronized block.
 */
public class BankAccountMain {
    public static void main(String[] args) {
        BankAccount bankAccount = new BankAccount(100);

        Thread depositThread = new Thread(() -> {
            for (int i=0; i<100; i++) {
                bankAccount.deposit(100);
                sleep();
            }
        });

        Thread withdrawThread = new Thread(() -> {
            for (int i=0; i<100; i++) {
                bankAccount.withdraw(100);
                sleep();
            }
        });

        depositThread.start();
        withdrawThread.start();

        try {
            depositThread.join();
            withdrawThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }

        System.out.println("Current balance available in account: " +bankAccount.getBalance());
    }

    private static void sleep() {
        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }
    }
}

class BankAccount {
    private long balance;

    public BankAccount(long balance) {
        this.balance = balance;
    }

    public void withdraw(long amount) {
        System.out.println("Withdrawing "+amount);
        long newBalance = balance - amount;
        System.out.println("W New Balance is: "+newBalance);
        balance = newBalance;
    }

    public void deposit(long amount) {
        System.out.println("Depositing "+amount);
        long newBalance = balance + amount;
        System.out.println("D New Balance is: "+ newBalance);
        balance = newBalance;
    }

    public long getBalance() {
        return balance;
    }
}
