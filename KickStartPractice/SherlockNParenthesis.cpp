/*
Sherlock and Watson have recently enrolled in a computer programming course. Today, the tutor taught them about the balanced parentheses problem. A string S consisting only of characters ( and/or ) is balanced if:
It is an empty string, or:
It has the form (S), where S is a balanced string, or:
It has the form S1S2, where S1 is a balanced string and S2 is a balanced string.
Sherlock coded up the solution very quickly and started bragging about how good he is, so Watson gave him a problem to test his knowledge. He asked Sherlock to generate a string S of `L + R` characters, in which there are a total of L left parentheses ( and a total of R right parentheses ). Moreover, the string must have as many different balanced non-empty substrings as possible. (Two substrings are considered different as long as they start and end at different indexes of the string, even if their content happens to be the same). Note that S itself does not have to be balanced.
Sherlock is sure that once he knows the maximum possible number of balanced non-empty substrings, he will be able to solve the problem. Can you help him find that maximum number?
*/

#include <bits/stdc++.h>

using namespace std;

int getMaximumBalancedSubstrings(int L, int R) {
    int maximumBalancedSubstrings = 0;

  // TODO: Complete this function to compute the maximum possible number of
  // non-empty substrings that form a balanced parenthesis.
    long long min = L < R ? L : R;
    maximumBalancedSubstrings = (min * (min + 1))/2;
    return maximumBalancedSubstrings;
}

int main() {
  int T;
  // Get number of test cases
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int L, R;
    cin >> L >> R;
    cout << "Case #" << tc << ": " << getMaximumBalancedSubstrings(L, R)
         << endl;
  }
  return 0;
}
