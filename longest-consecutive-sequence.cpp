/*
Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
/*
JAN 16 2014
Time complexity: O(n)
Use map/ Hashmap data structure
Since it requires O(n) solution, normal sort won't be work here. Hash probably is the best choice.
3 Steps:
1. create the hashmap to hold <num, index>
2. scan the num vector from left to right, for each num
               i, check whether num -1 is in the map  (loop)
              ii, check whether num+1 is in the map  (loop)
3. track the sequence length during scanning.

Reference:
http://fisherlei.blogspot.com/2013/02/leetcode-longest-consecutive-sequence.html
http://vialgorithms.blogspot.com/2013/08/longest-consecutive-sequence.html
http://yucoding.blogspot.com/2013/05/leetcode-question-129-longest.html

Another approach: taken advantage of map in stl.
A more easier code (because of the c++ map is implemented by binary search tree/rb tree, the key are stored in ascending order, and the iterator of STL can be used to scan the whole map):
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (!num.size()) return 0;
        map<int, bool> table;
        for (int i = 0; i<num.size(); i++)
        {
            table[num[i]] = 1;
        }
        int tmplen = 1, maxlen = -1;
        int start, end;
        for(int i=0; i<num.size();i++)
        {
            if (table[num[i]])
            {
                tmplen = 1;
                table[num[i]] = 0;
                start = num[i]-1;
                end = num[i]+1;
                while((table.find(start)!=table.end()) && table[start])
                {
                    table[start] = 0;
                    tmplen++;
                    start--;
                }
                while((table.find(end)!=table.end()) && table[end])
                {
                    table[end] = 0;
                    tmplen++;
                    end++;
                }
                if (tmplen > maxlen)
                {maxlen = tmplen;}
            }
        }
        return maxlen;
    }
};

/*
Another approach: take advantage of c++ stl map.
A more easier code (because of the c++ map is implemented by binary search tree/rb tree, the key are stored in ascending order, and the iterator of STL can be used to scan the whole map):
http://yucoding.blogspot.com/2013/05/leetcode-question-129-longest.html
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,bool> mp;
        for (int i=0;i<num.size();i++){
            mp[num[i]]=true;
        }  
        int res = 1;
        int l;
        map<int,bool>::iterator it;
        int key;
        for (it=mp.begin();it!=mp.end();it++){
            if (it==mp.begin()){l=1; key=it->first;}
            else{
                if (it->first == key+1){
                    l++;
                }else{
                    l=1;
                }
                if (res<l){res=l;}
                key = it->first;
            }
        }
        return res;
    }
};
