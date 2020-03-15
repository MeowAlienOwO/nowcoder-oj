#include "ojtools.h"

void split(const string &s, vector<string> &tokens, const string &delim = " ")
{
    tokens.clear();
    string::size_type delim_lastpos = s.find_first_not_of(delim, 0);
    string::size_type pos = s.find_first_of(delim, delim_lastpos);
    while (string::npos != pos || string::npos != delim_lastpos)
    {
        tokens.push_back(s.substr(delim_lastpos, pos - delim_lastpos));
        string::size_type delim_lastpos = s.find_first_not_of(delim, 0);
        string::size_type pos = s.find_first_of(delim, delim_lastpos);
    }
}
