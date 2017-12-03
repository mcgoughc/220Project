#include <iostream>

#include "BookStore.h"
#include "Tests.h"

void runTests(){
    Book* book1 = new Book("Autumn", "Ali Smith");
    Book* book2 = new Book("Pachinko","Min Jin Lee");
    Person* person1 = new Person("Harry");
    Person* person2 = new Person("Gaben");

    bookHaveWant(book1);
    bookWaitList(book1, person1, person2);

}

void runProgram(){

}

int main() {
    runTests();
    //runProgram();
    return 0;
}