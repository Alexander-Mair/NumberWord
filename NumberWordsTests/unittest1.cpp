#include "stdafx.h"
#include <algorithm>
#include "CppUnitTest.h"
#include "../NumberWords/NumberWords.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumberWordsTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(WordForZero)
		{
			std::string numberWord = "zero";
			Assert::AreEqual(formatNumber(0), numberWord);
			// TODO: Your test code here
		}

		TEST_METHOD(TeensContainTeenSuffix)
		{
			for (int i = 13; i < 20; i++)
			{
				Assert::IsTrue(endsWith_secApproach(formatNumber(i), "teen"));
			}
		}
		TEST_METHOD(TensContainsTySuffix)
		{
			for (int i = 20; i <= 90; i += 10)
			{
				Assert::IsTrue(endsWith_secApproach(formatNumber(i), "ty"));
			}
		}

		TEST_METHOD(NumberWordContainsHyphenWhenTensIsNotZero)
		{
			size_t fail = -1;
			Assert::AreNotEqual(formatNumber(92).find("-"), fail);
		}

		TEST_METHOD(NumberWordDoesntContainHyphenWhenTensIsZero)
		{
			size_t success = -1;
			Assert::AreEqual(formatNumber(102).find("-"), success);
			Assert::AreEqual(formatNumber(2).find("-"), success);
			
		}

		TEST_METHOD(NumberWordContainsAndWhenHundredsNotZero)
		{
			size_t fail = -1;
			Assert::AreNotEqual(formatNumber(102).find("and"), fail);
		}

		TEST_METHOD(NumberWordContainsHundredWhenHundredsNotZero)
		{
			size_t fail = -1;
			for (int i = 100; i <= 900; i += 100)
			{
				
				Assert::AreNotEqual(formatNumber(i).find("hundred"), fail); 
			}
		}
		TEST_METHOD(NumberWordContainsThousandWhenThousandsNotZero)
		{
			size_t fail = -1;
			for (int i = 1000; i <= 10000; i += 1000)
			{
				Assert::AreNotEqual(formatNumber(i).find("thousand"), fail);
			}
		}
		bool endsWith_secApproach(const std::string &mainStr, const std::string &toMatch)
		{
			auto it = toMatch.begin();
			return mainStr.size() >= toMatch.size() &&
				std::all_of(std::next(mainStr.begin(), mainStr.size() - toMatch.size()), mainStr.end(), [&it](const char & c) {
				return c == *(it++);
			});
		}

	};
}