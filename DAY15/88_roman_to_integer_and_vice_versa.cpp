-----------------------------------------------------------------------------------------------
                          MY CODE
-----------------------------------------------------------------------------------------------
class Solution {
public:
    int romanToInt(string s) {
        int sz = s.length();
        int ar[sz];
        for(int i=0; i<sz; i++){
            char c = s[i];
            switch(c){
                case 'I': ar[i] = 1;
                    break;
                case 'V':ar[i] = 5;
                    break;
                case 'X': ar[i] = 10;
                    break;
                case 'L': ar[i] = 50;
                    break;
                case 'C': ar[i] = 100;
                    break;
                case 'D': ar[i] = 500;
                    break;
                case 'M': ar[i] = 1000;
                    break;
                    
            }
        }
        int sum=0;
        for(int i=0; i<sz; i++){
            if(i<(sz-1)){
            if(ar[i]==1){
               if(ar[i+1] == 5){
                   sum += 4;
                   i++;
               }
                else if(ar[i+1] == 10){
                   sum += 9;
                   i++;
               }
                else sum+=1;
                   
            }
            else if(ar[i] == 10){
                if(ar[i+1] == 50){
                   sum += 40;
                   i++;
               }
                else if(ar[i+1] == 100){
                   sum += 90;
                   i++;
               }
                else sum+=10;
            }
            else if(ar[i] == 100){
                if(ar[i+1] == 500){
                   sum += 400;
                   i++;
               }
                else if(ar[i+1] == 1000){
                   sum += 900;
                   i++;
               }
                else sum+=100;
            }
                else sum += ar[i];
            }
            else sum += ar[i];
        }
        return sum;
    }
};

---------------------------------------------------------------------------------------------------
                              DISCUSSION CODED
---------------------------------------------------------------------------------------------------
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char , int> mp={{'I', 1},
                                       {'V', 5},
                                       {'X', 10},
                                       {'L', 50},
                                       {'C', 100},
                                       {'D', 500},
                                       {'M', 1000},
            };
        int sum = mp[s.back()];
        for(int i=s.length()-2; i>=0; i--){
            if(mp[s[i]]<mp[s[i+1]])
                sum -= mp[s[i]];
            else if(mp[s[i]]>=mp[s[i+1]])
                sum+=mp[s[i]];
        }
        return sum;
    }
};
