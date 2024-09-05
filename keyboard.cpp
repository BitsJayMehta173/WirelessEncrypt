#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> keytable;
unordered_map<string, bool> reversekeytable;  // Stores codes to ensure uniqueness

vector<int> word;

void keyboard(char i, unordered_map<char, string>& keytable, vector<int>& word, unordered_map<string, bool>& reversekeytable) {
    // Create a random device and seed the generator
    random_device rd;
    mt19937 gen(rd());

    // Shuffle the word vector to further randomize the selection
    shuffle(word.begin(), word.end(), gen);

    // Define the distribution range for random indices
    uniform_int_distribution<> distrib(0, word.size() - 1);

    string code = "";
    // Generate a unique 4-character code
    do {
        code = "";
        for (int j = 0; j < 4; j++) {
            int x = distrib(gen);  // Get a random index
            code += static_cast<char>(word[x]);  // Convert int to corresponding char
        }
    } while (reversekeytable.count(code) > 0);  // Ensure the code is unique

    // Mark this code as used
    reversekeytable[code] = true;
    // Store the generated code in the keytable
    keytable[i] = code;
}

int main() {
    // Populate the word vector with ASCII values of A-Z (65-90) and a-z (97-122)
    for (int i = 65; i <= 90; i++) {
        word.push_back(i);
    }
    for (int i = 97; i <= 122; i++) {
        word.push_back(i);
    }

    // Generate random codes for A-Z
    for (char i = 65; i <= 90; i++) {
        keyboard(i, keytable, word, reversekeytable);
    }

    // Generate random codes for a-z
    for (char i = 97; i <= 122; i++) {
        keyboard(i, keytable, word, reversekeytable);
    }

    // Open a file to write the keytable
    ofstream outfile("keytable.txt");

    // Output the generated keytable to the file
    if (outfile.is_open()) {
        for (const auto& pair : keytable) {
            outfile << pair.first << " : " << pair.second << endl;
        }
        outfile.close();
        cout << "Keytable has been written to keytable.txt" << endl;
    } else {
        cerr << "Unable to open file" << endl;
    }

    return 0;
}
