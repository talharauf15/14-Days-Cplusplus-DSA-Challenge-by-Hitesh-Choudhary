#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    // Step I: Read the input document
    string document;
    getline(cin, document);
 
    // Step 2: Initialize variables for word splitting and counting
    unordered_map<string,int> wordCount;
    vector<string> wordOrder; // To track the order of words
    string word = "";

    // Step 3: Loop through the document and split words manually
    for (char c : document) {
        if (c == ' '){
            if (!word.empty()) {
                for (char& ch : word) {
                    ch = tolower(ch); // Convert to lowercase
                }
                if (wordCount[word] == 0) {
                    wordOrder.push_back(word); // Track the first occurrence of the word
                }
                wordCount[word]++;
                word = "";
            }
        } else {
            word += c; // Add the character to the current word
        }
    }

    // Handle the last word
    if (!word.empty()) {
        for (char& ch : word) {
            ch = tolower(ch);
        }
        if (wordCount[word] == 0) {
            wordOrder.push_back(word);
        } 
        wordCount[word]++;
    }

    // Step 4: Find the most common word
    string mostCommonWord;
    int maxCount = 0;

    for (const string& w : wordOrder) { // Iterate in the order of appearance
        if (wordCount[w] > maxCount) {
            maxCount = wordcount [w] ;
            mostConnonWord = w;
        }
    }

    // Step 5: Output the result
    cout << mostCommonWord;

    return 0;
}