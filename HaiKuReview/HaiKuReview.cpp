#include "HaiKuReview.h"

#include <regex>

HaiKuReview::HaiKuReview(std::string strReview)
    : m_strReview(strReview)
{

}

int HaiKuReview::getTotalCharacters()
{
    int iCount = 0;
    for (int iIndex = 0; iIndex < LINECOUNT; iIndex++)
    {
        iCount += m_strLines[iIndex].size();
    }

    return iCount;
}

bool HaiKuReview::haveNotLowercastCharacters()
{
    std::regex rex("[^a-z ]");
    std::smatch strMatch;
    for (int iIndex = 0; iIndex < LINECOUNT; iIndex++)
    {
        regex_search(m_strLines[iIndex], strMatch, rex);
        if (!strMatch.empty())
        {
            std::string sMatch = strMatch.str();
            return true;
        }
    }

    return false;
}

int HaiKuReview::getLineCounters()
{
    if (0 == m_strReview.compare(""))
    {
        return 0;
    }

    std::size_t pos = m_strReview.find_first_of("/");
    if (std::string::npos == pos)
    {
        return 1;
    }

    m_strLines[0] = m_strReview.substr(0, pos);
    std::string strReview = m_strReview.substr(pos + 1);
    if (0 == strReview.compare(""))
    {
        return 1;
    }

    pos = strReview.find_first_of("/");
    if (std::string::npos == pos)
    {
        return 2;
    }
    m_strLines[1] = strReview.substr(0, pos);
    m_strLines[2] = strReview.substr(pos + 1);
    
    return 3;
}

bool HaiKuReview::getSyllableResult()
{
    for (int iIndex = 0; iIndex < LINECOUNT; iIndex++)
    {
        if (m_strLines[iIndex].empty())
        {
            return false;
        }

        std::string strSource = m_strLines[iIndex];
        std::size_t pos = std::string::npos;
        do 
        {
            pos = strSource.find_first_of(' ');
            if (std::string::npos == pos)
            {
                if (!isHaveSyllable(strSource))
                {
                    return false;
                }
            }
            else
            {
                std::string word = strSource.substr(0, pos);
                if (!isHaveSyllable(word))
                {
                    return false;
                }
                word = strSource.substr(pos + 1);
                strSource = word;
            }
        } while (std::string::npos != pos);

        int iCount = haveSyllables(m_strLines[iIndex]);
        if (0 == iIndex)
        {
            if (5 != iCount)
            {
                return false;
            }
        }
        else if (1 == iIndex)
        {
            if (7 != iCount)
            {
                return false;
            }
        }
        else
        {
            if (5 != iCount)
            {
                return false;
            }
        }
    }

    return true;
}

void HaiKuReview::setReview(std::string strSource)
{
    m_strReview = strSource;
}

bool HaiKuReview::isHaveSyllable(std::string strSource)
{
    if (strSource.empty())
    {
        return false;
    }
    std::regex rex("[aeiouy]");
    std::smatch strMatch;
    return regex_search(strSource, strMatch, rex);
}

int HaiKuReview::haveSyllables(std::string strSource)
{
    if (strSource.empty())
    {
        return 0;
    }

    int iCount = 0;
    bool bMatch = false;
    for_each(strSource.begin(), strSource.end(), [&iCount, &bMatch]( char ch)
    {
        if (('a' == ch || 'e' == ch
            || 'u' == ch || 'o' == ch
            || 'y' == ch || 'i' == ch) && !bMatch)
        {
            iCount++;
            bMatch = true;
        }
        else
        {
            bMatch = false;
        }
    });
   
    return iCount;
}
