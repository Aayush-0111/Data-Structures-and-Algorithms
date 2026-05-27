class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size(), start = 0, len;
        for(int i = 0; i < n; i++){
            title[i] = tolower(title[i]);
            len = 0;
            if(i == 0 || (i > 0 && title[i-1] == ' ')){
                start = i;
            }
            while(i < n && title[i] != ' ') {
                title[i] = tolower(title[i]);
                len++;
                i++;
            }
            if(len > 2) title[start] = toupper(title[start]);
        }
        if(len > 2) title[start] = toupper(title[start]);
        return title;
    }
};