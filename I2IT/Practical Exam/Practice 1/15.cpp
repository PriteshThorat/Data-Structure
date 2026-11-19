// Implement the Naïve String Matching algorithm in C++ to find all occurrences of
// a pattern in a text and analyze its time complexity.

#include <iostream>
#include <string>

using namespace std;

void naiveStringMatching(string text, string pattern) {
  int n = text.length();
  int m = pattern.length();
  bool found = false;

  for (int i = 0; i <= n - m; i++) {
    int j;

    for (j = 0; j < m; j++) {
      if (text[i + j] != pattern[j]) break;
    }

    if (j == m) {
      cout << "Pattern found at index " << i << endl;
      found = true;
    }
  }

  if (!found) cout << "Pattern not found!" << endl;
}

int main() {
  string text, pattern;

  cout << "Enter Text: ";
  getline(cin, text);

  cout << "Enter Pattern: ";
  getline(cin, pattern);

  naiveStringMatching(text, pattern);

  return 0;
}
