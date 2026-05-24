class Solution {
public:
    unordered_map<string,
                  priority_queue<string,
                  vector<string>,
                  greater<string>>> graph;

    void dfs(string src,
             vector<string>& result){

        while(!graph[src].empty()){

            string next=
                graph[src].top();

            graph[src].pop();

            dfs(next,result);
        }

        result.push_back(src);
    }

    vector<string> findItinerary(
        vector<vector<string>>& tickets) {

        for(auto &t:tickets){
            graph[t[0]].push(t[1]);
        }

        vector<string> result;

        dfs("JFK",result);

        reverse(
            result.begin(),
            result.end()
        );

        return result;
    }
};