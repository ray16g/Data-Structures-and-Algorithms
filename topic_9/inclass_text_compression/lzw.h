#include <string>
#include <fstream>

#ifndef LZW_H
#define LZW_H

#define CB_LIMIT 1024

enum OPS
{
    COMPRESS,
    DECOMPRESS
};

void lzw(std::string&, std::string&, OPS);
void openInfile(const std::string&, std::ifstream&);
void openOutfile(const std::string&, std::ofstream&);
void compress(std::ifstream&, std::ofstream&);
void decompress(std::ifstream&, std::ofstream&);

#endif