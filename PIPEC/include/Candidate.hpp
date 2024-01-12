#pragma once

#include "User.hpp"
#include "JobOffer.hpp"
#include "JobApplication.hpp"
#include "Preference.hpp"

#include <string>
#include <list>

class Candidate : public User {
public:
    Candidate(int id, const std::string& name, const std::string& email, const std::string& password);
    ~Candidate();

    void apply();
    void updateProfile(Candidate* candidate);
    void cancelApplication(int jobOfferID);
    void displayApplications();

private:
    std::string CV;
    std::string candidateDescription;
    std::list<Application> applicationHistory;
    Preference* searchPreference;
    UserType userType{UserType::candidate};
};
