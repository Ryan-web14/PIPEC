/*
Les variable et différents mots seront écrits en anglais dans un soucis de sémantique beaucoup
 plus clair et général à comprendre. La langue a été choisi en prenant en considération les normes généralement appliqué dans un 
 projet informatique.

Par contre les commentaires pourront être en anglais comment en français 

*/


#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <string>
#include <memory>
#include <cstdlib>
#include <thread>
#include <chrono>

std::string username = std::getenv("DB_USERNAME") ? std::getenv("DB_USERNAME") : "";
std::string password = std::getenv("DB_PASSWORD") ? std::getenv("DB_PASSWORD") : "";


class DatabaseManager{
public:
//constructeur and destructor 
DatabaseManager();

//méthodes pour la classe DatabaseManager
std::unique_ptr<sql::PreparedStatement> preparedStatement(const std::string query);
void connectToDatabase();

private:
sql::Driver* driver;
std::unique_ptr<sql::Connection> co;
std::string server = "admin@pipec.cw5uco8nd5hh.us-east-1.rds.amazonaws.com:3306";
std::string database = "PIPEC";
static const int MAX_RECONNECT_ATTEMPTS = 3;
static const int MAX_wAITING_TIME = 5; // le temps est en seconde 

};