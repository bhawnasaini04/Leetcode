class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if ( rows == 0) return "";

        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        //traverse diagonally
        for(int start = 0; start < cols; start++){
        int i = 0, j = start;

        while(i < rows && j< cols){
            result += encodedText[i * cols + j];
            i++;
            j++;
        }
    }
    while ( !result.empty() && result.back() == ' '){
        result.pop_back();
    }
    return result;
    }
};