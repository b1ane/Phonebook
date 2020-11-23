//
//  GymContact.cpp
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#include "GymContact.h"
#include <string.h>

GymContact::GymContact() : GenericContact(), gName(""), badge("")
{
}

GymContact::GymContact(const string &_gName, const string &_badge, const string &_region, const string &_phoneNumber) : GenericContact("G", _region, _phoneNumber), gName(_gName), badge(_badge)
{
}

string GymContact::getGName()
{
   //complete
}

string GymContact::getBadge()
{
    //complete
}

void GymContact::setGName(const string &_gName)
{
    //complete
}

void GymContact::setBadge(const string &_badge)
{
    //complete
}

void GymContact::print() const
{
    //complete
}

bool GymContact::operator!=(const GenericContact &contact) {
   // Write the implementation of the overloaded operator != here
}

GymContact::~GymContact() {}
