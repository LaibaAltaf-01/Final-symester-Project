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

// Admin credentials
string adminUsername = "laiba";
string adminPassword = "laiba123";
bool isAdminLoggedIn = false;

// Function to check admin login
bool adminLogin() {
    string username, password;

    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username == adminUsername && password == adminPassword) {
        cout << "\nLogin successful!" << endl;
        return true;
    } else {
        cout << "\nInvalid username or password. Please try again." << endl;
        return false;
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


// Function to delete a book
void deleteBooks() {
    int bookId;
    cout << "Enter book ID to delete: ";
    cin >> bookId;

    if (bookId < 1 || bookId > bookCount) {
        cout << "Invalid book ID!" << endl;
        return;
    }

    // Shift books after the deleted book one position left
    for (int i = bookId - 1; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
        authors[i] = authors[i + 1];  // Shift the author array
        publishDates[i] = publishDates[i + 1];  // Shift the publish date array
        issuedBooks[i] = issuedBooks[i + 1];
    }
    bookCount--;  // Decrease the number of books
    cout << "Book deleted successfully!" << endl;
}

void viewBooks() {
    if (bookCount == 0) {
        cout << "No books available!" << endl;
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        cout << "Book " << i + 1 << ": " << books[i] << endl;
        cout << "Author: " << authors[i] << endl;
        cout << "Published Date: " << publishDates[i] << endl;
        cout << "Status: " << (issuedBooks[i] == 1 ? "Issued" : "Available") << endl;
        cout << "-----------------------------------" << endl;
    }
}


void editBooks() {
    int bookId;
    cout << "Enter book ID to edit: ";
    cin >> bookId;

    if (bookId < 1 || bookId > bookCount) {
        cout << "Invalid book ID!" << endl;
        return;
    }

    string newBookName, newAuthor, newPublishDate;
    cout << "Enter new book name: ";
    cin.ignore();
    getline(cin, newBookName);

    cout << "Enter new author name: ";
    getline(cin, newAuthor);

    cout << "Enter new published date (YYYY-MM-DD): ";
    getline(cin, newPublishDate);

    // Update book details
    books[bookId - 1] = newBookName;
    authors[bookId - 1] = newAuthor;
    publishDates[bookId - 1] = newPublishDate;

    cout << "Book details updated successfully!" << endl;
}

void searchBookByTitle() {
    string title;
    cout << "Enter book title to search: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i] == title) {
            cout << "Book found!" << endl;
            cout << "Book ID: " << i + 1 << endl;
            cout << "Title: " << books[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Published Date: " << publishDates[i] << endl;
            cout << "Status: " << (issuedBooks[i] == 1 ? "Issued" : "Available") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

// Function to borrow a book
void borrowBook() {
    int bookId;
    cout << "Enter book ID to borrow: ";
    cin >> bookId;

    if (bookId < 1 || bookId > bookCount) {
        cout << "Invalid book ID!" << endl;
        return;
    }

    if (issuedBooks[bookId - 1] == 1) {
        cout << "Book is already borrowed!" << endl;
    } else {
        issuedBooks[bookId - 1] = 1;  // Mark the book as issued
        cout << "Book borrowed successfully!" << endl;
    }
}

// Function to return a borrowed book
void returnBook() {
    int bookId;
    cout << "Enter book ID to return: ";
    cin >> bookId;

    if (bookId < 1 || bookId > bookCount) {
        cout << "Invalid book ID!" << endl;
        return;
    }

    if (issuedBooks[bookId - 1] == 0) {
        cout << "This book was not borrowed!" << endl;
    } else {
        issuedBooks[bookId - 1] = 0;  // Mark the book as available
        cout << "Book returned successfully!" << endl;
    }
}

// Function to view borrowed books
void viewBorrowedBooks() {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (issuedBooks[i] == 1) {  // Check if the book is issued
            cout << "Book " << i + 1 << ": " << books[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Published Date: " << publishDates[i] << endl;
            cout << "Status: " << (issuedBooks[i] == 1 ? "Issued" : "Available") << endl;
            cout << "-----------------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No borrowed books found!" << endl;
    }
}

// Function to add a student
void addStudent() {
    string studentName, sapId, department;

    cout << "\nEnter student SAP ID: ";
    cin.ignore();  // To clear any leftover input buffer
    getline(cin, sapId);  // Read SAP ID
    
    cout << "Enter student name: ";
    getline(cin, studentName);  // Read student name

    cout << "Enter student department: ";
    getline(cin, department);  // Read student department

    if (studentCount < MAX_STUDENTS) {
        // Store the student details
        studentSAP[studentCount] = sapId;
        students[studentCount] = studentName;
        studentDepartment[studentCount] = department;
        studentCount++;  // Increment the student count
        
        cout << "Student added successfully!" << endl;
    } else {
        cout << "Student list is full!" << endl;
    }
    
}

// Function to view all students
void viewStudents() {
    if (studentCount == 0) {
        cout << "No students found!" << endl;
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "SAP ID: " << studentSAP[i] << endl;
        cout << "Name: " << students[i] << endl;
        cout << "Department: " << studentDepartment[i] << endl;
        cout << "-----------------------------------" << endl;
    }
}

// Function to edit student information
void editStudent() {
    string sapId;
    cout << "Enter SAP ID of the student to edit: ";
    cin.ignore();
    getline(cin, sapId);  // Get the SAP ID to search for

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (studentSAP[i] == sapId) {
            found = true;
            string newName, newDepartment;
            
            cout << "Student found! Enter new details:" << endl;
            
            cout << "Enter new name: ";
            getline(cin, newName);
            students[i] = newName;  // Update name
            
            cout << "Enter new department: ";
            getline(cin, newDepartment);
            studentDepartment[i] = newDepartment;  // Update department
            
            cout << "Student details updated successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with SAP ID " << sapId << " not found!" << endl;
    }
}

// Function to delete a student
void deleteStudent() {
    string sapId;
    cout << "Enter SAP ID of the student to delete: ";
    cin.ignore();
    getline(cin, sapId);  // Get the SAP ID to search for

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (studentSAP[i] == sapId) {
            found = true;
            
            // Shift all subsequent students one position left
            for (int j = i; j < studentCount - 1; j++) {
                studentSAP[j] = studentSAP[j + 1];
                students[j] = students[j + 1];
                studentDepartment[j] = studentDepartment[j + 1];
            }
            studentCount--;  // Decrease student count
            cout << "Student deleted successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with SAP ID " << sapId << " not found!" << endl;
    }
}

// Function to search student by SAP ID
void searchStudentBySAP() {
    string sapId;
    cout << "Enter SAP ID to search: ";
    cin.ignore();
    getline(cin, sapId);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (studentSAP[i] == sapId) {
            cout << "Student found!" << endl;
            cout << "SAP ID: " << studentSAP[i] << endl;
            cout << "Name: " << students[i] << endl;
            cout << "Department: " << studentDepartment[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with SAP ID " << sapId << " not found!" << endl;
    }
}



// Admin menu display
void displayAdminMenu() {
                cout << " -------------------------------- "<< endl;
                cout << "|                                |"<< endl;
                cout << "|        Admin Panel             |"<< endl;
                cout << "|                                |"<< endl;
                cout << " -------------------------------- "<< endl;
                cout << " 1. Manage Books                       " << endl;
                cout << " 2. Manage Student                     " << endl;
                cout << " 3. Logout                             " << endl;
                cout << "----------------------------------" << endl;
                cout << "Enter your choice (0-3): ";
}

// Manage Books menu
void manageBooksMenu() {
    int choice;
    cout << "\n-------------- Manage Books ---------------" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Delete Book" << endl;
    cout << "3. View All Books" << endl;
    cout << "4. Edit Book Details" << endl;
    cout << "5. Search Book by Title" << endl;
    cout << "6. View Borrowed Books" << endl;
    cout << "7. Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addBooks();
            break;
        case 2:
            deleteBooks();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            editBooks();
            break;
        case 5:
            searchBookByTitle();
            break;
        case 6:
            viewBorrowedBooks();
            break;
        case 7:
            return;  // Go back to the Admin menu
        default:
            cout << "Invalid choice!" << endl;
    }
}

// Manage Students menu
void manageStudentsMenu() {
    int choice;
    cout << "\n---------------- Manage Students ---------------" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. View Students" << endl;
    cout << "3. Edit Students" << endl;
    cout << "4. Delete Students" << endl;
    cout << "5. Search Students By SapID" << endl;
    cout << "6. Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
            case 3:
            editStudent();
            break;
            case 4:
            deleteStudent();
            break;
            case 5:
           searchStudentBySAP();
            break;
        case 6:
            return;  // Go back to the Admin menu
        default:
            cout << "Invalid choice!" << endl;
    }
}



// Main function to run the system
int main() {
	 system("color B0");
	 int choice;
bool isAdminLoggedIn = false;  // Track if admin is logged i
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
                // Admin Panel login
                if (!isAdminLoggedIn) {
                    bool loggedIn = false;
                    while (!loggedIn) {
                        loggedIn = adminLogin();  // Only ask for login if not logged in
                    }
                    isAdminLoggedIn = true;  // Set the admin logged in flag
                }
               
                // After successful login, show Admin menu
                int adminChoice;
                while (isAdminLoggedIn) { 
                displayAdminMenu();
                cin >> adminChoice;

                switch (adminChoice) {
                    case 1:
                        manageBooksMenu();
                        break;
                    case 2:
                        // Manage Students Menu
                        manageStudentsMenu();
                        break;
                    case 3:
                    	cout << "Logging out..." << endl;
                            isAdminLoggedIn = false;  // Logout and go back to the main menu
                            break;
                    default:
                        cout << "Invalid choice!" << endl;
                }
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
                        viewBooks();
                        break;
                    case 2:
                        borrowBook();
                        break;
                    case 3:
                        returnBook();
                        break;
                    case 4:
                        searchBookByTitle();
                        break;
                        case 5:
                        viewBorrowedBooks();
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
