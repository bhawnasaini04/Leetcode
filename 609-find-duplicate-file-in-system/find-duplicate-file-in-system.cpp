class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {

        unordered_map<string, vector<string>> mp;

        for (string path : paths) {

            stringstream ss(path);
            string directory;
            ss >> directory;

            string file;

            while (ss >> file) {

                int pos = file.find('(');

                string fileName = file.substr(0, pos);

                string content = file.substr(pos + 1);

                // Remove closing ')'
                content.pop_back();

                string fullPath =
                    directory + "/" + fileName;

                mp[content].push_back(fullPath);
            }
        }

        vector<vector<string>> ans;

        for (auto &p : mp) {

            if (p.second.size() > 1) {
                ans.push_back(p.second);
            }
        }

        return ans;
    }
};