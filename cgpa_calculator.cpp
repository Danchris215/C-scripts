//C++ program to act as a cgpa calculator 
#include <iostream>
//used in place of if..else block for efficient handling and to create key, value pairs
#include <map>
//this allows us to create strings
#include <string>
//this will allow us to create pairs that can store units and grades 
#include <vector>
#include <limits> //required for numeric lists. Helps in error handling 

using namespace std;

double getGradePoints(const string& grade){
    map<string, double> gradePoints;
    gradePoints["A"] = 5.0;
    gradePoints["B"] = 4.0;
    gradePoints["C"] = 3.0;
    gradePoints["D"] = 2.0;
    gradePoints["E"] = 1.0;
    gradePoints["F"] = 0.0;
    
    //handle invalid input 
    auto it = gradePoints.find(grade);
    if (it == gradePoints.end()){
        cout << "Invalid grade: " << grade << ".Please use standard letter grades (A, B, C, D, E, F)." << endl;
        
        return 0.0;
    }
    return it->second;
}
double getGradePointsFromScore(double score){
    if (score >= 70) return 5.0;
    else if (score >= 60) return 4.0;
    else if (score >= 50) return 3.0;
    else if (score >= 45) return 2.0;
    else if (score >= 40) return 1.0;
    else return 0.0;
    
}

int main(){
    int numCourses;
    int inputMethod;
    
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    
    while (cin.fail() ||numCourses <= 0){
        cout << "Invalid input. Please enter a positive integer for the number of courses: ";
        cin.clear();
        //max is needed so that the computer will ignore all the characters . the characters should be discarded up to and including the new line character.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> numCourses;
    }
    cout << "Choose input method:" << endl;
    cout << "1. Letter grades (A, B, C, etc.)" << endl;
    cout << "2. Numerical scores (e.g., 85, 72)" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> inputMethod;
    
    //input validation for input method 
    while (cin.fail() || (inputMethod != 1 && inputMethod != 2)){
        cout << "Invalid input. Please enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> inputMethod;
    }
 
    vector<pair<double, double>> courses(numCourses); //store units and grade points 
    for (int i = 0; i < numCourses; i++){
        cout << "Enter units for course " << i + 1 << ": ";
        cin >> courses[i].first;
        
        //Input validation for credits 
        while (cin.fail() || courses[i].first <= 0){
            cout << "Invalid input. Please enter a positive number for units: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> courses[i].first;
        }
        if (inputMethod == 1){
            string grade;
            cout << "Enter grade for course "<< i + 1 << "(e.g., A, B, C, etc): ";
            cin >> grade;
            courses[i].second = getGradePoints(grade);
        }else{
            double score;
            cout << "Enter score for course " << i + 1 << ": ";
            cin >> score;
        
        //input validation for score
        while(cin.fail() || score > 100 || score < 0 ){
            cout << "Invalid input. Please enter a score between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> score;
        }
        courses[i].second = getGradePointsFromScore(score);
        }
    }
    double totalUnits = 0;
    double totalGradePoints = 0;
    
    for (const auto& course : courses){
        totalUnits += course.first;
        totalGradePoints += course.first * course.second;
    }
    if (totalUnits == 0){
        cout << "No courses entered. Cannot calculate cgpa. " << endl;
        return 1;
    }
    double cgpa = totalGradePoints / totalUnits;
    cout << "Your cgpa is: " << cgpa << endl;
    
    return 0;
    
}