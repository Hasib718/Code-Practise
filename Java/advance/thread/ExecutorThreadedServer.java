import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

/**
 * http://localhost:8080/
 *
 * to connect to this server
 */
public class ExecutorThreadedServer {
    private static final String DOCUMENT = "<!DOCTYPE html>\n" +
            "<html lang=\"en\">\n" +
            "<head>\n" +
            "    <meta charset=\"UTF-8\">\n" +
            "    <title>Single Threaded Server</title>\n" +
            "</head>\n" +
            "<body>\n" +
            "    <p>It works!</p>\n" +
            "</body>\n" +
            "</html>";
    private static final String HEADER = "HTTP/1.1 200 OK\r\n"+
            "Content-Type: text/html; charset=UTF-8\r\n"+
            "Content-length: "+DOCUMENT.length()+
            "\r\n\r\n";

    public static void main(String[] args)
        throws IOException {
        ServerSocket serverSocket = new ServerSocket(8080);

        Executor executor = Executors.newFixedThreadPool(10);

        while (true) {
            Socket connection = serverSocket.accept();

            executor.execute(new Runnable() {
                @Override
                public void run() {
                    serverRequest(connection);

                    try {
                        TimeUnit.MINUTES.sleep(1);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        throw new AssertionError(e);
                    }
                }
            });
        }
    }

    private static void serverRequest(Socket connection) {
        System.out.println("New connection request from: "+connection.toString());

        try (OutputStream os = connection.getOutputStream();
        PrintWriter out = new PrintWriter(os)) {
            out.write(HEADER);
            out.write(DOCUMENT);
        } catch (IOException e) {
            Thread.currentThread().interrupt();
            throw new AssertionError(e);
        }
    }
}
