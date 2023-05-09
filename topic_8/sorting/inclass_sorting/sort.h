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

    static void quickSort(T array[], size_t size)
    {
        if(size <= 1) return;

        quickSort(array, 0, size - 1);
    }

    static void mergeSort(T array[], size_t size)
    {
        if(size <= 1) return;
        static T* tmp{new T[size]};

        mergeSort(array, 0, size - 1, tmp);

        delete[] tmp;
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

        size_t pivot{partition(array, start, end)};

        if(start < pivot)
            quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);

    }

    static size_t partition(T array[], size_t start, size_t end)
    {
        size_t idx{start};
        size_t pivotIdx{start};

        for(; idx < end; ++idx)
        {
            if(array[idx] > array[end]) continue;

            if(pivotIdx != idx) swap(array[idx], array[pivotIdx]);

            ++pivotIdx;
        }

        swap(array[end], array[pivotIdx]);

        return pivotIdx;
    }

    static void mergeSort(T array[], size_t start, size_t end, T tmp[])
    {
        if(start >= end) return;

        size_t mid((start + end) >> 1);

        mergeSort(array, start, mid, tmp);
        mergeSort(array, mid + 1, end, tmp);

        merge(array, start, mid, end, tmp);
    }

    static void merge(T array[], size_t start, size_t mid, size_t end, T tmp[])
    {
        size_t leftIdx{start};
        size_t rightIdx{mid + 1};
        size_t arrayIdx{start};

        copyPartition(array, tmp, start, end);

        while(leftIdx <= mid && rightIdx <= end)
            array[arrayIdx++] = (tmp[leftIdx] <= tmp[rightIdx]) ? tmp[leftIdx++] : tmp[rightIdx++];

        while(leftIdx <= mid)
            array[arrayIdx++] = tmp[leftIdx++];

        while(rightIdx <= end)
            array[arrayIdx++] = tmp[rightIdx++];

    }

    static void copyPartition(T src[], T dst[], size_t start, size_t end)
    {
        for(size_t i = start; i <= end; ++i)
        {
            dst[i] = src[i];
        }
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