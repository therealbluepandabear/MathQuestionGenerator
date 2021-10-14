#include <iostream>
#include <ctime>
#include <random>

enum class QuestionDifficulty {
    EASY, MEDIUM, HARD, ADVANCED
};

enum class QuestionType {
    BASIC_ARITHMETIC, ALGEBRA
};

class RandomNumberGenerator {
public:
    // NAWAZ'S STACKOVERFLOW CODE LINK: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    static int Random(const int min, const int max) {
        static bool first = true;
        if (first) {
            srand( time(nullptr) );
            first = false;
        }
        return min + rand() % (( max + 1 ) - min);
    }
};

class MathQuestionGenerator {
private:
    static int ToArithmeticAnswer(const int left, const int right, const std::string &operationStr) {
        switch (operationStr[0]) {
            case '+':
                return left + right;
                break;
            case '-':
                return left - right;
                break;
            case '*':
                return left * right;
                break;
            case '/':
                return left / right;
                break;
        }
    }
    static std::pair<const std::string, const double> GenerateArithmeticQuestion(const QuestionDifficulty questionDifficulty) {
        switch (questionDifficulty) {
            case QuestionDifficulty::EASY: {
                bool isAddition;
                if (RandomNumberGenerator::Random(1, 2) == 1) isAddition = true; else isAddition = false;

                int left = RandomNumberGenerator::Random(1, 10);
                int right = RandomNumberGenerator::Random(1, 10);

                std::string operationStr;

                if (isAddition) operationStr = "+"; else operationStr = "-";

                return std::make_pair(std::to_string(left) + " " + operationStr + " " + std::to_string(right),
                                      ToArithmeticAnswer(left, right, operationStr));
                break;
            }
            case QuestionDifficulty::MEDIUM: {

                break;
            }
            case QuestionDifficulty::HARD: {

                break;
            }
            case QuestionDifficulty::ADVANCED: {

                break;
            }
        }
    }
public:
    static void GenerateQuestions(const int amount, const QuestionType questionType, const QuestionDifficulty questionDifficulty) {
        switch (questionType) {
            case QuestionType::BASIC_ARITHMETIC:
                break;
            case QuestionType::ALGEBRA:
                break;
        }
    }
};

int main() {
    return 0;
}

