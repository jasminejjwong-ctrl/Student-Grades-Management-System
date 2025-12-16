//
//  main.cpp
//  Student Grades Management FINAL
//
//  Created by Jasmine Wong on 4/26/25.
//

#include <iostream>
using namespace std;

const int multiple_students = 100; // user can input up to 100 students' data

int main() {
    char name[multiple_students][100]; // this array stores students' names stores students' names (100 characters max, which is more than enough for names)
    float exam[multiple_students]; // this array stores students' exam scores
    float assignment[multiple_students]; // this array stores students' assignment scores
    float project[multiple_students]; // this array stores students' project scores
    float average[multiple_students]; // this array stores students' final averages
    char letter[multiple_students]; // this array stores students' letter grades
    int student_count = 0; // initially, student count is set at 0 before user inputs any data
    int choice; // the choice that user inputs
   
    while (true) {
        cout << "\nStudent Score Menu\n"; // organized heading
        cout << "1. Enter student name and scores\n"; // user enters students' names and scores
        cout << "2. Calculate and display final grade and letter grade\n"; // when the user chooses option 2, it displays students' final grade and letter grade
        cout << "3. Display results for student\n"; // when user chooses 3, displays all data
        cout << "4. Exit\n"; // exit out of program
        cout << "Enter your option (1-4): "; // lets users choose option
        cin >> choice; // user's input choice
        cin.ignore(); // allows the next cin.getline() to work properly
        
        switch (choice) { // used for different menu options
            case 1: {
                if (student_count >= multiple_students) { // user won't be able to input more student info if it is above the max of 100
                    cout << "Error: The max input is 100 students.\n";
                    break;
                }
                cout << "Enter student's full name: ";
                cin.getline(name[student_count], 100); // gets the whole name
                
                cout << "Enter exam grade (0-100): ";
                cin >> exam[student_count];
                cout << "Enter assignment grade (0-100): ";
                cin >> assignment[student_count];
                cout << "Enter project grade (0-100): ";
                cin >> project[student_count];
                
                cin.ignore(); // this clears the input buffer
                student_count++; // this is +1 of the previous student count
                break;
            }
            case 2: {
                if (student_count == 0) { // if there were no students entered yet
                    cout << "Please enter student data first.\n";
                    break;
                }
                
                for (int i = 0; i < student_count; i++) { // this loops through each student
                    average[i] = (exam[i] * 0.4) + (assignment[i] * 0.4) + (project[i] * 0.2); // calculates weighted average
                    
                    if (average[i] >= 90) letter[i] = 'A'; // letter scale based off of number grade
                    else if (average[i] >= 80) letter[i] = 'B';
                    else if (average[i] >= 70) letter[i] = 'C';
                    else if (average[i] >= 60) letter[i] = 'D';
                    else letter[i] = 'F';
                }
                for (int i = 0; i < student_count; i++) {
                cout << "\nStudent Name: " << name[i] << endl;
                cout << "Final grade (average): " << average[i] << "%" << endl;
                cout << "Letter grade: " << letter[i] << endl;
            }
                break;
            }
            case 3: {
                if (student_count == 0) { // if no data was entered, then it tells the user
                    cout << "No student data entered yet.\n";
                    break;
                }
                cout << "\n--- Students' Data ---\n"; // organized way to show all data
                for (int i = 0; i < student_count; i++) {
                    cout << "\nStudent Number: " << (i+1) << endl;
                    cout << "Name: " << name[i] << endl;
                    cout << "Exam: " << exam[i] << "%" << endl;
                    cout << "Assignment: " << assignment[i] << "%" << endl;
                    cout << "Project: " << project[i] << "%" << endl;
                    cout << "Average: " << average[i] << "%" << endl;
                    cout << "Letter Grade: " << letter[i] << endl;
                }
                break;
            }
        
            case 4: {
        cout << "Exiting program.\n";
        return 0;
    }

            default: // if the user doesn't input a number from 1-4, then they would be asked to choose a valid option (1-4)
                cout << "Please choose a valid option (1-4).\n";
        break;
        }
    }
    return 0;
}
