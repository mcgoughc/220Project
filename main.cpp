#include <iostream>
#include "Tests.h"
#include "Run.h"

void runTests(){
    Book book1 = Book("Autumn", 0, 0);
    Book book2 = Book("Pachinko", 0, 0);
    Person person1 = Person("First","Last", "Phone Num", "Email", Person::SEND_TEXT);
    Person person2 = Person("First","Last", "Phone Num", "Email", Person::SEND_TEXT);
    ArrayInventory bs = ArrayInventory();
    BookStore b1 = BookStore();

    bookHaveWant(book1);
    std::cout << std::endl;
    bookWaitList(book1, person1, person2);
    std::cout << std::endl;
    personSetGet(person1);
    std::cout << std::endl;
    bookstoreAddSell(b1);
    std::cout << std::endl;
    bookstoreWantHave(b1);
    std::cout << std::endl;
    bookstoreFind(b1);
    std::cout << std::endl;
    bookstoreWaitlist(b1);
    std::cout << std::endl;
    linkQueueAssignOp();
    bookstoreFind(b1);
    arrayInventoryAddItem();

    BookStore b2 = BookStore();
    fileIOTests(b2);

}

void runProgram(){
    BookStore bkStore;
    load(bkStore);
    bool run = true;

    while(run){
        std::cout << "\nEnter function letter key or 'h' for help: ";
        std::string input = getLineIn();
        std::cout << std::endl;
        if(input.length() > 1){
            std::cout << "Invalid input" << std::endl;
        }else if(input == "h"){
            help();

        }else if(input == "i"){
            inquire(bkStore);
        }else if(input == "l"){
            list(bkStore);
        }else if(input == "a"){
            add(bkStore);
        }else if(input == "m"){
            modify(bkStore);
        }else if(input == "s"){
            sell(bkStore);
        }else if(input == "o"){
            order(bkStore);
        }else if(input == "d"){
            delivery(bkStore);
        }else if(input == "r"){
            returnBooks(bkStore);
        }else if(input == "q"){
            quit(bkStore);
            run = false;
        }else{
            std::cout << "Invalid input" << std::endl;
        }
    }
}

int main() {
    //runTests();
    runProgram();
    return 0;
}
