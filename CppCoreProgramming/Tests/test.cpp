#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

// 加载字典文件到哈希表
void loadDictionary(const string& filename, unordered_set<string>& dictionary) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "无法打开字典文件: " << filename << endl;
        return;
    }
    string word;
    while (file >> word) 
    {
        dictionary.insert(word);
    }
    cout << "已加载字典文件: " << filename << "，共 " << dictionary.size() << " 个单词" << endl;
}

// 检查单词是否在字典中
bool isWordInDictionary(const string& word, const unordered_set<string>& dictionary) 
{
    return dictionary.find(word) != dictionary.end();
}

// 生成拼写错误单词的可能纠正
vector<pair<string, string>> generateCorrections(const string& word, const unordered_set<string>& dictionary) 
{
    vector<pair<string, string>> corrections;

    // 添加一个字符
    for (char c = 'a'; c <= 'z'; ++c) 
    {
        for (size_t i = 0; i <= word.size(); ++i) 
        {
            string newWord = word.substr(0, i) + c + word.substr(i);
            if (isWordInDictionary(newWord, dictionary)) 
            {
                corrections.emplace_back(newWord, "添加字符 '" + string(1, c) + "'");
            }
        }
    }

    // 删除一个字符
    for (size_t i = 0; i < word.size(); ++i) 
    {
        string newWord = word.substr(0, i) + word.substr(i + 1);
        if (isWordInDictionary(newWord, dictionary)) 
        {
            corrections.emplace_back(newWord, "删除字符 '" + string(1, word[i]) + "'");
        }
    }

    // 交换相邻字符
    for (size_t i = 0; i < word.size() - 1; ++i) 
    {
        string newWord = word;
        swap(newWord[i], newWord[i + 1]);
        if (isWordInDictionary(newWord, dictionary)) 
        {
            corrections.emplace_back(newWord, "交换字符 '" + string(1, word[i]) + "' 和 '" + string(1, word[i + 1]) + "'");
        }
    }

    return corrections;
}

int main() {
    unordered_set<string> dictionary;

    // 加载大字典
    loadDictionary("large_dictionary.txt", dictionary);

    ifstream personalFile("personal_dictionary.txt");
    if (!personalFile.is_open()) 
    {
        cerr << "无法打开个人字典文件: personal_dictionary.txt" << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    while (getline(personalFile, line)) 
    {
        ++lineNumber;
        istringstream iss(line);
        string word;
        while (iss >> word) 
        {
            if (!isWordInDictionary(word, dictionary)) 
            {
                cout << "拼写错误的单词: " << word << " 在第 " << lineNumber << " 行" << endl;
                vector<pair<string, string>> corrections = generateCorrections(word, dictionary);
                if (!corrections.empty()) 
                {
                    cout << "纠正: ";
                    set<string> uniqueCorrections;
                    for (const auto& correction : corrections) 
                    {
                        if (uniqueCorrections.insert(correction.first).second) 
                        {
                            cout << correction.first << " (" << correction.second << ") ";
                        }
                    }
                    cout << "\n\n";
                } 
                else 
                {
                    cout << "找不到纠正" << endl;
                }
            }
        }
    }

    return 0;
}