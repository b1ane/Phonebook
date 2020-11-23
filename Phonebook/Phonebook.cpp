//
//  Phonebook.cpp
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#include "Phonebook.h"
#include <sstream>
#include <fstream>
using namespace std;

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



int Phonebook::findAvailablePosition() const {
   // Write the implementation of the finAvailable Position helper function here
    if(contacts == nullptr)
               return -1;
        for (int i = 0; i < size; i++)
            if (contacts[i] != nullptr)
                   continue;
            else
                return i;
           return -1;
}

int Phonebook::findContactPosition(const string &_phoneNumber) {
   // Write the implementation of the finContactPosition helper function here
    for(int i = 0; i < size; i++)
        if (contacts[i] -> getPhoneNumber() == _phoneNumber)
            return i;
        return -1;
   
}

bool Phonebook::addContact(const string &type, const string &contactInformation) {
// Write the implementation of the addContact method here
// print the following message if the phonebook is full
// cout << "Cannot add the personal contact. The phonebook is full" << endl;
// Hint: use the findAvailablePosition helper function
    if (contacts == nullptr) {
        cout << "Cannot add the personal contact. The phonebook is full." << endl;
        return false;
    }
    int insert_position = this->findAvailablePosition();
    if(insert_position == -1) return false;
    vector<string> data = this->getDataParts(contactInformation);
    
    if(type.compare("T") == 0) {
        TrainerContact t = TrainerContact(data[0], data[1], data[2], data[3]);
        contacts[insert_position] = new TrainerContact;
        *((TrainerContact *)contacts[insert_position]) = t;
        
    }
    else if(type.compare("G") == 0) {
        GymContact g = GymContact(data[0], data[1], data[2], data[3]);
        contacts[insert_position] = new GymContact;
        *((GymContact *)contacts[insert_position]) = g;
        
    }
    return true;
}

bool Phonebook::deleteContact(const string &_phoneNumber) {
    // Write the implementation of the deleteContact method here
    // print the following message if no contact was found
    // cout << "Cannot find the phone number in the phonebook" << endl;
    // Hint: use the findContactPosition helper function
    int contact_position = this->findContactPosition(_phoneNumber);
    if(contact_position != -1) {
        contacts[contact_position] = nullptr;
        return true;
    }
    cout << "Cannot find the phone number in the phonebook" << endl;
    return false;

}
vector<string> Phonebook::getDataParts(const string input)
{
    vector<std::string> result;
    istringstream iss(input);
    for(string s; iss >> s; )
        result.push_back(s);
    return result;
}

void Phonebook::print() const {
    // Write the implementation of the print method here
    // Show the following message before printing the contacts' information
    cout << "Contacts: " << endl;
    cout << "Contacts: " << endl;
    for(int i = 0; i < size; i ++)
        if(contacts[i] != nullptr)
            contacts[i]->print();
}

bool Phonebook::readFromFile(const string &filename) {
    // Write the implementation of the readFromFile method here
    fstream infile;
        infile.open(filename, ios::in);
        if(infile.is_open())
        {
            string line;
            while (getline(infile, line))
            {
                this->addContact(line.substr(0, 1), line.substr(2));
            }
            infile.close();
            return true;
        }
        else
            return false;


}

bool Phonebook::operator==(const Phonebook &RHS) const {
    // Write the implementation of the overloaded == operator here
    if(this->size != RHS.size)
            return false;
        if( (this->findAvailablePosition()) != RHS.findAvailablePosition())
            return false;
        for(int i = 0; i < size; i ++)
        {
            if(contacts[i] != RHS.contacts[i])
                return false;
        }
        return true;
    
}

Phonebook::~Phonebook() {
   
}
