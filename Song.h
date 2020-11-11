#ifndef UTPod_Song_H
#define UTPod_Song_H
#include <string>
#include <iostream>

using namespace std;

//Preconditions: The title and the artist cannot be blank and the file size must be > 0


class Song{
    private:

        string songName;
        string artistName;
        int fileSize;
    
    public:

        Song();
        Song(string songNameP, string artistNameP, int fileSizeP);
        string getArtist() const{
            return artistName;
        }
        string getSong() const{
            return songName;
        }
        int getFileSize() const{
            return fileSize;
        }
        bool operator> (Song const &rhs);
        bool operator== (Song const &rhs);
        bool operator< (Song const &rhs);

};

#endif // UTPod_Song_H

