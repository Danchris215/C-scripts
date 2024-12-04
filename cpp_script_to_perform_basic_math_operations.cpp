#include <iostream>
using namespace std;

int main(){
    //you can use double value1, value2, result; instead
    double value1;
    double value2;
    double result;
    char operation;
    
    cout << "Enter two numbers and an operation (+, - ,/, *): ";
    cin >> value1 >> operation >> value2;
    switch(operation){
    
    case '+':
        result = value1 + value2;
        cout << "Ther result of your addition operation is: " << result << endl;
        break;
    case '-':
        result = value1 - value2;
        cout << "The result of your subtraction operation is: " << result << endl;
        break;
        
    case '*':
        result = value1 * value2;
        cout << "The result of your multiplication operation is:  "<< result << endl;
        break;
    case '/':
    if (value2 == 0){
        cout << "Error: Division by zero!" << endl;
    }else{
    result = value1/value2;
    cout << "The result of the division operation is: "<< result <<endl;}
    break;
    default:
    cout << "Invalid operation entered." << endl;
    }
    return 0;
}