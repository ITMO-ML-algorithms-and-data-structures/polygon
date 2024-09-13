#include <iostream>
#include <vector>

int uniqe(std::vector<int>& v){
    int n = v.size(), ans = 0;

    for (size_t i = 0; i < n; ++i){
        int a = v[i];

        while (a%2 == 0){
            a = a/2;
        }
        if (a == 1){
            ++ans;
        }
    }

    return ans;
}

int main(){
    std::vector<int> v = {1,2,3,4,5,7,5,6,7,256,9, 8, 8, 8, 4096};

    int ans = uniqe(v);

    std::cout << ans << "\n";
}