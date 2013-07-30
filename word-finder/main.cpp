//
//  main.cpp
//  word-finder
//
//  Created by Graham Brooks on 7/29/13.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//

#include <iostream>
#include <aspell.h>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char * argv[])
{
    
    AspellConfig * spell_config = new_aspell_config();
    
    AspellCanHaveError * possible_err = new_aspell_speller(spell_config);
    
    
    if (aspell_error_number(possible_err) != 0)
        puts(aspell_error_message(possible_err));
    else {
        auto spell_checker = to_aspell_speller(possible_err);
        
        auto word = "hello";
        auto correct = aspell_speller_check(spell_checker, word, static_cast<int>(strlen(word)));
        
        if (correct == 0) {
            cout << word << " miss-spelled" << endl;
        } else {
            cout << word << " spelled correctly" << endl;
        }
        
        auto text = " xlirei";
        
        vector<char> y(text, text + strlen(text));
        
        map<string, string> found;
        
        vector<string> real_words;
        
        do {
            for (auto i : {3, 4, 5, 6}) {
                auto j = y.begin();
                string word;
                while (i > 0) {
                    if (*j != ' ') {
                        word += *j;
                        i--;
                    }
                    j++;
                }
                
                if (found.count(word) == 0) {
                    
                    auto correct = aspell_speller_check(spell_checker, word.c_str(), static_cast<int>(word.length()));
                    
                    if (correct) {
                        real_words.insert(real_words.end(), word);
                        found[word] = word;
                     }
                }
            }
        } while (next_permutation(y.begin(), y.end()));
        
        sort(real_words.begin(), real_words.end());
        
        for(auto g : real_words)
            cout << g << endl;
        
        delete_aspell_speller(spell_checker);
        delete_aspell_config(spell_config);
    }
    return 0;
}

