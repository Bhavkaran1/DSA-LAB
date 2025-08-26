#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int count = 0;

    // Compare every pair
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] - arr[j] == k) || (arr[j] - arr[i] == k)) {
                count++;
                cout << "Pair: (" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }

    cout << "Total pairs with difference " << k << " = " << count << endl;

    return 0;
}
