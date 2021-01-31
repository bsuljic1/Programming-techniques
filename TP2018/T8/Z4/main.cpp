//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <string>
#include <map>

std::string ZamijeniPremaRjecniku (std::string s, std::map<std::string, std::string> mapa)
{
    std::string novi_string;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            novi_string.push_back(s[i]);
            continue;
        } else {
            int j = i;
            while(s[j] != ' ' && j != s.length()) j++;

            std::string rijec;
            while(i != j) {
                rijec.push_back(s[i]);
                i++;
            }

            auto it = mapa.find(rijec);
            if(it == mapa.end()) {
                i -= rijec.length();
                while(i != j) {
                    novi_string.push_back(s[i]);
                    i++;
                }
            } else {
                std::string zamjena = it->second;
                for(int l = 0; l < zamjena.length(); l++)
                    novi_string.push_back(zamjena[l]);
            }
            if(i == s.length() - 1) break;
            i--;

        }
    }

    return novi_string;
}

int main ()
{
    return 0;
}
