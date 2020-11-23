//
//  GenericContact.cpp
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#include "GenericContact.h"
#include <string.h>

GenericContact::GenericContact()
{
}
string GenericContact::getType() const
{
    return this->type;
}
string GenericContact::getRegion() const
{
    return this->region;
}
string GenericContact::getPhoneNumber() const
{
    return this->phoneNumber;
}
void GenericContact::setType(const string &_type)
{
    this->type = _type;
}
GenericContact::GenericContact(const string &_type, const string &_region, const string &_phoneNumber)
{
    this->setType(_type);
    this->setRegion(_region);
    this->setPhoneNumber(_phoneNumber);
}
void GenericContact::setRegion(const string &_region)
{
    this->region = _region;
}
void GenericContact::setPhoneNumber(const string &_phoneNumber)
{
    this->phoneNumber = _phoneNumber;
}
bool GenericContact::operator!=(const GenericContact &contact)
{
    return this->getType() != contact.getType() || this->getRegion() != contact.getRegion() || this->getPhoneNumber() != contact.getPhoneNumber();
}
GenericContact::~GenericContact()
{
    
}
