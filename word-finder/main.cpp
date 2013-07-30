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

void permute(vector<char> chars, std::function<void(const string&)> f) {
    do {
        string perm;
        for (auto x : chars)
            perm += x;
        
        f(perm);
    } while (next_permutation(chars.begin(), chars.end()));
}


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
        
        permute(y, [&](const string& w) {
            
            for (int i = 3; i <= w.size(); i++) {
                for (int j = 0; j < w.size() - i; j++) {
                    string to_check(&w.c_str()[j], i);
                    
                    if (found.count(to_check) == 0) {
                        if (checker.is_correct(to_check)) {
                            real_words.insert(real_words.end(), to_check);
                            found[to_check] = to_check;
                        }
                    }
                }
            }
        });
        
        sort(real_words.begin(), real_words.end());
        
        for(auto g : real_words)
            cout << g << endl;
    }
    
    return 0;
}
