#include <iostream>
#include "dbms.hh"

using namespace std;
using namespace dbms;

/*
 * Constructor for the DbTable Class
 */
DbTable::DbTable() {
    table = (album*)malloc(sizeof(album)*rowsTotal);
}
/*
 * Deconstructor for the DbTable Class
 */
DbTable::~DbTable() {
    delete [] table;
    table = nullptr;
}
/*
 * returns the amount of rows that currently have an entry
 */
int DbTable::rows() {
    return rowsUsed;
}
/*
 * returns the total amount of rows allocated to the table
 */
int DbTable::allocated() {
    return rowsTotal;
}

/*
 * returns all fields of a entry with a matching ID
 */
bool DbTable::show(unsigned int searchId) {
    if(searchId>rowsUsed){
        cout<<"Requested Record Does Not Exist"<<endl;
        return false;

    } else{
        album locatedRecord = table[searchId];
        cout<<"Requested Entry"<<endl<<"ID: "<<locatedRecord.id<<" Title: "<<locatedRecord.title<<" Year: "<<locatedRecord.year<<" Artist: "<<locatedRecord.artist<<endl;
        return true;
    }
    return false;
}
/*
 * Adds the supplied album to the table
 */
bool DbTable::add(album toAdd){
    if(rowsUsed<rowsTotal){
        table[rowsUsed] = toAdd;
        rowsUsed++;
        return true;
    } else if(rowsUsed == rowsTotal){
        table = (album*)realloc(table,rowsTotal+5);
        rowsTotal += 5;
        table[rowsUsed] = toAdd;
        rowsUsed++;
        return true;
    }
    return false;
}

/*
 * Removes the entry with the specified album id
 */
bool DbTable::remove(unsigned int idToRemove) {
    album *toRemove = nullptr;
    int indexOfRemoval = 0;
    for(int i = 0;i<rowsUsed;i++){
        if(table[i].id == idToRemove){
            toRemove = &table[i];
        }
    }
    if(toRemove== nullptr){
        return false;
    } else{
        indexOfRemoval = (int)(toRemove-table);
        for(int i = indexOfRemoval;i<rowsUsed-1;i++){
            table[i] = table[i+1];
        }
        rowsUsed -= 1;
        if(rowsTotal-rowsUsed<=5){
            return true;
        } else{
            table = (album*)realloc(table,rowsTotal-5);
            rowsTotal -=5;
            return true;
        }
    }
    return false;
}
