//
// Created by Chase McGough on 11/30/17.
//

#ifndef INC_220PROJECT_BOOKTESTS_H

#include "Book.h"
#include "BookStore.h"
#include "LinkedQueue.h"
#include "ArrayInventory.h"
#include "Run.h"
#include <iostream>
#include <fstream>
#include <sstream>

void bookHaveWant(Book& book1);

void bookWaitList(Book& book1, Person& person1, Person& person2);

void personSetGet(Person& person1);

void bookstoreAddSell(BookStore& bookstore);

void bookstoreWantHave(BookStore& bookstore);

void bookstoreFind(BookStore& bookstore);

void bookstoreWaitlist(BookStore& bookstore);

void isAlphaGreaterThanTest(ArrayInventory& inventory);

void linkQueueAssignOp();

void arrayInventoryAddItem();

void fileIOTests(BookStore& bookstore);

void fileWriteTest();

#define INC_220PROJECT_BOOKTESTS_H

#endif //INC_220PROJECT_BOOKTESTS_H
