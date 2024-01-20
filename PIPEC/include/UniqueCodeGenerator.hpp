#pragma once 

#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <unordered_set>
#include "DatabaseManager.hpp"
#include <random>
#include <algorithm>


class UniqueCodeGenerator{

public:
  //Constructeur et Destructeur
  UniqueCodeGenerator();
  ~UniqueCodeGenerator();

  //méthode pour la classe 
  std::string generateUniqueCode(std::string& firstname, std::string& lastname);
  bool isUniqueCode(const std::string& code);
  std::string fetchIdFromDatabase(std::string code);
  //std::unordered_set<std::string> fetchIdFromDatabase();
  void storeCode(const std::string& code);

private:

DatabaseManager db;
std::string generateCode(std::string& firstname, std::string& lastname);

};
