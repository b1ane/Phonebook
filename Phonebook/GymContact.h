//
//  GymContact.h
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#ifndef GYMCONTACT_H
#define GYMCONTACT_H

#include <iostream>
#include <string>
#include "GenericContact.h"

using namespace std;

class GymContact : public GenericContact
{
private:
    string gName;
    string badge;

public:
    GymContact();
    GymContact(const string &_name, const string &_badge, const string &_region, const string &_phoneNumber);
    string getGName();
    string getBadge();
    void setGName(const string &_gName);
    void setBadge(const string &_badge);
    void print() const;
    bool operator!=(const GenericContact &contact);
    ~GymContact();
};

#endif
