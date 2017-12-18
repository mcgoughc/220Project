/*
 * Person.h
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the class definition of Person
*/

#ifndef INC_220PROJECT_PERSON_H
#define INC_220PROJECT_PERSON_H


#include <string>

class Person {
    private:
        std::string name;
        std::string phoneNumber;
        std::string email;
        int commMethod;

    public:

    static const int PHONE_CALL = 0;
    static const int SEND_TEXT = 1;
    static const int SEND_EMAIL = 2;

    /**
     * Construtor
     * Makes a new Person object
     * @param first First Name
     * @param last Last Name
     * @param phoneNumberIn Phone Number
     * @param emailIn Email address
     * @param commMethodIN Contact method. 0 = Phone call, 1 = Text, 2 = Email.
     */
    Person(std::string first, std::string last, std::string phoneNumberIn, std::string emailIn, int commMethodIN);

    /** Sets the name of the person
     * @param first
     * @param last
     */
    void setName(std::string first, std::string last);

    /**
     * Sets the phone number of the person
     * @param number
     */
    void setPhoneNumber(std::string number);

    /**
     * Sets the email address of the person
     * @param email
     */
    void setEmail(std::string email);

    /**
     * Sets the communication method of choice for the person
     * 1: Phone call
     * 2: Text
     * 3: Email
     * @param commMethod
     */
    void setCommMethod(int commMethod);

    /**
     * @return name of the person
     */
    std::string getName();

    /**
     * @return a string containing the phone number of the person
     */
    std::string getPhoneNumber();

    /**
     * @return email of the person
     */
    std::string getEmail();

    /**
     * @return the string version of the method of communication
     */
    std::string getCommMethod();

    /**
     * @return A string representation of the person object
     */
    std::string toString();
};


#endif //INC_220PROJECT_PERSON_H
