#include "JobOffer.hpp"
#include "Employer.hpp"
#include "Candidate.hpp"
#include <iostream>

JobOffer::JobOffer(int id, const std::string& offerName, const std::string& description, const std::list<std::string>& prerequisites, const std::string& contractType, Employer* employer)
    : id(id), offerName(offerName), description(description), prerequisites(prerequisites), contractType(contractType), employer(employer) {}

JobOffer::~JobOffer() {}

void JobOffer::updateJobOffer(JobOffer* jobOffer) {
   
}

void JobOffer::receiveApplication() {
  
}
