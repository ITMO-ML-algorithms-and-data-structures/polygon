class Solution {
public:
    bool isMatch(string s, string p) {
        int textLen = s.size();
        int patternLen = p.size();
        vector<vector<bool>> mTable(textLen + 1, vector<bool>(patternLen + 1, false));
        mTable[textLen][patternLen] = true;
        bool charMatch = false;
        bool starP = false;
        bool dotP = false;
        char patternChar;
        for (int patternIndex = patternLen - 1; patternIndex >= 0; patternIndex--) {
            patternChar = p[patternIndex];
            if (patternChar == '*') {
                starP = true;
                continue;
            }
            dotP = (patternChar == '.');
            for (int textIndex = textLen; textIndex >= 0; textIndex--) {
                if (textIndex < textLen) {
                    charMatch = (dotP || (patternChar == s[textIndex]));
                } else {
                    charMatch = false;
                }
                if (starP) {
                    if (mTable[textIndex][patternIndex + 2]) {
                        mTable[textIndex][patternIndex] = true;
                    } else if (charMatch) {
                        if (textIndex < textLen) {
                           mTable[textIndex][patternIndex] = mTable[textIndex + 1][patternIndex];
                        }
                    }
                } else { 
                    if (charMatch) {
                        if (textIndex < textLen) {
                            mTable[textIndex][patternIndex] = mTable[textIndex + 1][patternIndex + 1];
                        }
                    }
                }
            }
            starP = false;
        }
        return mTable[0][0];
    }
};
