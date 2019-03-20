#ifndef Subtraction_h
#define Subtraction_h
class Subtraction
{
public:
	Subtraction();
	Subtraction(int&, int&);
	void randomize(int&, int&);
	int getDifference();
	void checkUserResponse(int);
	void updateStats(int);
	void displayStats();

private:
	static int totalWrong;
	static int totalRight;
	int num1;
	int num2;
	int theAnswer;
};
#endif