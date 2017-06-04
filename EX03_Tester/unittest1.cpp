#include "stdafx.h"
#include <CppUnitTest.h>
#include "readint.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EX03_Tester
{		
	TEST_CLASS(READINT_TEST) //Test suite for read_int()
	{
	public:

		TEST_METHOD(TestCase1) //Test case 1: invalid input
		{
			// crate a string stream object with the desired input
			/*
			If you see this, I need help getting the program reading from the file,
			as the only reason I made it a string stream was because I couldn't
			get the other way to work.
			*/
			istringstream ss("Hello\n0");

			// Replace the cin read buffer with the read buffer from the string stream 
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			// cin will now read contents from your stringstream and not from the keyboard.
			// We expect the correct value returned is 0, ignoring the Hello string.
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			// Restore cin to the way it was before
			cin.rdbuf(orig_cin);
		}

		TEST_METHOD(TestCase2) //Expect invalid argument exception thrown
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 5, 1);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestCase3) //Expect 3 to be returned by the function
		{
			// crate a string stream object with the desired input
			/*
			If you see this, I need help getting the program reading from the file,
			as the only reason I made it a string stream was because I couldn't
			get the other way to work.
			*/
			istringstream ss("-3\n5\n10\n-2\n3");

			// Replace the cin read buffer with the read buffer from the string stream 
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			// cin will now read contents from your stringstream and not from the keyboard.
			// We expect the correct value returned is 0, ignoring the Hello string.
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			// Restore cin to the way it was before
			cin.rdbuf(orig_cin);
		}

		TEST_METHOD(TestCase4) //Expect invalid argument exception thrown
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 0, 0);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}