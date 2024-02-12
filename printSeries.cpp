#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1 || n == 0)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main(){

    int N = 100;
 
//Print the series 4,6,12,18,30,42,60,72
    for (int i = 1; i <= N; i++) {
        if (isPrime(i) && isPrime(i+2))
            cout << i+1 << " ";
    }

    return 0;
}