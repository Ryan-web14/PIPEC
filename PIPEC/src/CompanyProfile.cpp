#include "CompanyProfil.hpp"
#include <iostream>

CompanyProfil::CompanyProfil(int id, const std::string& name, const std::string& description, const std::string& location, const std::string& activitySector, const std::string& companySize)
    : id(id), name(name), description(description), location(location), activitySector(activitySector), companySize(companySize) {}

CompanyProfil::~CompanyProfil() {}

void CompanyProfil::updateCompanyProfil() {
   
}

void CompanyProfil::displayCompanyProfil() {
   
}
