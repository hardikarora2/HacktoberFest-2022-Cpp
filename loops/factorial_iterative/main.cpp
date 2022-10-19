#include<iostream>
using namespace std;
 
double factorial(int n){
   //Enter your code here
 int fact=1;
    for(int i=n; i>=1; i--)
        fact = fact*i;
    return fact;
}

//Driver Code
int main()
{   
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}
