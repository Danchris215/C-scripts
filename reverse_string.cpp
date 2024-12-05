#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//method 1
/*
string reverseStringIterative(string& str){
        string reversedStr = str;
        int n = reversedStr.length();
        for(int i = 0; i < n/2; i++){
            swap(reversedStr[i], reversedStr[n - i - 1]);
        }
        return reversedStr;
    }
int main(){ 
   string str = "hello";
   string reversed = reverseStringIterative(str);
   cout << "Reversed string: " << reversed << endl;
}
*/
//method 2

string reverseStringAlgorithm(string str){
    reverse(str.begin(), str.end());
    return str;
}
int main(){
    string str = "Hello";
    string reversed  = reverseStringAlgorithm(str);
    cout << "Reversed string: " << reversed <<endl;
    return 0;
}
