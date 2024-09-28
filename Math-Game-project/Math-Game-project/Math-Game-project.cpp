#include <iostream>
using namespace std;

enum eDiffclutly
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    Mix = 4,
};

enum eType
{
    Sum = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    All = 5,
};

struct sQuestionInfo
{
    int randNum1;
    int randNum2;
    int rightAnswersCounter;
    int wrongAnswersCounter;
};

sQuestionInfo questionInfoInstance;

int randomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int questionInfo(string msg) {
    int value;
    cout << msg;
    cin >> value;
    return value;
}

int sumOpp(int num1, int num2) {
    return num1 + num2;
}

int subOpp(int num1, int num2) {
    return num1 - num2;
}

int mulOpp(int num1, int num2) {
    return num1 * num2;
}

int divOpp(int num1, int num2) {
    return num1 / num2;
}

char mixOpSymbol(int rnd) {
    char operation;

    if (rnd == 1) {
        operation = '+';
    }
    else if (rnd == 2) {
        operation = '-';
    }
    else if (rnd == 3) {
        operation = '*';
    }
    else {
        operation = '/';
    }
    return operation;
}

int mixOp(int num1, int num2, int rnd) {
    
    switch (rnd)
    {
    case 1:
        return num1 + num2;
    case 2:
        return num1 - num2;
    case 3:
        return num1 * num2;
    case 4:
        return num2 != 0 ? num1 / num2 : 0;

    default:
        return 0;
    }
}

void checkAnswer(int operationForRightAnswer, char opp) {
    int playerAnswer;
    int theRightAnswer;

            
    cout << questionInfoInstance.randNum1 << endl;
    cout << questionInfoInstance.randNum2 << "    " << opp << endl;
    cout << "-----------\n";

     theRightAnswer = operationForRightAnswer;

     playerAnswer = questionInfo("your answer: \n");

    if (playerAnswer == theRightAnswer)
    {
      cout << "\nYou answer is Right :-)\n";
      questionInfoInstance.rightAnswersCounter++;
      system("color 2F");
    }
    else
    {
       cout << "\nYour answer is worng but don't give up :)\n";
       cout << "\nThe right answer is: " << theRightAnswer << endl << endl;
       questionInfoInstance.wrongAnswersCounter++;
       system("color 4F");
    }
}

void questionMakerAndOpType(int operationType, int from , int to) {
    char symobl;
    int result;
    int rnd;

    questionInfoInstance.randNum1 = randomNumber(from, to);
    questionInfoInstance.randNum2 = randomNumber(from, to);
    if (operationType == eType::Sum)
    {
       symobl = '+';
       result = sumOpp(questionInfoInstance.randNum1, questionInfoInstance.randNum2);
    }
    else if (operationType == eType::Sub)
    {
        symobl = '-';
        result = sumOpp(questionInfoInstance.randNum1, questionInfoInstance.randNum2);
    }
    else if (operationType == eType::Mul)
    {
        symobl = '*';
        result = sumOpp(questionInfoInstance.randNum1, questionInfoInstance.randNum2);
    }
    else if (operationType == eType::Div)
    {
        symobl = '/';
        result = sumOpp(questionInfoInstance.randNum1, questionInfoInstance.randNum2);
    }
    else if (operationType == eType::All) {
        rnd = randomNumber(1, 4);

        symobl = mixOpSymbol(rnd);
        result = mixOp(questionInfoInstance.randNum1, questionInfoInstance.randNum2, rnd);
    }
    checkAnswer(result, symobl);
 }

void mixDiff(int operationType) {
    int rnd = randomNumber(1, 3);

    if (rnd == eDiffclutly::Easy) {
        questionMakerAndOpType(operationType, 1, 10);
    }
    else if (rnd == eDiffclutly::Med)
    {
        questionMakerAndOpType(operationType, 10, 50);
    }
    else if (rnd == eDiffclutly::Hard)
    {
        questionMakerAndOpType(operationType, 50, 200);
    }
}

void diffcultyLevelMaker(int diffcultyLevel, int operationType) {

    if (diffcultyLevel == eDiffclutly::Easy) {
        questionMakerAndOpType(operationType, 1, 10);
    }
    else if (diffcultyLevel == eDiffclutly::Med) 
    {
        questionMakerAndOpType(operationType, 10, 50);
    }
    else if (diffcultyLevel == eDiffclutly::Hard)
    {
        questionMakerAndOpType(operationType, 50, 200);
    }
    else if (diffcultyLevel == eDiffclutly::Mix)
    {
        mixDiff(operationType);
    }
}

void gameResults(int qNums, int diffLevel, int opType)
{
    string diffcultyLevel;
    string operationType;

    switch (diffLevel)
    {
    case 1:
        diffcultyLevel = "Easy";
        break;
    case 2:
        diffcultyLevel = "Med";
        break;
    case 3:
        diffcultyLevel = "Hard";
        break;
    case 4:
        diffcultyLevel = "Mix";
        break;
    default:
        break;
    }

    switch (opType)
    {
    case 1:
        operationType = "Sum";
        break;
    case 2:
        operationType = "Subtract";
        break;
    case 3:
        operationType = "Multiply";
        break;
    case 4:
        operationType = "Divied";
        break;
    case 5:
        operationType = 'Mix';
        break;
    default:
        break;
    }


    cout << "\n-----------------------------\n";
    if (questionInfoInstance.rightAnswersCounter > questionInfoInstance.wrongAnswersCounter) {
        cout << "Final Results is passed :)" << endl;
    }
    else {
        cout << "Final Results is faild try again :(" << endl;
    }
    cout << "-----------------------------\n\n";
    cout << "Number of questions: " << qNums << endl;
    cout << "Question diffculty level: " << diffcultyLevel << endl;
    cout << "Question operation Type: " << operationType << endl;
    cout << "Number of right answers: " << questionInfoInstance.rightAnswersCounter << endl;
    cout << "Number of wrong answers: " << questionInfoInstance.wrongAnswersCounter << endl;

}

string playAnotherGame() {
    string playGameChoice;
    cout << "\nDo you wnat to play another game(Y/N): ";
    cin >> playGameChoice;
    return playGameChoice;
}

void startGame() {
    int i;
    int questionNums = questionInfo("How many Question do you want to play: ");
    int diffcultyLevel = questionInfo("Chose the diffculty level from [1] Easy, [2] Med, [3] Hard, [4] Mix: ");
    int operationType = questionInfo("Chose the operation type from [1] Sum +, [2] Sub -, [3] Mul x, [4] Div /, [5] Mix: ");

    for (i = 0; i < questionNums; i++) {
        cout << "\nQuestion [" << i + 1 << "] :\n";
        diffcultyLevelMaker(diffcultyLevel, operationType);
    }

    if (i >= questionNums) {
        gameResults(questionNums, diffcultyLevel, operationType);

    }
}

int main()
{
    srand((unsigned)time(NULL));

    string playAgain;

    do
    {
        startGame();
        questionInfoInstance.rightAnswersCounter = 0;
        questionInfoInstance.rightAnswersCounter = 0;
        playAgain = playAnotherGame();
    } while (playAgain == "Y" || playAgain == "y");
}

