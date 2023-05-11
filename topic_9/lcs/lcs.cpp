#include<iostream>

size_t lcs(const std::string& S, const std::string& T, int i, int j)
{
    if(i < 0 || j < 0) return 0;

    if(S[i] == T[j])
    {
        return 1 + lcs(S, T, i - 1, j - 1);
    }
    return std::max(lcs(S, T, i, j - 1), lcs(S, T, i - 1, j));
}

size_t lcs(const std::string& S, const std::string& T)
{
    return lcs(S, T, S.size() - 1, T.size() - 1);
}

int main(int argc, char const *argv[])
{
    std::cout << lcs("acgtac", "gctaact");
    return 0;
}
