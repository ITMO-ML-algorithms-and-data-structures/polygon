#include <iostream>
#include <vector>
#include <cassert>
using namespace std;//позволяет не проставлять std каждый раз
vector<int> find_singular(vector<int>& elements)
{
    vector<int> singular_arr;
    vector<bool> seen(10000, false);
    for (int num : elements)
    {
        if (not(seen[num]) == true)
        {
            singular_arr.push_back(num);
            seen[num] = true;
        }
    }
    return singular_arr;
}
int main()
{
    // тест пустого списка
    vector<int> emptyList;
    vector<int> expectedEmptyList;
    vector<int> resultEmptyList = find_singular(emptyList);
    assert(resultEmptyList == expectedEmptyList);

    // тест списка с одним эл-том
    vector<int> singleElementList = {1};
    vector<int> expectedSingleElementList = {1};
    vector<int> resultSingleElementList = find_singular(singleElementList);
    assert(resultSingleElementList == expectedSingleElementList);

    // тест списка с повторяющимися эл-тами
    vector<int> duplicateList = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    vector<int> expectedDuplicateList = {1, 2, 3, 4};
    vector<int> resultDuplicateList = find_singular(duplicateList);
    assert(resultDuplicateList == expectedDuplicateList);

    cout << "tests completed" << endl;
    return 0;
}