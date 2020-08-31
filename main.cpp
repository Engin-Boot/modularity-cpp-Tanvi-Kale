#include <iostream>
#include <assert.h>

#include "TelCoColorCoder.h"

void  ToString()                          
{
    using namespace TelCoColorCoder;
    int pairNumber;
    int numberOfMinorColors, numberOfMajorColors;
    int totalColorPairs=numberOfMinorColors*numberOfMajorColors;
    
    std::cout << std::endl << "Color Code Manual"<< std::endl;
    for(pairNumber=1;pairNumber<=totalColorPairs;pairNumber++)
    {
	TelCoColorCoder::ColorPair colorPair[totalColorPair];
        TelCoColorCoder::ColorPair colorPair[pairNumber] =
            TelCoColorCoder::GetColorFromPairNumber(pairNumber);

        std::cout << pairNumber <<"." << colorPair.ToString() << std::endl;
    }

}

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    return 0;
}
