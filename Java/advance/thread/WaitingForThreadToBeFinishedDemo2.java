import java.util.concurrent.TimeUnit;

public class WaitingForThreadToBeFinishedDemo2 {

    private static boolean doneWorking = false;

    public static void main(String[] args) {
        Thread willThrowException = new Thread(() -> {
            throwRuntimeException();
            doneWorking = true;
        });
        willThrowException.start();

        try {
            TimeUnit.MILLISECONDS.sleep(500);

            if (doneWorking) {
                System.out.println("\nThread willThrowException " +
                        "has finished the work");
            } else {
                System.out.println("\nThread willThrowException " +
                        "didn't finished the work!");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private static void throwRuntimeException() {
        throw new RuntimeException("something terribly bad happened");
        }
}
