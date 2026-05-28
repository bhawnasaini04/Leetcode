class Solution {
public:
    int lengthLongestPath(string input) {

        unordered_map<int,int> mp;
        mp[0] = 0;

        stringstream ss(input);
        string line;

        int result = 0;

        while(getline(ss,line,'\n')) {

            int level = 0;

            while(line[level]=='\t')
                level++;

            string name = line.substr(level);

            if(name.find('.') != string::npos) {

                result = max(
                    result,
                    mp[level] + (int)name.size()
                );
            }
            else {

                mp[level+1] =
                    mp[level] +
                    name.size() + 1;
            }
        }

        return result;
    }
};