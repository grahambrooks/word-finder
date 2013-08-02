//
//  word_finder.hpp
//  word-finder
//
//  Created by Graham Brooks on 8/1/13.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//
#pragma once

void permute(vector<char> chars, std::function<void(const string&)> f) {
    do {
        string perm;
        for (auto x : chars)
            perm += x;
        
        f(perm);
    } while (next_permutation(chars.begin(), chars.end()));
}

class word_finder {
    const char* seed;
public:
    word_finder(const char* seed) : seed(seed) {}
    
    vector<string> find() {
        spell_checker checker;
        
        vector<char> y(seed, seed + strlen(seed));
        sort(y.begin(), y.end());
        
        map<string, string> found;
        
        vector<string> real_words;
        
        permute(y, [&](const string& w) {
            
            for (int i = 3; i <= w.size(); i++) {
                for (int j = 0; j <= w.size() - i; j++) {
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
        sort(real_words.begin(), real_words.end(), [](const string& a, const string& b) { return b.length() == a.length() ? a < b : b.length() > a.length();});
        
        return real_words;
        
    }
};
