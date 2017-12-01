//
// Created by Chase McGough on 11/30/17.
//

#include "Tests.h"


void bookHaveWant(Book* book1){
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
        std::cout << "PASS" << std::endl;
    }else{
        std::cout << "FAIL" << std::endl;
    }
}

void bookWaitList(Book* book1, Person& person1, Person& person2){
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
        std::cout << "PASS" << std::endl;
    }else{
        std::cout << "FAIL" << std::endl;
    }


}

void bookAssignOpCopyConst(Book *book1) {

}
