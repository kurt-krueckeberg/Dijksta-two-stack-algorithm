/* 
 * File:   main.cpp
 * Author: kurt
 *
 * Created on July 6, 2014, 2:17 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main(int argc, char** argv) 
{
    string input, str;
    
    stack<double> vals; // value stack
    stack<string> ops;  // operator stack
    cout << "Enter a infix string. Then enter Ctrl+D to terminate the input" << endl;     
            
    getline(cin, input);
    
    istringstream istr(input);
    while (!istr.eof()) {    
            
         if (str == string("(")) {

             // ignore
         } else if (str == string("+")) {
             
             ops.push(str); 
             
         } else if (str == string("*")) {
             
             ops.push(str);
             
         } else if (str == string(")")) {
            
            // Get last operator 
            string oper(ops.top());
            ops.pop(); 
             
             /* 
              * Get left and right operands from vals stack
              */ 
            double right = vals.top();
            vals.pop();
                 
            double left = vals.top();
            vals.pop();
            /* 
             * Perform operation and push result 
             */
            if (oper == string("+"))  {
                                 
                vals.push(left + right);
                
            } else if (oper == string("*"))  {
                 
                vals.push(left * right);
            }
         } 
         else {
             
            vals.push(str); // needs to be double
         }
    }
           
    return 0;
}

