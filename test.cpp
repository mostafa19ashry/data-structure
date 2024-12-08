#include <iostream>
#include <string>
using namespace std;

// Node structure representing each song in the playlist
struct Song
{
    string name; // Name of the song
    Song *next;  // Pointer to the next song

    Song(string songName)
    {
        name = songName;
        next = nullptr;
    }
};

// Playlist class
class Playlist
{
private:
    Song *head;    // Head pointer for the linked list
    int songCount; // Counter for the number of songs

public:
    // Constructor
    Playlist() : head(nullptr), songCount(0) {}

    // Destructor to clean up memory
    ~Playlist()
    {
        Song *current = head;
        while (current != nullptr)
        {
            Song *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Add a song to the playlist
    void addSong(const string &songName)
    {
        Song *newSong = new Song(songName);
        if (!head)
        {
            head = newSong;
        }
        else
        {
            Song *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newSong;
        }
        songCount++;
        cout << "Added: " << songName << " to the playlist." << endl;
    }

    // Display the songs in the playlist
    void displayPlaylist() const
    {
        if (!head)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }
        cout << "Playlist:" << endl;
        Song *temp = head;
        while (temp)
        {
            cout << "- " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Delete a song from the playlist
    void deleteSong(const string &songName)
    {
        if (!head)
        {
            cout << "Playlist is empty. Cannot delete song." << endl;
            return;
        }
        if (head->name == songName)
        {
            Song *temp = head;
            head = head->next;
            delete temp;
            songCount--;
            cout << "Deleted: " << songName << " from the playlist." << endl;
            return;
        }

        Song *current = head;
        Song *previous = nullptr;

        while (current && current->name != songName)
        {
            previous = current;
            current = current->next;
        }

        if (current)
        {
            previous->next = current->next;
            delete current;
            songCount--;
            cout << "Deleted: " << songName << " from the playlist." << endl;
        }
        else
        {
            cout << "Song not found in the playlist." << endl;
        }
    }

    // Search for a song in the playlist
    bool searchSong(const string &songName) const
    {
        Song *temp = head;
        while (temp)
        {
            if (temp->name == songName)
            {
                return true; // Song found
            }
            temp = temp->next;
        }
        return false; // Song not found
    }

    // Display the number of songs in the playlist
    void displaySongCount() const
    {
        cout << "Number of songs in the playlist: " << songCount << endl;
    }
};

// Main function
int main()
{
    Playlist myPlaylist;
    int choice;
    string songName;

    do
    {
        cout << "\nPlaylist Menu:\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Search Song\n";
        cout << "4. Delete Song\n";
        cout << "5. Display Song Count\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            getline(cin, songName);
            myPlaylist.addSong(songName);
            break;
        case 2:
            myPlaylist.displayPlaylist();
            break;
        case 3:
            cout << "Enter song name to search: ";
            getline(cin, songName);
            if (myPlaylist.searchSong(songName))
            {
                cout << "Song found in the playlist." << endl;
            }
            else
            {
                cout << "Song not found in the playlist." << endl;
            }
            break;
        case 4:
            cout << "Enter song name to delete: ";
            getline(cin, songName);
            myPlaylist.deleteSong(songName);
            break;
        case 5:
            myPlaylist.displaySongCount();
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
