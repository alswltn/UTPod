/* UTPod_driver.cpp
Demo Driver for the UTPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UTPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UTPod t;
    
    Song s1("Jackson Lundy", "Calypso", 4);
    t.addSong(s1);
    
    t.showSongList();
    cout << "\n";
          
    Song s2("Taylor Swift", "Style", 22);
    t.addSong(s2);
    
    Song s3("K/DA", "Popstars", 32);
    t.addSong(s3);
    
    Song s4("DPR Live", "Cheese and Wine", 11);
    t.addSong(s4);
    

    t.showSongList();
    cout << "\n";

    Song s5("UPSAHL", "Drugs", 12);
    t.addSong(s5);

    Song s6("K/DA", "More", 4);
    t.addSong(s6);

    Song s7("dpr Live", "Text Me", 2);
    t.addSong(s7);

    Song s8("DPR Live", "Martini Blue", 5);
    t.addSong(s8);
    
    t.showSongList();
    t.sortSongList();
    cout << "\n";
    t.showSongList();
    cout << "\n";    
    t.shuffle();
    cout << "\n";
    t.showSongList();
    cout << "\n";

    t.removeSong(s2);
    t.showSongList();
    cout << "\n";

    Song s9("Minkee", "Hardstuck", 88);
    t.addSong(s9);
    
    t.showSongList();

    Song s10("", "", 0);
    t.addSong(s10);

    Song s11("asdkfjh", "mooeoir", 517);
    t.addsong(11);

    cout << "memory = " << t.getRemainingMemory() << endl;
    
    t.~UTPod();
}
