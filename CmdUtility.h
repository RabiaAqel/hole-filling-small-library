//
// Created by Rabia on 16/02/2019.
//

#ifndef HOLEFILLING_CMDUTILITY_H
#define HOLEFILLING_CMDUTILITY_H

#include <string>
#include <vector>
#include <regex>


class CmdUtility
{
public:
    CmdUtility();

    void run();

private:
    std::string prompt();

    void render(const std::string &out);

    void renderError(const std::string &out);

    void renderHelp();

    bool checkInput(const std::string &input);

    void executeCommand();


    static constexpr char USAGE[] = "Usage: fill <image-path>"
                                    " <mask-path> <z> <epsilon> <connectivity-type>";
    static constexpr char PROMPT[] = "HoleFilling > ";
    static constexpr char EXIT[] = "exit";
    static constexpr char HELP[] = "help";
    static constexpr char USAGE_REGEX[] = R"(^\s*fill\s+([\w]*|\.{2}(?:\/[\w]+)*\.[\w]+){1}\s+((?:[\w]*|\.{2})(?:\/[\w]+)*\.[\w]+){1}\s+([\d]+)\s+([\d]+(?:\.[\d]+)?)\s+([\d]+)$)";

    static constexpr char TARGET_PATH[] = "../sample_images";
    static constexpr char DEFAULT_FILE_NAME[] = "new_hole_filled.jpg";

    std::regex rgx_;
    std::smatch matches_;

};


#endif //HOLEFILLING_CMDUTILITY_H
