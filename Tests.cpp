//
// Created by Chase McGough on 11/30/17.
//

#include "Tests.h"


void bookHaveWant(Book& book1){
    std::cout << "bookHaveWant" << std::endl;
    bool errors;

    book1->setHaveValue(100);
    book1->setWantValue(100);

    std::cout << "Have value: " << book1->getHaveValue() << std::endl;
    std::cout << "Want value: " << book1->getWantValue() << std::endl;

    try {
        book1->setHaveValue(-100);
        printf("Allowed negative have");
        errors = true;
    }catch(std::out_of_range e){}

    try {
        book1->setWantValue(-100);
        printf("Allowed negative want");
        errors = true;
    }catch(std::out_of_range e){}

    if(!errors){
        printf("PASS");
    }else{
        printf("FAIL");
    }
}

void bookWaitList(Book& book1, Person& person1, Person& person2){
    std::cout << "bookWaitList" << std::endl;

    bool errors = false;

    book1->addToWaitList(person1);
    book1->addToWaitList(person2);
    std::cout << "Wait list: " << book1->getWaitList() << std::endl;

    book1->removeFromWaitList();
    std::cout << "Wait list: " << book1->getWaitList() << std::endl;
    book1->removeFromWaitList();
    std::cout << "Wait list: " << book1->getWaitList() << std::endl;

    try{
        book1->removeFromWaitList();
        printf("Removed from empty wait list");
        errors = true;
    }catch(std::out_of_range e){}

    if(!errors){
        printf("PASS");
    }else{
        printf("FAIL");
    }


}

void bookAssignOpCopyConst(Book& book1) {

}

void personSetGet(Person& person1) {
    bool errors = false;

    person1->setPhoneNumber("7864249000");
    person1->setEmail("joeshmoe@aol.com");

    try{
        person1->setCommMethod(6);
        printf("Does not throw error for out of range option");
        errors = true;
    }catch(std::out_of_range e){}

    person1->setCommMethod(1);

    std::string expectOut =
            "Name: " + person1->getName() +
            "\nPhone Number: " + person1->getPhoneNumber() +
            "\nEmail: " + person1->getEmail() +
            "\nCommunication Method: " + person1->getCommMethod();

    std::string actualOut = person1->toString();

    std::cout << "Expected output\n" << expectOut << std::endl;
    std::cout << "Actual output\n" << actualOut << std::endl;

    if(expectOut != actualOut){
        printf("Getters do not return same as to_string");
        errors = true;
    }

    if(!errors){
        printf("PASS");
    }else{
        printf("FAIL");
    }


}

void personAssignOpCopyConst(Person& person1) {

}
