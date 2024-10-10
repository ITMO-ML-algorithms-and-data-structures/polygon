#include <iostream>
#include <vector>
#include <string>
#include "lab-2.cpp"

using namespace std;

int main()
{
    vector<std::string> tests = {"pdglopizz", "kcnoqtlvipfabundrp", "wpwa", "twjtwndlribxaw", "cunzdkqiocm", "kymhudtftxqqblyhx", "nohvmumoh", "fzg", "axmwjzjevh", "hmgtoiteektjy", "gaxoqhvjiqpi", "c", "maelejthunbtooq", "otaak", "jc", "kfzf", "meo", "cunzdkqiocm", "ngkodaf", "tvxbdcer", "lmh", "wcqczda", "gaxoqhvjiqpi", "aoj", "qdrpjgxvjanpcfdds", "lgd", "ngkodaf", "lemvrcsidyorv", "lgd", "axmwjzjevh", "ojmhdaasymmbgfwcyxj", "slublxpnpbe", "lmh", "zirsfnyrunvmgtlf", "uoxpprkzhccajgnuipj", "slublxpnpbe", "lmh", "trmkfltdeucwjs", "gjjahwlzqnwnhicnw", "tynunhhppdrkib", "ngkodaf", "hdahtxbaeydmeofviqm", "cunzdkqiocm", "rzequdqau", "jbttfvczfgdhcdrkqovu", "frrcel", "onhlqnpjhdmqfut", "zknxjdziavli", "vteqrsxwrvwpudmap", "egit", "kmahus", "kxlbvjyunctdp", "fzg", "onhlqnpjhdmqfut", "hlmdbqdvguxt", "aoj", "kmahus", "wpwa", "slsvv", "aoj", "kfzf", "garbcdgzedrq", "kcnoqtlvipfabundrp", "pdglopizz", "qbrkuijluiikt", "ngkodaf", "qccflrnsbnwlrnjgccz", "lhaeasxrmkcjhgarbl", "pyslzgqnbsvyctbfegcr", "uoxpprkzhccajgnuipj", "odqo", "y", "uelbeogyfycthvi", "vteqrsxwrvwpudmap", "pyslzgqnbsvyctbfegcr", "rzequdqau", "ojmhdaasymmbgfwcyxj", "slublxpnpbe", "pdi", "lhaeasxrmkcjhgarbl", "meo", "aoj", "hjxayuamdyyszwuvrmzd", "jc", "xecnmserpjrjereqxbto", "nohvmumoh", "dzpslahkjvftt", "dzpslahkjvftt", "thoxsmmbarzejvpi", "pyslzgqnbsvyctbfegcr", "tvxbdcer", "pdglopizz", "kofhvlidzfjwjsab", "qtawknynj", "vnpzofkqahtz", "emqeyrwadmt", "rzequdqau"};
    bool answer = 0;
    int size_of_vector = tests.size();
    cout << size_of_vector;
    for (int i = 0; i < size_of_vector; i++) {
        for (int k = i + 1; k < size_of_vector; k++) {
            if (tests[i].length() == tests[k].length()) {
            answer = is_isomorf(tests[i], tests[k]);
            if (answer == 1) {
                cout << "words " << tests[i] << " and " << tests[k] << " are isomorfs" << endl;
            }
            else {
                cout << "words " << tests[i] << " and " << tests[k] << " are NOT isomorfs" << endl;
            }
            }
            else {
                cout << "not the same length" << endl;
            }
        }
    }
}