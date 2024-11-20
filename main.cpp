#include <limits>
#include <vector>
#include <iostream>
//hard+
//Дан массив чисел, требуется найти пару чисел, произведение которых максимально
template<typename T>
T get_max_mult(const std::vector<T>& v)
{
        if(v.size() == 0)
                return 0;
        else if(v.size() == 1)
                return v[0];
        else if(v.size() == 2)
                return v[0] * v[1];
        else
        {
                T max1 = std::numeric_limits<T>::max(), max2 = std::numeric_limits<T>::max();
                for(size_t i = 0; i < v.size(); ++i)
                        if(v[i] >= max1)
                        {
                                max2 = max1;
                                max1 = v[i];
                        }
                return max1 * max2;
        }       
}
template<typename T>
T get_max_mult(const T v[], size_t size)
{
        if(size == 0)
                return 0;
        else if(size == 1)
                return v[0];
        else if(size == 2)
                return v[0] * v[1];
        else
        {
                T max1 = std::numeric_limits<T>::max(), max2 = std::numeric_limits<T>::max();
                for(size_t i = 0; i < size; ++i)
                        if(v[i] >= max1)
                        {
                                max2 = max1;
                                max1 = v[i];
                        }
                return max1 * max2;
        }       
}

int main()
{
        std::cout << get_max_mult<int>({1,2,3,4,5}) << std::endl;
        std::cout << get_max_mult<int>(new int[]{1,2,3,4,5,6,7}, 7) << std::endl;
}
