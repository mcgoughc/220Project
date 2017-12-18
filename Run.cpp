/*
 * Run.cpp
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file contains run functions for user interaction with a bookstore.
*/

#include "Run.h"



void help(){
    std::cout << "To call any of these functions, please use the lower case key letter" << std::endl;
    std::cout << std::endl;
    std::cout << "Help (h) - provides summary of all commands" << std::endl;
    std::cout << "Inquire (i) - display information about a book" << std::endl;
    std::cout << "List (l) - displays a list of our entire inventory of books in alphabetical order" << std::endl;
    std::cout << "Add (a) - adds a new book title to the inventory if it does not already exist" << std::endl;
    std::cout << "Modify (m) - modify the want value for a specific book title" << std::endl;
    std::cout << "Sell (s) - decreases the number of books we have of that title."
    "\nIf the title of the book does not exist it will be added to the inventory."
    "\nIf the title is sold out, we will ask for your buyer information and place you on that title's waitlist" << std::endl;
    std::cout << "Order (o) - creates a bulk purchase of additional books based on the have and want values." << std::endl;
    std::cout << "Delivery (d) - reads in the delivery from the delivery.txt file." << std::endl;
    std::cout << "Return (r) - writes a return invoice to a text file specifying all books that should be returned" << std::endl;
    std::cout << "Quit (q) - saves the inventory and wait lists and then ends the program" << std::endl;
}

void inquire(BookStore& bk1){
    if(bk1.bookCount() <= 0){
        std::cout << "Bookstore is empty" << std::endl;
    }else {
        std::cout << "Please enter a book title: ";
        std::string bookTitle = getLineIn();

        if(bk1.bookCheck(bookTitle)){
            std::cout << "Title: " + bookTitle << std::endl;
            std::cout << "Have: " + std::to_string(bk1.getHave(bookTitle)) << std::endl;
            std::cout << "Want: " + std::to_string(bk1.getWant(bookTitle)) << std::endl;
            std::cout << "Waitlist: " + bk1.getWaitList(bookTitle) << std::endl;

        }else{
            std::cout << "Book does not exist" << std::endl;
        }
    }
}

void list(BookStore& bk1){
    if(bk1.bookCount() <= 0){
        std::cout << "Bookstore is empty" << std::endl;
    }else {
        for (int i = 0; i < bk1.bookCount(); ++i) {
            Book &temp = bk1.findBookByIndex(i);
            std::string output = temp.getTitle() +
                                 "\nWant: " + std::to_string(temp.getWantValue()) +
                                 "\nHave: " + std::to_string(temp.getHaveValue()) +
                                 "\nWaitlist: \n" + temp.getWaitList();

            std::cout << output << std::endl;
        }
    }
}

void add(BookStore& bk1){
    std::cout << "Enter title of book to add: ";
    std::string bookTitle = getLineIn();

    if (bk1.bookCheck(bookTitle)) {
        std::cout << "Book already exists" << std::endl;
        std::cout << bookTitle << "\nWant: " << std::to_string(bk1.getWant(bookTitle))
                  << "\nHave: " << std::to_string(bk1.getHave(bookTitle)) << std::endl;

    } else {
        std::cout << "Enter want value: ";
        int want = stoi(getLineIn());
        while(want < 0){
            std::cout << "Want value cannot be negative" << std::endl;
            std::cout << "Enter want value: ";
            want = stoi(getLineIn());
        }

        std::cout << "Enter have value: ";
        int have = stoi(getLineIn());
        while(have < 0){
            std::cout << "Have value cannot be negative" << std::endl;
            std::cout << "Enter have value: ";
            have = stoi(getLineIn());
        }

        bk1.add(bookTitle, want, have);
        std::cout << "Successfully added" << std::endl;
    }
}

void modify(BookStore& bk1){
    if(bk1.bookCount() <= 0) {
        std::cout << "Bookstore is empty" << std::endl;
    }else {
        std::cout << "Enter name of book to modify: ";
        std::string bookTitle = getLineIn();
        std::cout << bookTitle << std::endl;

        if (bk1.bookCheck(bookTitle)) {
            std::string wantHave = bookTitle + "\nWant: " + std::to_string(bk1.getWant(bookTitle)) +
                                   "\nHave: " + std::to_string(bk1.getHave(bookTitle));

            std::cout << "Enter new want: ";
            int newWant = stoi(getLineIn());
            while(newWant < 0){
                std::cout << "Want value cannot be negative" << std::endl;
                std::cout << "Enter new want: ";
                newWant = stoi(getLineIn());
            }
            bk1.setWant(bookTitle, newWant);

        } else {
            std::cout << "No book exists with that title" << std::endl;
        }
    }
}

