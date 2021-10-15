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
    static char GenRandElement(std::vector<char> vector) {
        return vector[rand() % vector.size()];
    }

    static const std::string GenerateArithmeticQuestion(const QuestionDifficulty questionDifficulty) {
        std::string val;
        switch (questionDifficulty) {
            case QuestionDifficulty::EASY: {
                val = (
                        std::to_string(RandomNumberGenerator::Random(1, 10)) +
                        " " +
                        GenRandElement({'+', '-'}) +
                        " " +
                        std::to_string(RandomNumberGenerator::Random(1, 10))
                        );
                break;
            }
            case QuestionDifficulty::MEDIUM: {
                val = (
                        std::to_string(RandomNumberGenerator::Random(1, 20)) +
                        " " +
                        GenRandElement({'+', '-'}) +
                        " " +
                        std::to_string(RandomNumberGenerator::Random(1, 20))
                );
                break;
            }
            case QuestionDifficulty::HARD: {
                val = (
                        std::to_string(RandomNumberGenerator::Random(1, 15)) +
                        " " +
                        GenRandElement({'*', '/'}) +
                        " " +
                        std::to_string(RandomNumberGenerator::Random(1, 15))
                );
                break;
            }
            case QuestionDifficulty::ADVANCED: {
                val = (
                        std::to_string(RandomNumberGenerator::Random(1, 25)) +
                        " " +
                        GenRandElement({'*', '/'}) +
                        " " +
                        std::to_string(RandomNumberGenerator::Random(1, 25))
                );
                break;
            }
        }
        return val;
    }

public:
    static void GenerateQuestion(const QuestionType questionType, const QuestionDifficulty questionDifficulty) {
        switch (questionType) {
            case QuestionType::BASIC_ARITHMETIC:
                std::cout << GenerateArithmeticQuestion(questionDifficulty) << "\n";
                break;
            case QuestionType::ALGEBRA:
                break;
        }
    }
};

static int ToArithmeticAnswer(const int left, const int right, const char operationStr) {
    switch (operationStr) {
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

int main() {
    for (int i = 0; i < 20; ++i) {
        MathQuestionGenerator::GenerateQuestion(QuestionType::BASIC_ARITHMETIC, QuestionDifficulty::EASY);
    }
    return 0;
}

