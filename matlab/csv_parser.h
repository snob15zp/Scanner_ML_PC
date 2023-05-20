#ifndef __CSV_PARSER_HPP
#define __CSV_PARSER_HPP

#include <string>
#include <sstream>
#include <fstream>

#include <stdexcept>
#include <vector>

template <typename T>
class csv_parser_t : public std::vector<std::vector<T>>
{
public:
    /**
     * @brief Construct a new csv parser object
     * 
     * @param path Path to CSV file
     * @param skip_first_line Is CSV file contains header which should be skipped
     * @param delimeter Table items delimeter
     */
    csv_parser_t(std::string path, bool skip_first_line = false, char delimeter = '\t' ) 
        : _path(path), _skip_first_line(skip_first_line), _delimeter(delimeter)
    {
        reload();
    }

    /**
     * @brief Reloads CSV file
     */
    void reload()
    {
        std::ifstream ip(_path.c_str());

        if (!ip.is_open())
        {
            throw std::invalid_argument("Failed to open the data file");
        }

        std::string str;
        if (_skip_first_line)
        {
            std::getline(ip, str); // Skip the first line
        }

        while (std::getline(ip, str))
        {
            std::istringstream iss(str);
            std::string token;
            std::vector<T> row;

            while (std::getline(iss, token, _delimeter))
            {
                std::stringstream ss; 
                T val;
                
                ss << token;
                ss >> val;

                row.push_back(val);
            }

            this->push_back(row);
        }

        ip.close();
    }

private:
    std::string &_path;
    bool _skip_first_line;
    char _delimeter;
};

#endif