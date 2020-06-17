import java.util.concurrent.TimeUnit;

public class ThreadDemo {
    public static void main(String[] args) {
        /**
         * By extending Thread class
         */
        ExtendedThread extendedThread = new ExtendedThread();
        extendedThread.setName("Extended Thread");
        extendedThread.start();

        /**
         * By implementing Runnable interface
         */
        ImplementedThread implementedThread = new ImplementedThread();
        Thread thread = new Thread(implementedThread);
        thread.setName("Implemented Thread");
        thread.start();

        /**
         * By sending anonymous inner class as Thread argument
         */
        new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    System.out.println("[" + i + "] Inside Anonymous Inner Class");

                    sleepOneSecond(1);
                }
            }
        }).start();

        /**
         * Using lambda expression
         */
        new Thread(() -> {
            for (int i = 0; i < 10; i++) {
                System.out.println("[" + i + "] Inside Lambda expression");

                sleepOneSecond(1);
            }
        }).start();

        /**
         * In the Main Thread
         */
        for (int i = 0; i < 10; i++) {
            System.out.println("[" + i + "] Inside " + Thread.currentThread().getName());

            sleepOneSecond(1);
        }
    }

    private static void sleepOneSecond(int i) {
        try {
            Thread.sleep(TimeUnit.SECONDS.toMillis(i));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}

class ExtendedThread extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println("[" + i + "] Inside " + Thread.currentThread().getName());

            sleepOneSecond(1);
        }
    }

    private void sleepOneSecond(int i) {
        try {
            Thread.sleep(TimeUnit.SECONDS.toMillis(i));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class ImplementedThread implements Runnable {

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println("[" + i + "] Inside " + Thread.currentThread().getName());

            sleepOneSecond(1);
        }
    }

    private void sleepOneSecond(int i) {
        try {
            Thread.sleep(TimeUnit.SECONDS.toMillis(i));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
