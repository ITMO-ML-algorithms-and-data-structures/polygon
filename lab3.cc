#include "lab3.h"
#include <vector>
#include <map>

#include "limits"
std::vector<int> CPPLib::output_vector(std::vector<std::string> inputs) {
    std::vector<int> outputs(inputs.size());
    std::map<std::string, int> count_words;
    for (int i = 0; i<inputs.size(); i++) { // O(n)
        /* if (count_words.count(inputs[i]) == 0) {   // если делать через метод count, то O(logn*n), тк count за logn
            count_words[inputs[i]] = 1;  
        }
        else {
            count_words[inputs[i]] += 1;
        } */
        count_words[inputs[i]] +=1; // O(1)
    }
    for (int i = 0; i<inputs.size(); i++) { // O(n)
        outputs[i] = count_words[inputs[i]]; // O(1)
    } // итог: O(n+1) + O(n+1) = O(n) итоговая асимптотика
    return outputs;
}