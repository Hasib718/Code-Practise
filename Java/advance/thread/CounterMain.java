import java.util.concurrent.TimeUnit;

/**
 * Though @synchronized is useful, but it has a heavy cost to sustain.
 * Because of using @synchronized the program run a lot slower than usual.
 */
public class CounterMain {
    public static void main(String[] args) {
        Counter counter = new Counter();
        CounterSync counterSync = new CounterSync();
        long start, end;

        Thread t1 = new Thread(() -> {
            for (int i=0; i<Integer.MAX_VALUE; i++) {
                counter.increment();
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i=0; i<Integer.MAX_VALUE; i++) {
                counter.decrement();
            }
        });

        Thread t3 = new Thread(() -> {
            for (int i=0; i<Integer.MAX_VALUE; i++) {
                counter.increment();
            }
        });

        Thread t4 = new Thread(() -> {
            for (int i=0; i<Integer.MAX_VALUE; i++) {
                counter.decrement();
            }
        });

        start = System.nanoTime();

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }

        end = System.nanoTime();
        System.out.println("Duration without Sync: "+
                TimeUnit.MINUTES.convert((end - start), TimeUnit.MICROSECONDS));

        start = System.nanoTime();

        t3.start();
        t4.start();

        try {
            t3.join();
            t4.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }

        end = System.nanoTime();
        System.out.println("Duration with Sync: "+
                TimeUnit.MINUTES.convert((end - start), TimeUnit.MICROSECONDS));
    }
}

class Counter {
    private int count;

    public void increment() {
        count++;
    }

    public void decrement() {
        count--;
    }
}

class CounterSync {
    private int count;
    private Object object = new Object();

    public void increment() {
        synchronized (object) {
            count++;
        }
    }

    public void decrement() {
        synchronized (object) {
            count--;
        }
    }
}
