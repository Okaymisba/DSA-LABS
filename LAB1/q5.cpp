#include <iostream>
#include <climits>
using namespace std;

int SecondLargest(int arr[], int size)
{

    int first = INT_MIN;
    int second = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first)
        {
            second = arr[i];
        }
    }
    if (second == INT_MIN)
    {
        cout << "No second largest element found." << endl;
    }
    else
    {

        return second;
    }
}
int main()
{
    int arr[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    cout << "The second largest element is: " << SecondLargest(arr, 5);
    return 0;
}