class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mpp;
        queue<pair<string,int>>que;
        for(int i=0;i<wordList.size();i++)
        {
            if(wordList[i]==beginWord)continue;
             mpp[wordList[i]]++;
        }
        que.push({beginWord,1});
        while(!que.empty())
        {
            auto [word,level]=que.front();que.pop();
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(mpp.find(word)!=mpp.end())
                    {
                        mpp.erase(word);
                        if(word==endWord)
                        {
                            return level+1;
                        }
                        else que.push({word,level+1});
                    }
                    word[i]=original;
                }
            }
        }
        return 0;
    }
};
