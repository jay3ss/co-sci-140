#ifndef Addition_h
#define Addition_h
class Addition
{
public:
	Addition();
	int generateOperand();
	void checkUserResponse(int, int);
	void updateStats(int, int);
	void displayStats();
	int getProblemCount();

private:
	static int totalWrong;
	static int totalRight;
	int problemCount;
	int num1;
	int num2;
};
#endif