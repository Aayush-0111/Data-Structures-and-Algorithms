class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size(), i = 0;
        string s = "";
        while(i < n){
            char c = title[i];
            if(c == ' '){
                int len = s.size();
                if(len <= 2){
                    int j = i-len;
                    while(j < n && title[j] != ' '){
                        title[j] = tolower(title[j]);
                        j++;
                    }
                }else{
                    title[i-len] = toupper(title[i-len]);
                    int j = i-len+1;
                    while(j < n && title[j] != ' '){
                        title[j] = tolower(title[j]);
                        j++;
                    }
                }
                s = "";
            }else{
                s += title[i];
            }
            i++;
        }
        int len = s.size();
        if(s.size() <= 2){
            int j = i-len;
            while(j < n && title[j] != ' '){
                title[j] = tolower(title[j]);
                j++;
            }
        }else{
            title[i-len] = toupper(title[i-len]);
            int j = i-len+1;
            while(j < n && title[j] != ' '){
                title[j] = tolower(title[j]);
                j++;
            }
        }
        return title;
    }
};