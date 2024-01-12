#pragma once

#include "User.hpp"

enum AccessLevel { basic, sudo };

class Admin : public User {
public:
    Admin(int id, const std::string& name, const std::string& email, const std::string& password);
    ~Admin();

    void manageJobApplication(JobApplication* jobApplication);
    void manageCandidate(Candidate* candidate);
    void manageEmployer(Employer* employer);
    void showStatistics();

private:
    AccessLevel accessLevel;
};
