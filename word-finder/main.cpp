//
//  main.cpp
//  word-finder
//
//  Created by Graham Brooks on 7/29/13.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//

#include <iostream>
#include <aspell.h>

int main(int argc, const char * argv[])
{

    AspellConfig * spell_config = new_aspell_config();
    
    AspellCanHaveError * possible_err = new_aspell_speller(spell_config);
    
    AspellSpeller * spell_checker = 0;
    if (aspell_error_number(possible_err) != 0)
        puts(aspell_error_message(possible_err));
    else
        spell_checker = to_aspell_speller(possible_err);
    
    int correct = aspell_speller_check(spell_checker, "hello", 5);
    
    std::cout << "Spell returned " << correct << std::endl;
    
    delete_aspell_speller(spell_checker);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

