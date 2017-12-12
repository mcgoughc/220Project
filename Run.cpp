//
// Created by Chase McGough on 12/9/17.
//

#include "Run.h"

void help(){
    //TODO
}

void inquire(BookStore& bk1){
    //TODO
}

void list(BookStore& bk1){
    //TODO
}

void add(BookStore& bk1){
    //TODO
}

void modify(BookStore& bk1){
    //TODO
}

void sell(BookStore& bk1){
    //TODO
}

void order(BookStore& bk1){
    //TODO
}

void delivery(BookStore& bk1){
    //TODO
}

void returnBooks(BookStore& bk1){
    //TODO
}

void quit(BookStore& bk1){

}

std::string getLineFromTerminal(){
    std::string line;
    getline(std::cin, line);
    return line;
}

void printToFile(std::string line, char delimiter){
    std::ofstream fout ("bookstore.txt");
    if (fout) {
        std::stringstream parts (line);
        while(parts){
            std::string part;
            getline(parts, part, delimiter);
            fout << part << std::endl;
        }
        fout.close();
    }
    else {
        std::cout << "Error in opening bookstore.txt";
    }
}
