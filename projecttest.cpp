#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void printline(char, int);
bool is_valid(string, string, string);

class contact
{

public:
    string fName, lName, street, zipCode, city, email, cellNumber, birthday, comment;
    //initialize the contact by a default value
    contact() : fName(""), lName(""), street(""), zipCode(""), city(""), email(""), cellNumber(""), birthday(""), comment("")
    {}


    //Show all contacts
    bool showAll()
    {
        if (fName != "")
        {
            cout << "Name: " << fName << " " << lName << "\n" << "Mobilenumber:  "
            << cellNumber << "\n" << "Adress: " << street << ", " << zipCode << " " << city << "\n" << "Email: "
            << email << "\n" << "Birthday: " << birthday << "\n" << "Comment: "
            << comment << "\n\n\n";

            return 1;   //Success!!
        }
        else
          return 0;   //Fail!!
    }


    // Search
    bool Search(string search_term)
    {

      int termLength = search_term.length();

      string fNameSub = fName.substr(0, termLength);
      string lNameSub = lName.substr(0, termLength);
      string streetSub = street.substr(0, termLength);
      string zipCodeSub = zipCode.substr(0, termLength);
      string citySub = city.substr(0, termLength);
      string emailSub = email.substr(0, termLength);
      string birthdaySub = birthday.substr(0, termLength);
      string cellSub = cellNumber.substr(0, termLength);
      string commentSub = comment.substr(0, termLength);

      transform(search_term.begin(), search_term.end(), search_term.begin(), ::tolower);
      transform(fNameSub.begin(), fNameSub.end(), fNameSub.begin(), ::tolower);
      transform(lNameSub.begin(), lNameSub.end(), lNameSub.begin(), ::tolower);
      transform(streetSub.begin(), streetSub.end(), streetSub.begin(), ::tolower);
      transform(zipCodeSub.begin(), zipCodeSub.end(), zipCodeSub.begin(), ::tolower);
      transform(citySub.begin(), citySub.end(), citySub.begin(), ::tolower);
      transform(emailSub.begin(), emailSub.end(), emailSub.begin(), ::tolower);
      transform(birthdaySub.begin(), birthdaySub.end(), birthdaySub.begin(), ::tolower);
      transform(cellSub.begin(), cellSub.end(), cellSub.begin(), ::tolower);
      transform(commentSub.begin(), commentSub.end(), commentSub.begin(), ::tolower);

        if (search_term == fNameSub || search_term == lNameSub
          || search_term == streetSub || search_term == zipCodeSub
          || search_term == citySub || search_term == emailSub
          || search_term == birthdaySub || search_term == commentSub)
        {

          cout << "Name: " << fName << " " << lName << "\n" << "Mobilenumber:  "
          << cellNumber << "\n" << "Adress: " << street << ", " << zipCode << " " << city << "\n" << "Email: "
          << email << "\n" << "Birthday: " << birthday << "\n" << "Comment: "
          << comment << "\n\n\n";
            return 1;
        }
        else
            return 0;
    }

    // Check if a name exists or not
    bool name_exists(string tname)
    {
      transform(tname.begin(), tname.end(), tname.begin(), ::toupper);
      transform(fName.begin(), fName.end(), fName.begin(), ::toupper);

        if (tname == fName)
            return 1;
        else
            return 0;
    }

    bool addFromFile(string new_fName, string new_lName, string new_street,
      string new_zipCode, string new_city, string new_email, string new_cellNumber,
      string new_birthday, string new_comment)
    {
      if (fName == "")
      {
        fName = new_fName;
        lName = new_lName;
        street = new_street;
        zipCode = new_zipCode;
        city = new_city;
        email = new_email;
        cellNumber = new_cellNumber;
        birthday = new_birthday;
        comment = new_comment;
        return 1;
      }
      else
        cout << "return 0 i addfromfile" << endl;
        return 0;

    }
    // Adding everything to a file.

    bool addContact(string new_fName, string new_lName, string new_street,
      string new_zipCode, string new_city, string new_email, string new_cellNumber,
      string new_birthday, string new_comment)

    {
        if (fName == "")
        {
          fName = new_fName;
          lName = new_lName;
          street = new_street;
          zipCode = new_zipCode;
          city = new_city;
          email = new_email;
          cellNumber = new_cellNumber;
          birthday = new_birthday;
          comment = new_comment;
            return 1; // Success !!
        }
        else
            cout << "return 0 i addContact" << endl;
            return 0; // Failure !!

    }

    //edits the contact details
    bool edit(string);

    bool erase(string new_name)
    {

        if (new_name == fName)
        {
            fName = "";
            lName = "";
            street = "";
            zipCode = "";
            city = "";
            email = "";
            cellNumber = "";
            birthday = "";
            comment = "";
            return 1;
        }
        else
            return 0;
    }
};

