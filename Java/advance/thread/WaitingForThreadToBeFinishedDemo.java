import java.util.concurrent.TimeUnit;

public class WaitingForThreadToBeFinishedDemo {

    private static boolean doneWorking = false;

    public static void main(String[] args) {
        Thread fibonacciThread = new Thread(() -> {
            findTheTop20FibonacciNumber();
            doneWorking = true;
        });
        fibonacciThread.setName("Fibonacci Thread");
        fibonacciThread.start();

        /**
         * Here, we have put Main thread in sleep for about 500 milliseconds
         * to keep the track of other thread's current state. But in general cases
         * we don't how much time will be needed to complete the work given to the
         * other thread. So, it's a primary drawback.
         *
         * Another big issue about this method of controlling threads is if any
         * exception occurs while running the thread before changing the value of
         * static control variable of that thread, we can't get those exceptions
         * information.
         */
        try {
            TimeUnit.MILLISECONDS.sleep(500);

            /**
             * isAlive() method for checking invoked thread is running or not
             *
             * by doing this we can keep the main thread alive.
             * But this method simply waste CPU life cycle.
             */
            while (fibonacciThread.isAlive()) {
                System.out.println(fibonacciThread.getName()+" is still alive");
            }

            /**
             * the #join() method just simply detain the the thread where it is called until the invoked thread
             * is finished.
             */
            fibonacciThread.join();

            System.out.println(Thread.currentThread().getName()+" Thread terminated!");

            if (doneWorking) {
                System.out.println("\nFibonacci Thread has finished the work");
            } else {
                System.out.println("\nFibonacci Thread didn't finished the work!");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private static void findTheTop20FibonacciNumber() {
        for (int value = 1; value <= 20; value++) {
            System.out.println(fib(value) + ", ");
        }
    }

    private static int fib(int value) {
        if (value == 1 || value == 2) {
            return 1;
        }
        return fib(value - 1) + fib(value - 2);
    }
}
