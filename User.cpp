// TO DO: #include needed standard libraries and your own libraries here
#include "User.h"
// TO DO: function implementations
User::User()
    : id(0), //graph id
      username(""),
      email(""),
      password(""),
      bio(""),
      profilePicture(""),
      posts()
{
}

User::User(const std::string& username,
           const std::string& email,
           const std::string& password,
           const std::string& bio,
           const std::string& profilePicture)
    : id(0), //graph id
      username(username),
      email(email),
      password(password),
      bio(bio),
      profilePicture(profilePicture),
      posts()
{
}

User::~User() {
    // Free dynamically allocated posts
    posts.clear(); // shared_ptr handles memory automatically
}

// ---------------- Basic access ----------------
std::string User::getUsername() const {
    return username;
}

int User::getPostCount() const {
    return posts.getCurrentSize();
}

int User::getId() const { //for returning int id for graph
    return id;
}

void User::setId(int newId) { //int id for graph
    id = newId;
}

// ---------------- User management ----------------
void User::displayProfile() const {
    std::cout << "Username: " << username << "\n"
              << "Email: " << email << "\n"
              << "Bio: " << bio << "\n"
              << "Profile picture: " << profilePicture << "\n";
    // DO NOT DISPLAY password
}

void User::modifyPassword(const std::string& newPassword) {
    password = newPassword;
    std::cout << "Password updated.\n";
}

// ---------------- Post management ----------------
void User::createPost() {
    int choice = 0;
    std::cout << "Choose post type:\n"
              << "1. Reel\n"
              << "2. Story\n"
              << "Choice: ";
    std::cin >> choice;

    std::cin.ignore(); // clear newline

    std::string title, url;
    int length = 0;

    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter media URL: ";
    std::getline(std::cin, url);

    std::cout << "Enter video length in seconds: ";
    std::cin >> length;

    if (choice == 1) {
        if (length > 90) {
            std::cout << "Error: Reel duration limit is 90 seconds.\n";
            return;
        }
        std::shared_ptr<Post> p = std::make_shared<Reel>(title, url, length);
        posts.append(p); // required usage
        std::cout << "Reel created.\n";
    }
    else if (choice == 2) {
        if (length > 60) {
            std::cout << "Error: Story duration limit is 60 seconds.\n";
            return;
        }
        std::shared_ptr<Post> p = std::make_shared<Story>(title, url, length);
        posts.append(p); // required usage
        std::cout << "Story created.\n";
    }
    else {
        std::cout << "Invalid post type.\n";
    }
}

void User::displayAllPosts() const {
    int size = posts.getCurrentSize();
    if (size == 0) {
        std::cout << "No posts to display.\n";
        return;
    }

    for (int i = 1; i <= size; i++) {
        Node<std::shared_ptr<Post>>* nodePtr = posts.findKthItem(i);
        if (nodePtr != nullptr) {
            std::cout << "\nPost #" << i << ":\n";
            nodePtr->getItem()->display();
        }
    }
}

void User::displayKthPost(int k) const {
    int size = posts.getCurrentSize();
    if (k < 1 || k > size) {
        std::cout << "Error: Invalid post index. Linked Bag size = " << size << "\n";
        return;
    }

    Node<std::shared_ptr<Post>>* nodePtr = posts.findKthItem(k);
    nodePtr->getItem()->display();
}

void User::modifyPostTitle(int index, const std::string& newTitle) {
    int size = posts.getCurrentSize();
    if (index < 1 || index > size) {
        std::cout << "Error: Invalid post index. Linked Bag size = " << size << "\n";
        return;
    }

    Node<std::shared_ptr<Post>>* nodePtr = posts.findKthItem(index);
    nodePtr->getItem()->setTitle(newTitle);
    std::cout << "Post title updated.\n";
}

void User::editPost(int index) {
    int size = posts.getCurrentSize();
    if (index < 1 || index > size) {
        std::cout << "Error: Invalid post index. Linked Bag size = " << size << "\n";
        return;
    }

    Node<std::shared_ptr<Post>>* nodePtr = posts.findKthItem(index);
    std::shared_ptr<Post> postPtr = nodePtr->getItem();

    // Polymorphism: calls Reel::edit or Story::edit
    postPtr->edit();
}

void User::deletePost(int index) {
    int size = posts.getCurrentSize();
    if (index < 1 || index > size) {
        std::cout << "Error: Invalid post index. Linked Bag size = " << size << "\n";
        return;
    }

    Node<std::shared_ptr<Post>>* nodePtr = posts.findKthItem(index);
    std::shared_ptr<Post> postPtr = nodePtr->getItem();

    bool removed = posts.remove(postPtr);
    if (removed) {
        std::cout << "Post deleted.\n";
}   else {
        std::cout << "Error: Could not delete post.\n";
}
}
// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}
