#pragma once

#include <string>

namespace anyfileviewer {

enum class FileKind {
    Text,
    Binary,
    Hex,
    TmpScript,
    Executable,
    Unknown
};

class FileTypeDetector {
public:
    static FileKind detect(const std::string& data, const std::string& extension);
    static std::string normalizedExtension(const std::string& path);
};

} // namespace anyfileviewer
