//
// Created by Chase McGough on 11/28/17.
//

#include "Person.h"

Person::Person(std::string firstName, std::string lastName, std::string email, std::string phoneNumber, std::string contactPreference){
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->phoneNumber = phoneNumber;
    this->contactPreference = contactPreference;
}

std::string Person::toString(){
    return firstName + lastName;
}