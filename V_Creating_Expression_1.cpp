#include <bits/stdc++.h>
using namespace std;
long long dp[25][25];
bool subset_sum(long long n, long long s, long long a[])
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (a[n - 1] <= s)
    {
        bool op1 = subset_sum(n - 1, s - a[n - 1], a);
        bool op2 = subset_sum(n - 1, s, a);
        return dp[n][s] = op1 || op2;
    }
    else
    {

        return dp[n][s] = subset_sum(n - 1, s, a);
    }
}
int main()
{
    long long n, x;
    cin >> n >> x;
    long long a[n+1];

    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    // s1+s2 = sum; s1-s2 = dif; 2s1=dif+sum;
    if (abs(x + sum) % 2 == 0)
    {
        long long s = abs(x + sum) / 2;
        for (long long i = 0; i <= n; i++)
        {
            for (long long j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }
        if (subset_sum(n, s, a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        cout<<"NO" << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// bool isPossible(int n, int x, int a[], int currentSum, int currentIndex) {
//     // Base case: If we have reached the end of the array
//     if (currentIndex == n) {
//         return (currentSum == x);
//     }

//     // Try adding the current element
//     bool withPlus = isPossible(n, x, a, currentSum + a[currentIndex], currentIndex + 1);

//     // Try subtracting the current element
//     bool withMinus = isPossible(n, x, a, currentSum - a[currentIndex], currentIndex + 1);

//     // Return true if either withPlus or withMinus is true
//     return withPlus || withMinus;
// }

// int main() {
//     int n, x;
//     cin >> n >> x;
//     int a[20];

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     if (isPossible(n, x, a, 0, 0)) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

