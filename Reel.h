#ifndef REEL_H
#define REEL_H

#include "Post.h"

class Reel : public Post {
public:
    Reel(const std::string& title,
         const std::string& mediaURL,
         int videoLengthSeconds);

    Reel(const Reel& other);
    Reel& operator=(const Reel& other);
    ~Reel() = default;

    void edit() override;
};

#endif // REEL_H