//
//  TrainerContact.h
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#ifndef TRAINCONTACT_H
#define TRAINCONTACT_H

#include <iostream>
#include <string>
#include "GenericContact.h"

using namespace std;

class TrainerContact : public GenericContact
{
private:
    string name;
    string specialize;

public:
    TrainerContact();
    TrainerContact(const string &_name, const string &_specialize, const string &_region, const string &_phoneNumber);
    string getName();
    string getSpecialize();
    void setName(const string &_name);
    void setSpecialize(const string &_specialize);
    void print() const;
    bool operator!=(const GenericContact &contact);
    ~TrainerContact();
};

#endif
