#include <iostream>


using namespace std;


int main() {
    string text;
    int counter = 0;
    std::cin >> text;
    int ans= 0;
    for (int i = 0;i < text.size();i++){
        if (text[i] == '('){
            counter += 1;
        } else{
            if (counter > 0){
                ans += 1;
                counter-= 1;
            }

        }
    }
    std::cout << ans;
    return 0;
}