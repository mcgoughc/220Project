#include <iostream>

#include "BookStore.h"
#include "Tests.h"

void runTests(){
    Book book1 = Book("Autumn", "Ali Smith", 0, 0);
    Book book2 = Book("Pachinko","Min Jin Lee", 0, 0);
    Person person1 = Person("First","Last", "Phone Num", "Email", "Text");
    Person person2 = Person("First","Last", "Phone Num", "Email", "Text");
    BookStore bs = BookStore();

    bookHaveWant(book1);
    std::cout << std::endl;
    bookWaitList(book1, person1, person2);
    std::cout << std::endl;
    personSetGet(person1);
    std::cout << std::endl;
    isAlphaGreaterThanTest(bs);
    std::cout << std::endl;
    bookstoreAddSell(bs);
    std::cout << std::endl;
    bookstoreWantHave(bs);
    std::cout << std::endl;
    bookstoreFind(bs);
    std::cout << std::endl;
    bookstoreWaitlist(bs);

}

void runProgram(){

}

int main() {
    runTests();
    //runProgram();
    return 0;
}