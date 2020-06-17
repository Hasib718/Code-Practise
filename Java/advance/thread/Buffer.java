import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.LinkedList;
import java.util.Queue;

public class Buffer {
    private static final int SIZE = 10;
    private Queue<Integer> queue = new LinkedList<>();
    private final Object lock = new Object();

    public void addItem(int item) {
        synchronized (lock) {
            while (queue.size() == SIZE) {
                log("Size is full, let's wait!");
                try {
                    lock.wait();
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    throw new AssertionError(e);
                }
            }
            log("Thread Resumed!");
            log("Adding item: "+item);

            queue.add(item);

            log("Item added, let's notify");
            lock.notifyAll();
        }
    }

    public synchronized Integer getItem() {
        synchronized (lock) {
            while (queue.isEmpty()) {
                log("Queue is empty, let's wait!");
                try {
                    lock.wait();
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    throw new AssertionError(e);
                }
            }
            log("Thread Resumed!");
            log("Let's consume value");
            Integer value = queue.poll();

            log("Item consumed: "+value+", let's notify");
            lock.notifyAll();

            return value;
        }
    }

    private void log(String s) {
        String time = DateTimeFormatter.ISO_LOCAL_TIME.format(LocalDateTime.now());
        String thread = Thread.currentThread().getName();

        System.out.printf("%12s Thread:%s %s%n", time, thread, s);
        System.out.flush();
    }

    public static void main(String[] args) {
        Buffer buffer = new Buffer();

        Thread addingThread = new Thread(() -> {
            buffer.addItem(5);
        });
        addingThread.setName("Adding Thread");

        Thread gettingThread = new Thread(() -> {
            buffer.getItem();
        });
        gettingThread.setName("Getting Thread");

        gettingThread.start();
        addingThread.start();

        try {
            addingThread.join();
            gettingThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }
    }
}
