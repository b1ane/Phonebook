//
//  Phonebook.h
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <fstream>
#include <sstream>
#include <vector>
#include "GenericContact.h"
#include "GymContact.h"
#include "TrainerContact.h"

class Phonebook
{
private:
    GenericContact **contacts;
    int numContacts;
    int size;
    int findAvailablePosition() const;
    int findContactPosition(const string &_phoneNumber);

public:
    Phonebook(int _size);
    Phonebook(const Phonebook &origOBJ);
    const Phonebook &operator=(const Phonebook &ObjToCopy);
    bool addContact(const string &type, const string &contactInformation);
    bool deleteContact(const string &_phoneNumber);
    void print() const;
    bool readFromFile(const string &filename);
    vector<string> getDataParts(const string input);
    bool operator==(const Phonebook &RHS) const;
    ~Phonebook();
};

#endif
