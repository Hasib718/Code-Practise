import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.concurrent.TimeUnit;

public class WatchThread implements Runnable {
    private static final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:s a");

    private static FileOutputStream out = null;
    private static File outputFile = null;

    /**
     * #volatile
     * this keyword is for avoiding visibility problem related to Thread.
     */
    private volatile boolean running = true;

    public WatchThread() {
        try {
            outputFile = new File("F:\\PROJECTS\\Java\\Practices\\myDir\\watch.txt");
            out = new FileOutputStream(outputFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (running) {
            printCurrentTime();
            sleepOneSecond(1);

            if (Thread.interrupted()) {
                System.out.println("Thread is Interrupted");
                return;
            }
        }
    }

    private void sleepOneSecond(int i) {
        try {
            Thread.sleep(TimeUnit.SECONDS.toMillis(i));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void printCurrentTime() {
        String formattedCurrentTime = LocalDateTime.now().format(formatter);

        System.out.println(formattedCurrentTime);

        try {
            out.write((formattedCurrentTime+"\n").getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void shutDown() {
        this.running = false;
    }

    public static void main(String[] args) {
        WatchThread watch = new WatchThread();
        Thread thread = new Thread(watch);
        thread.start();

        try {
            Thread.sleep(TimeUnit.SECONDS.toMillis(10));
            System.out.println(Thread.currentThread().getName());
            /**
             * @interruot()
             * is for stopping thread
             */
//            thread.interrupt();
            watch.shutDown();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
