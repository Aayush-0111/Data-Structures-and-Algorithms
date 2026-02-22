class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string encrypted = "";
        for(int i = 0; i < n; i++){
            encrypted += s[(i+k)%n];
        }
        return encrypted;
    }
};