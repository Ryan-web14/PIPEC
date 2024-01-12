#pragma once

#include <string>

enum class UserType { candidate, company, admin };

class User {
public:
    User(int id, const std::string& name, const std::string& email, const std::string& password, UserType userType);
    virtual ~User();

    void login(const std::string& email, const std::string& password);
    void logout();
    void signUp();

protected:
    int id;
    std::string name;
    std::string email;
    std::string password;
    UserType userType;
};