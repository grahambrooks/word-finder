//
//  word_accumulator.h
//  word-finder
//
//  Created by Graham Brooks on 8/3/13.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//

#pragma once


class word_accumulator {
    map<string, string> found;
public:
    bool seen(const string& candidate) {
        return found.count(candidate) == 0;
    }
    
    void add(const string& word) {
        found[word] = word;
    }
    
    vector<string> sorted(function<bool (const string&, const string&)> comparator) {
        vector<string> real_words;
        for (auto w : found) {
            real_words.insert(real_words.begin(),w.first);
        }
        
        sort(real_words.begin(), real_words.end(), comparator);
        return real_words;
    }
};
