#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using std::cout;
using std::cin;


std::string punctuation(const std::string& str) //Функция удаления знаков
{
    const char* signs{ ".,:;- " };
    const auto idx_begin(str.find_first_not_of(signs));
    const auto idx_end(str.find_last_not_of(signs));

    return str.substr(idx_begin, idx_end - idx_begin +1);
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::map<std::string, size_t> words;
    int max_word = { 0 };      //длинна самого длинного слова

    std::string str;
    cout << "enter a sentence:" << std::endl;
    while (cin >> str) 
    {
        auto result(punctuation(str)); //удаляем знаки(signs)
        max_word =std:: max<int>(max_word, result.length()); //запись самого длинного слова max_word
        ++words[result]; //кол-во слов
    }

    std::vector<std::pair<std::string, size_t>> word_counts;
    word_counts.reserve(words.size());

    move(begin(words), end(words), back_inserter(word_counts)); //делаем move в word_counts, для дальнейшей сортировки


    sort(begin(word_counts), end(word_counts),[](const auto& a, const auto& b) 
        {
        return a.second > b.second; //слова, которые встречаются чаще идут первыми
        });
   
    cout << "# " << std::setw(max_word) << "<WORD>" << " #<COUNT>"<<std::endl;

    for (const auto& [word, count] : word_counts)
    {
        cout << std::setw(max_word ) << word << "  :  " << count << '\n';
    }



    return 0;
}