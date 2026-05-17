#include "Reel.h"
#include <iostream>

Reel::Reel(const std::string& title,
           const std::string& mediaURL,
           int videoLengthSeconds)
    : Post(title, mediaURL, videoLengthSeconds)
{
}
// Copy const
Reel::Reel(const Reel& other)
    : Post(other)
{
}

// Assignment op
Reel& Reel::operator=(const Reel& other) {
    if (this != &other) {
        Post::operator=(other);
    }
    return *this;
}

void Reel::edit() {
    std::cout << "You have added a filter, AR effects, and music." << std::endl;
}