#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>

#include <curl/curl.h>

using namespace std;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

void downloadFile(char* url) {
    CURL *curl_handle;
    static const char *pagefilename = "page.out";
    FILE *pagefile;


    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */ 
    curl_handle = curl_easy_init();

    /* set URL to get here */ 
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    /* Switch on full protocol/debug output while testing */ 
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    /* disable progress meter, set to 0L to enable and disable debug output */ 
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
    // Follow redirects
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);


    /* send all data to this function  */ 
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    /* open the file */ 
    pagefile = fopen(pagefilename, "wb");
    if(pagefile) {

        /* write the page body to this file handle */ 
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

        /* get it! */ 
        curl_easy_perform(curl_handle);

        /* close the header file */ 
        fclose(pagefile);
    }
    /* cleanup curl stuff */ 
    curl_easy_cleanup(curl_handle);

}

bool downloadMaze(string filename, int rows, int cols, int width,
        int height, string type="text", string seed="") {
    CURL *curl;
    CURLcode res;
    FILE *pagefile;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        cout << "Could not initialize curl" << endl;
        return false;
    }

    // Create post data
    string data="cols=" + to_string(cols) + "&" +
                "rows=" + to_string(rows) + "&" +
                "type=text&" +
                "width=" + to_string(width) + "&" +
                "height=" + to_string(height) + "&" +
                "seed=";

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    
    // write the returned webpage into the file specified by 'filename'
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    pagefile = fopen(filename.c_str(), "wb");
    if (!pagefile) {
        cout << "couldnt open file!" << endl;
        return false;
    }
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, pagefile);

    if (!curl) {
        cout << "Error with curl" << endl;
        fclose(pagefile);
        return false;
    }

    // set the URL for the maze generator website
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.delorie.com/game-room/mazes/genmaze.cgi");

    // Perform the request
    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    fclose(pagefile);

    return true;
}

/*
int main(int argc, char* argv[]) {
    downloadMaze("amaze.txt", 20, 20, 2, 2);

    return 0;
}
*/
