#include "LCG.h"

LCG::LCG(unsigned long long a, unsigned long long c, unsigned long long m, unsigned long long seed)
    : m_A(a), m_C(c), m_M(m), m_Seed(seed) {

}

unsigned long long LCG::Next() {
    m_Seed = (m_A * m_Seed + m_C) % m_M;
    return m_Seed;
}

unsigned long long LCG::NextInRange(unsigned long long min, unsigned long long max) {
    return Next() % (max - min + 1) + min;
}


