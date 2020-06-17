package com.hasib.java.immediate.collection;

import java.time.LocalDateTime;
import java.util.*;

public class TweetImpl implements Twitter {
    private List<Tweet> list = new ArrayList<>();

    @Override
    public void addTweet(Tweet tweet) {
        list.add(tweet);
    }

    @Override
    public void printAllTweets() {
        for (Tweet tweet : list) {
            System.out.println(tweet);
        }
    }

    public static void main(String[] args) {
        Twitter twitter = new TweetImpl();
        Tweet tweet = new Tweet("Welcome to our School of" +
                " Online Courses", "Dimik Computing");

        twitter.addTweet(tweet);
        twitter.printAllTweets();
    }
}

interface Twitter {
    public void addTweet(Tweet tweet);
    public void printAllTweets();
}

class Tweet {
    private String name;
    private String text;
    private LocalDateTime dateTime;

    public Tweet(String text, String name) {
        this.name = name;
        this.text = text;
        this.dateTime = LocalDateTime.now();
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public LocalDateTime getDateTime() {
        return dateTime;
    }

    public void setDateTime(LocalDateTime dateTime) {
        this.dateTime = dateTime;
    }

    @Override
    public String toString() {
        return text + " - by" + name + " on " + dateTime.toString();
    }
}
