#include "UTPod.h"
#include "Song.h"

//Deafault constructor for UTPod
UTPod::UTPod(){
    songs = nullptr;
    memSize = MAX_MEMORY;
}

UTPod::UTPod(int size){
    if((size > 512) || (size <= 0)){
        memSize = MAX_MEMORY;
    }else{
        memSize = size;
    }
}


//Precondition: Is there enough memory to add a song? If so execute:
int UTPod::addSong(const Song &s){
    if(s.getFileSize() > getRemainingMemory()){
        cout << "No memory left, cannot add song." << endl;
        return NO_MEMORY;
    }
    if(s.getSong() == ""){
        if(s.getArtist() == ""){
            if(s.getFileSize() == 0){
                cout << "Song title, artist name, or file size not valid. Cannot be added." << endl;
                return NOT_FOUND;
            }
        }
    }
    SongNode* tempNode = new SongNode;
    tempNode->s = s;

    //Add at the head
    if(songs == nullptr){      //If no songs, then add song and make next pointer nullptr
        songs = tempNode;   //tempNode is temporary placeholder for songs
        tempNode->next = nullptr;
    }else{
        tempNode->next = songs;
        songs = tempNode;
    }

        cout << "Song successfully added! \n" << endl;
        return SUCCESS;
}

//Cannot remove a song if there are no songs
int UTPod::removeSong(const Song &s){
    if((songs->s.getSong() == s.getSong()) && (songs->s.getFileSize() == s.getFileSize()) && (songs->s.getArtist() == s.getArtist())){
        SongNode* tempNode = songs;
        songs = songs->next;
        delete(tempNode);
        cout << "Song successfully removed! \n" << endl;
        return SUCCESS;
    } 

    SongNode* leadingPtr = songs;
    SongNode* chasingPtr;
    while(leadingPtr != nullptr){
        chasingPtr = leadingPtr;
        leadingPtr = leadingPtr->next;
        if((leadingPtr->s.getSong() == s.getSong()) && (leadingPtr->s.getFileSize() == s.getFileSize()) && (leadingPtr->s.getArtist() == s.getArtist())){
            chasingPtr->next = leadingPtr->next;
            delete(leadingPtr);
            cout << "Song successfully removed! \n" << endl;
            return SUCCESS;
        }
    }
    return NOT_FOUND;
}

//Fischer Yates Algo
void UTPod::shuffle(){
    SongNode* firstPtr = songs;
    SongNode* secondPtr = nullptr;
    int randomNum = 0;
    int modNum = getNumOfSongs();

    if(getNumOfSongs() < 2){
        return;
    }

    for(int i = 0; i < (getNumOfSongs()-1); i++){
        secondPtr = firstPtr;
        randomNum = (rand() % modNum);
        for(int j = 0; j < randomNum; j ++){
            secondPtr = secondPtr->next;
        }
        if(secondPtr != firstPtr){
            swapNodes(firstPtr, secondPtr);
        }
        firstPtr = firstPtr->next;
        modNum = modNum - 1;
    }
    cout << "Successfully shuffled! \n" << endl;
}

//Shows the song list
void UTPod::showSongList() {    
    SongNode* headPtr = songs;
    cout << "Here's the list of songs! Enjoy! \n" << endl;
    while(headPtr != nullptr){
        cout << headPtr->s.getSong() << ", " << headPtr->s.getArtist() << ", " << headPtr->s.getFileSize() << " MB" <<endl;
        headPtr = headPtr->next;
    }
    cout << "\n";
}

//getNumOfSongs() used for different functions within UTPod.cpp
int UTPod::getNumOfSongs() const{
    int numSongs =0;
    SongNode* headPtr = songs;
    while(headPtr != nullptr){
        numSongs++;
        headPtr = headPtr->next;
    }
    return numSongs;
}

//Used to shuffle and sort
void UTPod::swapNodes(SongNode* s1, SongNode* s2){
    Song tempNode = s1->s;
    s1->s = s2->s;
    s2->s = tempNode;
}

int UTPod::getRemainingMemory(){
    SongNode* temp = songs;
    int totalUsed = 0;
    while(temp != nullptr){
        totalUsed = totalUsed + temp->s.getFileSize();
        temp = temp->next;
    }
    return (memSize-totalUsed);
}

void UTPod::clearMemory(){
    SongNode* headPtr = songs;
    SongNode* nextPtr = songs;
    while(nextPtr != nullptr){
        headPtr = headPtr->next;
        delete(nextPtr);
        nextPtr = headPtr;
    }
}

// Destructor
UTPod::~UTPod(){
    clearMemory();
}

void UTPod::sortSongList(){
    int numSongs = getNumOfSongs();
    if(numSongs < 2){
        return;
    }
    SongNode* firstPtr = songs;
    SongNode* secondPtr = songs->next;


    cout << "Successfully sorted! \n" << endl;
    for(int i = 0; i < numSongs; i++){
        for(int j = 0; j < numSongs-1; j++){
            if(firstPtr->s > secondPtr->s){
                swapNodes(firstPtr, secondPtr);
                firstPtr = secondPtr;
                secondPtr = secondPtr->next;
            }else{
                firstPtr = secondPtr;
                secondPtr = secondPtr->next;
            }
        }
        firstPtr = songs;
        secondPtr = songs->next;
    }
}