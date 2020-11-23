//
//  Phonebook.cpp
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#include "Phonebook.h"
#include <sstream>
#include <fstream>

Phonebook::Phonebook(const int _size)
{
    size = _size;
    numContacts = 0;
    contacts = new GenericContact *[size];
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
}

Phonebook::Phonebook(const Phonebook &origOBJ)
{
    size =origOBJ.size;
    numContacts = origOBJ.numContacts;
    contacts = new GenericContact *[size];
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (origOBJ.contacts[i] != nullptr)
        {
            if (origOBJ.contacts[i]->getType() == "G")
            {
                GymContact temp = *((GymContact *)origOBJ.contacts[i]);    //assign RHS obj's content to the temporary obj
                contacts[i] = new GymContact;                                   //allocate new momory for the pointer contacts[i]
                *((GymContact *)contacts[i]) = temp;                            //assign temporary obj's content to the new memory
            }
            else
            {
                TrainerContact temp = *((TrainerContact *)origOBJ.contacts[i]);
                contacts[i] = new TrainerContact;
                *((TrainerContact *)contacts[i]) = temp;
            }
        }
    }
}

const Phonebook &Phonebook::operator=(const Phonebook &ObjToCopy)
{
    if (this != &ObjToCopy)
    {
        for (int i = 0; i < size; i++)
        {
            if (contacts[i] != nullptr)
            {
                delete contacts[i];
                contacts[i] = nullptr;
            }
        }
        delete[] contacts;
        contacts = nullptr;
        size = ObjToCopy.size;
        numContacts = ObjToCopy.numContacts;
        contacts = new GenericContact *[size];
        for (int i = 0; i < size; i++)
            contacts[i] = nullptr;
        for (int i = 0; i < size; i++)
        {
            if (ObjToCopy.contacts[i] != nullptr)
            {
                if (ObjToCopy.contacts[i]->getType() == "G")
                {
                    GymContact temp = *((GymContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new GymContact;
                    *((GymContact *)contacts[i]) = temp;
                }
                else
                {
                    TrainerContact temp = *((TrainerContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new TrainerContact;
                    *((TrainerContact *)contacts[i]) = temp;
                }
            }
        }
    }
    return *this;
}



int Phonebook::findAvailablePosition() {
   // Write the implementation of the finAvailable Position helper function here
   
}

int Phonebook::findContactPosition(const string &_phoneNumber) {
   // Write the implementation of the finContactPosition helper function here
   
}

bool Phonebook::addContact(const string &type, const string &contactInformation) {
// Write the implementation of the addContact method here
// print the following message if the phonebook is full
// cout << "Cannot add the personal contact. The phonebook is full" << endl;
// Hint: use the findAvailablePosition helper function

}

bool Phonebook::deleteContact(const string &_phoneNumber) {
    // Write the implementation of the deleteContact method here
    // print the following message if no contact was found
    // cout << "Cannot find the phone number in the phonebook" << endl;
    // Hint: use the findContactPosition helper function

}

void Phonebook::print() const {
    // Write the implementation of the print method here
    // Show the following message before printing the contacts' information
    cout << "Contacts: " << endl;
    
}

bool Phonebook::readFromFile(const string &filename) {
    // Write the implementation of the readFromFile method here

}

bool Phonebook::operator==(const Phonebook &RHS) const {
    // Write the implementation of the overloaded == operator here
    
}

Phonebook::~Phonebook() {
   
}
