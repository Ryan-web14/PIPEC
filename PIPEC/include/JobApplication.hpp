#pragma once

#include "Candidate.hpp"
#include "JobOffer.hpp"

enum Status { inWaiting, accepted, denied };

class JobApplication {
public:
    Application(int id, Candidate* candidate, JobOffer* jobOffer, Status status);
    ~Application();

    void submit();
    void withdraw();
    void updateStatus(Status status);

private:
    int id;
    Candidate* candidate;
    JobOffer* jobOffer;
    Status status;
    // date of application can be added if needed
};