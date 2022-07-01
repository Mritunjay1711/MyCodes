#include <bits/stdc++.h>

using namespace std;

bool canFormPalindrome(string str, int a, int b)
{

    // Create a list
    vector<char> list;

    for (int i = a; i <= b; i++)
    {
        auto pos = find(list.begin(), list.end(), str[i]);
        if (pos != list.end())
        {
            auto posi = find(list.begin(), list.end(), str[i]);
            list.erase(posi);
        }
        else
            list.push_back(str[i]);
    }
    // cout << b - a  << " * " << list.size() << endl;
    int size = (b-a)+1;
    if ((size % 2 == 0 && list.empty()) || ((size % 2 == 1 && list.size() == 1)))
        return true;

    else
        return false;
}

int positiveAnswersCount(int N, int Q, string str, vector<int> L,
                         vector<int> R)
{
    // TODO: Complete this function to count number of questions Anna can answer
    // "yes" to

    int count = 0, n = L.size();

    for (int i = 0; i < n; i++)
    {
        bool flag = canFormPalindrome(str, L[i] - 1, R[i] - 1);
        if (flag)
            count++;
    }
    return count;
}

int main()
{
    int T;
    // Get number of test cases
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int N, Q;
        // Get number of blocks and number of questions
        cin >> N >> Q;

        string blockCharacters;
        // Get the string representing the characters on the blocks
        cin >> blockCharacters;

        vector<int> L(Q), R(Q);
        for (int i = 0; i < Q; i++)
        {
            cin >> L[i] >> R[i];
        }

        cout << "Case #" << tc << ": "
             << positiveAnswersCount(N, Q, blockCharacters, L, R) << endl;
    }
    return 0;
}
