//
// Created by Chase McGough on 11/30/17.
//

#include "Tests.h"


void bookHaveWant(Book* book1){
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
}

void bookWaitList(Book* book1, Person& person1, Person& person2){
    book1->addToWaitList(person1);
    book1->addToWaitList(person2);
    std::cout << "Wait list: " << book1->getWaitList() << std::endl;

    book1->removeFromWaitList();
    std::cout << "Wait list: " << book1->getWaitList() << std::endl;
    book1->removeFromWaitList();
    std::cout << "Wait list: " << book1->getWaitList() << std::endl;
    book1->removeFromWaitList();
    std::cout << "Wait list: " << book1->getWaitList() << std::endl;

}

void bookAssignOpCopyConst(Book *book1) {

}
