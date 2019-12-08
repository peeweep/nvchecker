//
// Created by peeweep on 2019-12-03.
// jetbrains' products https://www.jetbrains.com/updates/updates.xml
//

#include <iostream>
#include <pugixml.hpp>

int main(int argc, char const *argv[]) {
  pugi::xml_document     doc;
  pugi::xml_parse_result result = doc.load_file(argv[1]);
  if (result.status != pugi::status_ok) {
    std::cout << "load file failed";
    return 0;
  }
  std::cout << (doc.child("products")
                    .find_child_by_attribute("name", "PyCharm Edu")
                    .find_child_by_attribute("name", "PyCharm Edu RELEASE")
                    .first_child()
                    .attribute("version")
                    .value());
}
