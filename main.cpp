#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int maxMin(int k, vector<int> arr)
{
    sort(arr.begin(), arr.end());

    int retValue = arr[k - 1] - arr[0];

    for(size_t i = 1; i < arr.size() - k + 1; i++)
    {
        if(retValue > arr[i + k - 1] - arr[i])
            retValue = arr[i + k - 1] - arr[i];
    }

    return retValue;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    cout << result << endl;

    return EXIT_SUCCESS;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
            );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
        );

    return s;
}
