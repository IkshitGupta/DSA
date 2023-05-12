// Name: Ikshit Gupta
// Roll No.: 20IE10046
// Assignment 1
#include <bits/stdc++.h>
using namespace std;

// Sample Input File
// NFG 1 R "Untitled Strategic Game" { "Player 1" "Player 2" }

// { { "1" "2" "3" "4" "5" }
// { "1" "2" "3" "4" "5" }
// }
// ""

// {
    // gives all the cells of the payoff matrix
// { "" 0, 7687687 }
// { "" 87, 6 }
// { "" 687, 687 }
// { "" 876, 86 }
// { "" 6, 877 }
// { "" 87, 68 }
// { "" 75, 686 }
// { "" 87, 68 }
// { "" 7, 78 }
// { "" 7686, 5 }
// { "" 76, 57 }
// { "" 576, 0 }
// { "" 987, 7 }
// { "" 84, 76 }
// { "" 5687, 67 }
// { "" 5, 68 }
// { "" 87, 67 }
// { "" 6987, 0 }
// { "" 798, 6 }
// { "" 58, 68 }
// { "" 68, 68 }
// { "" 98, 79 }
// { "" 787, 779 }
// { "" 87, 9 }
// { "" 68, 7 }
// }
// 1 2 11 16 21 3 4 12 17 22 5 8 13 18 23 6 9 14 19 24 7 10 15 20 25 
// can be used such as first column consist of 5 cells with entries of 1 2 11 16 and 21 cell in the above matrix, stored in position vector

int number_of_players;
vector<int> strategies; // to store number of strategies of each player
vector<vector<vector<float>>> payoff;   // it will store payoff matrix
vector<int> positions;
void parse_input(vector<string>& lines){
    deque<string> words;
    for (auto &ele : lines){
        int n = ele.size();
        for (int i = 0; i < n; i++){
            if (ele[i] == ' '){
                continue;
            }
            int j, len = 0;
            for (j = i; j < n; j++){
                if (ele[j] == ' '){
                    break;
                }
                len++;
            }
            words.push_back(ele.substr(i, len));
            i += len - 1;
        }
    }
    while(words[0] != "}"){
        words.pop_front();
    }
    words.pop_front();
    words.pop_front();
    while(words[0] != "\"\""){
        int cnt = 0;
        while(words[0] != "}"){
            words.pop_front();
            cnt++;
        }
        words.pop_front();
        if (cnt > 0){
            strategies.push_back(cnt - 1);
        }
    }
    words.pop_front();
    words.pop_front();
    vector<vector<float>> cells;
    while(words[0] != "}"){
        words.pop_front();
        words.pop_front();
        vector<float> x;
        while(words[0] != "}"){
            if (words[0].back() == ','){
                words[0].pop_back();
            }
            x.push_back(stof(words[0]));
            words.pop_front();
        }
        words.pop_front();
        cells.push_back(x);
    }
    words.pop_front();
    while(!words.empty()){
        positions.push_back(stoi(words[0]) - 1);
        words.pop_front();
    }
    int idx = 0;
    vector<vector<vector<float>>> temp;
    while(idx < positions.size()){
        vector<vector<float>> p;
        for(int j = 0; j < strategies[1]; j++){
            if (positions[idx] == -1){
                p.push_back({0, 0});
            }
            else{
                p.push_back(cells[positions[idx]]);
            }
            idx++;
        }
        temp.push_back(p);
    }
    // transpose required for payoff as we stored in rows while position vector stores order in column
    payoff.resize(temp[0].size(), vector<vector<float>>(temp.size()));
    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp[0].size(); j++){
            payoff[i][j] = temp[j][i];
        }
    }

}

void nash_equ(){
    // for 2 players
    map<pair<int, int>, pair<bool, bool>> marked;
    for(int i = 0; i < strategies[0]; i++){
        float ma = INT_MIN;
        for(int j = 0; j < strategies[1]; j++){
            ma = max(ma, payoff[i][j][1]);
        }
        for(int j = 0; j < strategies[1]; j++){
            if (payoff[i][j][1] == ma){
                marked[{i, j}].second = 1;
            }
        }
    }
    for(int j = 0; j < strategies[1]; j++){
        float ma = INT_MIN;
        for(int i = 0; i < strategies[0]; i++){
            ma = max(ma, payoff[i][j][0]);
        }
        for(int i = 0; i < strategies[1]; i++){
            if (payoff[i][j][0] == ma){
                marked[{i, j}].first = 1;
            }
        }
    }
    pair<bool, bool> req = {1, 1};
    vector<pair<int, int>> nash_eq;
    for(auto& i : marked){
        if (i.second == req){
            nash_eq.push_back({i.first.first + 1, i.first.second + 1});
        }
    }
    if (nash_eq.empty()){
        cout << "No Pure Strategy Nash Equilibrium\n";
    }
    else{
        cout << "Pure Strategy Nash Equilibriums are\n";
        for(auto& i : nash_eq){
            cout << "Strategy " << i.first << " of player 1 & Strategy " << i.second << " of player 2\n";
        }
    }
    return;
}

int main(){
    cout << "Number of players:  ";
    cin >> number_of_players;
    vector<string> lines;   // contain each line
    string line;
    // give input file of nfg extension in same folder as cpp file
    ifstream myfile("input.txt");
    if (myfile.is_open()){
        while (getline(myfile, line)){
            lines.push_back(line);
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    parse_input(lines);
    nash_equ();
    return 0;
}