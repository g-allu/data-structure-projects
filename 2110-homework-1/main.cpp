#include <iostream>

#include "Container1.hpp"
#include "Container2.hpp"
#include "Container3.hpp"

using namespace std;

Client createClient()
{
    string name, dob;
    char gender;
    int age, familyMembers;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter Gender (M/F): ";
    cin >> gender;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Number of Family Members: ";
    cin >> familyMembers;
    cout << "Enter DOB (MM-DD-YYYY): ";
    cin >> dob;

    return Client(name, gender, age, familyMembers, dob);
}

void printClient(Node *n)
{
    if (n != nullptr)
    {
        cout << "\nClient Found\n";
        cout << "Name: " << n->getClient().getName() << "\n";
        cout << "Age: " << n->getClient().getAge() << "\n";
        cout << "Gender: " << n->getClient().getGender() << "\n";
        cout << "--------------------\n\n";
    }
    else
    {
        cout << "\n!!!!!!!Client not found or list is empty.!!!!!!!!!\n\n";
    }
}

int main()
{

    int manager;

    cout << "Which Manager is using the System?" << endl;

    cout << "Enter 1 Manager 1 (Linked List)" << endl;

    cout << "Enter 2 Manager 2 (Stack)" << endl;

    cout << "Enter 3 Manager 3 (Queue)" << endl;

    cin >> manager;

    if (manager == 1)
    {
        Container1 list;
        int input = -1;

        while (input != 0)
        {
            cout << "\n\nEnter corresponding number for output: " << endl;
            cout << "1. Add Client to Beginning: " << endl;
            cout << "2. Add Client to End: " << endl;
            cout << "3. Add Client after a client with a specific Name: " << endl;
            cout << "4. Add Client after a client with a specific Age: " << endl;
            cout << "5. Add Client after a client with a specific Gender: " << endl;
            cout << "6. Get Info Of first client: " << endl;
            cout << "7. Get Info Of Last client: " << endl;
            cout << "8. Get Info Of first client: " << endl;
            cout << "9. Get Info Of Client with a specific Name: " << endl;
            cout << "9. Get Info Of Client with a specific Age: " << endl;
            cout << "10. Get Info Of Client with a specific Gender: " << endl;
            cout << "0. To Exit: \n";

            cin >> input;

            if (input == 1)
            {
                list.insertAtBeginning(createClient());
            }

            else if (input == 2)
            {
                list.insertAtEnd(createClient());
            }

            else if (input == 3)
            {
                string name;
                cout << "Enter Name of Client: \n";
                cin.ignore();
                getline(cin, name);
                if (list.insertAfterName(name, createClient()))
                {
                    cout << "Inserted After " << name << endl;
                }

                else cout << name << "Not Found\n";
            }

            else if (input == 4)
            {
                int age;
                cout << "Enter Age of Client: \n";
                cin >> age;
                if (list.insertAfterAge(age, createClient()))
                {
                    cout << "Inserted After client with age " << age << endl;
                }
                else
                {
                    cout << "Age " << age << " Not Found\n";
                }
            }
            else if (input == 5)
            {
                char gender;
                cout << "Enter Gender of Client (M/F): \n";
                cin >> gender;
                if (list.insertAfterGender(gender, createClient()))
                {
                    cout << "Inserted After client with gender " << gender << endl;
                }
                else
                {
                    cout << "Gender " << gender << " Not Found\n";
                }
            }

            else if (input == 6)
            {
                Node *first = list.getFirst();
                printClient(first);
            }

            else if (input == 7)
            {
                Node *last = list.getLast();
                printClient(last);
            }

            else if (input == 8)
            {
                string name;
                cout << "Enter Name to search: \n";
                cin.ignore();
                getline(cin, name);
                printClient(list.getByName(name));
            }
            else if (input == 9)
            {
                int age;
                cout << "Enter Age to search: \n";
                cin >> age;
                printClient(list.getByAge(age));
            }

            else if (input == 10)
            {
                char gender;
                cout << "Enter gender (M/F) to search: \n";
                cin >> gender;
                printClient(list.getByGender(gender));
            }
        }
    }

    if (manager == 2)
    {
        Container2 stack;

        int input = -1;

        while (input != 0)
        {
            cout << "\n\nEnter corresponding number for output: " << endl;
            cout << "1. Add to top" << endl;
            cout << "2. Remove and view top" << endl;
            cout << "0. to exit" << endl;
            cin >> input;

            if(input ==1){
                stack.insertToStack(createClient());
            }

            else if(input ==2){
                Node* recent = stack.getTop();
                printClient(recent);
                delete recent;
            }
        }
    }


    if(manager ==3){
        Container3 queue;

        int input = -1;

        while (input != 0)
        {
            cout << "\n\nEnter corresponding number for output: " << endl;
            cout<<"1. Add to back\n";
            cout<<"2. Remove and view Front\n";
            cout<<"0. to exit\n";

            cin >> input;

            if(input ==1){
                queue.insertToQueue(createClient());
            }

            else if(input ==2){
                Node* oldest = queue.getOldest();
                printClient(oldest);
                delete oldest;
            }
        }
        
    }

    return 0;
}