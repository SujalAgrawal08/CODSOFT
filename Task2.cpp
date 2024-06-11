#include<iostream>
#include<math.h>
using namespace std;

int main() {
    double x,y,ans;
    char op;
    cout<<"Enter the first number: ";
    cin>>x;
    cout<<"Enter the second number: ";
    cin>>y;
    cout<<"Enter the operation (+, -, *, /): ";
    cin>>op;

    switch(op){
        case '+':
            ans = x + y;
            break;
        case '-':
            ans = x - y;
            break;
        case '*':
            ans = x * y;
            break;
        case '/':
            if(y != 0) {
                ans = x / y;
            }
            else {
                cout<<"Error: Division by zero is not defined."<<endl;
                return 1;
            }
            break;
        default:
            cout<<"Error: Invalid operation. Please use one of (+, -, *, /)."<<endl;
            return 1; 
    }
    cout<<"The ans is: "<<ans<<endl;
    return 0;  
}
