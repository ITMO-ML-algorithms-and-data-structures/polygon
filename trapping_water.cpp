class Solution {
public:
    int trap(vector<int>& height) {
        int max_height = 0;
        for (int i = 0; i<height.size(); i++) {
            if (height[i] > max_height) {
                max_height = height[i];
            }
        }

        int last_highest_index = 0;
        for (int i = height.size()-1; i>=0; i--) {
            if (height[i] == max_height) {
                last_highest_index = i;
                break;
            }
        }
        
        int summa = 0;
        bool switch_direction = false;
        int first_max = height[0];
        unsigned short first_index = 0;
        int second_max = 0;
        unsigned short second_index = 0;
        unsigned short index_to_stop = 0;

        for (int i = 1; i<height.size(); i++) {
            if (first_max == max_height && first_index == last_highest_index) {
                index_to_stop = first_index;
                switch_direction = true;
                break;
            }
            if (height[i] >= first_max) {
                second_max = height[i];
                second_index = i;
                if (second_index - first_index > 1) {
                    for (int j = first_index+1; j<second_index; j++) {
                        summa += (first_max - height[j]);
                    }
                }
                first_max = second_max;
                first_index = second_index;
            }
        }

        if (switch_direction == true) {
            first_max = height.back();
            first_index = height.size() - 1;
            for (int i = height.size() - 2; i >= index_to_stop; --i) {
                if (height[i] >= first_max) {
                    int second_max = height[i];
                    int second_index = i;
                    if (first_index > second_index && (first_index - second_index) > 1) {
                        for (int j = first_index - 1; j > second_index; --j) {
                            summa += first_max - height[j];
                        }
                    }
            first_max = second_max;
            first_index = second_index;
                }
            }
        }
        return summa;
    }
};
//
