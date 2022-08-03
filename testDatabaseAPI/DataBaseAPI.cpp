
#include "DataBaseAPI.h"

DataBaseAPI::DataBaseAPI()
{
    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
   
}

void DataBaseAPI::AddReader(int ReaderId, std::string Name, std::string IpAddress, int AnteneaId, int RSSI, std::string EPC, int Direction)
{
    curl_easy_setopt(curl, CURLOPT_URL, this->URL.data());
    std::string s = "ReaderId=" + std::to_string(ReaderId) + "&Name=" + Name + "&IpAddress=" + IpAddress + "&AnteneaId=" + std::to_string(AnteneaId) + "&RSSI=" + std::to_string(RSSI) + "&EPC=" + EPC + "&Direction=" + std::to_string(Direction);
    /* Now specify the POST data */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, s.data());

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);

curl_global_cleanup();
}

void DataBaseAPI::SetUrl(std::string url)
{
    this->URL = url;
}
