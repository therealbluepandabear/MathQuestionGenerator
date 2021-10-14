#include <iostream>

enum class QuestionDifficulty {
    EASY, MEDIUM, HARD, ADVANCED
};

enum class QuestionType {
    BASIC_ARITHMETIC, ALGEBRA
};

class MathQuestionGenerator {
private:
    std::pair<std::string, double> GenerateArithmeticQuestion(QuestionDifficulty questionDifficulty) {

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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
