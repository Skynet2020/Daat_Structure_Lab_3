/* 
 * File:   main.cpp
 * Author: Arman B. *
 * Created on September 23, 2019, 10:04 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*
 * 
 */

bool push(vector <char>&, char&, int&);
bool isEmpty(const int);
bool pop(vector <char>&, int&);
char peek();

void displayStack(const vector <char>& stack);
void extractIntegerWords(vector <double>& stack2, string str);

int main(int argc, char** argv) {
    int top;
    vector <char> stack;

    string str = "100 * 250";
    for (char& ch : str){
        if (ch != ' ' && ch != '+'){
            cout << ch << ' ';
            push(stack, ch, top);
        }
    } cout << endl;
    displayStack(stack);
    
    vector<double> stack2;
    extractIntegerWords(stack2, str);
    cout << "\nStack2 content: ";
    for (int i=0; i<stack2.size(); i++){
        cout << stack2[i] << ' ';
    } cout << endl;
    cout << "Stack2 math: " << stack2[0] + stack2[1] << endl;
    
//    for (char& ch : str){
//        if (isdigit(ch)){
//           cout << "Push result: " << push(stack, ch) << endl;
//        }
//        else{
//            switch (ch){
//                case '+':
//                cout << "A '+' operator was encountered" << endl;
//                break;
//            default:
//                cout << "No operators were enterred" << endl;
//                break;
//            }
//            
//        }
//    }
//    for (int i=0; i<stack.size(); i++){
//        cout << stack[i] << ' ';
//    } cout << endl;
//    int sum = stack[0];
//    cout << "top: " << top << endl;
//    
//    int size = stack.size();
//    for (int j=0; j<size; j++){
//        pop(stack, top);
//    }
//    cout << "top: " << top << endl;
       
    
    return 0;
}

bool isEmpty(const int top) {
    return top < 0;
}

bool push(vector <char>& stack, char& ch, int& top){    
    top++;
    stack.push_back(ch);
    bool result = true;
    return result;
}

bool pop(vector <char>& stack, int& top){
    bool result = false;
    if(!isEmpty(top)){
        top--;
        stack.pop_back();
        result = true;
    }
    return result;
}

char peek(vector <char>& stack, const int& top){
    return stack[top];
}


void displayStack(const vector <char>& stack){
    cout << "Stack content: ";
    for (int i=0; i<stack.size(); i++){
        if (i == stack.size()-1){
            cout << stack[i] << endl;
        } else {
            cout << stack[i] << ", "; 
        }        
    } cout << endl;
}


void extractIntegerWords(vector<double>& stack, string str){ 
    stringstream ss;
    string strWithReplacedOperators, temp; 
    double extractedDigit;
    for (char& ch: str){
        if (ch =='+' || ch=='-' || ch=='*' || ch=='/'){
            strWithReplacedOperators += ' ';
        } else {
            strWithReplacedOperators += ch;
        }
    }
    /* Storing the whole string into string stream */
    ss << strWithReplacedOperators; 
    /* Running loop till the end of the stream */    
    while (!ss.eof()) {
        /* extracting word by word from stream */
        ss >> temp;
        cout << "Extracting word by word: " << temp << ' ';
        cout << endl;
        /* Checking the given word is a number or not */
        if (stringstream(temp) >> extractedDigit){
            stack.push_back(extractedDigit); 
        }            
        /* To save from space at the end of string */
        temp = ""; 
    } 
}
