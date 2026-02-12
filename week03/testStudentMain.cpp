#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h" 
#include "Student.h"

TEST_CASE("Student #1") {
    Student* student = new Student();
    student->setName("Bradford");
    student->midterm = 99;
    student->final = 100;
    student->next = NULL;

    CHECK(student->getName() == "Bradford");
    CHECK(student->midterm == 99);
    CHECK(student->final == 100);
    CHECK(student->next == NULL);    
    delete student;
}

TEST_CASE("Student #2") {
    Student* head = new Student();
    Student* follow = new Student();

    head->setName("First");
    follow->setName("Second");
        
    head->next = follow;
    follow->next = NULL;

    CHECK(head != NULL);
    if (head != NULL) { 
        CHECK(head->next == follow);
    }
    CHECK(follow->next == NULL);

    delete head;
    delete follow;
}

TEST_CASE("Student #3") {
    Student* student = new Student();
        
    CHECK(student->hw_grades.size() == 0);

    student->hw_grades.push_back(32);
    student->hw_grades.push_back(0);
    student->hw_grades.push_back(100);

    CHECK(student->hw_grades.size() == 3);
    CHECK(student->hw_grades[1] == 0);

    delete student;
}

TEST_CASE("Student #4") {
    Student* head = NULL;
    CHECK(head == NULL);
}
