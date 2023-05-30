#include <iostream>
#include <stdexcept>

#include "lzw.h"

void printUsage(const std::string&);
void processArgs(char const *argv[]);

std::string paths[2];
OPS op;

int main(int argc, char const *argv[])
{
    if(argc != 4)
    {
        printUsage(argv[0]);
        return 1;
    }

    processArgs(argv);

    try
    {
        lzw(paths[0], paths[1], op);
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
        return 1;
    }
    

    return 0;
}

void printUsage(const std::string& exe)
{
    system("cls");
    std::cout << "\tUsage: " << exe << "OP_SWITCH src_path dstPath\n\n";
    std::cout << "\tOP_SWITCHES:\n\n\t\t-c: compress\n\t\t-d: decompress\n\n";

}

void processArgs(char const *argv[])
{
    int idx{0};
    for (size_t i{1 }; i < 4; i++)
    {
        if(argv[i][0] == '-')
            op = (argv[i][1] == 'c') ? OPS::COMPRESS : OPS::DECOMPRESS;
        else
            paths[idx++] = argv[i];
    }
}
