#ifndef POST_H
#define POST_H

#include <string>
#include <chrono>
#include <iostream>

class Post {
protected:
    std::string title;
    std::chrono::steady_clock::time_point time_stamp; // per-post timestamp
    int numberOfLikes;
    std::string mediaURL;
    int videoLengthSeconds;

public:
    // BST-compatible fields
    int postID;
    int likes;

    // Constructors / destructor
    Post();
    Post(const std::string& title,
         const std::string& mediaURL,
         int videoLengthSeconds);

    // NEW constructor for BST use
    Post(int id, const std::string& title, int likes);

    // Big 3
    Post(const Post& other);
    Post& operator=(const Post& other);

    virtual ~Post() = default;

    // BST helper functions
    int getPostID() const;
    void displayPost() const;

    // Existing getters / setters
    std::string getTitle() const;
    void setTitle(const std::string& newTitle);

    std::string getMediaURL() const;
    int getVideoLengthSeconds() const;
    int getNumberOfLikes() const;

    // Polymorphism
    virtual void display() const;
    virtual void edit();

    // Operator overloading
    bool operator==(const Post& otherPost) const;
};

#endif // POST_H