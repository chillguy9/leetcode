#include <iostream>
#include <string>
using namespace std;

class Course; // Forward declaration

class Student {
public:
    int id;
    string name;
    Student* next;
    Course* courseList;

    Student(int id, string name) {
        this->id = id;
        this->name = name;
        this->next = nullptr;
        this->courseList = nullptr;
    }
};

class Course {
public:
    int id;
    string name;
    Course* next;
    Student* studentList;

    Course(int id, string name) {
        this->id = id;
        this->name = name;
        this->next = nullptr;
        this->studentList = nullptr;
    }
};

class EnrollmentSystem {
private:
    Student* studentHead;
    Course* courseHead;

public:
    EnrollmentSystem() {
        studentHead = nullptr;
        courseHead = nullptr;
    }

    void addStudent(int id, string name) {
        Student* newStudent = new Student(id, name);
        if (!studentHead)
            studentHead = newStudent;
        else {
            Student* temp = studentHead;
            while (temp->next)
                temp = temp->next;
            temp->next = newStudent;
        }
        cout << "Student added successfully.\n";
    }

    void addCourse(int id, string name) {
        Course* newCourse = new Course(id, name);
        if (!courseHead)
            courseHead = newCourse;
        else {
            Course* temp = courseHead;
            while (temp->next)
                temp = temp->next;
            temp->next = newCourse;
        }
        cout << "Course added successfully.\n";
    }

    Student* findStudent(int id) {
        Student* temp = studentHead;
        while (temp) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    Course* findCourse(int id) {
        Course* temp = courseHead;
        while (temp) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void enrollStudent(int sid, int cid) {
        Student* s = findStudent(sid);
        Course* c = findCourse(cid);

        if (!s || !c) {
            cout << "Invalid Student ID or Course ID.\n";
            return;
        }

        Course* newCourse = new Course(c->id, c->name);
        newCourse->next = s->courseList;
        s->courseList = newCourse;

        Student* newStudent = new Student(s->id, s->name);
        newStudent->next = c->studentList;
        c->studentList = newStudent;

        cout << "Student enrolled successfully!\n";
    }

    void displayStudents() {
        cout << "\n--- Student List ---\n";
        Student* temp = studentHead;
        while (temp) {
            cout << "ID: " << temp->id << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void displayCourses() {
        cout << "\n--- Course List ---\n";
        Course* temp = courseHead;
        while (temp) {
            cout << "ID: " << temp->id << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void displayStudentCourses(int sid) {
        Student* s = findStudent(sid);
        if (!s) {
            cout << "Student not found.\n";
            return;
        }
        cout << "\nCourses of " << s->name << ":\n";
        Course* c = s->courseList;
        while (c) {
            cout << "- " << c->name << endl;
            c = c->next;
        }
    }

    void displayCourseStudents(int cid) {
        Course* c = findCourse(cid);
        if (!c) {
            cout << "Course not found.\n";
            return;
        }
        cout << "\nStudents enrolled in " << c->name << ":\n";
        Student* s = c->studentList;
        while (s) {
            cout << "- " << s->name << endl;
            s = s->next;
        }
    }
};

int main() {
    EnrollmentSystem system;
    int choice, sid, cid;
    string name;

    do {
        cout << "\n====== Course Enrollment System ======\n";
        cout << "1. Add Student\n2. Add Course\n3. Enroll Student\n";
        cout << "4. Display All Students\n5. Display All Courses\n";
        cout << "6. Display Student's Courses\n7. Display Course's Students\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Student ID: "; cin >> sid;
            cout << "Enter Student Name: "; cin >> name;
            system.addStudent(sid, name);
            break;
        case 2:
            cout << "Enter Course ID: "; cin >> cid;
            cout << "Enter Course Name: "; cin >> name;
            system.addCourse(cid, name);
            break;
        case 3:
            cout << "Enter Student ID: "; cin >> sid;
            cout << "Enter Course ID: "; cin >> cid;
            system.enrollStudent(sid, cid);
            break;
        case 4:
            system.displayStudents();
            break;
        case 5:
            system.displayCourses();
            break;
        case 6:
            cout << "Enter Student ID: "; cin >> sid;
            system.displayStudentCourses(sid);
            break;
        case 7:
            cout << "Enter Course ID: "; cin >> cid;
            system.displayCourseStudents(cid);
            break;
        case 8:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}