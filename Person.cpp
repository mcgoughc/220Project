//
// Created by Chase McGough on 11/28/17.
//

#include "Person.h"


Person::Person(std::string first, std::string last, std::string phoneNumberIn, std::string emailIn, std::string commMethodIN) {
    this->first = first;
    this->last = last;
    phoneNumber = phoneNumberIn;
    email = emailIn;
    commMethod = commMethodIN;
    name = last + ", " + first;
}

void Person::setName(std::string first, std::string last) { //TODO Do we need this?
    this->first = first;
    this->last = last;
}

void Person::setPhoneNumber(std::string number) {
    phoneNumber = number;
}

void Person::setEmail(std::string email) {
    this->email = email;
}

void Person::setCommMethod(int commMethod) {//TODO Throw error if commMethod out of range. Do we want an int or take a string like the constructor?
    if (commMethod > 3 and commMethod < 1) {

    }
    if (commMethod == 1) {
        this->commMethod = "Phone call";
    }
    if (commMethod == 2) {
        this->commMethod = "Send Text";
    }
    if (commMethod == 3) {
        this->commMethod = "Send Email";
    }
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
    return this->commMethod;
}

std::string Person::toString() {
    std::string result = "Name: " + name +
    "\nPhone Number: " + phoneNumber +
    "\nEmail: " + email +
    "\nCommunication Method: " + commMethod;
    return result;
}
