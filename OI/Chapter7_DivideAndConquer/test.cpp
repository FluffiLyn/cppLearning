#include <iostream>
using namespace std;

int n, m, a[1145],left_, right_;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    a[0] = -1;
    for (int i = 1; i <= m; i++)
    {
        left_ = 1, right_ = n;
        int x, mid;
        cin >> x;

        while (left_ <= right_)
        {
            mid = (left_ + right_) / 2;
            if (a[mid] > x) right_ = mid - 1; 
            else left_ = mid + 1;
        }
        cout << a[right_] << endl;
    }
    return 0;
}