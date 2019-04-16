//
// Created by Connor on 16/04/2019.
//

#ifndef NWEN241_ASSIGNMENT_3_DBMS_HH
#define NWEN241_ASSIGNMENT_3_DBMS_HH
namespace dbms {
    struct album {
        unsigned long int id;
        char title[100];
        unsigned int year;
        char artist[100];
    };

    class DbTable {
    private:
        unsigned int rowsTotal = 5;
        unsigned int rowsUsed = 0;
        album *table;
    public:
        DbTable();
        ~DbTable();
        int rows();
        int allocated();
        bool add(album toAdd);
        bool remove(unsigned int idToRemove);
        bool show(unsigned int);
    };
}

#endif //NWEN241_ASSIGNMENT_3_DBMS_HH
