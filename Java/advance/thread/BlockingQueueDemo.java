import java.util.Random;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.TimeUnit;

public class BlockingQueueDemo {
    private BlockingQueue<Integer> queue = new LinkedBlockingDeque<>(10);

    public void addItem(Integer item) {
        try {
            queue.put(item);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }
    }

    public Integer getItem() {
        try {
            return queue.take();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }
    }

    public static void main(String[] args) {
        BlockingQueueDemo blockingQueueDemo = new BlockingQueueDemo();

        Thread producer = new Thread(() -> {
            while (true) {
                int anInt = (new Random()).nextInt();
                System.out.println("Producer: "+anInt);
                blockingQueueDemo.addItem(anInt);
                sleepOneSecond();
            }
        });

        Thread consumer = new Thread(() -> {
            while (true) {
                Integer item = blockingQueueDemo.getItem();
                System.out.println("Consumed: "+item);
                sleepOneSecond();
            }
        });

        consumer.start();
        producer.start();
    }

    private static void sleepOneSecond() {
        try {
            TimeUnit.MILLISECONDS.sleep(1000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }
    }
}
