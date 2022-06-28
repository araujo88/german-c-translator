#if defined(_WIN32)
    #include "C:\curl-7.79.1-win64-mingw\include\curl\curl.h" // windows
#elif defined(__linux__)
    #include <curl/curl.h> // unix
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define URL_LEN 2048
#define WORD_LEN 1024

void to_lower_case(char *string) {
    int i;
    for(i = 0; string[i]; i++){
        string[i] = tolower(string[i]);
    }
}

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void *ignorethis) {
    size_t bytes = itemsize * nitems;
    int i = 0;
    char *word;
    char *html_tag = "<span class=\"btn-inner\"> ";

    word = strstr(buffer, html_tag);

    if (word != NULL) {
        word += strlen(html_tag);
        while (word[i] != ',' && word[i] != '<') {
            printf("%c", word[i]);
            i++;
        }
        printf("\n");
        //exit(EXIT_SUCCESS);
    }
    return bytes;
}

int main(int argc, char *argv[]) {
    CURL *curl = curl_easy_init(); // initialize Curl pointer
    char URL[URL_LEN] = "https://en.langenscheidt.com/"; 
    char word[WORD_LEN] = "";
    char language1[WORD_LEN] = "";
    char language2[WORD_LEN] = "";
    char *usage = "Usage:\ngerman-translator <word> <input-language> <output-language>\n";

    if (argc < 2) {
        printf("Please provide a word to be translated!\n");
        printf(usage);
        return EXIT_FAILURE;
    }
    if (argc < 3) {
        printf("Please provide the input language!\n");
        printf(usage);
        return EXIT_FAILURE;
    }
    if (argc < 4) {
        printf("Please provide the output language!\n");
        printf(usage);
        return EXIT_FAILURE;
    }
    if (argc > 4) {
        printf("Too many arguments provided!\n");
        printf(usage);
        return EXIT_FAILURE;
    }
    if (strlen(argv[1]) > WORD_LEN) {
        printf("Maximum string length exceeded.\n");
        return EXIT_FAILURE;
    }
    if (strlen(argv[2]) > WORD_LEN) {
        printf("Maximum string length exceeded.\n");
        return EXIT_FAILURE;
    }
    if (strlen(argv[3]) > WORD_LEN) {
        printf("Maximum string length exceeded.\n");
        return EXIT_FAILURE;
    }

    strncpy(word, argv[1], strlen(argv[1]));
    strncpy(language1, argv[2], strlen(argv[2]));
    strncpy(language2, argv[3], strlen(argv[3]));
    to_lower_case(word);
    to_lower_case(language1);
    to_lower_case(language2);
    strncat(URL, language1, strlen(language1));
    strcat(URL, "-");
    strncat(URL, language2, strlen(language2));
    strcat(URL, "/");
    strncat(URL, word, strlen(word));

    if (!curl) {
        fprintf(stderr, "ERROR - failed to initialize Curl\n"); // check for errors in initialization
        return EXIT_FAILURE;
    }

    // set options
    curl_easy_setopt(curl, CURLOPT_URL, URL); // sets url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data); // sets function to print data

    // perform action
    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        fprintf(stderr, "ERROR - failed to download: %s\n", curl_easy_strerror(result));
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}