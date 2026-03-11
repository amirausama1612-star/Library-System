#include <iostream>
#include "library.h"
using namespace std;

void addBook(Library &l){

    Book b;

    cout<<"Book code: ";
    cin>>b.code;

    cout<<"Book title: ";
    cin.ignore();
    getline(cin,b.title);

    cout<<"Copies: ";
    cin>>b.totalCopies;

    b.availableCopies = b.totalCopies;

    l.books.push_back(b);

    cout<<"Book added\n";
}

void addMember(Library &l){

    Member m;

    cout<<"Member code: ";
    cin>>m.memberCode;

    cout<<"Member name: ";
    cin.ignore();
    getline(cin,m.memberName);

    l.members.push_back(m);

    cout<<"Member added\n";
}

Book* searchBook(Library &l,string code){

    for(int i=0;i<l.books.size();i++){

        if(l.books[i].code==code)
            return &l.books[i];
    }

    return NULL;
}

void borrowBook(Library &l){

    string bCode,mCode;

    cout<<"Book code: ";
    cin>>bCode;

    cout<<"Member code: ";
    cin>>mCode;

    Book* b = searchBook(l,bCode);

    if(b==NULL){
        cout<<"Book not found\n";
        return;
    }

    if(b->availableCopies==0){
        cout<<"No copies available\n";
        return;
    }

    Borrow br;

    br.bookCode = bCode;
    br.memberCode = mCode;
    br.dayTaken = l.currentDay;
    br.dayReturn = l.currentDay + 14;

    l.borrows.push_back(br);

    b->availableCopies--;

    cout<<"Book borrowed\n";
}

void giveBackBook(Library &l){

    string bCode,mCode;

    cout<<"Book code: ";
    cin>>bCode;

    cout<<"Member code: ";
    cin>>mCode;

    for(int i=0;i<l.borrows.size();i++){

        if(l.borrows[i].bookCode==bCode &&
           l.borrows[i].memberCode==mCode){

            Book* b = searchBook(l,bCode);

            if(b!=NULL)
                b->availableCopies++;

            l.borrows.erase(l.borrows.begin()+i);

            cout<<"Book returned\n";
            return;
        }
    }

    cout<<"Borrow not found\n";
}