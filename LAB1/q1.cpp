#include<iostream>
using namespace std;
//1. Modify the program to input values from the user instead of hardcoded values.
int main(){

    int arr[5];
    cout << "Enter 5 integers: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}