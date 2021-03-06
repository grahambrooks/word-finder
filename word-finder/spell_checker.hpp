//
//  spell_checker.hpp
//  word-finder
//
//  Created by Graham Brooks on 30/07/2013.
//  Copyright (c) 2013 GrahamBrooks. All rights reserved.
//
#pragma once

#include <aspell.h>
#include <string>

using namespace std;

class spell_checker {
private:
    AspellConfig *spell_config;
    AspellSpeller *speller;
public:
    spell_checker() {
        spell_config = new_aspell_config();

        AspellCanHaveError *possible_err = new_aspell_speller(spell_config);
        aspell_config_replace(spell_config, "size", "80");

        if (aspell_error_number(possible_err) != 0)
            puts(aspell_error_message(possible_err));
        else {
            speller = to_aspell_speller(possible_err);
        }
    }

    ~spell_checker() {
        if (speller != NULL) {
            delete_aspell_speller(speller);
            speller = NULL;
        }
        if (spell_config) {
            delete_aspell_config(spell_config);
            spell_config = NULL;
        }
    }

    bool is_correct(const string& word) {
        return aspell_speller_check(speller, word.c_str(), static_cast<int>(word.size())) != 0;
    }
};

