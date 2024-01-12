#pragma once

#include <string>

class Preference {
public:
    Preference(const std::string& preferredLocation, const std::string& preferredContractType, const std::string& preferredSector);
    ~Preference();

    void updatePreference(Preference* preference);

private:
    std::string preferredLocation;
    std::string preferredContractType;
    std::string preferredSector;
};