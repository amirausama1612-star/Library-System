#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
using namespace std;

struct Book{
    string code;
    string title;
    int totalCopies;
    int availableCopies;
};

struct Member{
    string memberCode;
    string memberName;
};

struct Borrow{
    string bookCode;
    string memberCode;
    int dayTaken;
    int dayReturn;
};

struct Library{
    vector<Book> books;
    vector<Member> members;
    vector<Borrow> borrows;
    int currentDay = 0;
};

void addBook(Library &l);
void addMember(Library &l);
Book* searchBook(Library &l,string code);
void borrowBook(Library &l);
void giveBackBook(Library &l);

#endif