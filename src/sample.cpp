#include <vector>
#include <unordered_set> 
#include <iostream>

// рандомчики.
uint32_t RAND_SEED = 52;

uint32_t linrand32() {
    return RAND_SEED = RAND_SEED * 9823489423 + 8234234;
}

uint32_t xorshift32() // src:wiki
{
	RAND_SEED ^= RAND_SEED << 13;
	RAND_SEED ^= RAND_SEED >> 17;
	RAND_SEED ^= RAND_SEED << 5;
	return RAND_SEED;
}


// pick whatever vibes w/ ya
// #define RAND() linrand32();
#define RAND() xorshift32()

std::vector<int> sample(const int& size, const std::vector<int>& input) { // вроде как всевышний говорит, что это похоже на перемешивания монте-карло, и оно работает в среднем за o(n)
    std::unordered_set<size_t> idxs; // O(n) по памяти
    std::vector<int> output(size);   // O(n) по памяти
    for (auto inputIter = input.rbegin(); inputIter != input.rend(); ++inputIter) {
        size_t idx; // O(1) по памяти
        do {
            idx = RAND();     // O(1) по времени
            idx = idx % size; // O(1) по времени
        } while (idxs.find(idx) != idxs.end()); // O(1) в лучшем, O(n) в среднем, если бог рандома меня накажет - будет O(n^2). буду верит в лучшее (не хочу писать Фишера-Йетиса)
        idxs.insert(idx); output[idx] = *inputIter; // O(1) + O(1) соответственно 
    }
    return output;

    /* итого - o(n) по памяти и в среднем o(n) по времени */
}
