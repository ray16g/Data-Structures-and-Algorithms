#include <unordered_map>
#include <string>

#include "lzw.h"

void compress(std::ifstream& in, std::ofstream& out)
{
    uint16_t code{1};
    uint16_t v;
    const uint16_t zero{0};
    std::string subStr{};
    char c;
    std::unordered_map<std::string, uint16_t> codebook;

    while(in)
    {
        in.read(&c, 1);
        
        if(codebook.find(subStr + c) != codebook.end())
        {
            subStr += c;
        }
        else
        {
            v = (subStr.empty()) ? 0 : codebook[subStr];
            out.write((char*)&v, 2);
            out.write(&c, 1); 
            if(code <= CB_LIMIT) codebook[subStr + c] = code++;
            subStr = "";
        }
    }

}

void decompress(std::ifstream& in, std::ofstream& out)
{

}

void lzw(std::string& src, std::string& dst, OPS op)
{
    std::ifstream in;
    std::ofstream out;
    openInfile(src, in);

    if(!in) throw std::runtime_error("failed to open input file");
    
    openOutfile(dst, out);

    if(!out) throw std::runtime_error("failed to open output file");

    if(op == COMPRESS) compress(in, out);
    else decompress(in, out);

}

void openInfile(const std::string& path, std::ifstream& file)
{
    file.open(path, std::ios::binary);
}

void openOutfile(const std::string& path, std::ofstream& file)
{
    file.open(path, std::ios::binary);
}