//
//  word_accumulator.h
//  word-finder
//
//  Created by Graham Brooks on 8/3/13.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//

#pragma once
#include <map>
#include <vector>
using namespace std;

template<typename T> class accumulator {
    map<T, T> found;
public:
    bool seen(const T& candidate) {
        return found.count(candidate) != 0;
    }

    void append_if(const T& word, function<bool (const T&)> predicate) {
        if (!seen(word)) {
            if (predicate(word)) {
                found[word] = word;
            }
        }
    }

    vector<T> sort_by(function<bool (const T&, const T&)> comparator) {
        vector<T> words;
        for (auto w : found) {
            words.insert(words.begin(), w.first);
        }

        sort(words.begin(), words.end(), comparator);
        return words;
    }
};
