#include <iostream>
#include<ctime>
#include "demo.h"
using namespace std;

void printMessage()
{
   cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<endl<<endl<<endl<<endl;
   cout<<"                        WELCOME TO THE CONTACT BOOK APPLICATION.....HOPE YOU ENJOY IT"<<endl;
   cout<<endl<<endl<<endl<<endl;
   cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<endl<<endl<<endl<<endl;
   time_t timetoday;
   time(&timetoday);
   cout <<"                         Date and time as per todays is : "<< asctime(localtime(&timetoday));
   cout<<endl<<endl<<endl<<endl;
   cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
   cout <<"                             Chose an action to continue "<< asctime(localtime(&timetoday));
   cout<<endl<<endl<<endl<<endl;
}

void printMenu()
{

    cout<<"                             1. Sign Up"<<endl;
    cout<<"                             2. Login"<<endl;
    cout<<"                             3. Exit"<<endl;
    cout<<endl<<endl<<"                             Enter your choice:"<<endl;
    cout<<endl<<endl;
}

void printChoice()
{
    cout<<endl<<endl<<endl;
    cout<<"                 *********************************************************************************"<<endl;
    cout<<"                 *********************************************************************************"<<endl<<endl;
    cout<<"                             1.Create and Insert new Contact Details"<<endl;
    cout<<"                             2.Enter initials to find Suggestions for a Contact by Name"<<endl;
    cout<<"                             3.Chose contact to retrieve details and call by name"<<endl;
    cout<<"                             4.Retrieve recent atmost 5 contacts"<<endl;
    cout<<"                             5.Search by Number to retrieve details and call"<<endl;//hashmap
    cout<<"                             6.Sort and Display details by name"<<endl;
    cout<<"                             7.Delete record by Name"<<endl;
    cout<<"                             8.Modify Details"<<endl;
    cout<<"                             9.Retrieve the phone number of person at a particular location if exists"<<endl;
    cout<<"                             10.Find phone numbers of all nearest neighbors to a location"<<endl;
    cout<<"                             11.Delete account"<<endl;
    cout<<"                             12.Exit application"<<endl<<endl;
    cout<<"                 *********************************************************************************"<<endl;
    cout<<"                 *********************************************************************************"<<endl<<endl;
    cout<<"                             Enter your choice"<<endl<<endl;


}

void printExitMessage()
{
   cout<<"                                      EXIT FROM CONTACT BOOK SIMULATION"<<endl<<endl;
   cout<<"                                      BACKED UP DATA SUCCESSFULLY"<<endl<<endl<<endl;
   cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl<<endl;
   cout<<"                                       GOODBYE..... SEE YOU SOON"<<endl<<endl;
   cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
   cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl<<endl;
}
