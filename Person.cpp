//
// Created by Chase McGough on 11/28/17.
//

#include "Person.h"


Person::Person(std::string first, std::string last, std::string phoneNumberIn, std::string emailIn, int commMethodIN) {
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
    }
}

std::string Person::toString() {
    std::string result = "Name: " + name +
    "\nPhone Number: " + phoneNumber +
    "\nEmail: " + email +
    "\nCommunication Method: " + getCommMethod();
    return result;
}
