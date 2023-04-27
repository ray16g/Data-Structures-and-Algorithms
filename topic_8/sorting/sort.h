#include<functional>

#ifndef SORT_H
#define SORT_H



template<typename T>
class Sort
{
    using Comparator = std::function<bool(const T&, const T&)>;
public:
    static void selectSort(T array[], size_t count, Comparator compare)
    {
        size_t extrema;

        for (size_t i = 0; i < count - 1; ++i)
        {
            extrema = getExtrema(array, i, count - 1, compare);
            if(i != extrema)
                swap(array, i, extrema);

        }
        
    }

private:
    static size_t getExtrema(T array[], size_t start, size_t end, Comparator compare)
    {
        size_t extrema{start};

        for (size_t i = start; i < end; ++i)
        {
            if(compare(array[extrema], array[i]))
                extrema = i;
        }

        return extrema;
        
    }

    static void swap(T array[], size_t a, size_t b)
    {
        T temp{array[a]};
        array[a] = array[b];
        array[b] = temp;
    }
};

#endif