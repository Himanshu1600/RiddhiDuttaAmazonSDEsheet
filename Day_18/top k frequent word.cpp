class Solution
{
public:
    template<typename t>
    void Insertion(vector<t> &arr)
    {
        int sz = arr.size();
        for(int i = 1; i < sz; i++)
        {
            t tmp = arr[i];
            int j = i-1;
            while(j >= 0 and arr[j] > tmp)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = tmp;
        }
        return;
    }

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> m;
        for (auto word : words)
            m[word]++;

        vector<vector<string>> freqBucket(words.size() + 1); // 0th bucket would be empty, as we won't be storing frequency 0
        for (auto pair : m)
            freqBucket[pair.second].push_back(pair.first);

        for (auto &bucket : freqBucket)
            Insertion(bucket);
        
        vector<string> ans;
        for (int i = freqBucket.size() - 1; i >= 0 and ans.size() < k; i--)
        {
            for (int j = 0; j < freqBucket[i].size(); j++)
            {
                ans.push_back(freqBucket[i][j]);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};
