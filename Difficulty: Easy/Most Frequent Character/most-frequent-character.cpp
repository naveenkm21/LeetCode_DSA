class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        vector<int> freq(26,0);
        
        for(char c: s){
            freq[c-'a']++;
        }
        int maxCount =0;
        char result = 'a';
        
        for(int i = 0; i<26; i++) {
            if(freq[i] > maxCount){
                maxCount = freq[i];
                result = (char)(i+'a');
            }
        }
        return result;
    }
};