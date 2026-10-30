#include "AnyFileViewer/FileTypeDetector.h"

#include <cstddef>
#include <string>

namespace anyfileviewer {

std::string FileTypeDetector::normalizedExtension(const std::string& path) {
    std::size_t dot = path.find_last_of('.');
    if (dot == std::string::npos) {
        return "";
    }
    return path.substr(dot);
}

FileKind FileTypeDetector::detect(const std::string& data, const std::string& extension) {
    if (data.rfind("TMP1.12B", 0) == 0) {
        return FileKind::TmpScript;
    }

    if (extension == ".txt" || extension == ".log" || extension == ".cfg" || extension == ".ini") {
        return FileKind::Text;
    }

    if (extension == ".tmp" || extension == ".dat" || extension == ".bin" || extension == ".unk") {
        return FileKind::Unknown;
    }

    if (data.size() >= 2 && static_cast<unsigned char>(data[0]) == 0x4D &&
        static_cast<unsigned char>(data[1]) == 0x5A) {
        return FileKind::Executable;
    }

    return FileKind::Binary;
}

} // namespace anyfileviewer
