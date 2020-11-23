//
//  main.cpp
//  Phonebook
//
//  Created by Blane Zewdie on 11/23/20.
//

#include "Phonebook.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   string filename;
   cin >> filename;
   Phonebook myPhonebook(10);
   myPhonebook.readFromFile(filename);
   myPhonebook.print();
   return 0;
}
