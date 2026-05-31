class Solution {
public:
    int minMutation(string startGene,
                    string endGene,
                    vector<string>& bank) {

        unordered_set<string> genes(
            bank.begin(),
            bank.end()
        );

        if(!genes.count(endGene))
            return -1;

        queue<pair<string,int>> q;
        q.push({startGene,0});

        vector<char> chars =
            {'A','C','G','T'};

        while(!q.empty()) {

            auto [gene,steps] = q.front();
            q.pop();

            if(gene == endGene)
                return steps;

            for(int i=0;i<8;i++) {

                char old = gene[i];

                for(char ch : chars) {

                    gene[i] = ch;

                    if(genes.count(gene)) {

                        q.push({
                            gene,
                            steps+1
                        });

                        genes.erase(gene);
                    }
                }

                gene[i] = old;
            }
        }

        return -1;
    }
};