// Edits the contact
bool contact::edit(string name_check)
{

    string new_fName, new_lName, new_street, new_zipCode, new_city, new_email, new_cellNumber, new_birthday, new_comment;
    transform(name_check.begin(), name_check.end(), name_check.begin(), ::tolower);
    transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
    if (name_check == fName)
    {
        cin.ignore();
        cin.clear();
        cout << "Enter new first name: ";
        getline(cin, new_fName);
        cout << "Enter new lastname: ";
        getline(cin, new_lName);
        cout << "Enter new street Name: ";
        getline(cin, new_street);
        cout << "Enter new zip code: ";
        getline(cin, new_zipCode);
        cout << "Enter new city: ";
        getline(cin, new_city);
        cout << "Enter new email: ";
        getline(cin, new_email);
        cout << "Enter new cellnumber:";
        getline(cin, new_cellNumber);
        cout << "Enter new birthday: ";
        getline(cin, new_birthday);
        cout << "Enter new comment:";
        getline(cin, new_comment);

        fName = new_fName;
        lName = new_lName;
        street = new_street;
        zipCode = new_zipCode;
        city = new_city;
        email = new_email;
        cellNumber = new_cellNumber;
        birthday = new_birthday;
        comment = new_comment;
        return 1;
    }
    else
        return 0;
}

    // Write all contacts to the file.

