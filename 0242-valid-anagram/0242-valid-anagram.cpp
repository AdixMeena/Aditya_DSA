class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char , int> smp;
        map<char , int> tmp;

        int sn = s.size();
        int tn = t.size();

        for(int i = 0; i < sn; i++)
        {
            smp[s[i]]++;
        }
        
        for(int i = 0; i < tn; i++)
        {
            tmp[t[i]]++;
        }
         
         if(smp == tmp) return true;
         else return false;

        
    }
};