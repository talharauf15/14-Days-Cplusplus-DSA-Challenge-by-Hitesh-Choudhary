#include <iostream>
#include <string>

using namespace std;

// you just need to implement this function
bool containsGlitchPattern(const string& videoStream, const string& glitchPattern) {
    // your code here
    int n = videoStream.size();
    int m = glitchPattern.size();
    
    // Edge case: If the glitchPattern is longer than the videoStream, return false
    if (m > n) {
        return false;
    }
    
    // Sliding Window: Check each substring of length 'm'
    for (int i = 0; i <= n - m; i++) {
        if (videoStream.substr(i, m) == glitchPattern) {
            return true; // Found a match
        }
    }
    
    return false; // No match found
 }

int main() {
    string videoStream, glitchPattern;
    cin >> videoStream;
    cin >> glitchPattern;

    // please do not change the below code
    if (containsGlitchPattern(videoStream, glitchPattern)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}