int main()
{

    contact person[100];
    string trash;
    string temp_fName, temp_lName, temp_street, temp_zipCode, temp_city,
    temp_email, temp_cellNumber, temp_birthday, temp_comment;
    int counter, choice, i;
    bool flag, cancel_flag;

    ifstream infile("Phonebook.txt");

    if (infile.fail())
    {
        cout << "Your file didnt work." << endl;
    }

    while (!infile.eof())
    {

        getline(infile, trash, ' ');
        trash.clear();
        getline(infile, temp_fName, ' ');
        getline(infile, temp_lName);
        getline(infile, trash, ' ');
        trash.clear();
        getline(infile, temp_cellNumber);
        getline(infile, trash, ' ');
        trash.clear();
        getline(infile, temp_street, ',');
        getline(infile, temp_zipCode, ' ');
        getline(infile, temp_city);
        getline(infile, trash, ' ');
        trash.clear();
        getline(infile, temp_email);
        getline(infile, trash, ' ');
        trash.clear();
        getline(infile, temp_birthday);
        getline(infile, trash, ' ');
        trash.clear();
        getline(infile, temp_comment);


        for (i = 0; i < 100; i++)
            if (person[i].addContact(temp_fName, temp_lName, temp_street, temp_zipCode, temp_city,
                temp_email, temp_cellNumber, temp_birthday, temp_comment))
            {
                temp_fName.clear();
                temp_lName.clear();
                temp_street.clear();
                temp_zipCode.clear();
                temp_city.clear();
                temp_email.clear();
                temp_cellNumber.clear();
                temp_birthday.clear();
                temp_comment.clear();

                cout << "Contact added successfully!" << endl;
                flag = 1;
                break;
            }

    }


    cout << "=========== Your Phonebook ==========" << endl;

    do
    {

        cout << "\n\n";
        printline('-', 25);
        cout << "1. Add Contact" << endl
            << "2. Edit Contact" << endl
            << "3. Delete Contact" << endl
            << "4. Search" << endl
            << "5. Show All Contacts" << endl
            << "6. Write All Contacts To File." << endl
            << "0. Exit" << endl << endl
            << "Your choice... ";
        cin >> choice;

        system("cls");
        printline('-', 25);
        cancel_flag = 0;
        flag = 0;
        counter = 0;

        switch (choice)
        {
        // Close the program
        case 0:
            return 0;


        // Adds a new contact
        case 1:
            cout << "Add New Contact\t\t\t\tpress - to cancel" << endl;
            printline('-', 25);
            counter = 0;
            int yes;

            // Loop until correct contact info is entered
            do
            {
                flag = 0;
                if (counter)
                    cout << "Try again \t\t\t\tpress - to cancel" << endl;

                //count how many times the do-while loop executes
                counter++;


                  cin.ignore();
                  cin.clear();
                  cout << "First Name: ";
                  getline(cin, temp_fName);
                  // Måste jag sätta if statement efter varje getline?
                  if (temp_fName == "-")
                  {
                      system("cls");
                      break;
                  }
                  cout << "Last Name: ";
                  getline(cin, temp_lName);
                  cout << "Street Name: ";
                  getline(cin, temp_street);
                  cout << "Zip Code: ";
                  getline(cin, temp_zipCode);
                  cout << "City: ";
                  getline(cin, temp_city);
                  cout << "Email: ";
                  getline(cin, temp_email);
                  cout << "Cellnumber: ";
                  getline(cin, temp_cellNumber);
                  cout << "Birthday: ";
                  getline(cin, temp_birthday);
                  cout << "Comment: ";
                  getline(cin, temp_comment);

                for (i = 0; i < 100; i++)
                    if (person[i].name_exists(temp_fName))
                    {
                        cout << "The name you entered is already there"
                            "in the phonebook, entere a different name." << endl;
                        flag = 1;
                        break;
                    }
            } while (!is_valid(temp_fName, temp_lName, temp_cellNumber) || flag);

            if (cancel_flag)
            {
                system("cls");
                break;
            }

            //This loop adds the contact to the phonebook

            for (i = 0; i < 100; i++)
                if (person[i].addContact(temp_fName, temp_lName, temp_street, temp_zipCode,
                   temp_city, temp_email, temp_cellNumber, temp_birthday, temp_comment))
                {
                    temp_fName.clear();
                    temp_lName.clear();
                    temp_street.clear();
                    temp_zipCode.clear();
                    temp_city.clear();
                    temp_email.clear();
                    temp_cellNumber.clear();
                    temp_birthday.clear();
                    temp_comment.clear();

                    cout << "Contact added successfully!" << endl;
                    flag = 1;
                    break;
                }


            if (!flag)
                cout << "Memory full! Delete some contacts first." << endl;
            break;


            // Edits an existing contact
        case 2:
            cout << "Enter a contact name to edit \t\t\t\tpress - to cancel" << endl;
            cin >> temp_fName;

            // Cancel operation
            if (temp_fName == "-")
            {
                system("cls");
                break;
            }

            for (i = 0; i < 100; i++)
                if (person[i].edit(temp_fName))
                {
                    cout << "Edited Successfully!" << endl;
                    flag = 1;
                    break;
                }

            if (!flag)
              cout << "Contact name not found!" << endl;
            break;

        //Delete a contact
        case 3:
            do
            {
                if (counter)
                    cout << "Try again" << endl;
                counter++;
                cout << "Enter a contact name to delete: \t\t\t\tpress - to cancel" << endl;
                cin >> temp_fName;

                // Cancel operation
                if (temp_fName == "-")
                {
                    system("cls");
                    break;
                }

                //Final Confirmation
                for (i = 0; i < 100; i++)
                    if (person[i].name_exists(temp_fName))
                    {
                        flag = 1;
                        cout << "Are you sure you want to delete (1/0)" << endl;
                        int yes;
                        cin >> yes;
                        if (!yes)
                        {
                            system("cls");
                            cancel_flag = 1;
                        }
                        break;
                    }

                if (!flag)
                    cout << "Contact name not found!" << endl;

                if (cancel_flag)
                    break;


                // This code deletes the contact
                if (flag)
                {
                    for (i = 0; i < 100; i++)
                        if (person[i].erase(temp_fName))
                        {
                            cout << "Deleted successfully!" << endl;
                            break;
                        }
                }
            } while (!flag);
            break;

            // Search a contact
        case 4:
            do
            {
              string search_term;
                if (counter)
                    cout << "Try again" << endl;
                counter++;
                cout << "Write a search word. \t\t\tpress - to cancel" << endl;
                cin >> search_term;

                // Cancel operation
                if (search_term == "-")
                {
                    system("cls");
                    break;
                }

                for (i = 0; i < 100; i++)
                    if (person[i].Search(search_term))
                    {

                    }
                    else if (person[i].fName == "")
                    {
                      flag = 1;
                      break;
                    }
                if (!flag)
                    cout << "Contact name not found!" << endl;
            } while (!flag);
            break;

        // Show all the contacts
        case 5:
            cout << "Showing Contacts" << endl;
            printline('-', 25);
            for (i = 0; i < 100; i++)
                if (person[i].showAll())
                    flag = 1;
                    cout << "\n\n";

            if (!flag)
                cout << "No contacts found!" << endl;
            break;

        case 6:

        ofstream outfile("Phonebook.txt");

            for (int i = 0; i < 100; i++)
            {
                if (person[i].fName != "")
                {
                  outfile << "Name: " << person[i].fName << " " << person[i].lName
                  << "\n" << "Cellnumber: " << person[i].cellNumber << "\n"
                  << "Adress: " << person[i].street << "," << person[i].zipCode
                  << " " << person[i].city << "\n" << "Email: "
                  << person[i].email << "\n" << "Birthday: " << person[i].birthday
                  << "\n" << "Comment: " << person[i].comment << "\n\n";
                }
            }

            outfile.close();
            break;
        }

    } while (1);
    return 0;
}


//prints a line
void printline(char ch, int size)
{
    for (int i = 0; i < size; i++)
        cout << ch;
    cout << "\n";
}


//Contact name validation
bool is_valid(string Fname, string Lname, string Cellnumber)
{
    if (Fname.size() > 20 || Lname.size() > 20)
    {
        cout << "Invalid name!\nEnter a name within 20 characters!" << endl;
        return 0;
    }
    else if (Fname == "")
    {
        cout << "Invalid Name!\nName cannot be blank" << endl;
        return 0;
    }
    else
    {
        return 1;
    }

}
