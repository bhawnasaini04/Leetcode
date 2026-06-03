class Solution {
public:
    int getMaxRepetitions(string s1, int n1,
                          string s2, int n2) {

        if (n1 == 0) return 0;

        int s1cnt = 0;
        int s2cnt = 0;
        int index = 0;

        unordered_map<int, pair<int,int>> recall;

        while (true) {

            s1cnt++;

            for (char c : s1) {
                if (c == s2[index]) {
                    index++;

                    if (index == s2.size()) {
                        s2cnt++;
                        index = 0;
                    }
                }
            }

            if (s1cnt == n1)
                return s2cnt / n2;

            if (recall.count(index)) {

                auto [preS1Cnt, preS2Cnt] =
                    recall[index];

                int preLoopS1 = preS1Cnt;
                int preLoopS2 = preS2Cnt;

                int inLoopS1 =
                    s1cnt - preS1Cnt;

                int inLoopS2 =
                    s2cnt - preS2Cnt;

                int result = preLoopS2;

                int remain =
                    n1 - preLoopS1;

                result +=
                    (remain / inLoopS1)
                    * inLoopS2;

                int rest =
                    remain % inLoopS1;

                for (int i = 0; i < rest; i++) {

                    for (char c : s1) {

                        if (c == s2[index]) {

                            index++;

                            if (index ==
                                s2.size()) {

                                result++;
                                index = 0;
                            }
                        }
                    }
                }

                return result / n2;
            }

            recall[index] =
                {s1cnt, s2cnt};
        }
    }
};