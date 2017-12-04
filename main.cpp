#include <iostream>

#include "BookStore.h"
#include "Tests.h"

void runTests(){
    Book book1 = Book("Autumn", "Ali Smith");
    Book book2 = Book("Pachinko","Min Jin Lee");
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
    bookstoreAddSell(bs, book1, book2);
    std::cout << std::endl;
    bookstoreWantHave(bs);

}

void runProgram(){

}

int main() {
    runTests();
    //runProgram();
    return 0;
}