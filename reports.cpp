#include <iostream>
#include "reports.h"
using namespace std;
void lateBooks(Library &l){
    for(int i=0;i<l.borrows.size();i++){

        if(l.currentDay > l.borrows[i].dayReturn){

            cout<<"Late book: "
                <<l.borrows[i].bookCode
                <<endl;
        }
    }
}