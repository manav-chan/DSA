class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        int ans = 0;
        while(!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord)
            {
                ans = level;
                break;
            }

            int l = word.length();
            for(int i=0; i<l; i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        q.push({word, level + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }   
        return ans; 
    }
};