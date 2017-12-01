//
// Created by Chase McGough on 11/30/17.
//

#ifndef INC_220PROJECT_BOOKTESTS_H

#include "Book.h"
#include <iostream>

void bookGetSet(Book* book1){
    std::cout << "Have value: " << book1->getHaveValue << std::endl;
    std::cout << "Want value: " << book1->getWantValue() << std::endl;

    book1->setHaveValue(100);
    book1->setHaveValue(-100);

    book1->setWantValue(100);
    book1->setWantValue(-100);
}

void bookWaitList(Book* book1, Person* person1, Person* person2){
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

void bookAssignOp(Book* book1){

}

#define INC_220PROJECT_BOOKTESTS_H

#endif //INC_220PROJECT_BOOKTESTS_H
