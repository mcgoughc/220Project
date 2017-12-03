//
// Created by Joseph Cleveland on 11/14/17.
//

#include "BookStore.h"

/**\
 * Helper function for isAlphabeticallyGreaterThan
 * Strings farther in the dictionary will have a higher relative value
 * @param input String to calculate value of
 * @return value input string of to be used for comparison
 */
int stringAlphaValue(std::string input){
    int stringValue = 0;
    for(int s = 0; s < input.length();s++){                   //Step through each character of string A
        int characterValue = (int)input.at(s);                   //Gets the ASCII value of the character at position cA
        if(characterValue >= 65 && characterValue <= 90)      //If char is between capital A to Z
            characterValue -= 64;                             //subtract so that A = 1 and Z = 26
        else if(characterValue >= 97 && characterValue <= 122)//If char is between lower-case a to z
            characterValue -= 96;                             //subtract so that a = 1 and z = 26
        else
            characterValue = 0;                               //All other characters will be ignored

        stringValue += characterValue;
    }
    return stringValue;
}

bool BookStore::isAlphabeticallyGreaterThan(std::string A, std::string B) {
    int A_Value = stringAlphaValue(A);
    int B_Value = stringAlphaValue(B);
    return A > B;
}