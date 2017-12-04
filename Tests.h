//
// Created by Chase McGough on 11/30/17.
//

#ifndef INC_220PROJECT_BOOKTESTS_H

#include "Book.h"
#include "BookStore.h"
#include <iostream>

void bookHaveWant(Book& book1);

void bookWaitList(Book& book1, Person& person1, Person& person2);

void bookAssignOpCopyConst(Book& book1);

void personSetGet(Person& person1);

void personAssignOpCopyConst(Person& person1);

void bookstoreAddSell(BookStore& bookstore, Book& book1, Book& book2);

void bookstoreWantHave(BookStore& bookstore);

void bookstoreFind(BookStore& bookstore);

void bookstoreWaitlist(BookStore& bookstore);

void bookstoreAssignOpCopyConst(BookStore& bookstore);


//todo Bookstore tests

void isAlphaGreaterThanTest(BookStore& bookStore);

#define INC_220PROJECT_BOOKTESTS_H

#endif //INC_220PROJECT_BOOKTESTS_H
