#include "Story.h"
#include <iostream>
#include <chrono>

Story::Story(const std::string& title,
             const std::string& mediaURL,
             int videoLengthSeconds)
    : Post(title, mediaURL, videoLengthSeconds)
{
}
Story::Story(const Story& other)
    : Post(other)
{
}
Story& Story::operator=(const Story& other) {
    if (this != &other) {
        Post::operator=(other);
    }
    return *this;
}
// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function
int Story::computeTimeToExpiration() const {
    const int secondsInHour = 3600;
    // 24 hours in seconds
    const int expiresAfter = 24 * secondsInHour;

    // Get current time
    auto time_now = std::chrono::steady_clock::now();
    // Compute elapsed time since post creation
    std::chrono::duration<double> elapsed_seconds = time_now - time_stamp;
    // time to expiration in hours
    int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

    return timeToExpiration;
}

void Story::display() const {
    Post::display();

    int hoursLeft = computeTimeToExpiration();
    if (hoursLeft > 0) {
        std::cout << hoursLeft << " hours till expiration" << std::endl;
    } else {
        std::cout << "This story has expired." << std::endl;
    }
}

void Story::edit() {
    std::cout << "A filter, music, stickers and effects have been added to the post." << std::endl;
}