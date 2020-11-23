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
   
}

string TrainerContact::getSpecialize()
{
   
}

void TrainerContact::setName(const string &_name)
{
  
}

void TrainerContact::setSpecialize(const string &_specialize)
{
  
}

void TrainerContact::print() const
{
  
}

bool TrainerContact::operator!=(const GenericContact &contact) {
   // Write the implementation of the overloaded operator != here
}

TrainerContact::~TrainerContact() {}
