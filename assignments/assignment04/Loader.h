// Loads the trivia file into memory and parses it
#include <fstream>
#include <string>

using namespace std;

class Loader
{
  public:
    Loader(string fn)
    { dataFile.open(fn, ios::in); }
    ~Loader()
    { dataFile.close(); }
    string getQuestion() const;
    string *getAnswers();
    int getCorrectAnswer() const;

  private:
    // string filename;
    ifstream dataFile;
};