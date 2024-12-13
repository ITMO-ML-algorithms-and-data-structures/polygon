class Solution {
public:

    int summ(int i, vector<int>& satisfaction){
        int n = satisfaction.size();
        int resSum = 0;
        for (int j = i+1; j < n;++j){
            resSum += satisfaction[j];
        }
        return resSum;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int full_sum = 0;
        int counter = 1;
        bool checker = false;
        for (int i = 0; i < n;++i){
            if (!checker){
                if (satisfaction[i] >= 0){
                    full_sum += counter*satisfaction[i];
                    counter++; 
                }
                if (satisfaction[i] < 0 && ((abs(satisfaction[i])*counter - summ(i, satisfaction)) <= 0)){
                    checker = true;
                    full_sum += counter*satisfaction[i];
                    counter++; 
                }
            }
            else{
                    full_sum += counter*satisfaction[i];
                    counter++; 
            }
        }
        return full_sum;
    }
};