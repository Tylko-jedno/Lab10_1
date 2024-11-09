#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <sstream>
#include "../Lab10_1/Lab10_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace StudentTests
{
    TEST_CLASS(StudentTests)
    {
    public:

        TEST_METHOD(TestVidminnikiSearch)
        {
            const int N = 2;
            Student students[N];

            students[0] = { "Ivanov", I, KN, 5, 5,};
            students[0].markProgramming = 5;
            students[1] = { "Petrov", II, IT, 4, 4};
            students[1].markNumericalMethods = 3;

            // Перенаправлення виводу для перевірки
            stringstream buffer;
            streambuf* oldCoutStreamBuf = cout.rdbuf();
            cout.rdbuf(buffer.rdbuf());

            VidminnikiSearch(students, N);

            // Відновлення стандартного потоку виводу
            cout.rdbuf(oldCoutStreamBuf);

            // Отримуємо результат у вигляді рядка
            string output = buffer.str();
            Assert::IsTrue(output.find("Ivanov") != string::npos);
            Assert::IsTrue(output.find("Petrov") == string::npos);
        }

        TEST_METHOD(TestNeVidminnikiSearch)
        {
            const int N = 3;
            Student students[N];

            students[0] = { "Ivanov", I, KN, 3, 3};
            students[0].markProgramming = 3;
            students[1] = { "Petrov", II, IT, 2, 3};
            students[1].markNumericalMethods = 2;
            students[2] = { "Sidorov", III, FI, 4, 4};
            students[2].markPedagogy = 4;

            // Перенаправлення виводу для перевірки
            stringstream buffer;
            streambuf* oldCoutStreamBuf = cout.rdbuf();
            cout.rdbuf(buffer.rdbuf());

            NeVidminnikiSearch(students, N);

            // Відновлення стандартного потоку виводу
            cout.rdbuf(oldCoutStreamBuf);

            // Отримуємо результат у вигляді рядка
            string output = buffer.str();
            Assert::IsTrue(output.find("Ivanov") != string::npos);
            Assert::IsTrue(output.find("Petrov") != string::npos);
            Assert::IsTrue(output.find("Sidorov") == string::npos);
        }
    };
}
