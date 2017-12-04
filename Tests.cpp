//
// Created by Chase McGough on 11/30/17.
//

#include "Tests.h"


void bookHaveWant(Book& book1){
    printf("bookHaveWant ----------\n");
    bool errors = false;

    book1.setHaveValue(100);
    book1.setWantValue(100);

    std::cout << "Have value: " << book1.getHaveValue() << std::endl;
    std::cout << "Want value: " << book1.getWantValue() << std::endl;

    try {
        book1.setHaveValue(-100);
        printf("Allowed negative have\n");
        errors = true;
    }catch(std::out_of_range &e){}

    try {
        book1.setWantValue(-100);
        printf("Allowed negative want\n");
        errors = true;
    }catch(std::out_of_range &e){}

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }
}

void bookWaitList(Book& book1, Person& person1, Person& person2){
    printf("bookWaitList ----------\n");
    bool errors = false;

    book1.addToWaitList(person1);
    book1.addToWaitList(person2);

    book1.removeFromWaitList();

    book1.removeFromWaitList();

    try{
        book1.removeFromWaitList();
        printf("Removed from empty wait list\n");
        errors = true;
    }catch(std::out_of_range &e){}

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }

    book1.addToWaitList(person1);
    book1.addToWaitList(person2);
}

void bookAssignOpCopyConst(Book& book1) {
    printf("bookAssignOpCopyConst ----------\n");

}

void personSetGet(Person& person1) {
    printf("personSetGet ----------\n");
    bool errors = false;

    person1.setPhoneNumber("7864249000");
    person1.setEmail("joeshmoe@aol.com");

    try{
        person1.setCommMethod(6);
        printf("Does not throw error for out of range option\n");
        errors = true;
    }catch(std::out_of_range &e){}

    person1.setCommMethod(1);

    std::string expectOut =
            "Name: " + person1.getName() +
            "\nPhone Number: " + person1.getPhoneNumber() +
            "\nEmail: " + person1.getEmail() +
            "\nCommunication Method: " + person1.getCommMethod();

    std::string actualOut = person1.toString();

    std::cout << "\nExpected output\n" << expectOut << std::endl;
    std::cout << "\nActual output\n" << actualOut << std::endl;

    if(expectOut != actualOut){
        printf("Getters do not return same as to_string\n");
        errors = true;
    }

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }


}

void personAssignOpCopyConst(Person& person1) {
    printf("personAssignOpCopyConst ----------\n");

}

void bookstoreAddSell(BookStore& bookstore){
    //TODO Also check if book is added in proper place, and there are no duplicate entries
    printf("bookstoreAddSell ----------\n");
    bool errors = false;

    bookstore.add("Lincoln", "Abe Lincoln", 5, 5);
    bookstore.add("Grant", "Bjarn strautsrup", 5, 1);

    //bookstore.list();

    bookstore.sell("Lincoln");
    bookstore.sell("Lincoln");
    bookstore.sell("Grant");

    try {
        bookstore.sell("Grant");
        printf("Sold more copies than in the store");
        errors = true;
    }catch(std::out_of_range &e){}
}

void bookstoreWantHave(BookStore& bookstore){
    printf("bookstoreAddSell ----------\n");
    bool errors = false;

    int testHave = bookstore.getHave("Lincoln");
    int testWant = bookstore.getWant("Lincoln");

    bookstore.setHave("Lincoln", testHave+5);
    bookstore.setWant("Lincoln", testWant+5);

    if(bookstore.getHave("Lincoln") <= testHave){
        std::cout << "Did not change have value" << std::endl;
        errors = true;
    }
    if(bookstore.getWant("Lincoln") <= testWant){
        std::cout << "Did not change want value" << std::endl;
        errors = true;
    }

    try {
        bookstore.setHave("Lincoln", -60);
        printf("Allows negative have\n");
        errors = true;
    }catch(std::out_of_range &e){}

    try {
        bookstore.setWant("Lincoln", -60);
        printf("Allows negative want\n");
        errors = true;
    }catch(std::out_of_range &e){}

}

void bookstoreFind(BookStore& bookstore){
    printf("bookstoreFind ----------\n");
    bool errors = false;

    bookstore.add("Lincoln", "Abe Lincoln", 5, 5);
    bookstore.add("Grant", "Bjarn strautsrup", 5, 1);

    int linIdx = bookstore.findBook("Lincoln");
    int granIdx = bookstore.findBook("Grant");

    if(linIdx != 1){
        std::cout << "Wrong index for Lincoln" << std::endl;
        std::cout << "Index returned was: " << linIdx << std::endl;
        errors = true;
    }

    if(granIdx != 0){
        std::cout << "Wrong index for Grant" << std::endl;
        std::cout << "Index returned was: " << granIdx << std::endl;
        errors = true;
    }

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }
}

void bookstoreAssignOpCopyConst(BookStore& bookstore){

}

void bookstoreWaitlist(BookStore &bookstore) {

}

void isAlphaGreaterThanTest(BookStore& bookStore){
    bool errors = false;
    printf("isAlphaGreaterThanTest ------------\n");

    std::string a1 = "AAA";
    std::string a2 = "aaa";
    if(bookStore.isAlphabeticallyGreaterThan(a1, a2) == true) {
        printf("error");
        errors = true;
    }
    std::string a3 = "The Apple Tree";
    std::string a4 = "The-Apple-Tree";
    if(bookStore.isAlphabeticallyGreaterThan(a3, a4) == true)
        errors = true;

    std::string a5 = "The Big Short";
    if(bookStore.isAlphabeticallyGreaterThan(a5, a4) == false)
        errors = true;

    std::string a6 = "zzz";
    std::string a7 = "zzza";
    if(bookStore.isAlphabeticallyGreaterThan(a6, a7) == true)
        errors = true;

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }

}

