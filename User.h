// TO DO: #include all the standard libraries and your own libraries here
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <memory>
using std::shared_ptr;
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"
#include "Reel.h"
#include "Story.h"
// To DO: define the class User with the necessary functions and data fields
class User {
private:
    int id;
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;

//a user's profile can only have one list containing all their posts
    LinkedBag<shared_ptr<Post>> posts;

public:
    User();
    User(const std::string& username,
         const std::string& email,
         const std::string& password,
         const std::string& bio,
         const std::string& profilePicture);

    ~User(); //smart ptr should handle memory management, but you can implement if needed

    //basic access needed by the menu
    std::string getUsername() const;
    int getId() const; //returns id, graph
    void setId(int newId); // sets id, graph

    //user management
    void displayProfile() const;           // do NOT display password
    void modifyPassword(const std::string& newPassword);

    //post management
    void createPost();                     // prompts for Reel/Story + details, then adds
    void displayAllPosts() const;
    void displayKthPost(int k) const;      // uses findKthItem
    void modifyPostTitle(int index, const std::string& newTitle);
    void editPost(int index);              // polymorphism: Post*->edit()
    void deletePost(int index);

    int getPostCount() const;
// This is a function that allows you to compare two users based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:
bool operator==(const User& otherUser) const; };
#endif // USER_H