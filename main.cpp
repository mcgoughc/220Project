#include <iostream>

#include "BookStore.h"
#include "Tests.h"

void runTests(){
    Book book1 = Book("Autumn", "Ali Smith", 0, 0);
    Book book2 = Book("Pachinko","Min Jin Lee", 0, 0);
    Person person1 = Person("First","Last", "Phone Num", "Email", "Text");
    Person person2 = Person("First","Last", "Phone Num", "Email", "Text");
    ArrayInventory bs = ArrayInventory();
    BookStore b1 = BookStore();

    bookHaveWant(book1);
    std::cout << std::endl;
    bookWaitList(book1, person1, person2);
    std::cout << std::endl;
    personSetGet(person1);
    std::cout << std::endl;
    isAlphaGreaterThanTest(bs);
    std::cout << std::endl;
    bookstoreAddSell(b1);
    std::cout << std::endl;
    //bookstoreWantHave(bs);
    std::cout << std::endl;
    bookstoreFind(b1);
    //std::cout << std::endl;
    //bookstoreWaitlist(bs);
    std::cout << std::endl;
    linkQueueAssignOp();
    bookstoreFind(b1);
    //arrayInventoryAddItem();

}

void runProgram(){

}

int main() {
    runTests();
    //runProgram();
    return 0;
}