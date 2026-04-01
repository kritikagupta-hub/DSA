class Solution {
public:

    bool isAlphaNum(char c){
        if((c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }

    char toLowercase(char c){
        if(c >= 'A' && c <= 'Z'){
            return c + ('a' - 'A');
        }
        return c; 
    }

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(start <= end){

            while(start < end && !isAlphaNum(s[start])){
                start++;
            }

            while(start < end && !isAlphaNum(s[end])){
                end--;
            }

            if(toLowercase(s[start]) != toLowercase(s[end])){
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};
