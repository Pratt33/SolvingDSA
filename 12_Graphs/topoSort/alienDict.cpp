#include <bits/stdc++.h>
using namespace std;
string getAlienLanguage(vector<string> &dictionary, int k){
    int n=dictionary.size();
    vector<vector<int>> adj(k);

    for(int i=0; i<n-1; i++){
        string s1=dictionary[i], s2=dictionary[i+1];
        int m=min(s1.size(), s2.size());

        for(int j=0; j<m; j++){

            if(s1[j]!=s2[j]){
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';
                adj[u].push_back(v);
                break;
            }
        }
    }

    //topo sort
    vector<int> ans;
    vector<int> inDeg(k, 0);

    for(int i=0; i<k; i++){

        for(int j=0; j<adj[i].size(); j++){
            inDeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    for(int i=0; i<k; i++){

        if(inDeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(int j=0; j<adj[node].size(); j++){
            int neighbor=adj[node][j];
            inDeg[neighbor]--;

            if(inDeg[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    string res;
    for (int ch : ans) {
    res+=(char)(ch + 'a');
    }
    return res;
}

int main() {
    vector<string> dictionary = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4;  // Number of unique characters (e.g., 'a', 'b', 'c', 'd')

    string order = getAlienLanguage(dictionary, k);

    cout << "Alien language order: " << order << endl;

    return 0;
}