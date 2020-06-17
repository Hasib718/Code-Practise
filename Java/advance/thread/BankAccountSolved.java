import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.concurrent.TimeUnit;

public class BankAccountSolved {
    public static void main(String[] args) {
        BankAccountSync bankAccount = new BankAccountSync(100);
        DateTimeFormatter isoTimeFormatter = DateTimeFormatter.ISO_TIME;

        Thread depositThread = new Thread(() -> {
            System.out.println(Thread.currentThread().getName()+
                    " started at: "+ isoTimeFormatter.format(LocalDateTime.now()));
            bankAccount.deposit(100);
        });
        depositThread.setName("Deposit Thread");

        Thread withdrawThread = new Thread(() -> {
            System.out.println(Thread.currentThread().getName()+
                    " started at: "+ isoTimeFormatter.format(LocalDateTime.now()));
            bankAccount.withdraw(100);
        });
        withdrawThread.setName("Withdraw Thread");

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

class BankAccountSync {
    private long balance;

    public BankAccountSync(long balance) {
        this.balance = balance;
    }

    public synchronized  void withdraw(long amount) {
        System.out.println("Inside the withdraw method! Locked acquired!");

        try {
            TimeUnit.MILLISECONDS.sleep(500);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }

        System.out.println("Withdrawing "+amount);
        long newBalance = balance - amount;
        System.out.println("W New Balance is: "+newBalance);
        balance = newBalance;

        System.out.println("End of withdraw method! releasing the lock");
    }

    public synchronized void deposit(long amount) {
        System.out.println("Inside the deposit method! Locked acquired!");

        try {
            TimeUnit.MILLISECONDS.sleep(500);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }

        System.out.println("Depositing "+amount);
        long newBalance = balance + amount;
        System.out.println("D New Balance is: "+ newBalance);
        balance = newBalance;

        System.out.println("End of withdraw method! releasing the lock");
    }

    public long getBalance() {
        return balance;
    }
}
