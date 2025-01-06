#include <iostream>
#include <string>
#include <algorithm> // For the transform functionality
#include <map>  // For store word frequencies
#include <sstream>  // For splitting string into words

using namespace std;


// you just need to implement this function
string mostCommonWord(string document) {
    //convert the string into lower case
    transform(document.begin(), document.end(), document.begin(), ::tolower);

    //Remove any Punctuation from string 
    document.erase(remove_if(document.begin(), document.end(), [](char c) {
    return !isalnum(c) && c != ' '; 
    }), document.end());

    
    map<string, int> wordCount;
    stringstream ss(document);  
    string word;
    //Count the frequency of each word
    while (ss >> word) {
        wordCount[word]++;
    }

    string mostCommon = "";
    int maxFrequency = 0;
    //Find the most common word
    for (auto &entry : wordCount) {
        if (entry.second > maxFrequency) {
            mostCommon = entry.first;
            maxFrequency = entry.second;
        }
    }

    // your code here
    return  mostCommon;
}

int main() {
    string document;
    cin >> document;

    // please do not change the below code
    cout << mostCommonWord(document);
    return 0;
}