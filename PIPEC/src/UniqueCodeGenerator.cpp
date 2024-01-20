#include "UniqueCodeGenerator.hpp"



//Constructeur et destructeur 
UniqueCodeGenerator::UniqueCodeGenerator(){};
UniqueCodeGenerator::~UniqueCodeGenerator(){};


//Méthode


std::string UniqueCodeGenerator::generateUniqueCode(std::string& firstname, std::string& lastname){
    std::string code;
    int retries = 0;
    int MAX_RETRIES = 3;

    do
    {
        
        code = generateCode(firstname, lastname);
        retries++;
    } while (!isUniqueCode(code) && retries < MAX_RETRIES);
     
    if(retries == MAX_RETRIES)
    {
        throw std::runtime_error("the max retries for the creation of the code has been reached. ");
    }
}

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

//version modifiée de la méthode fetchIdFromDatabase qui ici utilise directement une requête préparée SQL
//pour trouver uniquement l'id concerné et non tous les id de la table GeneratedCode

std::string UniqueCodeGenerator::fetchIdFromDatabase(std::string code){
    auto pstmt = db.preparedStatement("SELECT * FROM GeneratedCode where generatedID = ?");
    pstmt->setString(1,code);
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    std::string retrivedCode;
    while (res->next())
    {
      retrivedCode = res->getString("generatedCode");
    }

    return retrivedCode;
}

// std::unordered_set<std::string> UniqueCodeGenerator::fetchIdFromDatabase() {

//     std::unordered_set<std::string> idSet;

//     try
//     {
//         auto stmt = db.statement();
//         sql::ResultSet *res = stmt->executeQuery("SELECT * FROM GeneratedCode");
        
//         while(res->next())
//         {
//             std::string fetchId = res->getString("generatedId");
            
//             idSet.insert(fetchId);
//         }
//         delete res;
//     }
//     catch(sql::SQLException& e)
//     {
//         std::cerr<<"SQL Code error " << e.getErrorCode(); 
//         std::cerr<<e.what();
//         throw;
//     }

//     return idSet;

// }

bool UniqueCodeGenerator::isUniqueCode(const std::string& code) {
    std::string usedId = fetchIdFromDatabase(code);

    return code == usedId;
}