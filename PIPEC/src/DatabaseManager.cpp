#include "DatabaseManager.hpp"

DatabaseManager::DatabaseManager(){
   connectToDatabase();
}


void DatabaseManager::connectToDatabase(){
    for(int attempt = 0; attempt <= MAX_RECONNECT_ATTEMPTS; attempt++)
    {
        try
        {
            driver = get_driver_instance();
            co = std::unique_ptr<sql::Connection>(driver->connect(server, username, password));
            co->setSchema(database);
            break;
        }
        catch(const sql::SQLException& e)
        {
            std::cerr<< "Tentative de connexion: " << (attempt + 1);
            std::cerr << "Erreur: exception SQL in " << __FILE__ << "\n";
            std::cerr << "Code d'erreur: " << e.getErrorCode();
            std::cout << "Etat de SQL: " << e.getSQLState();
            
            if(attempt == MAX_RECONNECT_ATTEMPTS){
                throw;
            }
            std::this_thread::sleep_for(std::chrono::seconds(MAX_wAITING_TIME));
        }
    }
}
