#include <iostream>
using namespace std;

void SumAndAverage(int arr[], int size)
{

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double average = sum / double(size);
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
}
int main()
{
    int arr[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    SumAndAverage(arr, 5);
    return 0;
}