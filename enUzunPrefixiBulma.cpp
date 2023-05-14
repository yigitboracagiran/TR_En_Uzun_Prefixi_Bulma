#include <iostream>
#include <string>
#include <cstring>
#include <vector>

class Solution {

public:

    std::string longestCommonPrefix ( std::vector<std::string>& strs ) {

        if ( strs.size() == 1 ) { //Eger tek kelime geldiyse...
            return strs[0];
        }

        int min = strs[0].size(); //Birden cok kelime geldiyse kelimeler arasindan min uzunluga sahip olanin uzunlugu bulunuyor.
        for ( int i = 1 ; i < strs.size() ; i++ ) {
            if ( strs[i].size() < min ) {
                min = strs[i].size();
            }
        }

        std::string prefix = "";
        for ( int i = 0 ; i < min ; i++ ) {
            int sayac = 0;
            for ( int j = 1 ; j < strs.size() ; j++ ) {
                if (strs[0][i] == strs[j][i]) {  //Harf ayniysa sayaci arttir.
                    sayac++;
                }
                if ( sayac == ( strs.size() - 1 ) ) { //Harf tum kelimelerde ortaksa ( sayac, kelime saysina esitse ) ekle.
                    prefix.push_back( strs[0][i] );
                }
            }
            if ( sayac != ( strs.size() - 1 ) ) { //Eger tek bir harf bile ortak degilse direk ortak olanlari dondur.
                return prefix;
            }
        }
        return prefix; //Buraya sadece tum harfler ortaksa gelir.

    }

};

int main ( void ) {

    Solution solution;
    std::vector<std::string> kelimeler = {"a"}; //Tek kelime
    //std::vector<std::string> kelimeler = {"flower","flow","flight"}; //Ilk iki harf ortak
    //std::vector<std::string> kelimeler = {"dog","racecar","car"}; //Ortak harf yok
    std::string prefix = solution.longestCommonPrefix(kelimeler);
    std::cout << prefix << std::endl;
    return 0;

}