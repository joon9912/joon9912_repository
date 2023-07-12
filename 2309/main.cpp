#include <iostream>
#include <algorithm>
using namespace std;

int arr_size = 9;
int arr[9];
int new_arr[7];
int sum;

int main() {
    int x = -1, y = -1;
    for (int i = 0; i < arr_size; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < arr_size - 1; ++i) {
        for (int j = i + 1; j < arr_size; ++j){
            if (sum - arr[i] - arr[j] == 100) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1 && y != -1)
            break;
    }

    // cout << x << " " << y << endl;
    int j = 0;
    for (int i = 0; i < arr_size; ++i) {
        if (i == x || i == y)
            continue;
        else
            new_arr[j++] = arr[i];
    }

    sort(new_arr, new_arr + 7);

    for (int i = 0; i < 7; ++i)
        cout << new_arr[i] << "\n";

    return 0;
}
