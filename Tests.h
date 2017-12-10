//
// Created by Chase McGough on 11/30/17.
//

#ifndef INC_220PROJECT_BOOKTESTS_H

#include "Book.h"
#include "BookStore.h"
#include "LinkedQueue.h"
#include "ArrayInventory.h"
#include <iostream>

void bookHaveWant(Book& book1);

void bookWaitList(Book& book1, Person& person1, Person& person2);

void bookAssignOpCopyConst(Book& book1);

void personSetGet(Person& person1);

void personAssignOpCopyConst(Person& person1);

void bookstoreAddSell(BookStore& bookstore);

void bookstoreWantHave(BookStore& bookstore);

void bookstoreFind(BookStore& bookstore);

void bookstoreWaitlist(BookStore& bookstore);

void bookstoreAssignOpCopyConst(BookStore& bookstore);

void isAlphaGreaterThanTest(ArrayInventory& inventory);

void linkQueueAssignOp();

//void arrayInventoryAddItem();

#define INC_220PROJECT_BOOKTESTS_H

#endif //INC_220PROJECT_BOOKTESTS_H
