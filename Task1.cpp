#include<iostream>
#include<cstdlib>  
#include<ctime>   
#include<math.h>
using namespace std; 

int genRandom(){
    srand(static_cast<unsigned int>(time(0)));
    int random=rand();
    return random;
}

int main(){
    bool x=false;
    while(x!=true){
        unsigned int n;
        cout<<"Guess the number: ";
        cin>>n;
        int y=genRandom();
        if(n==y){
            x=true;
            cout<<"You guessed it correct!"<<endl;
        }
        else if(n>y){
            cout<<"Your guess is too high! Try again."<<endl;
        }
        else{
            cout<<"Your guess is too low! Try again."<<endl;
        }
    }
    return 0;
}
