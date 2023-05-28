#include<string>
#include<fstream>
#include<iostream>

int letterCharToInt(char c)
{
    return c - 64;
}

int numCharToInt(char c)
{
    return c - 48;
}

int main(int argc, char const *argv[])
{
    std::string str;
    bool** arr;
    std::ifstream file("graph.dat");
    int i{0};

    if(file.is_open())
    {
        std::getline(file, str);

        int size{numCharToInt(str[0])};
        arr = new bool*[size];

        while(std::getline(file, str))
        {
            int size{numCharToInt(str[2])};
            arr[i] = new bool[size];

            for(int k = 0; k < size; k++)
            {
                for(int l = 0; l < size; l++)
                {
                    arr[k][l] = 0;
                }
            }

            for(int j{4}; j < str.length(); j+=2)
            {
                int index = letterCharToInt(str[j]);
                arr[i][index] = true;
            }

            i++;
        }
    }

    file.close();

    for(int j = 0; j < 9; j++)
    {
        for(int k = 0; k < 9; k++)
        {
            std::cout << arr[j][k] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
