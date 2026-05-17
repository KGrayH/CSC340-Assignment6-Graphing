#ifndef STORY_H
#define STORY_H

#include "Post.h"

class Story : public Post {
public:
    Story(const std::string& title,
          const std::string& mediaURL,
          int videoLengthSeconds);

              Story(const Story& other);
    Story& operator=(const Story& other);
   
    ~Story() = default;
    void display() const override;
    void edit() override;

private:
    int computeTimeToExpiration() const;  // moved to the right class (Story)
};

#endif // STORY_H