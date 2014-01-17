//
// Created by Graham Brooks on 8/13/13.
// Copyright (c) 2013 GrahamBrooks. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//

#pragma once
#include <iostream>
#include "word_finder.hpp"

using namespace std;

class app {
public:
    int run(int argc, const char *argv[]) {
        if (argc < 2) {
            cout << "Usage word-finder <word>" << endl;
        } else {
            
            word_finder finder(argv[1]);
            
            auto real_words = finder.find();
            
            for (auto w : real_words)
                cout << w << endl;
        }
        
        return 0;
    }
};
