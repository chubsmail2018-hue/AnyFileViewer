#include "AnyFileViewer/TmpInterpreter.h"

#include <iostream>
#include <sstream>
#include <string>

namespace anyfileviewer {

void TmpInterpreter::runScript(const std::string& script) {
    std::cout << "[TMP Language v1.12B]" << std::endl;
    std::cout << "Executing custom script..." << std::endl;

    std::istringstream stream(script);
    std::string line;

    while (std::getline(stream, line)) {
        if (line.empty()) {
            continue;
        }

        if (line.find("PRINT") != std::string::npos) {
            std::cout << "PRINT: " << line.substr(6) << std::endl;
        } else if (line.find("SET") != std::string::npos) {
            std::cout << "SET: " << line << std::endl;
        } else if (line.find("LOOP") != std::string::npos) {
            std::cout << "LOOP: " << line << std::endl;
        } else if (line.find("WAIT") != std::string::npos) {
            std::cout << "WAIT: " << line << std::endl;
        } else if (line.find("END") != std::string::npos) {
            std::cout << "END" << std::endl;
        } else {
            std::cout << "CMD: " << line << std::endl;
        }
    }
}

} // namespace anyfileviewer
