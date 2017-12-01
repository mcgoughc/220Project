//
// Created by Chase McGough on 11/28/17.
//

#ifndef INC_220PROJECT_PERSON_H
#define INC_220PROJECT_PERSON_H

#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string phoneNumber;
    std::string contactPreference;
public:
    Person(std::string firstName,
           std::string lastName,
           std::string email,
           std::string phoneNumber,
           std::string contactPreference);

    std::string toString();
};


#endif //INC_220PROJECT_PERSON_H
