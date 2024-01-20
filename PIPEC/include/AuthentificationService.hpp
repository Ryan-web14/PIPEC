#pragma once

#include "DatabaseManager.hpp"
#include <iostream>

enum class UserType { candidate, company};

UserType candidateType = UserType::candidate;
UserType employerType = UserType::company;


class AuthentificationService{

public:
    //Constructeur
    AuthentificationService();

    //méthodes
    bool registerUSer(const std::string& firstname,const std::string& lastname,const std::string& email, const std::string& password, UserType type);
    bool loginUser(const std::string& email, const std::string& password);



private: 

DatabaseManager db;
bool verifyPassword(const std::string& password, const std::string& userPassword);

};