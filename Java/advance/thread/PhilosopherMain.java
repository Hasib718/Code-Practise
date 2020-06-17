import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Random;
import java.util.concurrent.TimeUnit;

/**
 * This is multi threading "Dead Lock" problem. This situation arise
 * because of circular dependency between threads.
 * By avoiding this circular dependency we can resolve deadlock problem.
 */
public class PhilosopherMain {
    public static void main(String[] args) {
        Fork[] forks = new Fork[5];
        for (int i=0; i<forks.length; i++) {
            forks[i] = new Fork();
        }

        Philosopher[] philosophers = new Philosopher[5];
        for (int i=0; i<philosophers.length; i++) {
            Fork leftFork = forks[i];
            Fork rightFork = forks[(i+1) % forks.length];

            if (i == philosophers.length - 1) {
                philosophers[i] = new Philosopher("Philosopher "+i,
                        rightFork, leftFork);
            } else {
                philosophers[i] = new Philosopher("Philosopher "+i,
                        leftFork, rightFork);
            }
            philosophers[i].start();
        }
    }
}

class Philosopher extends Thread {
    private String name;
    private final Fork leftFork;
    private final Fork rightFork;

    public Philosopher(String name, Fork leftFork, Fork rightFork) {
        this.name = name;
        this.leftFork = leftFork;
        this.rightFork = rightFork;
    }

    private void think() {
        log("thinking");
    }

    private void log(String msg) {
        String time = DateTimeFormatter.ISO_LOCAL_TIME.format(LocalDateTime.now());
        String thread = Thread.currentThread().getName();

        System.out.printf("%12s Thread: %s %s: %s%n", time, thread, name, msg);
        System.out.flush();
    }

    private void eat() {
        try {
            log("eating");
            int eatingTime = getRandomEatingTime();
            TimeUnit.NANOSECONDS.sleep(eatingTime);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }
    }

    @Override
    public void run() {
        while (true) {
            keepThinkingAndEating();
        }
    }

    private void keepThinkingAndEating() {
        think();

        synchronized (leftFork) {
            log("grabbed left fork");
            synchronized (rightFork) {
                log("grabbed right fork");
                eat();
                log("put down right fork");
            }
            log("put down left fork");
        }
    }

    private static int getRandomEatingTime() {
        return (new Random()).nextInt(100) +50;
    }
}

class Fork {}
