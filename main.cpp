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
        switch (questionDifficulty) {
            case QuestionDifficulty::EASY: {
                int left = RandomNumberGenerator::Random(1, 10);
                int right = RandomNumberGenerator::Random(1, 10);

                char operator_ = GenRandElement({'+', '-'});

                return (std::to_string(left) + " " + operator_ + " " + std::to_string(right));
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
                std::cout << GenerateArithmeticQuestion(QuestionDifficulty::EASY) << std::endl;
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
    MathQuestionGenerator::GenerateQuestions(0, QuestionType::BASIC_ARITHMETIC, QuestionDifficulty::EASY);
    return 0;
}

