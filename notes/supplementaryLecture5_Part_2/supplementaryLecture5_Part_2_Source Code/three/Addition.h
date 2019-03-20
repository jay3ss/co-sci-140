#ifndef Addition_h
#define Addition_h
class Addition
{
public:
	Addition();
	Addition(int&, int&);
	void randomize(int&, int&);
	int getSum();
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