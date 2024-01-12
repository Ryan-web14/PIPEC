#include "User.hpp"
#include <iostream>

User::User(int id, const std::string& name, const std::string& email, const std::string& password, UserType userType)
    : id(id), name(name), email(email), password(password), userType(userType) {}

User::~User() {}

void User::login(const std::string& email, const std::string& password) {
    if (this->email == email && this->password == password) {
        std::cout << "Login successful." << std::endl;
    } else {
        std::cout << "Login failed. Incorrect email or password." << std::endl;
    }
}

void User::logout() {
    
}

void User::signUp() {
   
}
