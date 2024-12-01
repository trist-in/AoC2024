#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream inFile("inputs.txt");
    vector<int> data1;
    vector<int> data2;
    int dataOne, dataTwo;

    while(inFile >> dataOne >> dataTwo){
        data1.push_back(dataOne);
        data2.push_back(dataTwo);
    }
    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

    vector<int> distances;
    for(int i = 0; i < data1.size(); i++){
        distances.push_back(abs(data1[i] - data2[i]));
    }

    int sum = 0;
    for(int i = 0; i < distances.size(); i++){
        sum += distances[i];
    }
    cout << sum << endl;
    //part2
    unordered_map<int,int> mp;
    vector<int> prodSum;

    for(int i : data2){
        mp[i]++;
    }

    for(int i = 0; i < data1.size(); i++){
        if(mp.find(data1[i]) != mp.end()){
            prodSum.push_back(data1[i] * mp.find(data1[i])->second);
        }
    }

    int newSum = 0;
    for(int i = 0; i < prodSum.size(); i++){
        newSum += prodSum[i];
    }
    cout << newSum;
    return 0;
}