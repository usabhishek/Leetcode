class Solution {
public:
    bool isAvailable(set<int>& reserved, int start, int end) {
        for (int seat = start; seat <= end; seat++) {
            if (reserved.count(seat)) {
                return false;
            }
        }
        return true;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for (auto& Seat : reservedSeats) {
            mp[Seat[0]].insert(Seat[1]);
        }

        int res = (n - mp.size()) * 2;

        for (auto& it : mp) {
            set<int>& reserved = it.second;

            bool left = isAvailable(reserved, 2, 5);
            bool middle = isAvailable(reserved, 4, 7);
            bool right = isAvailable(reserved, 6, 9);

            if (left && right) {
                res += 2;
            } else if (left || middle || right) {
                res += 1;
            }
        }

        return res;
    }
};