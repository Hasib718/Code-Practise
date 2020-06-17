import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

public class ThreadJoinExample {
    public static void main(String[] args)
        throws InterruptedException {
        FileDownloader downloader1 = new FileDownloader("https://goo.gl/nqZJn4", "jugbd-meetup7_1.jpeg");
        FileDownloader downloader2 = new FileDownloader("https://goo.gl/UoSMMt", "jugbd-meetup7_2.jpeg");

        DownloadingHeartBeat heartBeat = new DownloadingHeartBeat();

        downloader1.start();
        downloader2.start();
        heartBeat.start();

        try {
            downloader1.join();
            downloader2.join();

            heartBeat.shutDown();

            heartBeat.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("\nThe download is complete");
    }
}

class DownloadingHeartBeat extends Thread {
    private volatile boolean beating = true;

    @Override
    public void run() {
        String[] dots = {
                ".",
                "..",
                "...",
                "...."
        };

        while (beating) {
            for (String dot : dots) {
                System.out.println(dot);

                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public void shutDown() {
        this.beating = false;
    }
}

class FileDownloader extends Thread {
    private String url;
    private String fileName;

    public FileDownloader(String url, String fileName) {
        this.url = url;
        this.fileName = fileName;
    }

    @Override
    public void run() {
        try {
            System.out.println("Started to download: "+fileName);

            URL resourceToDownload = new URL(url);
            URLConnection urlConnection = resourceToDownload.openConnection();
            InputStream inputStream = urlConnection.getInputStream();

            File fileToSave = new File(fileName);
            Files.copy(inputStream, fileToSave.toPath(), StandardCopyOption.REPLACE_EXISTING);
            inputStream.close();
        } catch (IOException e) {
            System.err.println("Failed to download the file: "+e.getMessage());
        }
    }
}