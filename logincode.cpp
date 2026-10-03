#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function declarations
void viewCourse();
void stdLogin();
void adminLogin();
void signUp();
bool login();


// ======================================================
// CENTER TEXT FUNCTION
// ======================================================

void centerText(string text)
{
    const int WIDTH = 70;

    int spaces = (WIDTH - text.length()) / 2;

    if (spaces < 0)
        spaces = 0;

    cout << string(spaces, ' ') << text << endl;
}


// ======================================================
// LINE FUNCTION
// ======================================================

void line()
{
    cout << "\t\t===================================================================" << endl;
}


// ======================================================
// VIEW COURSES
// ======================================================

void viewCourse()
{
    int c;

    while (true)
    {
        cout << endl;
        line();
        centerText("AVAILABLE FACULTY");
        line();

        cout << endl;
        cout << "\t\t\t1. Information Technology";
        cout << "\n\t\t\t2. Engineering";
        cout << "\n\t\t\t3. Business";
        cout << "\n\t\t\t4. Medicine";
        cout << "\n\t\t\t5. Exit" << endl;

        cout << "\n\t\tEnter your choice: ";
        cin >> c;

        switch (c)
        {
            case 1:
                cout << endl;
                line();
                centerText("AVAILABLE COURSES OF INFORMATION TECHNOLOGY");
                line();

                cout << endl;
                cout << "\t\t\t1. Bachelor of Information Technology";
                cout << "\n\t\t\t2. Bachelor of Computer Science";
                cout << "\n\t\t\t3. Bachelor of Computer Application" << endl;

                cout << "\n\t\tPress Enter to go back...";
                cin.ignore();
                cin.get();

                break;


            case 2:
                cout << endl;
                line();
                centerText("AVAILABLE COURSES OF ENGINEERING");
                line();

                cout << endl;
                cout << "\t\t\t1. Civil Engineering";
                cout << "\n\t\t\t2. Electrical Engineering";
                cout << "\n\t\t\t3. Mechanical Engineering" << endl;

                cout << "\n\t\tPress Enter to go back...";
                cin.ignore();
                cin.get();

                break;


            case 3:
                cout << endl;
                line();
                centerText("AVAILABLE COURSES OF BUSINESS");
                line();

                cout << endl;
                cout << "\t\t\t1. Bachelor of Business Administration";
                cout << "\n\t\t\t2. Bachelor of Business Studies";
                cout << "\n\t\t\t3. Bachelor of Business Management" << endl;

                cout << "\n\t\tPress Enter to go back...";
                cin.ignore();
                cin.get();

                break;


            case 4:
                cout << endl;
                line();
                centerText("AVAILABLE COURSES OF MEDICINE");
                line();

                cout << endl;
                cout << "\t\t\t1. Bachelor of Medicine and Bachelor of Surgery";
                cout << "\n\t\t\t2. Bachelor of Dental Surgery";
                cout << "\n\t\t\t3. Bachelor of Science in Nursing" << endl;

                cout << "\n\t\tPress Enter to go back...";
                cin.ignore();
                cin.get();

                break;


            case 5:
                cout << endl;
                centerText("Returning to main menu...");
                return;


            default:
                cout << endl;
                centerText("Invalid choice. Please try again.");
        }
    }
}


// ======================================================
// STUDENT SIGNUP
// ======================================================

void signUp()
{
    string username;
    string password;

    cout << endl;
    line();
    centerText("STUDENT SIGNUP");
    line();

    cout << "\n\t\tCreate Username: ";
    cin >> username;

    cout << "\t\tCreate Password: ";
    cin >> password;

    // Save username and password to file
    ofstream file("students.txt", ios::app);

    if (file.is_open())
    {
        file << username << " " << password << endl;
        file.close();

        cout << endl;
        centerText("Signup successful!");
        centerText("You can now login.");
    }
    else
    {
        cout << endl;
        centerText("Error opening file!");
    }
}


// ======================================================
// STUDENT LOGIN
// ======================================================

bool login()
{
    string username;
    string password;

    string savedUsername;
    string savedPassword;

    cout << endl;
    line();
    centerText("STUDENT LOGIN");
    line();

    cout << "\n\t\tUsername: ";
    cin >> username;

    cout << "\t\tPassword: ";
    cin >> password;

    ifstream file("students.txt");

    if (!file.is_open())
    {
        cout << endl;
        centerText("No student account found.");
        centerText("Please signup first.");

        return false;
    }

    while (file >> savedUsername >> savedPassword)
    {
        if (username == savedUsername &&
            password == savedPassword)
        {
            file.close();

            cout << endl;
            centerText("Login Successful!");

            cout << "\t\tWelcome, " << username << "!" << endl;

            return true;
        }
    }

    file.close();

    cout << endl;
    centerText("Invalid Username or Password!");

    return false;
}


// ======================================================
// STUDENT MENU
// ======================================================

void stdLogin()
{
    int s;

    while (true)
    {
        cout << endl;
        line();
        centerText("STUDENT PORTAL");
        line();

        cout << endl;
        cout << "\t\t\t1. Signup";
        cout << "\n\t\t\t2. Login";
        cout << "\n\t\t\t3. Exit" << endl;

        cout << "\n\t\tEnter your choice: ";
        cin >> s;

        switch (s)
        {
            case 1:
                signUp();
                break;


            case 2:
                if (login())
                {
                    cout << endl;
                    centerText("Student dashboard will be added here.");
                }

                break;


            case 3:
                cout << endl;
                centerText("Returning to main menu...");
                return;


            default:
                cout << endl;
                centerText("Invalid choice. Try again!");
        }
    }
}


// ======================================================
// ADMIN LOGIN
// ======================================================

void adminLogin()
{
    string username;
    string password;

    string correctUsername = "admin@143";
    string correctPassword = "adminlogins@123";

    cout << endl;
    line();
    centerText("ADMIN LOGIN");
    line();

    cout << "\n\t\tUsername: ";
    cin >> username;

    cout << "\t\tPassword: ";
    cin >> password;

    if (username == correctUsername &&
        password == correctPassword)
    {
        cout << endl;
        centerText("Login Successful!");
        centerText("Welcome, Admin!");

        cout << endl;
        line();
        centerText("ADMIN MENU");
        line();

        cout << endl;
        cout << "\t\t\t1. Manage Students";
        cout << "\n\t\t\t2. Manage Courses";
        cout << "\n\t\t\t3. Manage Faculty";
        cout << "\n\t\t\t4. View Enrollments";
        cout << "\n\t\t\t5. Logout" << endl;
    }
    else
    {
        cout << endl;
        centerText("Invalid Username or Password!");
    }
}


// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    int choice;
    int count = 0;
    int attempts = 3;

    while (count < 3)
    {
        cout << endl;
        line();
        centerText("UNIVERSITY COURSE REGISTRATION SYSTEM");
        line();

        cout << endl;
        cout << "\t\t\t1. View Course";
        cout << "\n\t\t\t2. Student Login";
        cout << "\n\t\t\t3. Admin Login";
        cout << "\n\t\t\t4. Exit" << endl;

        cout << "\n\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                viewCourse();
                break;


            case 2:
                stdLogin();
                break;


            case 3:
                adminLogin();
                break;


            case 4:
                cout << endl;
                centerText("Thank you for using the system!");
                return 0;


            default:
                count++;

                cout << "\n\t\tAttempts left: " << attempts - 1 << endl;
                centerText("Invalid choice. Please try again.");

                attempts--;
                cout<<" \n";
        }
    }

    cout << endl;
    centerText("Program exiting due to invalid attempts.");
    centerText("Please reopen the program.");

    return 0;
}