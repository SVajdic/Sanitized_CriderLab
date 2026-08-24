/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-21
 * LAST EDIT: 2025-05-14
 *
 * Generic Use Code 
 *
 * Input is the filename of a two column text file
 *
 * Returns a map<obj,obj> from a two column text file
 * Currently map<int,int> and map<string,double> and 
 * map <string,string> and map<double,double> are supported
 * 
 **********************************************************************/
#include "load_two_column.h"

template <typename KeyType, typename ValueType>
std::map<KeyType, ValueType> load_two_column(const std::string& filename) {
  std::map<KeyType, ValueType> output_map;
  std::ifstream infile(filename);
  if (!infile) {
    std::cerr << "ERROR: cannot open " << filename << "\n";
    return output_map;
  }

  std::string line;
  size_t line_no = 0;
  while (std::getline(infile, line)) {
    ++line_no;
    // trim leading whitespace (optional)  
    if (line.empty() || line[0] == '#') 
      continue;

    std::istringstream iss(line);
    KeyType key;
    ValueType value;
    if (!(iss >> key >> value)) {
      std::cerr << "Warning: could not parse line "
                << line_no << ": \"" << line << "\"\n";
      continue;
    }
    output_map[key] = value;  
  }

  std::clog << "Loaded " << output_map.size()
            << " entries from " << filename << "\n";
  return output_map;
}


//Explicit instantiation for specific types
template std::map<int, int> load_two_column<int, int>(const std::string& filename);
template std::map<std::string, double> load_two_column<std::string, double>(const std::string& filename);
template std::map<std::string, std::string> load_two_column<std::string, std::string>(const std::string& filename);
template std::map<double, double> load_two_column<double, double>(const std::string& filename);
