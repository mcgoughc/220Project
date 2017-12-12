//
// Created by Chase McGough on 12/9/17.
//

#include "Run.h"
#include "Book.h"

void help(){
    std::cout << "Help(H) - provides summary of all commands" << std::endl;
    std::cout << "Inquire(I) - display information about a book" << std::endl;
    std::cout << "List(L) - displays a list of our entire inventory of books in alphabetical order" << std::endl;
    std::cout << "Add(A) - adds a new book title to the inventory if it does not already exist" << std::endl;
    std::cout << "Modify(M) - modify the want value for a specific book title" << std::endl;
    std::cout << "Sell(S) - decreases the number of books we have of that title."
    "\nIf the title of the book does not exist it will be added to the inventory."
    "\nIf the title is sold out, we will ask for your buyer information and place you on that title's waitlist" << std::endl;
    std::cout << "Order(O) - creates a bulk purchase of additional books based on the have and want values." << std::endl;
}

void inquire(BookStore& bk1){
    std::cout << "Please enter a book title: " << std::endl;
    std::string titleToFind;
    std::cin >> titleToFind;
    bool haveBook;
    Book b1;
    try {
        b1 = bk1.findBook(titleToFind);
        std::cout << "We have the book" << std::endl;
        haveBook = true;
    }
    catch(std::out_of_range&e){
        std::cout << "We do not have that book" << std::endl;
        haveBook = false;
    }
    if (haveBook) {
        std::cout << "Book Title: " + b1.getTitle() << std::endl;
        std::cout << "Book Author: " + b1.getAuthor() << std::endl;
        std::cout << "Book Wait list: " + b1.getWaitList() << std::endl;
    }
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
