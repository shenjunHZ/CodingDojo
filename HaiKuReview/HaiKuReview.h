#pragma once

#include <string>

constexpr int LINECOUNT = 3;

class HaiKuReview
{
public:
    HaiKuReview(std::string strReview);

    int getLineCounters();
    int getTotalCharacters();
    bool haveNotLowercastCharacters();
    bool getSyllableResult();
    void setReview(std::string strSource);

private:
    bool isHaveSyllable(std::string strSource);
    int haveSyllables(std::string strSource);

private:
    std::string m_strReview;
    std::string m_strLines[LINECOUNT];
};