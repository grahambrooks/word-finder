//
//  main.cpp
//  word-finder
//
//  Created by Graham Brooks on 7/29/13.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//

#include <iostream>
#include <aspell.h>

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

        word = "kdsjfhsk";
        correct = aspell_speller_check(spell_checker, word, static_cast<int>(strlen(word)));

        if (correct == 0) {
            cout << word << " miss-spelled" << endl;
        } else {
            cout << word << " spelled correctly" << endl;
        }
        
        
        delete_aspell_speller(spell_checker);
        delete_aspell_config(spell_config);
    }
    return 0;
}

