/*
Copyright (c) 2018 Inverse Palindrome
JATR66 - RayCastData.cpp
InversePalindrome.com
*/


#include "RayCastData.hpp"


bool operator<(const RayCastData& rayCastData1, const RayCastData& rayCastData2)
{
	return rayCastData1.fraction < rayCastData2.fraction;
}