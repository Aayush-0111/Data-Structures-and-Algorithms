class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n/rows, x = 0;
        string originalText = "", rawText = "";
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        vector<vector<char>> matrix(rows,vector<char>(cols));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                matrix[i][j] = encodedText[x++];
            }
        }
    
        for(int j = 0; j < cols; j++){
            int k = j;
            for(int i = 0; i < rows; i++){
                if(!visited[i][k]){
                    rawText += matrix[i][k];
                    visited[i][k] = true;
                }
                if(k < cols-1) k++;
            }
        }
        int p = rawText.size()-1;
        while(p >= 0 && rawText[p] == ' ') p--;

        originalText = rawText.substr(0,p+1);

        return originalText;
    }
};