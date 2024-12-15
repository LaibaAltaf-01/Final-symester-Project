#include <iostream>
#include <string>
using namespace std;

// Global arrays to store data
const int MAX_BOOKS = 100;
const int MAX_STUDENTS = 100;
int bookCount = 0;  // Number of books
int studentCount = 0;  // Number of students
string books[MAX_BOOKS];
string authors[MAX_BOOKS];  // Array to store authors
string publishDates[MAX_BOOKS];  // Array to store publish dates
int issuedBooks[MAX_BOOKS]; // Array to track issued books
string students[MAX_STUDENTS];        // Array to store student names
string studentSAP[MAX_STUDENTS];      // Array to store student SAP IDs
string studentDepartment[MAX_STUDENTS]; // Array to store student departments

// Admin username and password
const string adminUsername = "admin";
const string adminPassword = "password";  // You can change this to any other password

// Function for admin login
bool adminLogin() {
    string username, password;
    cout << "Enter Admin Username: ";
    cin >> username;
    cout << "Enter Admin Password: ";
    cin >> password;

    // Check if the entered username and password match the correct ones
    if (username == adminUsername && password == adminPassword) {
        return true;  // Login successful
    } else {
        cout << "Invalid username or password!" << endl;
        return false;  // Login failed
    }
}

// Function to add a book
void addBooks() {
    string bookName, authorName, publishDate;
    int bookId = bookCount + 1;  // The ID will be assigned as the next available ID

    cout << "\n------------ Add books -------------" << endl;
    cout << "Enter book name to be added: ";
    cin.ignore();  // Clears the input buffer
    getline(cin, bookName);

    cout << "Enter author name: ";
    getline(cin, authorName);

    cout << "Enter published date (e.g., YYYY-MM-DD): ";
    getline(cin, publishDate);

    if (bookCount < MAX_BOOKS) {
        books[bookCount] = bookName;
        authors[bookCount] = authorName;
        publishDates[bookCount] = publishDate;
        issuedBooks[bookCount] = 0;  // Initially, the book is not issued
        
        cout << "\nBook added successfully!" << endl;
        cout << "Book ID: " << bookId << endl;
        cout << "Book Name: " << bookName << endl;
        cout << "Author: " << authorName << endl;
        cout << "Published Date: " << publishDate << endl;
        
        bookCount++;
    } else {
        cout << "Library is full, can't add more books!" << endl;
    }
}
bool adminLogin() {
    string storedUsername = "admin"; // Predefined username
    string storedPassword = "password123"; // Predefined password

    string username, password;

    cout << "\n======= Admin Login =======\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == storedUsername && password == storedPassword) {
        cout << "\nLogin successful! Welcome, Admin.\n";
        return true;
    } else {
        cout << "\nInvalid credentials. Access denied.\n";
        return false;
    }
}


// Function to display the Admin menu
void displayAdminMenu() {
    cout << " -------------------------------- "<< endl;
    cout << "|                                |"<< endl;
    cout << "|        Admin Panel             |"<< endl;
    cout << "|                                |"<< endl;
    cout << " -------------------------------- "<< endl;
    cout << " 1. Manage Books                       " << endl;
    cout << " 2. Manage Students                    " << endl;
    cout << " 3. Back                               " << endl;
    cout << "----------------------------------" << endl;
    cout << "Enter your choice (0-3): ";
}

// Main function to run the system
int main() {
    system("color A");
    int choice;
    while (true) {
        cout << "***************************************" << endl;
        cout << "*                                     *" << endl;
        cout << "*      Library Management System      *" << endl;
        cout << "*                                     *" << endl;
        cout << "***************************************" << endl;
        cout << " 1. Admin Panel                    " << endl;
        cout << " 2. Student Panel                  " << endl;
        cout << " 3. Exit                           " << endl;
        cout << "*************************************" << endl;
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Admin Panel - Check login first
                bool loggedIn = adminLogin(); // Ask for login credentials
                if (loggedIn) {
                    // After successful login, show the Admin Menu
                    int adminChoice;
                    displayAdminMenu();
                    cin >> adminChoice;

                    switch (adminChoice) {
                        case 1:
                            // Manage Books menu
                            cout << "Managing Books..." << endl;
                            break;
                        case 2:
                            // Manage Students menu
                            cout << "Managing Students..." << endl;
                            break;
                        case 3:
                            cout << "Exiting Admin Panel!" << endl;
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                } else {
                    cout << "Failed to login. Exiting to main menu!" << endl;
                }
                break;
            }
            case 2: {
                // Student Panel
                int studentChoice;
                cout << " -------------------------------- "<< endl;
                cout << "|                                |"<< endl;
                cout << "|        Student Panel           |"<< endl;
                cout << "|                                |"<< endl;
                cout << " -------------------------------- "<< endl;
                cout << "1. VIEW Book"   << endl;
                cout << "2. Borrow Book" << endl;
                cout << "3. Return Book" << endl;
                cout << "4. Search Book By Title" << endl;
                cout << "5. View borrowed Books" << endl;
                cout << "0. Back" << endl;
                cout << "Enter your choice: ";
                cin >> studentChoice;

                switch (studentChoice) {
                    case 1:
                        cout << "Viewing Books..." << endl;
                        break;
                    case 2:
                        cout << "Borrowing Book..." << endl;
                        break;
                    case 3:
                        cout << "Returning Book..." << endl;
                        break;
                    case 4:
                        cout << "Searching Book by Title..." << endl;
                        break;
                    case 5:
                        cout << "Viewing Borrowed Books..." << endl;
                        break;
                    case 0:
                        cout << "Exiting Student Panel!" << endl;
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting system..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}