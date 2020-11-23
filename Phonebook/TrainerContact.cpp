//
//  TrainerContact.cpp
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#include "TrainerContact.h"
#include <string.h>

TrainerContact::TrainerContact() : GenericContact(), name(""), specialize("")
{
}

TrainerContact::TrainerContact(const string &_name, const string &_specialize, const string &_region, const string &_phoneNumber) : GenericContact("T", _region, _phoneNumber), name(_name), specialize(_specialize)
{
}

string TrainerContact::getName()
{
    return this -> name;
   
}

string TrainerContact::getSpecialize()
{
    return this -> specialize;
   
}

void TrainerContact::setName(const string &_name)
{
    this -> name = _name;
  
}

void TrainerContact::setSpecialize(const string &_specialize)
{
    this -> specialize = _specialize;
  
}

void TrainerContact::print() const
{
    cout << "Name: " << this->name << ", Specialize: " << this->specialize << ", Region: " << this->getRegion() << ", Phone number: " << this->getPhoneNumber() << endl;
  
}

bool TrainerContact::operator!=(const GenericContact &contact) {
   // Write the implementation of the overloaded operator != here
    return GenericContact::operator!=(contact);
}

TrainerContact::~TrainerContact() {}
