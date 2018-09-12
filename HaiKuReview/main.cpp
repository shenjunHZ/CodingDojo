#include "HaiKuReview.h"
#include <iostream>

int main(int argc, char* argv[])
{
    HaiKuReview review("computer programs/the bugs try to eat my code/i must not let them");
    review.setReview("happy purple frog/eating bugs in the marshes/get indigestion");

    int iLine = review.getLineCounters();
    std::cout << "HaiKu review line: " << iLine<<std::endl;

    int iLen = review.getTotalCharacters();
    std::cout << "HaiKu review length: " << iLen << std::endl;

    bool bHave = review.haveNotLowercastCharacters();
    std::cout << "HaiKu review have not lowercast: " << (bHave ? "yes" : "no") << std::endl;

    bool bResult = review.getSyllableResult();
    std::cout << "this is HaiKu: " << (bResult ? "yes" : "no") << std::endl;

    system("pause");
    return 0;
}