#include <iostream>
#include <ctime>
#include <random>

enum class QuestionDifficulty {
    EASY, MEDIUM, HARD, ADVANCED
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

class AlgebraicQuestionGenerator {
private:
    struct quadratic_equation_question {
    private:
        struct root {
            double positiveRoot, negativeRoot;

            root(const double _positiveRoot, const double _negativeRoot) {
                positiveRoot = _positiveRoot;
                negativeRoot = _negativeRoot;
            }
        };
    public:
        int a, b, c;

        quadratic_equation_question(const int _a, const int _b, const int _c) {
            a = _a;
            b = _b;
            c = _c;
        }

        [[nodiscard]] root GetRoot() const {
            double positiveRoot = (-b + sqrt(pow(b, 2) - 4 * a * c))/(2 * a);
            double negativeRoot = (-b - sqrt(pow(b, 2) - 4 * a * c))/(2 * a);

            return root { positiveRoot, negativeRoot };
        }

        [[nodiscard]] std::string ToString() const {
            return "Find the root of " + std::to_string(a) + "x^2" + " + " + std::to_string(b) + "x" + " + " + std::to_string(c);
        }
    };

    static quadratic_equation_question GenerateAlgebraicQuestion() {
        return quadratic_equation_question {
            RandomNumberGenerator::Random(1, 10),
            RandomNumberGenerator::Random(1, 10),
            RandomNumberGenerator::Random(1, 10)};
    }
public:
    static quadratic_equation_question GenerateQuestion() {
        return GenerateAlgebraicQuestion();
    }

    static std::vector<quadratic_equation_question> GenerateQuestions(const int amount) {
        std::vector<quadratic_equation_question> vector;
        for (int i = 0; i < amount; i++) {
            auto question = GenerateQuestion();
            vector.push_back(question);
        }
        return vector;
    }
};

class ArithmeticQuestionGenerator {
private:
    struct question_t {
        int left, right;
        char operand;

        question_t(const int _left, const int _right, const char _operand) {
            left = _left;
            right = _right;
            operand = _operand;
        }

        [[nodiscard]] int GetAnswer() const {
            switch (operand) {
                case '+': return left + right;
                case '-': return left - right;
                case '/': return left / right;
                case '*': return left * right;
            }
        }

        [[nodiscard]] std::string ToString() const {
            return std::to_string(left) + " " + operand + " " + std::to_string(right);
        }
    };
    static char GenRandElement(std::vector<char> vector) {
        return vector[rand() % vector.size()];
    }

    static question_t GenerateArithmeticQuestion(const QuestionDifficulty questionDifficulty) {
        switch (questionDifficulty) {
            case QuestionDifficulty::EASY: {
                return question_t(
                        RandomNumberGenerator::Random(1, 10),
                        RandomNumberGenerator::Random(1, 10),
                        GenRandElement({'+', '-'}));
            }
            case QuestionDifficulty::MEDIUM: {
                return question_t(
                        RandomNumberGenerator::Random(1, 25),
                        RandomNumberGenerator::Random(1, 25),
                        GenRandElement({'+', '-'}));
            }
            case QuestionDifficulty::HARD: {
                return question_t(
                        RandomNumberGenerator::Random(1, 10),
                        RandomNumberGenerator::Random(1, 10),
                        GenRandElement({'*', '/'}));
            }
            case QuestionDifficulty::ADVANCED: {
                return question_t(
                        RandomNumberGenerator::Random(1, 25),
                        RandomNumberGenerator::Random(1, 25),
                        GenRandElement({'*', '/'}));
            }
        }
        return question_t {0, 0, '\0'};
    }

public:
    static question_t GenerateQuestion(const QuestionDifficulty questionDifficulty) {
        return GenerateArithmeticQuestion(questionDifficulty);
    }

    static std::vector<question_t> GenerateQuestions(const QuestionDifficulty questionDifficulty, const int amount) {
        std::vector<question_t> vector;
        for (int i = 0; i < amount; i++) {
            auto question = GenerateQuestion(questionDifficulty);
            vector.push_back(question);
        }
        return vector;
    }
};

int main() {

    return 0;
}

