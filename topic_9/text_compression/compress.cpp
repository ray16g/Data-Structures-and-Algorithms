#include<unordered_map>
#include<string>
#include<fstream>
#include<iostream>

void encode(std::string inputFile, std::string outputFile)
{
    std::unordered_map<std::string, int> table(1024);
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);

    for(int i{0}; i < 256; i++)
    {
        std::string s{static_cast<char>(i)};
        table[s] = i;
    }

    char c;
    std::string str1 = "";
    size_t count{256};

    while(in.get(c))
    {
        std::string str2{c};
        if(table[str1 + str2])
        {
            str1 = str1 + str2;
        }
        else
        {
            out << table[str1] << " ";
            table[str1 + str2] = count;
            count++;
            str1 = str2;
        }
    }

    out << table[str1];

    in.close();
    out.close();
}

int main(int argc, char const *argv[])
{
    encode("../text_compression/Shakespeare.txt", "compressed.txt");
    return 0;
}
