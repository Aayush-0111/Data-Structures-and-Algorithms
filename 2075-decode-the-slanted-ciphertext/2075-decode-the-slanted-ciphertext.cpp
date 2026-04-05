class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1) return encodedText;
        int n = encodedText.size();
        int cols = n/rows;
        string originalText = "";
        for(int i = 0; i < cols; i++){
            int r = 0, c = i;
            while(r < rows && c < cols){
                originalText += encodedText[r*cols + c];
                r++; c++;
            }
        }
        while(!originalText.empty() && originalText.back() == ' ') originalText.pop_back();
        return originalText;   
    }
};