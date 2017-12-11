//
// Created by Chase McGough on 12/9/17.
//

#ifndef INC_220PROJECT_RUN_H
#define INC_220PROJECT_RUN_H

#include "BookStore.h"
#include <iostream>

void help();

void inquire(BookStore& bk1);

void list(BookStore& bk1);

void add(BookStore& bk1);

void modify(BookStore& bk1);

void sell(BookStore& bk1);

void order(BookStore& bk1);

void delivery(BookStore& bk1);

void returnBooks(BookStore& bk1);

void quit(BookStore& bk1);

std::string getLineFromTerminal();

#endif //INC_220PROJECT_RUN_H
