//
//  GenericContact.h
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#ifndef GENCONTACT_H
#define GENCONTACT_H
#include <iostream>
#include <string>
using namespace std;

//Use virtual qualifier for methods and destructor if needed
class GenericContact
{
private:
    string type;
    string region;
    string phoneNumber;

public:
    GenericContact();
    GenericContact(const string &_type, const string &_region, const string &_phoneNumber);
    string getType() const;
    string getRegion() const;
    string getPhoneNumber() const;
    void setType(const string &_type);
    void setRegion(const string &_region);
    void setPhoneNumber(const string &_phoneNumber);
    void print() const;
    bool operator!=(const GenericContact &contact);
    ~GenericContact();
};

#endif
