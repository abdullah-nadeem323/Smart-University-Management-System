#include <iostream>
using namespace std;

class User {
protected:
    string name;
    int id;
public:
    User(string n, int i) : name(n), id(i) {
        cout << "[User Constructor] Called for: " << name << " (ID: " << id << ")" << endl;
    }

    void login() {
        cout << "== Welcome to the Smart Management System ==" << endl;
    }

    void logOut() {
        cout << "== Thank you for using the Smart Management System ==" << endl;
    }

    ~User() {
        cout << "[User Destructor] Called for: " << name << " (ID: " << id << ")" << endl;
    }
};

class student : public User {
public:
    string courseName;
    student(string n, int i, string c) : User(n, i), courseName(c) {
        cout << "[Student Constructor] Called for: " << name << endl;
    }

    void courseRegister() {
        login();
        cout << courseName << " course registered against ID: " << id << endl;
        logOut();
    }

    ~student() {
        cout << "[Student Destructor] Called for: " << name << endl;
    }
};

class Teacher : public User {
public:
    Teacher(string n, int i) : User(n, i) {
        cout << "[Teacher Constructor] Called for: " << name << endl;
    }

    void uploadMarks() {
        login();
        cout << "Teacher " << name << " uploading marks for students" << endl;
        logOut();
    }

    ~Teacher() {
        cout << "[Teacher Destructor] Called for: " << name << endl;
    }
};

class Admin : public User {
public:
    Admin(string n, int i) : User(n, i) {
        cout << "[Admin Constructor] Called for: " << name << endl;
    }

    void manageSystem() {
        login();
        cout << "[Admin] Name: " << name << "\n[Admin] ID: " << id << endl;
        cout << "System management assigned successfully" << endl;
        logOut();
    }

    ~Admin() {
        cout << "[Admin Destructor] Called for: " << name << endl;
    }
};

int main() {
    cout << "---- Creating Student Object ----" << endl;
    student s1("Abdullah", 101, "English");
    s1.courseRegister();

    cout << "\n---- Creating Teacher Object ----" << endl;
    Teacher t1("Ali", 201);
    t1.uploadMarks();

    cout << "\n---- Creating Admin Object ----" << endl;
    Admin a1("Sara", 301);
    a1.manageSystem();

    cout << "\n---- End of Program ----" << endl;
    return 0;
}
