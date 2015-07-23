#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int alphaScores[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

class Word{
    pair<int, string> wordWithScore;
    int calculateScore(){
        int sum = 0;
        int length = this->wordWithScore.second.length();
        for (int i = 0; i < length; i++) {
            sum += alphaScores[this->wordWithScore.second[i]-'a'];
        }
        return sum;
    }
public:
    Word(string word){
        this->wordWithScore.second = word;
        this->wordWithScore.first = calculateScore();
    }
    int getScore() {
        return this->wordWithScore.first;
    }
    pair<int, string> getWordWithScore() const {
        return this->wordWithScore;
    }
};

void getFile(string filename, ifstream& file)
{
    ifstream f(filename.c_str());
    if (f.is_open()) {
        file.open(filename.c_str());
        return;
    }
    cout<<"\n unable to open file";
}

bool wordCompare(const Word& word1, const Word& word2) {
    return word1.getWordWithScore() > word2.getWordWithScore();
}

void sortdictionary(vector<Word>& dictionary){
    sort(dictionary.begin(), dictionary.end(), wordCompare);
}

int main()
{
    ifstream file;
    string line;
    vector<Word> dictionary;
    getFile("words.txt", file);

    if (file.is_open()) {
        while (getline (file,line))
        {
            Word word(line);
            dictionary.push_back(word);
        }
    }

    sortdictionary(dictionary);

    for (int i = 0; i<dictionary.size(); i++){
        cout<<dictionary[i].getWordWithScore().first<<","<<dictionary[i].getWordWithScore().second<<"\n";
    }
}

