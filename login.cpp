#include <iostream>
#include <string>
using namespace std;

int main()
{
    string username, password,confirm;
    int choice;
    int phone;
    string email;

    string correctAdminUsername = "admin@143";
    string correctAdminPassword = "adminlogins@123";

    
    string correctStudentUsername = "student@143";
    string correctStudentPassword = "student123";

    cout << "====================================\n";
    cout << "   UNIVERSITY COURSE REGISTRATION   \n";
    cout << "====================================\n\n";

    cout << "1. View Courses" << endl;
    cout << "2. Student Login" << endl;
    cout << "3. Admin Login" << endl;
    cout << "4. Exit" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    // Main menu
    if (choice == 1)
    {
        cout << "\n========== AVAILABLE COURSES ==========\n";

        cout << "1. C Programming" << endl;
        cout << "2. Mathematics" << endl;
        cout << "3. Fundamentals of IT" << endl;
        cout << "4. Technical Communication" << endl;
        cout << "5. Society and Ethics in IT" << endl;
    }

    else if (choice == 2)
    {
        cout << "\n========== STUDENT LOGIN ==========\n";

        cout << "Enter Username: ";
        cin >> username;
        cin.ignore();
        cout << "Enter email: ";
        cin >> email;
        cin.ignore();
        cout<<" Enter Phone no: "<<endl;
        cin>> phone;
        cin.ignore();
        cout<<" Enter Password:  "<<endl;
        cin>>password;
        if (username == correctStudentUsername &&
            password == correctStudentPassword)
        {
            cout << "\nLogin Successful!\n";
            cout << "Welcome, Student!\n";

            cout << "\n========== STUDENT MENU ==========\n";
            cout << "1. View Profile" << endl;
            cout << "2. View Courses" << endl;
            cout << "3. Enroll in Course" << endl;
            cout << "4. View My Courses" << endl;
            cout << "5. Logout" << endl;
        }
        else
        {
            cout << "\nInvalid Username or Password!\n";
        }
    }

    else if (choice == 3)
    {
        cout << "\n========== ADMIN LOGIN ==========\n";

        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        if (username == correctAdminUsername &&
            password == correctAdminPassword)
        {
            cout << "\nLogin Successful!\n";
            cout << "Welcome, Admin!\n";

            cout << "\n========== ADMIN MENU ==========\n";
            cout << "1. Manage Students" << endl;
            cout << "2. Manage Courses" << endl;
            cout << "3. Manage Faculty" << endl;
            cout << "4. View Enrollments" << endl;
            cout << "5. Generate Reports" << endl;
            cout << "6. Logout" << endl;
        }
        else
        {
            cout << "\nInvalid Username or Password!\n";
        }
    }

    else if (choice == 4)
    {
        cout << "\nThank you for using the system!\n";
    }

    else
    {
        cout << "\nInvalid choice! Please select 1-4.\n";
    }

    return 0;
}