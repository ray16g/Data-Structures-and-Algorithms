#include<unordered_map>
#include<string>
#include<fstream>
#include<iostream>

void decompress(std::string inputFile, std::string outputFile)
{
    std::unordered_map<int, std::string> table(1024);
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);

    for(int i{0}; i < 256; i++)
    {
        std::string s{static_cast<char>(i)};
        table[i] = s;
    }

    int curr, prev;
    int count{256};
    in >> curr;
    out << table[curr];
    prev = curr;

    while(in >> curr)
    {
        std::string P, C;
        if (table[curr] != "")
		{
			out << table[curr];
            table[count] = table[prev] + table[curr][0];
		}
		else 
		{
            table[count] = table[prev] + table[prev][0];
			out << (table[prev] + table[prev][0]);
		}
		count++;
		prev = curr;
    }

    in.close();
    out.close();
}

int main(int argc, char const *argv[])
{
    decompress("../text_compression/compressed.txt", "decompressed.txt");
    return 0;
}
