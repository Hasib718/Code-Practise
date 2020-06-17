import java.util.concurrent.TimeUnit;

public class ThreadUncheckedExceptionExample {
    public static void main(String[] args) {
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    TimeUnit.SECONDS.sleep(5);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                    System.err.println("Thread interrupted due to "+e.getMessage());
                }

                throw new RuntimeException("Goodbye cruel world!");
            }
        });

        thread.setUncaughtExceptionHandler(new CustomUncaughtExceptionHandler());
        thread.start();
    }
}

class CustomUncaughtExceptionHandler implements Thread.UncaughtExceptionHandler {

    @Override
    public void uncaughtException(Thread thread, Throwable throwable) {
        System.out.println("Exception has been thrown from "+thread.getName());
        System.out.println("Exception message: "+throwable.getMessage());
    }
}