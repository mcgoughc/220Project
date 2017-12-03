#include <iostream>

#include "BookStore.h"
#include "Tests.h"

void runTests(){
    Book book1 = Book("Autumn", "Ali Smith");
    Book book2 = Book("Pachinko","Min Jin Lee");
    Person person1 = Person("Name", "Phone Num", "Email", "Text");
    Person person2 = Person("Name", "Phone Num", "Email", "Text");

    bookHaveWant(book1);
    bookWaitList(book1, person1, person2);

    personSetGet(person1);

}

void runProgram(){

}

int main() {
    runTests();
    //runProgram();
    return 0;
}