#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) { 
    if (n <= 1) 
        return false; 
    for (int i = 2; i <= sqrt(n); i++) {  
        if (n % i == 0) 
            return false;
    }
    return true; 
}

int main() {
    int n;
    cout << "Enter the number you want to check: ";
    cin >> n;

    if (isPrime(n)) 
        cout << "The entered number is Prime: " << n << endl;
    else 
        cout << "The entered number is not Prime: " << n << endl;

    return 0;
}
