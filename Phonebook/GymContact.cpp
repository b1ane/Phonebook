//
//  GymContact.cpp
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#include "GenericContact.h"
#include "GymContact.h"
#include <string.h>

GymContact::GymContact() : GenericContact(), gName(""), badge("")
{
}

GymContact::GymContact(const string &_gName, const string &_badge, const string &_region, const string &_phoneNumber) : GenericContact("G", _region, _phoneNumber), gName(_gName), badge(_badge)
{
    this->setGName(_gName);
    this->setBadge(_badge);
}

string GymContact::getGName()
{
   //complete
    return this -> gName;
}

string GymContact::getBadge()
{
    //complete
    return this -> badge;
}

void GymContact::setGName(const string &_gName)
{
    //complete
    this -> gName = _gName;
}

void GymContact::setBadge(const string &_badge)
{
    //complete
    this -> badge = _badge;
}

void GymContact::print() const
{
    //complete
    cout << "Gym: " << this->gName << ", Badge: " << this->badge << ", Region: " << this->getRegion() << ", Phone number: " << this->getPhoneNumber() << endl;
}

bool GymContact::operator!=(const GenericContact &contact) {
   // Write the implementation of the overloaded operator != here
    return GenericContact::operator!=(contact);
}

GymContact::~GymContact() {}