void sell(BookStore& bk1){
    if(bk1.bookCount() <= 0) {
        std::cout << "Bookstore is empty" << std::endl;
    }else {
        std::cout << "Enter name of book to order: ";
        std::string bookTitle = getLineIn();

        if (bk1.bookCheck(bookTitle)) {
            if (bk1.getHave(bookTitle) <= 0) {

                std::cout << "No more copies of " << bookTitle << std::endl;
                std::cout << "Would you like to join the waitlist? (y/n): ";
                std::string yesNo = getLineIn();

                if (yesNo == "y") {
                    std::cout << "Enter first name: ";
                    std::string fName = getLineIn();
                    std::cout << "Enter last name: ";
                    std::string lName = getLineIn();
                    std::cout << "Enter phone number: ";
                    std::string phNum = getLineIn();
                    std::cout << "Enter email: ";
                    std::string email = getLineIn();
                    std::cout << "Enter number for preferred communication (0 = Phone call, 1 = Text, 2 = Email): ";
                    int pref = stoi(getLineIn());
                    while(pref < 0 || pref > 2){
                        std::cout << "Communication must be 0, 1, or 2" << std::endl;
                        std::cout << "Enter number for preferred communication (0 = Phone call, 1 = Text, 2 = Email): ";
                        pref = stoi(getLineIn());
                    }

                    Person newP = Person(fName, lName, phNum, email, pref);
                    bk1.findBook(bookTitle).addToWaitList(newP);

                    std::cout << "Added to the waitlist" << std::endl;

                } else if (yesNo == "n") {
                    std::cout << std::endl;

                } else {
                    std::cout << "Invalid input." << std::endl;
                }

            } else {
                bk1.sell(bookTitle);
                std::cout << "1 copy sold" << std::endl;
            }

        } else {
            std::cout << "No book exists with that title" << std::endl;
        }
    }
}

void order(BookStore& bk1){
        bk1.order("order.txt");
        std::cout << "Book order file written to 'order.txt'." << std::endl;
}

void delivery(BookStore& bk1){
    std::cout << "Enter title of delivery file: ";
    std::string fileName = getLineIn();

    bk1.deliver(fileName);
    std::cout << "Delivery added to Bookstore." << std::endl;

}

void returnBooks(BookStore& bk1){
    if(bk1.bookCount() <= 0) {
        std::cout << "Bookstore is empty" << std::endl;
    }else {
        bk1.returnBooks("returns.txt");
        std::cout << "Book return file written to 'returns.txt'." << std::endl;
    }
}

void quit(BookStore& bk1){
    if(bk1.bookCount() <= 0) {
        std::cout << "Bookstore is empty" << std::endl;
    }else {
        std::ofstream fout ("bookstore.txt");
        std::stringstream waitStream;

        for (int i = 0; i < bk1.bookCount(); ++i) {
            Book& temp = bk1.findBookByIndex(i);
            std::string title = temp.getTitle();
            std::string wantValue = std::to_string(temp.getWantValue());
            std::string haveValue = std::to_string(temp.getHaveValue());
            waitStream = std::stringstream(temp.getWaitList());
            fout << "<b>\n";
            fout << wantValue + " ";
            fout << haveValue + " ";
            fout << title + "\n";
            fout << "</b>\n";
            std::string dataPiece;
            while(std::getline(waitStream, dataPiece)){ ;
                dataPiece += "\n";
                fout << dataPiece;
            }
        }
        fout.close();
        std::cout << "Bookstore data saved to 'bookstore.txt'. Quitting Bookstore operation..." << std::endl;
    }
}

void load(BookStore& bk1){
    std::ofstream fout ("bookstore.txt");
    if(fout){
        bk1.load("bookstore.txt");
    }
}

std::string getLineIn(){
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
