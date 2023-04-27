#include<functional>

#ifndef SORT_H
#define SORT_H

#define mask 1

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

    static void radixSort(int array[], size_t count)
    {
        int index;
        std::vector<int> src0;
        std::vector<int> src1;

        for (size_t i = 0; i < count; ++i)
        {
            ((array[i] & mask) ? src1 : src0).push_back(array[i]);
        }
        
        sortBuckets(src0, src1);
        
        index = 0;
        for (size_t i = 0; i < src0.size(); ++i)
            array[index++] = src0[i];
        
        for (size_t i = 0; i < src1.size(); ++i)
            array[index++] = src1[i];

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

    static void sortBuckets(std::vector<int>& src0, std::vector<int>& src1)
    {
        std::vector<int> dst0;
        std::vector<int> dst1;

        for (size_t i = 1; i < sizeof(int) << 3; ++i)
        {
            dst0.clear();
            dst1.clear();

            for(int j = 0; j < src0.size(); ++j)
                (src0[j] & (mask << i) ? dst1 : dst0).push_back(src0[j]);

            for(int j = 0; j < src1.size(); ++j)
                (src1[j] & (mask << i) ? dst1 : dst0).push_back(src1[j]);
            
            copyBuckets(dst0, src0);
            copyBuckets(dst1, src1);
        }
    }

    static void copyBuckets(std::vector<int>& src, std::vector<int>& dst)
    {
        dst.clear();
        for(int j = 0; j < src.size(); ++j)
            dst.push_back(src[j]);
    }

    static void swap(T array[], size_t a, size_t b)
    {
        T temp{array[a]};
        array[a] = array[b];
        array[b] = temp;
    }
};

#endif