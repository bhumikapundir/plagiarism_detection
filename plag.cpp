#include <bits/stdc++.h>
using namespace std;

// Function to calculate Levenshtein distance
int levenshteinDistance(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    return dp[m][n];
}

int main() {
    string file1, file2;

    cout << "Enter the name of the first file (Source File): ";
    cin >> file1;

    cout << "Enter the name of the second file (To be checked for plagiarism): ";
    cin >> file2;

    ifstream f1(file1);
    ifstream f2(file2);

    // Check if the files exist and are accessible
    if (!f1.is_open()) {
        cerr << "Error: The file \"" << file1 << "\" does not exist or cannot be opened." << endl;
        return 1;
    }

    if (!f2.is_open()) {
        cerr << "Error: The file \"" << file2 << "\" does not exist or cannot be opened." << endl;
        return 1;
    }

    string line1, line2;    //used to read line from f1 and f2
    vector<string> lines1, lines2;    //vector of strings to store all the lines as individual strings in the vector

    while (getline(f1, line1)) {
        lines1.push_back(line1);
    }

    while (getline(f2, line2)) {
        lines2.push_back(line2);
    }

    f1.close();
    f2.close();

    int totalDistance = 0;
    int totalLines = lines1.size() + lines2.size();

    for (const auto& line1 : lines1) {
        int minDistance = INT_MAX;
        for (const auto& line2 : lines2) {
            int distance = levenshteinDistance(line1, line2);
            minDistance = min(minDistance, distance);
        }
        totalDistance += minDistance;
    }

    double similarity = (1 - (double)totalDistance / totalLines);
  
  
    similarity= max(0.0,similarity);   //to avoid -ve sign values

    cout << "Similarity: " << similarity * 100 << "%" << endl;

    if (similarity > 0.8) {
        cout << "High similarity detected. Potential plagiarism." << endl;
    } else {
        cout << "Low similarity detected. No significant plagiarism found." << endl;
    }

    return 0;
}
