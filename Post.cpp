// TO DO: #include all the standard libraries and your own libraries here
#include <chrono>
#include "Post.h"
#include <iostream>

// TO DO: function implementations

//constructors:
Post::Post(int id, const std::string& title, int likes)
    : title(title),
      time_stamp(std::chrono::steady_clock::now()),
      numberOfLikes(likes),
      mediaURL(""),
      videoLengthSeconds(0),
      postID(id),
      likes(likes)
{
}
// Para
Post::Post(const std::string& title,
           const std::string& mediaURL,
           int videoLengthSeconds)
    : title(title),
      time_stamp(std::chrono::steady_clock::now()),
      numberOfLikes(0),
      mediaURL(mediaURL),
      videoLengthSeconds(videoLengthSeconds)
{
}
Post::Post(const Post& other)
    : title(other.title),
      time_stamp(other.time_stamp),
      numberOfLikes(other.numberOfLikes),
      mediaURL(other.mediaURL),
      videoLengthSeconds(other.videoLengthSeconds)
{
}
// Assignment op
Post& Post::operator=(const Post& other) {
    if (this != &other) {
        title = other.title;
        time_stamp = other.time_stamp;
        numberOfLikes = other.numberOfLikes;
        mediaURL = other.mediaURL;
        videoLengthSeconds = other.videoLengthSeconds;
    }
    return *this;
}
// Getters / setters
std::string Post::getTitle() const {
	return title;
}

void Post::setTitle(const std::string& newTitle) {
	title = newTitle;
}

std::string Post::getMediaURL() const {
	return mediaURL;
}

int Post::getVideoLengthSeconds() const {
	return videoLengthSeconds;
}

int Post::getNumberOfLikes() const {
	return numberOfLikes;
}
int Post::getPostID() const {
    return postID;
}

// Polymorphism / display and edit (base behavior)
void Post::displayPost() const {
    std::cout << "Post ID: " << postID << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Likes: " << likes << "\n";
    std::cout << "Media URL: " << mediaURL << "\n";
    std::cout << "Video length: " << videoLengthSeconds << " seconds\n";
    std::cout << "--------------------------\n";
}

void Post::edit() {
	std::cout << "Editing post..." << std::endl;
}

// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}

/*
 // When displaying a story, use this to compute expected expiration time: timeToExpiration
 // Define this as a private function

 IMPORTANT: This logic is moved to Story (the right class), because not all posts expire.
 Keep the provided code idea, but implement it in Story::computeTimeToExpiration().
*/