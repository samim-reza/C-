#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {

    int n;
    cout << "Enter the square dimension: ";
    cin >> n;

 // Get the current time before executing the code
    auto start_time = high_resolution_clock::now();
    
    int magicSquare[n][n];
    int row = n / 2, col = n - 1;

    for (int i = 1; i <= n * n; i++) {
        magicSquare[row][col] = i;
        if (i % n == 0) {
            col--;
        } else {
            row--;
            col++;
        }
        row = (row + n) % n;
        col = (col + n) % n;
    }

    cout << "output:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "magic number for the Lo Shu Magic Square is: " << (n * (n * n + 1)) / 2 << "\n";

    // Get the current time after executing the code
    auto end_time = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    cout << "Time taken by function: " << duration.count() << " milliseconds\n";

    return 0;
}
