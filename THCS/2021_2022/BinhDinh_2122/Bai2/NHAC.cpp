#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Struct to store the song information with index
struct Song {
    int index;
    int duration;
};

// Comparator to sort based on duration (ascending) and index (ascending)
bool compareSongs(const Song &a, const Song &b) {
    if (a.duration == b.duration) {
        return a.index < b.index;
    }
    return a.duration < b.duration;
}

int main() {
    // Read input from NHAC.INP
    std::ifstream inputFile("NHAC.INP");
    int N;
    inputFile >> N;

    std::vector<Song> songs(N);
    for (int i = 0; i < N; ++i) {
        songs[i].index = i + 1;
        inputFile >> songs[i].duration;
    }
    inputFile.close();

    // Sort the songs based on duration (ascending order) and then by index if durations are equal
    std::sort(songs.begin(), songs.end(), compareSongs);

    // Open the output file
    std::ofstream outputFile("NHAC.OUT");

    int cumulativeTime = 0;
    int totalTime = 0;

    for (const auto &song : songs) {
        cumulativeTime += song.duration;
        outputFile << song.index << " " << cumulativeTime << std::endl;
        totalTime = cumulativeTime; // Track the total cumulative time up to the last song
    }

    // Output the total time as the last line
    outputFile << totalTime << std::endl;
    outputFile.close();

    return 0;
}
