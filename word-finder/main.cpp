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
#include "word_finder.hpp"
using namespace std;


int main(int argc, const char * argv[])
{
    if (argc < 2) {
        cout << "Usage word-finder <word>" << endl;
    } else {
        
        word_finder finder(argv[1]);
        
        auto real_words = finder.find();
        
        for(auto w : real_words)
            cout << w << endl;
    }
    
    return 0;
}
