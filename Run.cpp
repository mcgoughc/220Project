//
// Created by Chase McGough on 12/9/17.
//

#include "Run.h"
#include "ArrayInventory.h"

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
    std::cout << "Enter name of book to modify: ";
    std::string bookTitle = getLineFromTerminal();
    try{
        bk1.findBook(bookTitle);
    }catch(MissingBook &e){
        std::cout << "No book exists with that title" << std::endl;
        return;
    }
    std::string wantHave = bookTitle + "\nWant: " + std::to_string(bk1.getWant(bookTitle)) + "\nHave: " + std::to_string(bk1.getHave(bookTitle));
    std::cout << "Enter new want: ";
    int newWant = stoi(getLineFromTerminal());
    bk1.setWant(bookTitle, newWant);
}

void sell(BookStore& bk1){
    std::cout << "Enter name of book to order: ";
    std::string bookTitle = getLineFromTerminal();
    try {
        bk1.sell(bookTitle);
    }catch(MissingBook &e){
        std::cout << "No book exists with that title" << std::endl;
        return;
    }catch(BookHaveEmpty &e){
        std::cout << "No more copies of " << bookTitle << std::endl;
        std::cout << "Would you like to join the waitlist? (y/n): ";
        if(getLineFromTerminal() == "y"){
            std::cout << "Enter first name: ";
            std::string fName = getLineFromTerminal();
            std::cout << "Enter last name: ";
            std::string lName = getLineFromTerminal();
            std::cout << "Enter phone number: ";
            std::string phNum = getLineFromTerminal();
            std::cout << "Enter email: ";
            std::string email = getLineFromTerminal();
            std::cout << "Enter preferred communication: ";
            std::string pref = getLineFromTerminal();

            Person newP = Person(fName, lName, phNum, email, pref);
            bk1.findBook(bookTitle).addToWaitList(newP);

            std::cout << "Added to the waitlist" << std::endl;
        }else if(getLineFromTerminal() == "n"){
            std::cout << std::endl;
        }else{
            std::cout << "Invalid input." << std::endl;
        }
    }
}

void order(BookStore& bk1){
    bk1.order("order.txt");
    std::cout << "Book order file written to 'order.txt'." << std::endl;
}

void delivery(BookStore& bk1){
    std::cout << "Enter title of delivery file: ";
    std::string fileName = getLineFromTerminal();
    bk1.deliver(fileName);
    std::cout << "Delivery added to Bookstore." << std::endl;
}

void returnBooks(BookStore& bk1){
    bk1.returnBooks("returns.txt");
    std::cout << "Book return file written to 'returns.txt'." << std::endl;
}

void quit(BookStore& bk1){
    for (int i = 0; i < bk1.bookCount(); ++i) {
        Book& temp = bk1.findBookByIndex(i);
        std::string output = temp.getTitle() + "," +
                             temp.getAuthor() + "," +
                             std::to_string(temp.getWantValue()) + "," +
                             std::to_string(temp.getHaveValue()) + "," +
                             temp.getWaitList();

        printToFile(output, ',', "bookstore.txt");
    }
    std::cout << "Bookstore data saved to 'bookstore.txt'. Quitting Bookstore operation..." << std::endl;
    delete bk1;
}

std::string getLineFromTerminal(){
    std::string line;
    getline(std::cin, line);
    return line;
}

void printToFile(std::string line, char delimiter, std::string fileName){
    std::ofstream fout (fileName);
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
        std::cout << "Error in opening " << fileName << std::endl;
    }
}
