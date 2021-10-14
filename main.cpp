#include <iostream>

enum class QuestionDifficulty {
    EASY, MEDIUM, HARD, ADVANCED
};

enum class QuestionType {
    BASIC_ARITHMETIC, ALGEBRA
};

class MathQuestionGenerator {
public:
    void GenerateQuestions(int amount, QuestionType questionType, QuestionDifficulty questionDifficulty) {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
