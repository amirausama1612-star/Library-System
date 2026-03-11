#include <fstream>
#include <iostream>
#include "storage.h"
using namespace std;

void saveData(Library &l){

    ofstream file("library_data.txt");
    file<<l.currentDay<<endl;
    file<<l.books.size()<<endl;
    for(int i=0;i<l.books.size();i++){

        file<<l.books[i].code<<","
            <<l.books[i].title<<","
            <<l.books[i].totalCopies<<","
            <<l.books[i].availableCopies
            <<endl;
     }

    file.close();

    cout<<"Data saved\n";
}