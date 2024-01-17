#include "Employer.hpp"
#include <iostream>

Employer::Employer(int id, const std::string& name, const std::string& email, const std::string& password)
    : User(id, name, email, password, UserType::company), companyProfile(nullptr) {}

Employer::~Employer() {
    delete companyProfile;
}

void Employer::postJobOffer(JobOffer* jobOffer) {
    // Implementation for posting a job offer
    std::cout << "Posted a job offer." << std::endl;
}

void Employer::deleteJobOffer(int jobOfferID) {
    // Implementation for deleting a job offer
    std::cout << "Deleted a job offer." << std::endl;
}

void Employer::viewApplications(JobOffer* jobOffer) {
    // Implementation for viewing applications for a specific job offer
    std::cout << "Viewed job applications for a specific offer." << std::endl;
}

// void Employer::searchForCandidate(Preference* preference) {
   
// }
