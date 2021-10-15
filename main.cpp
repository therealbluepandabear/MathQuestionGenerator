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
    struct question_t {
        int left, right;
        char operand;

        question_t(int _left, int _right, char _operand) {
            left = _left;
            right = _right;
            operand = _operand;
        }

        int GetAnswer() {
            switch (operand) {
                case '+': return left + right;
                case '-': return left - right;
                case '/': return left / right;
                case '*': return left * right;
            }
        }

        std::string ToString() {
            return std::to_string(left) + " " + operand + " " + std::to_string(right);
        }
    };
    static char GenRandElement(std::vector<char> vector) {
        return vector[rand() % vector.size()];
    }

    static const question_t GenerateArithmeticQuestion(const QuestionDifficulty questionDifficulty) {
        switch (questionDifficulty) {
            case QuestionDifficulty::EASY: {
                return question_t(
                        RandomNumberGenerator::Random(1, 10),
                        RandomNumberGenerator::Random(1, 10),
                        GenRandElement({'+', '-'}));
                break;
            }
            case QuestionDifficulty::MEDIUM: {
                return question_t(
                        RandomNumberGenerator::Random(1, 25),
                        RandomNumberGenerator::Random(1, 25),
                        GenRandElement({'+', '-'}));
                break;
            }
            case QuestionDifficulty::HARD: {
                return question_t(
                        RandomNumberGenerator::Random(1, 10),
                        RandomNumberGenerator::Random(1, 10),
                        GenRandElement({'*', '/'}));
                break;
            }
            case QuestionDifficulty::ADVANCED: {
                return question_t(
                        RandomNumberGenerator::Random(1, 25),
                        RandomNumberGenerator::Random(1, 25),
                        GenRandElement({'*', '/'}));
                break;
            }
        }
        return question_t(0, 0, '\0');
    }

public:
    static question_t GenerateQuestion(const QuestionType questionType, const QuestionDifficulty questionDifficulty) {
        switch (questionType) {
            case QuestionType::BASIC_ARITHMETIC:
                return GenerateArithmeticQuestion(questionDifficulty);
        }
    }
};

int main() {
    std::cout << MathQuestionGenerator::GenerateQuestion(QuestionType::BASIC_ARITHMETIC, QuestionDifficulty::EASY).ToString();
    return 0;
}

