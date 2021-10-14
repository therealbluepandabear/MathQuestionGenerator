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
    static int Random(int min, int max) {
        static bool first = true;
        if (first) {
            srand( time(NULL) );
            first = false;
        }
        return min + rand() % (( max + 1 ) - min);
    }
};

class MathQuestionGenerator {
private:
    std::pair<std::string, double> GenerateArithmeticQuestion(QuestionDifficulty questionDifficulty) {
        switch (questionDifficulty) {
            case QuestionDifficulty::EASY:
                break;
            case QuestionDifficulty::MEDIUM:
                break;
            case QuestionDifficulty::HARD:
                break;
            case QuestionDifficulty::ADVANCED:
                break;
        }
    }
public:
    void GenerateQuestions(int amount, QuestionType questionType, QuestionDifficulty questionDifficulty) {
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

