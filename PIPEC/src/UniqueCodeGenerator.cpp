#include "UniqueCodeGenerator.hpp"



//Constructeur et destructeur 
UniqueCodeGenerator::UniqueCodeGenerator(){};
UniqueCodeGenerator::~UniqueCodeGenerator(){};


//Méthode

std::string UniqueCodeGenerator::generateCode(std::string& firstname, std::string& lastname){
    std::string subFirst = firstname.substr(0,3);
    std::string subLast = lastname.substr(0,4);
    
    std::transform(std::begin(subFirst),std::end(subFirst),std::begin(subFirst),[](unsigned char c){return std::toupper(c);});
    std::transform(std::begin(subLast),std::end(subLast),std::begin(subLast),[](unsigned char c){return std::toupper(c);});

    auto now = std::chrono::system_clock::now();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution distrib(1999,5999);
    int randomNum = distrib(gen);

    std::ostringstream os;

    os <<subFirst <<"-"<<subLast<<"-"<<randomNum<<"-"<<milliseconds;

    std::string code = os.str();
    storeCode(code);

    if(!isUniqueCode(code))
    {
        generateCode(firstname,lastname);
    }
    return code;
}




void UniqueCodeGenerator::storeCode(const std::string& code){

    try
    {
      auto pstmt = db.preparedStatement("INSERT INTO GeneratedCode(generatedID) values (?)");
      pstmt->setString(1, code);
      pstmt->executeUpdate();
        
    }
    catch(sql::SQLException& e)
    {
        std::cerr <<"Code d'erreur SQL " << e.getErrorCode();
        throw;
    }
    
}


std::unordered_set<std::string> UniqueCodeGenerator::fetchIdFromDatabase() {

    std::unordered_set<std::string> idSet;

    try
    {
        auto stmt = db.statement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM GeneratedCode");
        
        while(res->next())
        {
            std::string fetchId = res->getString("generatedId");
            
            idSet.insert(fetchId);
        }
        delete res;
    }
    catch(sql::SQLException& e)
    {
        std::cerr<<"SQL Code error " << e.getErrorCode(); 
        std::cerr<<e.what();
        throw;
    }

    return idSet;

}

bool UniqueCodeGenerator::isUniqueCode(const std::string& code) {
    std::unordered_set<std::string> usedId = fetchIdFromDatabase();

    return usedId.find(code) == usedId.end();
}