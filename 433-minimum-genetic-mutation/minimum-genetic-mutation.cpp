class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> st(bank.begin(), bank.end());

        if (!st.count(endGene))
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while (!q.empty()) {

            auto [gene, steps] = q.front();
            q.pop();

            if (gene == endGene)
                return steps;

            for (int i = 0; i < 8; i++) {

                char original = gene[i];

                for (char ch : {'A', 'C', 'G', 'T'}) {

                    if (ch == original)
                        continue;

                    gene[i] = ch;

                    if (st.count(gene)) {
                        q.push({gene, steps + 1});
                        st.erase(gene);      // Mark as visited
                    }
                }

                gene[i] = original;
            }
        }

        return -1;
    }
};