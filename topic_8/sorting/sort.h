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
        std::vector<int> src[2];

        for (size_t i = 0; i < count; ++i)
        {
            ((array[i] & mask) ? src[1] : src[0]).push_back(array[i]);
        }
        
        sortBuckets(src);
        
        index = 0;
        for (size_t i = 0; i < src[0].size(); ++i)
            array[index++] = src[0][i];
        
        for (size_t i = 0; i < src[1].size(); ++i)
            array[index++] = src[1][i];
    }

    
    static void mergeSort(T array[], size_t count)
    {
        mergeSort(array, 0, count - 1);
    }

    static void quickSort(T array[], size_t count)
    {
        quickSort(array, 0, count - 1);
    }

    static T selection(const T array[], size_t count, size_t position)
    {

    }

private:
    
    static void swap(T& v1, T& v2)
    {
        T temp = v1;
        v1 = v2;
        v2 = temp;
    }

    static void quickSort(T array[], size_t start, size_t end)
    {
        if(start >= end) return;

        size_t r = partition(array, start, end, end);

        quickSort(array, start, r - 1);
        quickSort(array, r + 1, end);

    }

    static size_t partition(T array[], size_t start, size_t end, size_t p)
    {
        size_t pivotptr{end};
        size_t pivot{array[p]};
        size_t ptr{start};

        while(ptr < pivotptr)
        {
            while(array[ptr] < pivot && ptr < pivotptr)
            {
                ++ptr;
            }
            while(array[pivotptr] > pivot && ptr < pivotptr)
            {
                --pivotptr;
            }
            swap(array[ptr], array[pivotptr]);
        }

        return ptr;
    }

    static void merge(T array[], size_t start, size_t mid, size_t end)
    {
        size_t newArr[end - start + 1];

        size_t arrptr{0};

        size_t lptr{start};
        size_t rptr{mid + 1};

        while(lptr <= mid && rptr <= end)
        {
            if(array[lptr] < array[rptr])
                newArr[arrptr++] = array[lptr++];
            else
                newArr[arrptr++] = array[rptr++];
        }

        if(lptr <= mid)
        {
            for(; lptr <= mid; ++lptr)
                newArr[arrptr++] = array[lptr];
        }

        if(rptr <= end)
        {
            for(; rptr <= end; ++rptr)
                newArr[arrptr++] = array[rptr];
        }

        for (size_t i = start, j = 0; i <= end; i++, j++)
            array[i] = newArr[j];

    }

    static void mergeSort(T array[], size_t start, size_t end)
    {
        if(start >= end) return;

        size_t mid{start + (end - start) / 2};

        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);

        merge(array, start, mid, end);
    }

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

    static void sortBuckets(std::vector<int> in[])
    {
        std::vector<int> tmp[2];
        std::vector<int>* dst;
        std::vector<int>* src;

        for (size_t i = 1; i < sizeof(int) << 3; ++i)
        {
            src = (i & 1) ? in : tmp;
            dst = (i & 1) ? tmp : in;

            dst[0].clear();
            dst[1].clear();

            for(int j = 0; j < src[0].size(); ++j)
                (src[0][j] & (mask << i) ? dst[1] : dst[0]).push_back(src[0][j]);

            for(int j = 0; j < src[1].size(); ++j)
                (src[1][j] & (mask << i) ? dst[1] : dst[0]).push_back(src[1][j]);
        }
    }

    static void copyBuckets(std::vector<int> src[], std::vector<int> dst[])
    {
        for(int i = 0; i < 2; ++i)
        {
            dst[i].clear();
            for(int j = 0; j < src[i].size(); ++j)
                dst[i].push_back(src[i][j]);
        }
    }

    static void swap(T array[], size_t a, size_t b)
    {
        T temp{array[a]};
        array[a] = array[b];
        array[b] = temp;
    }
};

#endif