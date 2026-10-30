#include "AnyFileViewer/FileTypeDetector.h"
#include "AnyFileViewer/TmpInterpreter.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using anyfileviewer::FileKind;
using anyfileviewer::FileTypeDetector;
using anyfileviewer::TmpInterpreter;

static std::string readFileText(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return "";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

static std::vector<unsigned char> readFileBytes(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return {};
    }

    return std::vector<unsigned char>(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>());
}

static void viewText(const std::string& content) {
    std::cout << "[TEXT VIEWER]\n";
    std::cout << content << '\n';
}

static void viewHex(const std::vector<unsigned char>& bytes) {
    std::cout << "[HEX VIEWER]\n";
    for (std::size_t i = 0; i < bytes.size(); ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(bytes[i]) << " ";
        if ((i + 1) % 16 == 0) {
            std::cout << '\n';
        }
    }
    std::cout << std::dec << '\n';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: anyfileviewer <file_path>\n";
        return 1;
    }

    const std::string filePath = argv[1];
    const std::string fileData = readFileText(filePath);
    const std::string extension = FileTypeDetector::normalizedExtension(filePath);
    const FileKind kind = FileTypeDetector::detect(fileData, extension);

    switch (kind) {
        case FileKind::Text:
            viewText(fileData);
            break;

        case FileKind::TmpScript:
            TmpInterpreter::runScript(fileData);
            break;

        case FileKind::Unknown:
        case FileKind::Binary:
            viewHex(readFileBytes(filePath));
            std::cout << "Unknown file type opened in raw preview mode.\n";
            break;

        case FileKind::Executable:
            std::cout << "Native executable blocked by default.\n";
            std::cout << "Only approved or sandboxed execution is allowed.\n";
            break;

        case FileKind::Hex:
            viewHex(readFileBytes(filePath));
            break;
    }

    return 0;
}
