//
//  word_finder.hpp
//  word-finder
//
//  Created by Graham Brooks on 8/1/13.
//  Copyright (c) 2013 Graham Brooks. All rights reserved.
//
#pragma once

#include "word_accumulator.h"
#include "spell_checker.hpp"

void permute(vector<char> chars, std::function<void (const string&)> f) {
    do {
        string perm;
        for (auto x : chars)
            perm += x;

        f(perm);
    } while (next_permutation(chars.begin(), chars.end()));
}

class word_finder {
    const char *seed;
public:
    word_finder(const char *seed) : seed(seed) {
    }

    template<typename T> vector<T> sorted_vector_of(const T *seed) {
        vector<T> y(seed, seed + strlen(seed));
        sort(y.begin(), y.end());
        return y;
    }

    vector<string> find() {
        spell_checker checker;

        accumulator<string> accumulator;

        permute(sorted_vector_of(seed), [&](const string& w) {

            for (int i = 3; i <= w.size(); i++) {
                for (int j = 0; j <= w.size() - i; j++) {
                    string to_check(&w.c_str()[j], i);

                    accumulator.append_if(to_check, [&](const string& t) {
                        return checker.is_correct(t);
                    });
                }
            }
        });

        return accumulator.sort_by([](const string& a, const string& b) {
            return b.length() == a.length() ? a < b : b.length() > a.length();
        });
    }
};
