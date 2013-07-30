//
//  main.cpp
//  word-finder
//
//  Created by Graham Brooks on 7/29/13.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

#include "spell_checker.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    if (argc < 2) {
        cout << "Usage word-finder <word>" << endl;
    } else {
        spell_checker checker;
        
        auto text = argv[1];
        
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
                    if (checker.is_correct(word)) {
                        real_words.insert(real_words.end(), word);
                        found[word] = word;
                    }
                }
            }
        } while (next_permutation(y.begin(), y.end()));
        
        sort(real_words.begin(), real_words.end());
        
        for(auto g : real_words)
            cout << g << endl;
    }
    
    return 0;
}
