#include<iostream>
using namespace std;

int FindNumberFrequency(int arr[],int size)
{
    if (size == 0)
    {
        cout << "Array is empty.";
        return 0;
    }
    int freq = 0;
    int i = 0;

    while(i < size)
    {
        int count = 1;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        cout << "Number " << arr[i] << " occurs " << count << " times." << endl;
        freq++;
        i += count;
    }
}

int main(){

    int arr[8];
    cout << "Enter 8 integers: ";
    for(int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    FindNumberFrequency(arr, 8);
    
    return 0;
}