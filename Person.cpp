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

void Person::setName(std::string first, std::string last) {
    this->first = first;
    this->last = last;
}

void Person::setPhoneNumber(std::string number) {
    phoneNumber = number;
}

void Person::setEmail(std::string email) {
    this->email = email;
}

void Person::setCommMethod(int commMethod) {
    if (commMethod > 3 or commMethod < 1) {
        throw std::out_of_range("Invalid Value, please re-enter");
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
