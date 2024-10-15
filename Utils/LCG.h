#pragma once

class LCG {
public:
    LCG(unsigned long long a, unsigned long long c, unsigned long long m, unsigned long long seed);

    unsigned long long Next();
    unsigned long long NextInRange(unsigned long long min, unsigned long long max);

private:
    unsigned long long m_A;
    unsigned long long m_C;
    unsigned long long m_M;
    unsigned long long m_Seed;
};
