#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }

    double x[9]{};
    for (int i = 0; i < 9; i++)
    {
        cin >> x[i];
    }
    
    bool found = false;
    for (int i = 0; i < 9; i++)
    {
        found = false;
        for (int j = 0; j < n; j++)
        {
            if (x[i] == y[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << x[i] << ", ";
        }
    }
    return 0;
}
