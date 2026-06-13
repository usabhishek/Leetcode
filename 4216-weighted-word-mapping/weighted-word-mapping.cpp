class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        cout << 45 - 'a' << endl;
        for(auto s: words){
            int weight = 0;
            for(auto c: s){
                weight += weights[c - 'a'];
            }
            res += 'z' - weight % 26;
        }

        return res;
    }
};