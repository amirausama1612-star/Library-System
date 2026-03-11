#include <iostream>
#include "library.h"
#include "reports.h"
#include "storage.h"
using namespace std;

int main(){

    Library lib;
    int op;

    do{

        cout<<"\nLibrary Menu\n";

        cout<<"1 Add Book\n";
        cout<<"2 Add Member\n";
        cout<<"3 Borrow Book\n";
        cout<<"4 Return Book\n";
        cout<<"5 Late Books\n";
        cout<<"6 Next Day\n";
        cout<<"7 Save Data\n";
        cout<<"0 Exit\n";

        cin>>op;

        if(op==1) addBook(lib);
        else if(op==2) addMember(lib);
        else if(op==3) borrowBook(lib);
        else if(op==4) giveBackBook(lib);
        else if(op==5) lateBooks(lib);
        else if(op==6) lib.currentDay++;
        else if(op==7) saveData(lib);

    }while(op!=0);

}