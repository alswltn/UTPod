#include "Song.h"



Song::Song(){       //default constructor for Song()

    songName = "";
    artistName = "";
    fileSize = 0;

}


//Precondition that songName, artistName, and fileSize cannot be empty
Song::Song(string artistNameP, string songNameP, int fileSizeP){

        songName = songNameP;
        artistName = artistNameP;
        fileSize = fileSizeP;

}

bool Song::operator== (Song const &rhs){
    if((this->fileSize == rhs.fileSize) && (this->songName == rhs.songName) && (this->artistName == rhs.artistName)){

        return true;
    
    }else{

        return false;

    }
}

bool Song::operator< (Song const &rhs){

    if(this->artistName < rhs.artistName){
        return true;
    }

    if(this->artistName == rhs.artistName){
        if(this->songName < rhs.songName){
            return true;
        
        }
        if(this->songName == rhs.songName){
            if(this->fileSize < rhs.fileSize){
                return true;
            }
        }
    }
    return false;

}

bool Song::operator> (Song const &rhs){

    if(this->artistName > rhs.artistName){
        return true;
    }

    if(this->artistName == rhs.artistName){
        if(this->songName > rhs.songName){
            return true;
        
        }
        if(this->songName == rhs.songName){
            if(this->fileSize > rhs.fileSize){
                return true;
            }
        }
    }
    return false;

}