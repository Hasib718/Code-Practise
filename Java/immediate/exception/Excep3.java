package com.hasib.java.immediate.exception;

class DataFetcher{
    public String fetchDataFreomUrl(String url)
        throws CheckedException{
        if (url == null){
            throw new CheckedException("Url Not Found");
        }
        String data = null;
        return data;
    }
}
class CheckedException extends Exception{
    public CheckedException(String message){
        super(message);
    }
}
class DataFetcherDemo {
    private DataFetcher dataFetcher;

    public DataFetcherDemo(DataFetcher dataFetcher) {
        this.dataFetcher = dataFetcher;
    }

    public void fetchData() {
        String url = "http://google.com";
        try {
            String fetchedData = dataFetcher.fetchDataFreomUrl(url);
            System.out.println(fetchedData);
        }catch (CheckedException e) {
            e.printStackTrace();
        }
    }
}
class DataFetcherDemoDuplicate {
    private DataFetcher dataFetcher;

    public DataFetcherDemoDuplicate(DataFetcher dataFetcher) {
        this.dataFetcher = dataFetcher;
    }

    public void fetchData()
        throws CheckedException {
        String url = "http://google.com";

        String fetchedData = dataFetcher.fetchDataFreomUrl(url);
        System.out.println(fetchedData);
        throw new CheckedException("Mistake");
    }
}

public class Excep3 {
    public static void main(String[] args){
        DataFetcherDemo dataFetcherDemo = new DataFetcherDemo(
                                                new DataFetcher());
        DataFetcherDemoDuplicate dataFetcherDemoDuplicate = new DataFetcherDemoDuplicate(
                                                                new DataFetcher());

        //dataFetcherDemo.fetchData();
        try {
            dataFetcherDemoDuplicate.fetchData();
        }catch (CheckedException e) {
            System.out.println("This is exception");
        }
    }
}