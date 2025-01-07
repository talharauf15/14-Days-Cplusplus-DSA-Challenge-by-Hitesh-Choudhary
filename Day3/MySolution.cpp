#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

// Custom comparator for sorting
bool compareTeams(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) // Compare by total eliminations
        return a[1] > b[1];
    return a[2] > b[2]; // Compare by highest individual elimination
}

vector<vector<int>> func(vector<vector<int>> teams) {
    vector<vector<int>> teamStats; // Stores {team_index, total_eliminations, highest_individual_elimination}
    
    // Calculate stats for each team
    for (int i = 0; i < teams.size(); i++) {
        int totalEliminations = 0;
        int maxIndividualEliminations = 0;
        for (int eliminations : teams[i]) {
            totalEliminations += eliminations;
            maxIndividualEliminations = max(maxIndividualEliminations, eliminations);
        }
        teamStats.push_back({i + 1, totalEliminations, maxIndividualEliminations}); // 1-based index
    }

    // Sort teams based on total eliminations and highest individual eliminations
    sort(teamStats.begin(), teamStats.end(), compareTeams);

    // Find the winning teams
    vector<vector<int>> result;
    int maxTotal = teamStats[0][1];
    int maxIndividual = teamStats[0][2];

    for (const auto& team : teamStats) {
        if (team[1] == maxTotal && team[2] == maxIndividual) {
            result.push_back(team);
        } else {
            break; // Stop once teams no longer meet the criteria
        }
    }

    return result;
}

int main() {
    // Initial code 
    vector<vector<int>> teams;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int team_size;
        cin >> team_size;
        vector<int> team(team_size);
        for (int j = 0; j < team_size; j++) {
            cin >> team[j];
        }
        teams.push_back(team);
    }

    // Call the function
    vector<vector<int>> result = func(teams);

    // Print the result (please don't modify this)
    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2];
        } else {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    }
    return 0;
}
