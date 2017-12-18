/*
 * Person.cpp
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the method definitions of the Person class
*/

#include "Person.h"


Person::Person(std::string first, std::string last, std::string phoneNumberIn, std::string emailIn, int commMethodIN) {
    name = first + " " + last;
    phoneNumber = phoneNumberIn;
    email = emailIn;
    commMethod = commMethodIN;
}

void Person::setName(std::string first, std::string last) {
    name = first + " " + last;
}

void Person::setPhoneNumber(std::string number) {
    phoneNumber = number;
}

void Person::setEmail(std::string email) {
    this->email = email;
}

void Person::setCommMethod(int commMethod) {
    if (commMethod > 3 or commMethod < 1) {
        throw std::out_of_range("Invalid Value for person's comm method");
    }
    this->commMethod = commMethod;
}

std::string Person::getName() {
    return this->name;
}

std::string Person::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Person::getEmail() {
    return this->email;
}

std::string Person::getCommMethod() {
    switch(commMethod){
        case PHONE_CALL:
            return "Phone Call";
        case SEND_TEXT:
            return "Send Text";
        case SEND_EMAIL:
            return "Send Email";
        default:
            return "None";
    }
}

std::string Person::toString() {
    std::string result = name +
    "\n" + phoneNumber +
    "\n" + email +
    "\n" + getCommMethod();
    return result;
}
