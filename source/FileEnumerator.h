#pragma once
#include <filesystem>

template<typename T>
void FilesWalk(const char* directory, const char* extension, T callback)
{
    try
    {
        for (auto& it : std::filesystem::directory_iterator(directory))
        {
            if (it.is_regular_file())
            {
                auto& filePath = it.path();

                if (extension != nullptr)
                {
                    if (_stricmp(filePath.extension().string().c_str(), extension) != 0)
                    {
                        continue;
                    }
                }

                auto result = std::filesystem::absolute(filePath);
                callback(result.string().c_str(), result.filename().string().c_str());
            }
        }
    }
    catch (const std::exception& ex)
    {
        TRACE("Error while iterating directory: %s", ex.what());
    }
}
