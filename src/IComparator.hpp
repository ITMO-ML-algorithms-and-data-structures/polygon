#ifndef ICOMPARATOR
#define ICOMPARATOR

template <typename T>

class IComparable {
public:
    virtual int compareTo(const T& v1, const T& v2) const = 0;
    virtual ~IComparable() = default;
};


#endif