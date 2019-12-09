//
// Created by peeweep on 2019-12-03.
// jetbrains' products https://www.jetbrains.com/updates/updates.xml
//

#include <curl/curl.h>

#include <iostream>
#include <pugixml.hpp>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

auto getString(std::string url) {
  std::string readBuffer;
  CURL *      curl;
  CURLcode    res;
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    //    std::cout << readBuffer << std::endl;
  }
  return readBuffer;
}

int main(int argc, char const *argv[]) {
  std::string url = "https://www.jetbrains.com/updates/updates.xml";
  //  std::string            url = argv[1];
  pugi::xml_document     doc;
  pugi::xml_parse_result result = doc.load_string(getString(url).c_str());
  if (result.status != pugi::status_ok) {
    std::cout << "load file failed";
    return 0;
  }
  std::cout << (doc.child("products")
                    .find_child_by_attribute("name", argv[1])
                    //      .find_child_by_attribute("name", "PyCharm Edu")
                    .child("channel")
                    .first_child()
                    .attribute("version")
                    .value());
}
