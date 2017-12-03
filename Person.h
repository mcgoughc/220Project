//
// Created by Chase McGough on 11/28/17.
//

#ifndef INC_220PROJECT_PERSON_H
#define INC_220PROJECT_PERSON_H


#include <string>

class Person {
    private:
        std::string name;
        std::string phoneNumber;
        std::string email;
        std::string commMethod;

    public:

    //Constructor
    Person(std::string nameIn, std::string phoneNumberIn, std::string emailIn, std::string commMethodIN);

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
     * @param commMethod
     */
    void setCommMethod(int commMethod);

    /**
     * @return name of the person
     */
    std::string getName();

    /**
     *
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
     * @return A string representstion of the person object
     */
    std::string toString();
};


#endif //INC_220PROJECT_PERSON_H
