#include <iostream>
using namespace std;
// 3. Find the maximum and minimum value in the array.

int main()
{
    int arr[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int maxVal = arr[0];
    int minVal = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal << endl;

    return 0;
}