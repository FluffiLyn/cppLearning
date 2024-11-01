#include <vector>
#include <iostream>

using namespace std;

vector<double> calculateAmplitudes(const vector<double>& data)
{
    vector<double> amplitudes;
    for (double value : data)
    {
        amplitudes.push_back(value / 200);
    }
    return amplitudes;
}

int main()
{
    vector<double> data;
    double input;
    int n;

    cout << "Enter the number of data points: ";
    cin >> n;

    cout << "Enter the data points:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        data.push_back(input);
    }

    vector<double> amplitudes = calculateAmplitudes(data);

    cout << "Amplitudes:" << endl;
    for (double amplitude : amplitudes)
    {
        cout << amplitude << " ";
    }
    cout << endl;

    return 0;
}