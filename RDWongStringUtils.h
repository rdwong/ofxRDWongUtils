//
//  RDWongStringUtils.h
//  httpTest
//
//  Created by richard on 27/07/2017.
//
//

#ifndef __httpTest__RDWongStringUtils__
#define __httpTest__RDWongStringUtils__

#include "ofMain.h"


//-----------------------------------------
static void toUpper(string & _string)
{
    for (int i = 0; i < _string.size(); i++) {
        _string[i] = toupper(_string[i]);
    }
}

//-----------------------------------------
static void toLower(string & _string)
{
    for (int i = 0; i < _string.size(); i++) {
        _string[i] = tolower(_string[i]);
    }
}

//-----------------------------------------
static string getRandomName()
{
    vector<string> hardSounds = {"b","c","d","e","f","g","h","j","k","l","m","n","p","qu","r","s","t","v","w","b","c","d","e","f","g","h","j","k","l","m","n","p","qu","r","s","t","v","w","b","c","d","e","f","g","h","j","k","l","m","n","p","qu","r","s","t","v","w","b","c","d","e","f","g","h","j","k","l","m","n","p","qu","r","s","t","v","w","ex","y","z", "ch", "th", "ph", "ck", "nth", "gh"};
    vector<string> softSounds = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u","a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oo", "ea", "ai", "oo", "ui", "ue", "oe", "ie", "ou", "ei", "au"};
    
    int firstLength = (int)ofRandom(2, 5);
    int lastLength = (int)ofRandom(3, 6);
    string firstname = "";
    string lastname = "";
    
    int sType = (ofRandom(-50,100) > 0) ? 0 : 1;
    for (int i = 0; i < firstLength; i++) {
        if (sType == 0) {
            int randomSound = (int)floor(ofRandom((int)hardSounds.size() - 0.001));
            firstname += hardSounds[randomSound];
            sType = 1;
        } else {
            int randomSound = (int)floor(ofRandom((int)softSounds.size() - 0.001));
            firstname += softSounds[randomSound];
            sType = 0;
        }
    }
    
    sType = (ofRandom(-50,100) > 0) ? 0 : 1;
    for (int i = 0; i < lastLength; i++) {
        if (sType == 0) {
            int randomSound = (int)floor(ofRandom((int)hardSounds.size() - 0.001));
            lastname += hardSounds[randomSound];
            sType = 1;
        } else {
            int randomSound = (int)floor(ofRandom((int)softSounds.size() - 0.001));
            lastname += softSounds[randomSound];
            sType = 0;
        }
    }
    
    firstname[0] = toupper(firstname[0]);
    lastname[0] = toupper(lastname[0]);
    
    return firstname + " " + lastname;
}

// ------------------------------------------------------------------
static void replaceString(std::string& subject, const std::string& search, const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}

// ------------------------------------------------------------------
static void removeTags(string & subject) {
    size_t pos = 0;
    while ((pos = subject.find('<', pos)) != std::string::npos) {
        
        size_t endTag = pos;
        if ((endTag = subject.find('>', endTag)) != std::string::npos) {
            
            string temp = subject;
            
            toLower(temp);
            temp = temp.substr(pos, endTag-pos+1);
            
            bool bErase = true;
            if (temp == "<i>") bErase = false;
            if (temp == "</i>") bErase = false;
            if (temp == "<b>") bErase = false;
            if (temp == "</b>") bErase = false;
            if (temp == "<br>") bErase = false;
            
            if (bErase) subject.erase(pos, endTag-pos+1);
            else pos = endTag;
            
        } else break;
        
    }
}

// ------------------------------------------------------------------
static void formatComplexString(string & s)
{
    replaceString(s, "&nbsp;", " "); // weird character space
    replaceString(s, "<br>", ""); // first remove all br tags, as we are only counting <p> tags
    replaceString(s, "<p>", ""); // remove open <p> tags
    replaceString(s, "\r", ""); // remove all backslash linebreaks
    replaceString(s, "\n", "");
    replaceString(s, "</p>", "\n"); // break at </p> tags
    removeTags(s);
}


#endif /* defined(__httpTest__RDWongStringUtils__) */
