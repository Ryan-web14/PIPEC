set(SOURCE_FILES
main.cpp
Admin.cpp
Candidate.cpp
CompanyProfile.cpp
Employer.cpp
JobOffer.cpp
Notification.cpp
User.cpp
)


add_executable(main ${SOURCE_FILES})

target_include_directories(main PRIVATE ../include)

target_include_directories(main PRIVATE "C:/Users/user/OneDrive/JoJo_personal/OneDrive/Bureau/PIPEC/PIPEC/Connector C++ 8.0/include/jdbc/cppconn")

