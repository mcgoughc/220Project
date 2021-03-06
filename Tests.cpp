/*
 * Tests.cpp
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file contains testing functions for different parts of the bookstore
*/

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
    std::cout << book1.getWaitList() << std::endl;

    book1.removeFromWaitList();
    std::cout << book1.getWaitList() << std::endl;
    book1.removeFromWaitList();
    std::cout << book1.getWaitList() << std::endl;

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

    bookstore.add("Lincoln", 5, 5);
    bookstore.add("Grant", 5, 1);

    //bookstore.list();

    bookstore.sell("Lincoln");
    bookstore.sell("Lincoln");
    bookstore.sell("Grant");

    try {
        bookstore.sell("Grant");
        printf("Sold more copies than in the store\n");
        errors = true;
    }catch(std::out_of_range& e){
        printf("Caught Error\n");
    }

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }
}

void bookstoreWantHave(BookStore& bookstore){
    printf("bookstoreWantHave ----------\n");
    bool errors = false;

    bookstore.add("Lincoln", 5, 5);
    bookstore.add("Grant", 5, 1);

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

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }
}

void bookstoreFind(BookStore& bookstore){
    printf("bookstoreFind ----------\n");
    bool errors = false;

    bookstore.add("Lincoln", 10, 5);
    bookstore.add("Grant", 5, 1);

    Book& lin = bookstore.findBook("Lincoln");
    Book& gran = bookstore.findBook("Grant");

    if(lin.getTitle() != "Lincoln"){
        std::cout << "Wrong index for Lincoln" << std::endl;
        std::cout << "Index returned was: " << lin.getTitle() << std::endl;
        errors = true;
    }

    if(gran.getTitle() != "Grant"){
        std::cout << "Wrong index for Grant" << std::endl;
        std::cout << "Index returned was: " << gran.getTitle() << std::endl;
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
    //TODO
}

/**
void isAlphaGreaterThanTest(ArrayInventory& inventory){
    bool errors = false;
    printf("isAlphaGreaterThanTest ------------\n");

    std::string a1 = "AAA";
    std::string a2 = "aaa";
    if(inventory.isAlphabeticallyGreaterThan(a1, a2) == true) {
        printf("error");
        errors = true;
    }
    std::string a3 = "The Apple Tree";
    std::string a4 = "The-Apple-Tree";
    if(inventory.isAlphabeticallyGreaterThan(a3, a4) == true)
        errors = true;

    std::string a5 = "The Big Short";
    if(inventory.isAlphabeticallyGreaterThan(a5, a4) == false)
        errors = true;

    std::string a6 = "zzz";
    std::string a7 = "zzza";
    if(inventory.isAlphabeticallyGreaterThan(a6, a7) == true)
        errors = true;

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }

}
*/

void linkQueueAssignOp(){
    printf("linkedQueueAssignOp ----------\n");
    bool errors = false;

    Person testPerson1 = Person("Bill", "Sapsis", "18007854444", "billy@sri.org", Person::SEND_TEXT);
    Person testPerson2 = Person("Kim", "Turncliffe", "9048753000", "kimmie@yahoo.com", Person::SEND_EMAIL);
    Person testPerson3 = Person("Rachel", "Young", "3356874300", "ryoung@gmail.com", Person::PHONE_CALL);
    LinkedQueue<Person>* origTestQueue = new LinkedQueue<Person>();
    LinkedQueue<Person>* newTestQueue = new LinkedQueue<Person>();

    origTestQueue->enqueue(testPerson1);
    origTestQueue->enqueue(testPerson2);
    newTestQueue->enqueue(testPerson2);

    newTestQueue = origTestQueue;

    origTestQueue->enqueue(testPerson3);

    Person returnPerson = newTestQueue->dequeue();
    if(returnPerson.getName() == testPerson3.getName()){
        printf("Fail. newTestQueue looking at origTestQueue\n");
        errors = true;
    }else if(returnPerson.getName() == testPerson1.getName()){
        printf("Success\n");
    }

    Person returnPerson2 = origTestQueue->dequeue();
    if(returnPerson2.getName() == testPerson1.getName()){
        printf("Fail. origTestQueue looking at origTestQueue\n");
        errors = true;
    }else if(returnPerson2.getName() == testPerson3.getName()){
        printf("Success\n");
    }

    if(!errors){
        printf("PASS\n");
    }else{
        printf("FAIL\n");
    }
}

void arrayInventoryAddItem(){
    printf("arrayInventoryAddItem ---------- \n");
    Book b1 = Book("FA FA", 5, 5);
    Book b2 = Book("Ccc", 5, 5);
    Book b3 = Book("Aaa", 5, 5);
    Book b4 = Book("Aab", 5, 5);
    Book b5 = Book("Dad", 5, 5);
    ArrayInventory* myInv = new ArrayInventory();

    myInv->addItem(b1);
    myInv->addItem(b2);
    myInv->addItem(b3);
    myInv->addItem(b4);
    myInv->addItem(b5);

    std::cout << "Expected: -101234" << std::endl;
    std::cout << "Actual: ";
    std::cout << myInv->getIndex("Zo Zo");
    std::cout << myInv->getIndex("Aaa");
    std::cout << myInv->getIndex("Aab");
    std::cout << myInv->getIndex("Ccc");
    std::cout << myInv->getIndex("Dad");
    std::cout << myInv->getIndex("FA FA") << std::endl;

    delete myInv;
}

void fileIOTests(BookStore& bookstore){
    //Order test
    bookstore.add("Red", 10, 8);
    bookstore.add("Blue", 9, 0);
    bookstore.add("Orange", 3, 2);
    Person p("Johnny", "Johnson", "555-5555", "John@ithaca.edu", Person::SEND_TEXT);
    bookstore.findBook("Red").addToWaitList(p);
    bookstore.order("order.txt");

    //Delivery test
    bookstore.deliver("order.txt");
}



