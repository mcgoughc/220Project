/*
 * Run.h
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is an interface for Run.cpp which contains run functions for user interaction with a bookstore.
*/

#ifndef INC_220PROJECT_RUN_H
#define INC_220PROJECT_RUN_H

#include "BookStore.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>



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

std::string getLineIn();

void printToFile(std::string line, char delimiter, std::string fileName);

#endif //INC_220PROJECT_RUN_H
