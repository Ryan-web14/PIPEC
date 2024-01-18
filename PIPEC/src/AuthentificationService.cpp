#include "AuthentificationService.hpp"
#include  <algorithm>
#include <sstream>


AuthentificationService::AuthentificationService(){};

bool AuthentificationService::verifyPassword( const std::string& password, const std::string& userPassword){
     return password == userPassword;
}


bool AuthentificationService::registerUSer(const std::string& firstname,const std::string& lastname,const std::string& email, const std::string& password, UserType type)
{
    

try{
    if(type == candidateType)
   auto pstmt = db.preparedStatement("INSERT INTO Candidate()");
}catch(sql::SQLException& e){
    
}
   
}
