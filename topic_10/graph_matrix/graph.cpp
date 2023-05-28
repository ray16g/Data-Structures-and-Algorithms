#include<iostream>
#include<fstream>
#include<iomanip>

constexpr size_t map(char c)
{
    return c - 'A';
}

bool** createAdjacencyMatrix(int rows, int cols, bool defaultValue = false)
{
    bool** matrix{new bool*[rows]};
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new bool[cols];
        for (size_t j = 0; j < cols; ++j)
        {
            matrix[i][j] = defaultValue;
        }
        
    }

    return matrix;
    
}

void deleteAdjacencyMatrix(bool** matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    
}

void printMatrix(bool** matrix, size_t rows, size_t cols)
{

    std::cout << std::left << std::boolalpha << std::setw(5) << ' ';

    for (size_t i = 0; i < rows; i++)
    {
        std::cout << std::setw(7) << static_cast<char>('A' + i);
    }
    std::cout << std::endl;

    for (size_t i = 0; i < rows; ++i)
    {
        std::cout << static_cast<char>('A' + i) << std::setw(2) << " ";
        for (size_t j = 0; j < cols; ++j)
        {
            std::cout << std::setw(7) << matrix[i][j];
        }
        std::cout << std::endl;
        
    }
    
}

int main(int argc, char const *argv[])
{
    // load from file
    std::ifstream in("graph.dat");
    bool **matrix{nullptr};
    int rows;
    size_t adjQty;
    char v;
    size_t vIdx;
    in >> rows;

    matrix = createAdjacencyMatrix(rows, rows);
    for (size_t i = 0; i < rows; ++i)
    {
        in >> v;
        vIdx = map(v);
        in >> adjQty;
        for (size_t j = 0; j < adjQty; ++j)
        {
            in >> v;
            matrix[vIdx][map(v)] = true;
        }
    }
    
    printMatrix(matrix, rows, rows);

    deleteAdjacencyMatrix(matrix, rows, rows);

    return 0;
}
